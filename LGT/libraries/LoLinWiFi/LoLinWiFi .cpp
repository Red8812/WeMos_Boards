#include <LoLinWiFi.h>
#include <WiFiSoftwareSerial.h>
#include <LoLinPins.h>

WiFiSoftwareSerial LoLin(_LOLIN_RX_, _LOLIN_TX_);


/*************************************************************************
    Fuction: begin -- All begin here
    
    parameter:  none
    
    Return:
        true    -   successfully
        false   -   unsuccessfully

***************************************************************************/
bool LoLinWiFi::begin(void)
{
    pinMode(_LOLIN_RST_, OUTPUT);
    digitalWrite(_LOLIN_RST_, HIGH);


    LoLin.begin(9600);
    LoLin.setTimeout(1000);
    LoLin.println("AT");
    bool result=LoLin.find("OK");

    return result;
}

/*************************************************************************
    Fuction: init -- Initialize shield's mode

    parameter:
        mode:
                1 MODE_STA     Station mode
                2 MODE_AP      AP mode
                3 MODE_AP_STA  AP+Station mode

        ssid:   joined AP's name(String)
         pwd:   joined AP'spassword(String, max: 64bytes ASCII)

      myssid:   shield's name(String)
       mypwd:   shield's password(String, max: 64bytes ASCII)
         chl:   shield's Channel
         
         ecn:   shield's Encryption
                    0 OPEN
                    1 WEP
                    2 WPA_PSK
                    3 WPA2_PSK
                    4 WPA_WPA2_PSK

    
    Return:
        true    -   successfully
        false   -   unsuccessfully

***************************************************************************/
bool LoLinWiFi::init(byte mode, String ssid, String pwd)
{
    if (mode == MODE_STA || mode == MODE_AP_STA)
    {   
        bool res = confMode(mode);
        if (!res)
        {
            return false;
        }
        
        while(!joinAP(ssid, pwd));
        return true;

    }
    else
    {
        return false;
    }
}

bool LoLinWiFi::init(byte mode, String myssid, String mypwd, byte chl, byte ecn)
{
    if (mode == MODE_AP)
    {
        bool res = confMode(mode);
        if (!res)
        {
            return false;
        }
        
        //reset();
        while(!confAP(myssid, mypwd, chl, ecn));
        return true;
    }
    else
    {
        return false;
    }
}

bool LoLinWiFi::init(byte mode, String ssid, String pwd, String myssid, String mypwd, byte chl, byte ecn)
{
    if(mode == MODE_AP_STA)
    {
        bool res = confMode(mode);
        if (!res)
        {
            return false;
        }
        
        //reset();
        while(!confAP(myssid, mypwd, chl, ecn));
        while(!joinAP(ssid, pwd));
        return true;

    }
    else
    {
        return false;
    }
}
/*************************************************************************
    Fuction: reset -- reset lolin wifi shield

    parameter:  none
    
    Return:
        true    -   successfully
        false   -   unsuccessfully

***************************************************************************/
bool LoLinWiFi::reset(void)
{
    pinMode(_LOLIN_RST_, OUTPUT);
    digitalWrite(_LOLIN_RST_, LOW);
    delay(10);
    digitalWrite(_LOLIN_RST_, HIGH);

    return 1;
}

/*************************************************************************
    Fuction: confMode -- configure shield's mode

    parameter:
        mode:
            1 MODE_STA     Station mode
            2 MODE_AP      AP mode
            3 MODE_AP_STA  AP+Station mode

    
    Return:
        true    -   successfully
        false   -   unsuccessfully

***************************************************************************/
bool LoLinWiFi::confMode(byte mode)
{
    bool result = false;

    LoLin.print("AT+CWMODE=");  
    LoLin.println(String(mode));
    
    //result = LoLin.find("OK");

    return result;      
}


/*************************************************************************
    Fuction: joinAP -- join to AP

    parameter:
        ssid: AP's name(String)
         pwd: password(String, max: 64bytes ASCII)

    
    Return:
        true    -   successfully
        false   -   unsuccessfully

***************************************************************************/
bool LoLinWiFi::joinAP(String ssid , String pwd)
{
    bool result = false;

    //LoLin.setTimeout(3000);
    LoLin.setTimeout(10000);
    LoLin.print("AT+CWJAP=");
    LoLin.print("\"");     //"ssid"
    LoLin.print(ssid);
    LoLin.print("\"");

    LoLin.print(",");

    LoLin.print("\"");      //"pwd"
    LoLin.print(pwd);
    LoLin.println("\"");

    result = LoLin.find("OK");


    return result;

}




/*************************************************************************
    Fuction: quitAP -- disconnect to AP

    parameter: none

    
    Return:
        true    -   successfully
        false   -   unsuccessfully

***************************************************************************/
bool LoLinWiFi::quitAP(void)
{
    bool result = false;

    LoLin.println("AT+CWQAP");

    result = LoLin.find("OK");

    #ifdef _DEBUG_
        if(result)
            DBG("quit AP...OK\r\n");
        else
            DBG("quit AP...fail\r\n");
    #endif

    return result;

}


/*************************************************************************
    Fuction: confAP -- configure AP

    parameter: 
      myssid:   shield's name(String)
       mypwd:   shield's password(String, max: 64bytes ASCII)
         chl:   shield's Channel
         
         ecn:   shield's Encryption
                    0 OPEN
                    1 WEP
                    2 WPA_PSK
                    3 WPA2_PSK
                    4 WPA_WPA2_PSK

    
    Return:
        true    -   successfully
        false   -   unsuccessfully

***************************************************************************/
bool LoLinWiFi::confAP(String myssid, String mypwd, int chl, int ecn)
{
    LoLin.print("AT+CWSAP=");  
    LoLin.print("\"");     //"ssid"
    LoLin.print(myssid);
    LoLin.print("\"");

    LoLin.print(",");

    LoLin.print("\"");      //"pwd"
    LoLin.print(mypwd);
    LoLin.print("\"");

    LoLin.print(",");
    LoLin.print(String(chl));

    LoLin.print(",");
    LoLin.println(String(ecn));
    unsigned long start;
    start = millis();
    while (millis()-start<3000) 
    {                            
        if(LoLin.find("OK")==true )
        {
           while(!reset());//reset after configure AP
           return true;
        }
     }
     
     return false;

}



String LoLinWiFi::showIP(void)
{
    LoLin.println("AT+CIFSR"); 
    

}