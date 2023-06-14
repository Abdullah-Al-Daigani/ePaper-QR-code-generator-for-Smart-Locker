/**
 *  QRCode
 *
 *  A quick example of generating a QR code.
 *
 *  This prints the QR code to the serial monitor as solid blocks. Each module
 *  is two characters wide, since the monospace font used in the serial monitor
 *  is approximately twice as tall as wide.
 *
 */
#include <Arduino.h>
#include "qrcode.h"

#define LILYGO_T5_V213
#include <boards.h>
#include <GxEPD.h>
#include <GxDEPG0213BN/GxDEPG0213BN.h> // 2.13" b/w  form DKE GROUP
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
GxIO_Class io(SPI, EPD_CS, EPD_DC, EPD_RSET);
GxEPD_Class display(io, EPD_RSET, EPD_BUSY);

void setup()
{
  Serial.begin(115200);

  SPI.begin(EPD_SCLK, EPD_MISO, EPD_MOSI);
  display.init(); // enable diagnostic output on Serial

  // Create the QR code
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(3)];
  qrcode_initText(&qrcode, qrcodeData, 3, 0, "checkpoint reached!");

  Serial.print("\n\n\n\n");

  // Top quiet zone
  Serial.print("\n\n\n\n");
  Serial.print("{{\n");

  for (uint8_t y = 0; y < qrcode.size; y++)
  {
    for (uint8_t x = 0; x < qrcode.size; x++)
    {
      if (qrcode_getModule(&qrcode, x, y))
      {
        Serial.print("**");
      }
      else
      {
        Serial.print("  ");
      }
    }
    Serial.print("\n");
  }

  // Bottom quiet zone
  Serial.print("\n\n\n\n");

  display.setRotation(0);
  display.fillScreen(GxEPD_WHITE);
  for (uint8_t y = 0; y < qrcode.size; y++)
  {
    for (uint8_t x = 0; x < qrcode.size; x++)
    {
      if (qrcode_getModule(&qrcode, x, y))
      {
        // display.fillRect(118 - (4 * x), 4 * y, 3, 3, GxEPD_BLACK);
        // display.fillRect(118 - (4 * x), 120 + (4 * y), 3, 3, GxEPD_BLACK);
        display.fillRect(4 + (4 * x), 4 + (4 * y), 3, 3, GxEPD_BLACK);
        display.fillRect(4 + (4 * x), 130 + (4 * y), 4, 4, GxEPD_BLACK);
      }
    }
  }
  display.update();
}

void loop()
{
}
