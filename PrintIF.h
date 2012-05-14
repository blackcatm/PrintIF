/*
 PrintIF.h - Utility Library for printing Ethernet interface configuration
             on Arduino
 Copyright (c) 2012 J.P. McGlinn. All Rights reserved
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */


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
