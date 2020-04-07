#include <SoftwareSerial.h>
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8  

void loadingScreen();
void readBTvalue();
void printToScreen();

SoftwareSerial HM10(2, 3); // RX = 2, TX = 3
TFT TFTscreen = TFT(cs, dc, rst);

char sensorPrintout[100];
int i=0; //screen x
int j=20; //screen y
int m=0; //array element

void setup()
{
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  
  TFTscreen.begin();

  loadingScreen();
  
  TFTscreen.text("BT value :\n ",0,0);
  TFTscreen.setTextSize(2);

}

void loop()
{
  HM10.listen();  // listen the HM10 port
  while (HM10.available() > 0) {   // if HM10 is available
      readBTvalue();
      printToScreen();
  }
}

void readBTvalue(){
    delay(100);
    sensorPrintout[m] = char(HM10.read());
    Serial.print(sensorPrintout); //this line is for you my dear friend
}

void printToScreen(){
   TFTscreen.stroke(255,20,147);
    // print the sensor value
    TFTscreen.text(sensorPrintout, i, j);
    i = i+13;//13 punto spacing between characters.
    if(i >= 156){//if line ends, go to the new line
      j = j+20;
      i = 0;
    }
    if(j>=120){//if screen ends refresh and go back to start
      TFTscreen.stroke(0,0,0);
      TFTscreen.text(sensorPrintout, j, i);
      i=0;
      j=20;
    }
}
void loadingScreen(){
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
}
 
