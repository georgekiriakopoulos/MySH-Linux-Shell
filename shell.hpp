#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <cstring>
#include <glob.h>
#include<signal.h>


#define READ 0 
#define WRITE 1 

using namespace std; 

class Alias {
    public:
        string originalCommand;
        string aliasedCommand;

        Alias(string oc, string ac) {
            originalCommand = oc;
            aliasedCommand = ac; 
        }
};

class MyHistory {
    public:
        vector<string> commandsVector;
        int currentFreeIndex;

        MyHistory(){currentFreeIndex = 0;}

        void addToMyHistory(string command) {
            if (currentFreeIndex < 20) {
                commandsVector.push_back(command);
                currentFreeIndex++;
            } else {
                for (int i = 0; i < 19; i++) {
                    commandsVector[i] = commandsVector[i+1];
                }
                commandsVector[19] = command;
            }
        }

        void printMyHistory() {
            for (int i = 0; i < commandsVector.size(); i++) {
                cout << i << "|" << commandsVector[i] << endl; 
            }
        }

        string getMyHistoryElement(int index) {
            return commandsVector[index];
        }
};

extern std::vector<Alias *> aliasesVector; 
extern pid_t stoppedProcessPid;


std::vector<std::string> normalizeInput( std::string );
int redirectInput(std::string);
int redirectOutput(std::string);  
int appendOutput(std::string); 
void traverseCommand(std::vector<std::string>);
void executeCommand(std::string, bool ); 
void implementPipe(std::string, std::string); 
int countWordsInCommand(std::string);
bool handleAliases(std::string &);
void createAlias(std::string);
void destroyAlias(std::string);
void handleSigint(int);
void handleSigtstp(int);
void printAliases();
void printInputArguments(char *[], int);
void changeDirectory(std::string);

