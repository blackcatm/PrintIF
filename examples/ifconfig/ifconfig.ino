/*
 DHCP-based IP printer
 
 This sketch uses the DHCP extensions to the Ethernet library
 to get an IP address via DHCP and print the address obtained.
 using an Arduino Wiznet Ethernet shield. 
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 
 created 12 April 2011
 by Tom Igoe

 modified 13 May 2012 to act as an example of PrintIF utility library
 by J.P. McGlinn 
 */

#include <SPI.h>
#include <Ethernet.h>
#include <PrintIF.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {  
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };

// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

void setup() {
  // start the serial library:
  Serial.begin(57600);
  Serial.println("Attempting to start Ethernet.");
  
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    forever();
  }
  
}


// DEMO CODE RUNS ONCE
void loop(){
  //Print the interface information
  PrintIF.print(Serial, mac);
  Serial.println();

  //As before, but no mac address
  PrintIF.print(Serial);
  Serial.println();

  //use the default stream (Serial)
  PrintIF.print(mac);
  Serial.println();

  //one more time without mac address
  PrintIF.print();
  Serial.println();


  // You can also print individual properties, with and without labels.
  // Send output to alternate streams if you like too.
  Serial.println("\nIndividual properties:\n");
  
  PrintIF.printMAC(Serial, mac);
  PrintIF.printMAC(mac);
  PrintIF.printMAC(Serial, mac, 0);  Serial.println();
  PrintIF.printMAC(mac, 0);          Serial.println();
  
  PrintIF.printIP(Serial);
  PrintIF.printIP();
  PrintIF.printIP(Serial, 0);        Serial.println();
  PrintIF.printIP(0);                Serial.println();
  
  PrintIF.printGW(Serial);
  PrintIF.printMask();
  PrintIF.printDNS();

  forever();
}


void forever(void){
  while(1){
  }
}
