/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 *
 * This example shows how to use LightBlue Bean / Bean+
 * to connect your project to Blynk.
 *
 * For this example you need to install Bean Loader:
 *   https://punchthrough.com/bean/guides/getting-started/intro/
 *
 * NOTE: BLE support is in beta!
 *
 **************************************************************/

//#define BLYNK_USE_DIRECT_CONNECT

#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#define BLYNK_PRINT DebugSerial
#define BLYNK_NO_YIELD
#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "a7afb9ccb18c4210816c8d9638369710";

void setup()
{
  DebugSerial.begin(9600);

  Blynk.begin(auth, Serial);

  Bean.setLed(255,255,255);
}

void loop()
{
  Blynk.run();
}

// Attach a ZeRGBa widget to the Virtual pin 1
// to control the built-in RGB led!
BLYNK_WRITE(V1) {
  int r = param[0].asInt();
  int g = param[1].asInt();
  int b = param[2].asInt();
  Bean.setLed(r, g, b);
}

