#include <SoftwareSerial.h>
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8  
 
int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3
int i=0,j=20,m=0;

String dataFromBt;
 
TFT TFTscreen = TFT(cs, dc, rst);

// char array to print to the screen
char sensorPrintout[100];
 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
 
void setup()
{
  Serial.begin(9600);  // Begin the serial monitor at 9600bps
 
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  pinMode(8, OUTPUT);
  
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  
  // write the static text to the screen
  // set the font color to white
  TFTscreen.stroke(0,255,0);
  // set the font size
  TFTscreen.setTextSize(7);
  // write the text to the top left corner of the screen
  TFTscreen.text("COBO\n ",0,25);
  
  TFTscreen.stroke(255,255,0);
  
  TFTscreen.setTextSize(1);
  // write the text to the top left corner of the screen
  TFTscreen.text("Circuit Of Bionic Organism",0,80);
  delay(5000);
  TFTscreen.background(0, 0, 0);
  TFTscreen.stroke(0,255,0);
  // set the font size
  TFTscreen.setTextSize(2);
  // write the text to the top left corner of the screen
  TFTscreen.text("BT value :\n ",0,0);
  // ste the font size very large for the loop
  TFTscreen.setTextSize(2);
}
 
void loop()
{
  
  if (bluetooth.available()) // If the bluetooth sent any characters
  {
    // Send any characters the bluetooth prints to the serial monitor
    sensorPrintout[m] = char(bluetooth.read());
    //sensorVal.toCharArray(sensorPrintout, 20);
    Serial.print(sensorPrintout);
    TFTscreen.stroke(255,20,147);
    // print the sensor value
    TFTscreen.text(sensorPrintout, i, j);
    i = i+13;
    Serial.print(i);
    if(i >= 156){
      j = j+20;
      i = 0;
    }
    if(j>=120){
      TFTscreen.stroke(0,0,0);
      TFTscreen.text(sensorPrintout, j, i);
      i=0;
      j=20;
    }
    
    // wait for a moment
    delay(100);
    // erase the text you just wrote
    //TFTscreen.stroke(0,0,0);
    //TFTscreen.text(sensorPrintout, j, i);
   
  }
 
  if (Serial.available()) // If stuff was typed in the serial monitor
  {
    // Send any characters the Serial monitor prints to the bluetooth
    //String myStr = (String)Serial.read();
    //char myStr1[] = "hello this is testing!";
 
   // uint8_t payload[myStr.length() + 1];
    //    myStr.getBytes(payload, myStr.length()+1);
 
    int bytes=Serial.available();
    //Serial.readBytes(buffer, startPosition, bytes);
 
    bluetooth.print((char)Serial.read());
 
  }
 
}
