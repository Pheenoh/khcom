# Kingdom Hearts: Chain of Memories

A work-in-progress matching decompilation of *Kingdom Hearts: Chain of Memories*
for the Game Boy Advance.

> [!IMPORTANT]
> This repository does **not** contain any game assets or ROMs. An existing
> copy of the game is required to build.

The project can target the following versions:

| Version | Code | SHA-1 |
|---------|------|-------|
| `us`    | B8CE | `10729bd884f8fdca7a310b6d606c52e46657aa48` |
| `jp`    | B8CJ | `59ec0a0a4ccd1e6acb3bbd7bfb21d63988958cfa` |
| `eu`    | B8CP | `8db73586cdb11b3795907edebf43228dbcd3e6b2` |

## Dependencies

- git
- ninja
- python3
- `binutils-arm-none-eabi`
- [agbcc](https://github.com/pret/agbcc):

  ```sh
  git clone https://github.com/pret/agbcc
  cd agbcc && ./build.sh && ./install.sh ../com
  ```

## Building

- Clone the repository:

  ```sh
  git clone https://github.com/pheenoh/khcom.git
  ```

- Copy your legally dumped ROM(s) into `roms/` as `<code>.gba` (e.g. `roms/B8CE.gba`).

- Configure:

  ```sh
  python3 configure.py
  ```

  To use a version other than `us`, specify it with `--version`.

- Build:

  ```sh
  ninja
  ```

## License

This project is released under the [CC0 1.0 Universal](LICENSE.md) license.
