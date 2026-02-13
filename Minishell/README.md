*This project was created as part of the 42 curriculum by [jonamart, anvilla-].*

# Minishell

## Description

Minishell is a simplified implementation of a command interpreter inspired by bash.
The goal of the project is to dive into the internal workings of a real shell, including process management, signals, redirections, pipes, and command parsing.

The program must be able to execute simple and compound commands, respect bash’s expected behavior in most cases, and handle errors consistently.

Key aspects of the project include:

    Interpretation and execution of commands.

    Handling of pipes and redirections.

    Implementation of builtins.

    Signal management.

    Expansion of environment variables.

    Process control and return statuses.

---

## Instructions

### Compilation

The proyect uses a Makefile with the standard rules:

make        # Compiles minishell
make clean  # Removes object files
make fclean # Removes binaries and object files
make re     # Rebuilds everything from scratch


## Documentation and references

Bash manual: https://www.gnu.org/software/bash/manual/
Unix processes and signals: man 2 fork, man 2 execve, man 2 pipe, man 7 signal
Shell redirections and operators: man bash
Readline documentation: https://tiswww.case.edu/php/chet/readline/rltop.html
Online Guide: https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218
Simple shell in c Video: https://www.youtube.com/watch?v=yTR00r8vBH8 
"Build a shell" Video: https://www.youtube.com/watch?v=vgxWYYdwKLc

## Implemented features

Interactive prompt
Execution of external commands
Multiple pipes
Redirections (>, >>, <)
Expansion of $VARIABLES
Handling of single and double quotes
Builtins:

        echo

        cd

        pwd

        export

        unset

        env

        exit
Signal handling:

        Ctrl‑C

        Ctrl‑\

        Ctrl‑D

## Technical decisions

### Choice of parsing model

A staged parser was implemented (tokenization → expansion → command construction → execution).
A full recursive parser like bash’s was discarded due to its complexity and because it exceeded the project requirements.
Tokenization was designed to respect quotes, operators (|, <, >, >>), and variables.

### Pipe and redirection handling

A chained command structure was chosen, where each node contains its own redirection configuration and its corresponding pipe.
The use of popen() was discarded because it does not allow the level of granular control required.
File descriptors are managed manually to avoid leaks and unexpected behavior.


### Signal handling

It was decided to replicate bash’s behavior as closely as possible:
Ctrl‑C interrupts the prompt but does not close the shell
Ctrl‑\\ is ignored in the prompt
In child processes, signals return to their default behavior
Handling signals inside the parser or executor was discarded to keep responsibilities clearly separated.

### Builtin implementation

Builtins that modify the environment (cd, export, unset) are executed in the parent process because they must affect the shell’s state.
Builtins that do not modify the environment (echo, pwd, env, exit) can run in child processes when they appear inside a pipeline.
Running all builtins in the parent process was discarded because it would break the expected behavior inside pipelines.

### Environment handling

A custom copy of envp was created to allow modifying it without depending on the original process environment.
Global variables were avoided to prevent side effects and make maintenance easier.

### Memory management

A strict memory‑freeing policy was adopted at every stage of the execution cycle.
Implementing a custom garbage collector was discarded due to unnecessary complexity.

### Style and architecture

A modular architecture was followed:

    lexer/

    parser/

    executor/

    builtins/

    etc.

This makes debugging easier and allows the project to grow cleanly.
A single monolithic file was avoided to reduce coupling and improve readability.