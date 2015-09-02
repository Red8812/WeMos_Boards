/*
SoftwareSerial.h (formerly NewSoftSerial.h) - 
Multi-instance software serial library for Arduino/Wiring
-- Interrupt-driven receive and other improvements by ladyada
   (http://ladyada.net)
-- Tuning, circular buffer, derivation from class Print/Stream,
   multi-instance support, porting to 8MHz processors,
   various optimizations, PROGMEM delay tables, inverse logic and 
   direct port writing by Mikal Hart (http://www.arduiniana.org)
-- Pin change interrupt macros by Paul Stoffregen (http://www.pjrc.com)
-- 20MHz processor support by Garrett Mace (http://www.macetech.com)
-- ATmega1280/2560 support by Brett Hagman (http://www.roguerobotics.com/)

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

The latest version of this library can always be found at
http://arduiniana.org.
*/

#ifndef LOLIN_WIFI_H
#define LOLIN_WIFI_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
  #include <pins_arduino.h>
#endif


#define MODE_STA     1
#define MODE_AP      2
#define MODE_AP_STA  3

#define TYPE_UDP 0
#define TYPE_TCP 1


#ifndef GCC_VERSION
#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#endif

class LoLinWiFi {
  public:
    //base command
    bool begin(void); //connect to Lolin WiFi Shield

    bool init(byte mode, String ssid, String pwd);

    bool init(byte mode, String myssid, String mypwd, byte chl, byte ecn);

    bool init(byte mode, String ssid, String pwd, String myssid, String mypwd, byte chl, byte ecn);
    
    bool reset(void);    //reset the module
    
    //wifi command
    bool confMode(byte mode);//change wifi mode
    
    bool joinAP(String ssid , String pwd);// join AP
    
    bool quitAP(void);//quit AP
    
    bool confAP(String myssid, String mypwd, int chl, int ecn);//conf AP parameter
    

    
    //TCP/IP Command
    String showIPStatus(void);//show Connection Status
    
    bool newConn(byte type, String addr, int port);   //create new tcp or udp connection (sigle connection mode)
    bool newConn(byte id, byte type, String addr, int port);   //create new tcp or udp connection (multiple connection mode)(id:0-4) 
    
    bool send(int len);  //send data in single connection mode
    bool send(byte id, int len);  //send data in multiple connection mode
    
    bool closeConn(void);   //close tcp or udp (sigle connection mode)
    bool closeConn(byte id); //close tcp or udp (multiple connection mode)
    
    String showIP(void); //show IP
    
    bool confMux(bool mode);//set the connection mode(single:0 or multiple:1)
    
    bool confServer(byte mode, int port);//server mode
    
    bool confIPMode(byte mode);//set Transfer mode
    
    bool confIPTimeout(unsigned int time);//set server time out

    int receive(void);//Receive Message

    byte receive_ID;//Received connection ID (0-4)

    char * receive_start;


    //other
    bool upgrade(void);//Upgrade
    bool setRelay(int on);
    bool setLed(int on);
  private:
    

};


#endif
