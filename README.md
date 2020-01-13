# ft_select

<div align='center'>
    <sub>Created by <a href='https://github.com/rouhija'>Sami Rouhe (srouhe)</a></sub>
</div>
<div align='center'>
    <sub>From <a href='https://hive.fi'>Hive Helsinki</a></sub>
</div>

### Description
Command line file browser/manager. Browse files in a simple UI with arrows and return selection back to shell.

### Usage
```sh
./ft_select arg1 [arg2] ...
```

### Commands
- ENTER: return selection
- SPACE: select/unselect object
- BACKSPACE/DEL: remove object from list
- SHIFT+a: select all
- SHIFT+z: unselect all
- ESC: exit

### Dependencies
Termcaps lib
```sh
sudo apt-get install libncurses5-dev
```

### Reading
- [Termcaps library](https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html)
- [Low level terminal interface](https://www.gnu.org/software/libc/manual/html_node/Low_002dLevel-Terminal-Interface.html#Low_002dLevel-Terminal-Interface)
