#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.hpp"

using namespace std;

int main() {

  MyHistory * myhistory = new MyHistory(); 

  while (1) {
    printf("in-mysh-now:>");
     
    char inputBuffer[50];
    fgets(inputBuffer, 50, stdin);
    inputBuffer[strlen(inputBuffer) - 1] = '\0';
    if (strcmp("exit", inputBuffer) == 0) {
        break; 
    }

    string comm;
    if (strcmp("myHistory", inputBuffer) == 0) {      
      myhistory->printMyHistory();
    } else if (strncmp(inputBuffer, "myHistory", 9) == 0 ) {
      char charIndex = inputBuffer[10];               
      int intIndex = (int)charIndex - 48;               //converting the index that the user typed in for the myHistory vector to an integer, i do -48 because in ASCII numbers start from 48
      comm = myhistory->getMyHistoryElement(intIndex);
      strcpy(inputBuffer, comm.c_str());
    }

    if (strncmp(inputBuffer, "cd", 2) == 0) {
      string cdCommand = inputBuffer;
      changeDirectory(cdCommand);
    }


    
    string command = inputBuffer;
    myhistory->addToMyHistory(command);     

    vector<string> inputVector = normalizeInput(inputBuffer);
    traverseCommand(inputVector);

    strcpy(inputBuffer, "");        //emptying inputBuffer so the next command can be executed
  }
  delete myhistory;
}
