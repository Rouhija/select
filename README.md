tgetflag(3)
tgetnum(3)
tgetstr(3)
tputs(3)
tcgetattr(3)
tcsetattr(3)

### Dependencies
Termcaps lib
```sh
sudo apt-get install libncurses5-dev
```

### Reading
[suspend ctrl-z](https://superuser.com/questions/262942/whats-different-between-ctrlz-and-ctrlc-in-unix-command-line)
[Termcaps library](https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html)

```
tcflag_t c_iflag;      /* input modes */
tcflag_t c_oflag;      /* output modes */
tcflag_t c_cflag;      /* control modes */
tcflag_t c_lflag;      /* local modes */
cc_t     c_cc[NCCS];   /* special characters */

termios_p->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
				| INLCR | IGNCR | ICRNL | IXON);
termios_p->c_oflag &= ~OPOST;
termios_p->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
termios_p->c_cflag &= ~(CSIZE | PARENB);
termios_p->c_cflag |= CS8;
```

```
Many terminals have arrow and function keys that transmit specific character sequences to the computer. Since the precise sequences used depend on the terminal, termcap defines capabilities used to say what the sequences are. Unlike most termcap string-valued capabilities, these are not strings of commands to be sent to the terminal, rather strings that are received from the terminal.

Programs that expect to use keypad keys should check, initially, for a `ks' capability and send it, to make the keypad actually transmit. Such programs should also send the `ke' string when exiting.

`ks'
String of commands to make the keypad keys transmit. If this capability is not provided, but the others in this section are, programs may assume that the keypad keys always transmit.
`ke'
String of commands to make the keypad keys work locally. This capability is provided only if `ks' is.
`kl'
String of input characters sent by typing the left-arrow key. If this capability is missing, you cannot expect the terminal to have a left-arrow key that transmits anything to the computer.
`kr'
String of input characters sent by typing the right-arrow key.
`ku'
String of input characters sent by typing the up-arrow key.
`kd'
String of input characters sent by typing the down-arrow key.
`kh'
String of input characters sent by typing the "home-position" key.
`K1' ... `K5'
Strings of input characters sent by the five other keys in a 3-by-3 array that includes the arrow keys, if the keyboard has such a 3-by-3 array. Note that one of these keys may be the "home-position" key, in which case one of these capabilities will have the same value as the `kh' key.
`k0'
String of input characters sent by function key 10 (or 0, if the terminal has one labeled 0).
`k1' ... `k9'
Strings of input characters sent by function keys 1 through 9, provided for those function keys that exist.
`kn'
Number: the number of numbered function keys, if there are more than 10.
`l0' ... `l9'
Strings which are the labels appearing on the keyboard on the keys described by the capabilities `k0' ... `l9'. These capabilities should be left undefined if the labels are `f0' or `f10' and `f1' ... `f9'.
`kH'
String of input characters sent by the "home down" key, if there is one.
`kb'
String of input characters sent by the "backspace" key, if there is one.
`ka'
String of input characters sent by the "clear all tabs" key, if there is one.
`kt'
String of input characters sent by the "clear tab stop this column" key, if there is one.
`kC'
String of input characters sent by the "clear screen" key, if there is one.
`kD'
String of input characters sent by the "delete character" key, if there is one.
`kL'
String of input characters sent by the "delete line" key, if there is one.
`kM'
String of input characters sent by the "exit insert mode" key, if there is one.
`kE'
String of input characters sent by the "clear to end of line" key, if there is one.
`kS'
String of input characters sent by the "clear to end of screen" key, if there is one.
`kI'
String of input characters sent by the "insert character" or "enter insert mode" key, if there is one.
`kA'
String of input characters sent by the "insert line" key, if there is one.
`kN'
String of input characters sent by the "next page" key, if there is one.
`kP'
String of input characters sent by the "previous page" key, if there is one.
`kF'
String of input characters sent by the "scroll forward" key, if there is one.
`kR'
String of input characters sent by the "scroll reverse" key, if there is one.
`kT'
String of input characters sent by the "set tab stop in this column" key, if there is one.
`ko
```