#include <Arduino.h>
#include "qrcode.h"

#define LILYGO_T5_V213                 //
#include <boards.h>                    //
#include <GxEPD.h>                     //
#include <GxDEPG0213BN/GxDEPG0213BN.h> // include necessary libraries for the E-paper display to function
#include <GxIO/GxIO_SPI/GxIO_SPI.h>    //
#include <GxIO/GxIO.h>                 //

GxIO_Class io(SPI, EPD_CS, EPD_DC, EPD_RSET); //
GxEPD_Class display(io, EPD_RSET, EPD_BUSY);  // construct the display object to control the E-paper display

void displayName(void);            //
void displayQRcode(QRCode qrcode); // declare functions to use later

void setup()
{
  // Serial.begin(115200);

  SPI.begin(EPD_SCLK, EPD_MISO, EPD_MOSI); // start the SPI protocol
  display.init();                          // initiate the display
  display.setRotation(3);                  // set the rotation to landscape

  QRCode qrcode;                                                //
  uint8_t qrcodeData[qrcode_getBufferSize(3)];                  // Create the QR code
  qrcode_initText(&qrcode, qrcodeData, 3, 0, "RUH-10005 #PIN"); //

  displayQRcode(qrcode); // display the QR code on the display
  displayName();         // display the name on the display
}

void loop() // nothing needed in the loop function for now
{
}

void displayQRcode(QRCode qrcode) // display the QR code on the screen
{
  display.fillScreen(GxEPD_WHITE);
  for (uint8_t y = 0; y < qrcode.size; y++)
  {
    for (uint8_t x = 0; x < qrcode.size; x++)
    {
      if (qrcode_getModule(&qrcode, x, y))
      {
        display.fillRect(4 + (4 * x), 4 + (4 * y), 4, 4, GxEPD_BLACK);
      }
    }
  }
}

void displayName(void) // display the name and location of the locker on the screen
{
  display.setCursor(135, 30);
  display.setTextSize(2);
  display.setTextColor(GxEPD_BLACK);
  display.print("RUH-10005");
  display.setCursor(135, 60);
  display.print("Al-Muraba");
  display.setCursor(155, 80);
  display.print("Riyadh");
  display.update();
}