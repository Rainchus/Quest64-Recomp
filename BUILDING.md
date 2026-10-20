# Building Guide

This guide will help you build the project on your local machine. You will need your own copy of the **1.0 North American (USA)** version of Quest 64 in `.z64` format. No other version will work.

These steps cover: cloning the repository, installing the tools, running the recompiler and finally building the project.

## 1. Clone the Quest64Recomp Repository
This project makes use of submodules so you will need to clone the repository with the `--recurse-submodules` flag.

```bash
git clone --recurse-submodules https://github.com/Rainchus/Quest64-Recomp.git
# if you forgot to clone with --recurse-submodules
# cd /path/to/cloned/repo && git submodule update --init --recursive
```

Then copy your ROM into the repository root and name it `quest64.us.z64`.

## 2. Install Dependencies

### Windows
Install the following:

- [Visual Studio 2022](https://visualstudio.microsoft.com/downloads/) with these options selected:
  - Desktop development with C++
  - C++ Clang Compiler for Windows
  - C++ CMake tools for Windows
- [LLVM](https://github.com/llvm/llvm-project/releases), for its `ld.lld` linker: `winget install LLVM.LLVM`
- [MSYS2](https://www.msys2.org/), for a clang that can compile MIPS code: `winget install MSYS2.MSYS2`, then in an MSYS2 shell run `pacman -S mingw-w64-clang-x86_64-clang`
- `make`: `winget install ezwinports.make`

> [!NOTE]
> The patches in `patches/` are compiled for the N64's MIPS CPU. The official Windows builds of LLVM (the installer, the release archive, and the copy bundled with Visual Studio) are built without the MIPS target, which is why MSYS2's clang is needed. The official `ld.lld` is still used for linking, because MSYS2's `ld.lld` defaults to Windows-style linking.

### Linux
For Linux the instructions for Ubuntu are provided, but you can find the equivalent packages for your preferred distro. The Linux build has not been tested since the Windows build fixes.

```bash
# For Ubuntu, simply run:
sudo apt-get install cmake ninja-build libsdl2-dev libgtk-3-dev lld llvm clang
```

## 3. Build

### Windows
From the repository root, run:

```bash
build-windows.bat Release
```

The script builds the recompiler tools, recompiles the ROM into C code, and builds the game. Steps that are already done are skipped, so running it again only rebuilds what changed. If a tool is missing, the script says which one and how to install it.

The result is `build-Release\Quest64Recompiled.exe`. Use `Debug` instead of `Release` for a debug build.

### Linux (manual steps)
Build [N64Recomp](https://github.com/N64Recomp/N64Recomp) from `lib/N64ModernRuntime/N64Recomp` (the version this project's runtime expects), copy `N64Recomp` and `RSPRecomp` to the repository root, then run:

```bash
./N64Recomp us.rev0.toml
./RSPRecomp aspMain.toml
cmake -S . -B build-cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build-cmake --target Quest64Recompiled -j$(nproc)
```

## 4. Run

Run the executable with the repository root as the working directory, or copy the `assets` folder next to the executable. When the game asks for a ROM, select your USA 1.0 Quest 64 ROM.
