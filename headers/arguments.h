#pragma once
#include <iostream>
#include "printers.h"
#include "exploit.h"

struct InitArguments {
    std::string OUTPUT_FILENAME;
    std::string TARGET_HOST;
    std::string TARGET_PORT = "9999";
    std::string SHELLCODE_PATH;
};

class InitProgram : public Printers {
    InitArguments ProgramArguments;
    InitArguments GetArguments(int argc, char* argv[]);
    void PrintHelpMenu();
    void PrintBanner();
    void PrintStatus(std::string status_option, std::string status_value) const override{
        std::cout << status_option << "\t . . . . . "  << status_value << std::endl;
    }
public:
    InitProgram(int argc, char* argv[]){
        if(argc < 2){
            PrintHelpMenu();
        }
        PrintBanner();
        ProgramArguments = this->GetArguments(argc, argv);
        Exploit StartExploitation(ProgramArguments.TARGET_HOST,
                                ProgramArguments.TARGET_PORT, 
                                ProgramArguments.SHELLCODE_PATH);
    }
};