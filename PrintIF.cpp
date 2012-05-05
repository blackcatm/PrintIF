#include <PrintIF.h>

void PrintIFClass::printInfo(Stream &output, byte mac[]){
    printMAC(output, mac, 1);
    printInfo(output);
}

void PrintIFClass::printInfo(Stream &output){
    printIP(output);
    printMask(output);
    printGW(output);
    printDNS(output);
}

void PrintIFClass::printMAC(Stream &output, byte mac[], byte label){
    // print mac address:
    if(label)
        output.print("Ethernet address: ");
    
    sprintf(buffer,"%02x:%02x:%02x:%02x:%02x:%02x",
            mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
    output.print(buffer);
    if(label)
        output.println();
}

void PrintIFClass::printIP(Stream &output, byte label){
    // print your local IP address:
    if(label)
        output.print("      IP address: ");
    
    sprintf(buffer,"%u.%u.%u.%u",
            Ethernet.localIP()[0],
            Ethernet.localIP()[1],
            Ethernet.localIP()[2],
            Ethernet.localIP()[3]);
    output.print(buffer);
    if(label)
        output.println();
}

void PrintIFClass::printMask(Stream &output, byte label){
    // print subnet mask:
    if(label)
        output.print("     Subnet mask: ");
    
    sprintf(buffer,"%u.%u.%u.%u",
            Ethernet.subnetMask()[0],
            Ethernet.subnetMask()[1],
            Ethernet.subnetMask()[2],
            Ethernet.subnetMask()[3]);
    output.print(buffer);
    if(label)
        output.println();
}
        
void PrintIFClass::printGW(Stream &output, byte label){
    // print local gateway IP address:
    if(label)
        output.print(" Gateway address: ");
    
    sprintf(buffer,"%u.%u.%u.%u",
            Ethernet.gatewayIP()[0],
            Ethernet.gatewayIP()[1],
            Ethernet.gatewayIP()[2],
            Ethernet.gatewayIP()[3]);
    output.print(buffer);
    if(label)
        output.println();
}

void PrintIFClass::printDNS(Stream &output, byte label){
    // print DNS server IP address:
    if(label)
        output.print("      DNS server: ");
    
    sprintf(buffer,"%u.%u.%u.%u",
            Ethernet.dnsServerIP()[0],
            Ethernet.dnsServerIP()[1],
            Ethernet.dnsServerIP()[2],
            Ethernet.dnsServerIP()[3]);
    output.print(buffer);
    if(label)
        output.println();
}

PrintIFClass PrintIF;
