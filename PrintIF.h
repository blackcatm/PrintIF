#ifndef PRINTIF_h
#define PRINTIF_h

#include <stdio.h>
#include <Stream.h>
#include <Ethernet.h>

class PrintIFClass{
public:
    void print(Stream &output);
    void print(Stream &output, byte mac[]);
    
    void print(byte mac[])  { print(Serial, mac); }
    void print()            { print(Serial); }
    
    
    void printMAC(Stream &output, byte mac[], byte label = 1);
    void printIP(Stream &output, byte label = 1);
    void printGW(Stream &output, byte label = 1);
    void printMask(Stream &output, byte label = 1);
    void printDNS(Stream &output, byte label = 1);
    
    void printMAC(byte mac[], byte label = 1)   { printMAC(Serial, mac, label); }
    void printIP(byte label = 1)                { printIP(Serial, label); }
    void printGW(byte label = 1)                { printGW(Serial, label); }
    void printMask(byte label = 1)              { printMask(Serial, label); }
    void printDNS(byte label = 1)               { printDNS(Serial, label); }
    
private:
    char buffer[18];
};

extern PrintIFClass PrintIF;
#endif
