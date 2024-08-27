# Starfox64 Recompiled

```bash
git clone https://github.com/<YOUR_USERNAME>/Starfox64Recomp.git
```

```bash
git submodule update --init --recursive
```

Build N64Recomp and place it on the root of the repository.

```bash
./N64Recomp us.rev1.toml
```

```bash
./RSPRecomp aspMain.rev1.toml
```

Place an uncompressed rom in the root of the repository and name it:

starfox64.us.rev1.uncompressed.z64

open folder in visual studio, wait for cmake to finish scanning

Build->Build All