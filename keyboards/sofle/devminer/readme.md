# DevMiner's keymap for the Sofle v2

## Changes

- Moved around most symbol keys on the lower layer
- Moved the arrow keys to <kbd>h</kbd> <kbd>j</kbd> <kbd>k</kbd> <kbd>l</kbd> (like in VIM)
- Swapped <kbd>Enter</kbd> and <kbd>Space</kbd>
- Removed Colemak
- Added Game mode (shifts left keyboard half by one key to the right)
- OLED screen is disabled for lower latency
- VSCode debugger hotkeys

## Commands

### Build

```shell
make sofle/devminer:devminer
```

The resulting `.hex` file will be in `.build/sofle_devminer_devminer.hex`.

### Flash

```shell
qmk flash -kb sofle/devminer -km devminer -bl avrdude-split-left
qmk flash -kb sofle/devminer -km devminer -bl avrdude-split-right
```
