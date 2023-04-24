#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#define PERMS 0644
#include <string.h>
#include <sys/wait.h>
#include "shell.hpp"

using namespace std;

//NOTES
//you have to implement cd command by yourself.


int main() {


  while (1) {
    printf("in-mysh-now:>");
     
    char inputBuffer[50];
    fgets(inputBuffer, 50, stdin);
    inputBuffer[strlen(inputBuffer) - 1] = '\0';
    if (strcmp("exit", inputBuffer) == 0) {
        break; 
    }

    string inputString = inputBuffer;
    vector<string> inputVector = normalizeInput(inputBuffer);

    traverseCommand(inputVector);
  }
  
}
