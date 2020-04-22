### Description
Command line file browser/manager. Browse files in a simple UI with arrows and return selection back to shell.

## Usage
```sh
make && ./select arg1 [arg2] ...
```

## Commands
| KEY | ACTION |
|---------|---------|
| <kbd>ENTER</kbd> | Return selection |
| <kbd>SPACE</kbd> | Select/unselect object |
| <kbd>BACKSPACE/DEL</kbd> | Remove object from list |
| <kbd>SHIFT + A</kbd> | Select all |
| <kbd>SHIFT + Z</kbd> | De-select all |
| <kbd>ESC</kbd> | Exit |

### Dependencies
Termcaps lib
```sh
sudo apt-get install libncurses5-dev
```

### Reading
- [Termcaps library](https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html)
- [Low level terminal interface](https://www.gnu.org/software/libc/manual/html_node/Low_002dLevel-Terminal-Interface.html#Low_002dLevel-Terminal-Interface)

<div align='center'>
    <sub>Created by <a href='https://github.com/rouhija'>Sami Rouhe (srouhe)</a></sub>
</div>
<div align='center'>
    <sub>From <a href='https://www.hive.fi/en/'>Hive Helsinki</a></sub>
</div>
