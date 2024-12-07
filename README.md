# MySH: A Custom Linux Shell in C++

## Overview
**MySH** is a lightweight Linux shell implemented in C++. It provides basic shell functionalities, including command execution, input/output redirection, piping, background processes, and command aliasing. Additionally, it includes a custom command history feature for convenience.

## Features
- **Command Execution:** Supports standard Linux commands using `execvp`.
- **Input/Output Redirection:** Redirect input/output using `<`, `>`, and `>>`.
- **Piping:** Supports single pipes (e.g., `ls | grep txt`).
- **Background Processes:** Execute commands in the background using `&`.
- **Command Aliases:** Create and manage command aliases with `createalias` and `destroyalias`.
- **Command History:** View and execute previous commands using `myHistory`.

## Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/mysh.git
   cd mysh
2. **Compile the code:**
   ```bash
   g++ -o mysh main.cpp shell.cpp -std=c++17
3. Run the shell:
  ```bash
  ./mysh
