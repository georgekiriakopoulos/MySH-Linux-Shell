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

#define READ 0 
#define WRITE 1 
//bool background_process; 



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

extern std::vector<Alias *> aliasesVector; 


// std::vector<char **> myHistory;


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
//void addToMyHistory(char *, int ) ;
//void printAliases();
//void printInputArguments(char *[], int);
//void printMyHistory();
//char **stringToCharCommand(std::string, int &); 
