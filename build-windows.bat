@echo off
setlocal
rem One-command Windows build for Quest 64 Recompiled. See BUILDING.md.
rem
rem Usage: build-windows.bat [Release|Debug]
rem
rem Toolchain:
rem   - Main game: Visual Studio 2022 clang-cl ("C++ Clang Compiler for Windows" component).
rem   - Patches (MIPS code): MSYS2 clang, because the official Windows LLVM builds
rem     (installer, release tarball, and Visual Studio's copy) don't include the MIPS target.
rem   - Patches linker: official LLVM ld.lld. MSYS2's ld.lld defaults to the MinGW/COFF
rem     flavor and rejects ELF linker flags. Linking doesn't need the MIPS target.
rem Override the defaults with the PATCHES_CC / PATCHES_LD environment variables.

set BUILD_TYPE=%1
if "%BUILD_TYPE%"=="" set BUILD_TYPE=Release

if "%PATCHES_CC%"=="" set PATCHES_CC=C:\msys64\clang64\bin\clang.exe
if "%PATCHES_LD%"=="" set PATCHES_LD=C:\Program Files\LLVM\bin\ld.lld.exe

cd /d "%~dp0" || exit /b 1

rem The patches Makefile can't handle spaces in tool paths, so use 8.3 short paths.
for %%I in ("%PATCHES_CC%") do set PATCHES_CC=%%~sI
for %%I in ("%PATCHES_LD%") do set PATCHES_LD=%%~sI

if not exist "%PATCHES_CC%" (
    echo ERROR: MSYS2 clang not found at %PATCHES_CC%
    echo Install MSYS2, then run in an MSYS2 shell: pacman -S mingw-w64-clang-x86_64-clang
    exit /b 1
)
if not exist "%PATCHES_LD%" (
    echo ERROR: LLVM ld.lld not found at %PATCHES_LD%
    echo Install LLVM: winget install LLVM.LLVM
    exit /b 1
)
where make >nul 2>nul || (
    echo ERROR: make not found. Install it: winget install ezwinports.make
    exit /b 1
)

set VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe
for /f "usebackq tokens=*" %%I in (`"%VSWHERE%" -latest -version [17.0^,18.0^) -requires Microsoft.VisualStudio.Component.VC.Llvm.Clang -property installationPath`) do set VSDIR=%%I
if "%VSDIR%"=="" (
    echo ERROR: Visual Studio 2022 with the "C++ Clang Compiler for Windows" component was not found.
    exit /b 1
)
call "%VSDIR%\VC\Auxiliary\Build\vcvars64.bat" >nul || exit /b 1

rem Build the recompiler tools from the N64Recomp version pinned by the runtime.
if not exist N64Recomp.exe (
    echo === Building N64Recomp tools ===
    cmake -S lib\N64ModernRuntime\N64Recomp -B lib\N64ModernRuntime\N64Recomp\build -G Ninja ^
        -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl || exit /b 1
    cmake --build lib\N64ModernRuntime\N64Recomp\build --target N64RecompCLI RSPRecomp RecompModTool || exit /b 1
    for %%T in (N64Recomp RSPRecomp RecompModTool) do copy /y lib\N64ModernRuntime\N64Recomp\build\%%T.exe . >nul
)

rem Generate C code from the ROM.
if not exist RecompiledFuncs\ (
    if not exist quest64.us.z64 (
        echo ERROR: Put your Quest 64 ^(USA 1.0^) ROM in this folder as quest64.us.z64
        exit /b 1
    )
    echo === Recompiling the ROM ===
    N64Recomp.exe us.rev0.toml || exit /b 1
    RSPRecomp.exe aspMain.toml || exit /b 1
)

echo === Building Quest64Recompiled (%BUILD_TYPE%) ===
cmake -S . -B build-%BUILD_TYPE% -G Ninja -DCMAKE_BUILD_TYPE=%BUILD_TYPE% ^
    -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl ^
    -DPATCHES_C_COMPILER=%PATCHES_CC% -DPATCHES_LD=%PATCHES_LD% || exit /b 1
cmake --build build-%BUILD_TYPE% --target Quest64Recompiled || exit /b 1

echo.
echo Built build-%BUILD_TYPE%\Quest64Recompiled.exe
echo Run it with this folder as the working directory so it can find assets\.
