# About Minishell

This is the eighth project in the 42 Cadet Curriculum. Minishell is about creating a simple shell with limited external functions.

![image](https://i.imgur.com/O3coJSA.gif)

As beautiful as a shell.

![image](https://game.42sp.org.br/static/assets/achievements/minishelln.png)


### External functs.
`readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history`, `printf`, `malloc`, `free`, `write`, `access`, `open`, `read`, `close`, `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`, `exit`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`, `opendir`, `readdir`, `closedir`, `strerror`, `perror`, `isatty`, `ttyname`, `ttyslot`, `ioctl`, `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`

### Group
Made with <3 by:
- Willian Lima (@willianlim)
- Paulo Rafael Ramalho (@Yaten)

---
# Installation & Usage

### Requirements
The only requirements are:
- GNU make (v4.2.1)
- GCC (v9.4.0)

Those versions are the ones used during development.

### Building the program

1. Download/Clone this repo

        git clone https://github.com/willianlim/Minishell
2. `cd` into the root directory and run `make`

        cd Minishell
        make

### Running the program

1. After building the source, run `./bin/minishell` from the project root.

        ./bin/minishell

---
# Mandatory part

- [x] Display a **prompt** when waiting for a new command.
- [x] **History**.
- [x] Search and launch the right executable.
- [x] Only **one global variable**.
- [x] Not interpret unclosed quotes or special characters which are not required by the subject.
- [ ] Handle **’** (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- [ ] Handle **"** (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
- [ ] Handle **environment variables** (**$** followed by a sequence of characters) which should expand to their values.
- [ ] Handle **$**? which should expand to the exit status of the most recently executed foreground pipeline.
- [ ] Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
### In interactive mode:
- [ ] ctrl-C displays a new prompt on a new line.
- [ ] ctrl-D exits the shell.
- [ ] ctrl-\ does nothing.
### Implemented builtins
- [x] **echo** with option **-n**
- [x] **cd** with only a relative or absolute path
- [x] **pwd** with no options
- [x] **export** with no options
- [x] **unset** with no options
- [x] **env** with no options or arguments
- [x] **exit** with no options
### Implemented **redirections**
- [ ] **<** redirect input.
- [ ] **>** redirect output.
- [ ] **<<** with a delimiter, then read the input until a line containing the delimiter is seen.
- [ ] **>>** redirect output in append mode.
- [ ] **Pipes** `(| character)`. The output of each command in the pipeline is connected to the input of the next command via a pipe.

Yes, my own little bash! :D

---
# Reference
- links
