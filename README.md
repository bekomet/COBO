# COBO

COBO (circuit of the bionical organism) is a hardware prototype for project *SLATE*.

## Components

### Hardware

[Arduino Nano](https://www.direnc.net/arduino-nano-usb-chip-ch340-usb-kablo-dahil) x1:

	Arduino Nano used to control external display and Bluetooth module.
	Nano preferred over Uno because of the compact design of Nano.

[HM-10 Bluetooth Module](https://www.direnc.net/arduino-bluetooth-40-seri-modul) x1:

	HM-10 is for communicating between web application and Arduino Nano. 

[1.8 inch Arduino TFT LCD Screen Module](https://www.direnc.net/18-inch-128x160-arduino-tft-lcd-oled-ekran-modulu) x1:

	External Display used for printing the data coming from Bluetooth that comes from web application.

[Mini-B USB cable](https://www.direnc.net/usb-a-erkek-5-pin-micro-kablo) x1:

	Usb cable for sending the arduino codes to the Arduino Nano.

[Jumper cables](https://www.direnc.net/40-adet-erkek-erkek-jumper-20cm):

	Jumper cables used for establishing the circuit. *This version is a prototype, that is why cables were used.*

### Software

Use [Arduino IDE](https://www.arduino.cc/en/main/software) Version 1.8.33.0 editor to send and edit your arduino codes.

You can use [Fritzing](https://fritzing.org/home/) Version 0.9.4  to draw your circuit design.

## Preperation

Clone git hub repository using:

```
git clone https://github.com/bekomet/COBO.git
``` 

After cloning the repo use circuit desing folders to setup the circuit. After setting up the circuit use Arduino IDE 

to open up and compile arduino codes. With usb cable send the codes to your own arduino nano. 

## Usage

Pair your application(in our project -> our web application) to COBO's HM-10 bluetooth module. 

**Be carefull HM-10 is a BLuetooth Low Energy(BLE) module and has 4.0 bluetooth technology.**

After pairing completed, HM-10's led will be *go off*. Now you can send text messages from your application to your arduino nano 

and external display with using Bluetooth Low Energy module.

## License
[COBO](https://www.instagram.com/berkay.byndr/)
