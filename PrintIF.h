#ifndef PRINTIF_h
#define PRINTIF_h

#include <stdio.h>
#include <Stream.h>
#include <Ethernet.h>

class PrintIFClass{
public:
    void printInfo(Stream &output);
    void printInfo(Stream &output, byte mac[]);
    
    void printMAC(Stream &output, byte mac[], byte label = 1);
    void printIP(Stream &output, byte label = 1);
    void printGW(Stream &output, byte label = 1);
    void printMask(Stream &output, byte label = 1);
    void printDNS(Stream &output, byte label = 1);

private:
    char buffer[18];
};

extern PrintIFClass PrintIF;
#endif
