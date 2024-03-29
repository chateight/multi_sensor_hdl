#include <pgmspace.h>  // PROGMEM support header

#define imgWidth  64  // logo width
#define imgHeight 32  // logo height

static const uint8_t hb1_bmp[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 
  0xDC, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0xCC, 0x01, 0x00, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 
  0x8C, 0x01, 0x00, 0x00, 0x00, 0x6E, 0x00, 0x00, 0x8C, 0x01, 0x00, 0x00, 
  0x00, 0xE6, 0x00, 0x00, 0x8E, 0x01, 0x00, 0x00, 0xF8, 0xC7, 0x0F, 0xFF, 
  0x87, 0xFF, 0xC0, 0x0F, 0xF0, 0x83, 0x1F, 0xFF, 0x07, 0xFF, 0xC1, 0x0F, 
  0x00, 0x00, 0x18, 0x03, 0x00, 0x80, 0xC1, 0x00, 0x00, 0x00, 0x9C, 0x01, 
  0x00, 0x80, 0x61, 0x00, 0x00, 0x00, 0x98, 0x01, 0x00, 0x80, 0x63, 0x00, 
  0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0xF8, 0x01, 
  0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x3F, 0x00, 
  0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0xF0, 0x00, 
  0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x0E, 0x00, 
  0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, };

static const uint8_t hb2_bmp[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x87, 0x0F, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xFE, 0x8F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 
  0x3F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x3F, 0x7F, 0x00, 0x00, 
  0x00, 0x00, 0xC0, 0xFF, 0x7F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 
  0xE3, 0xFF, 0x01, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0xC3, 0xFF, 0x01, 0x00, 
  0x00, 0x00, 0xE0, 0xFF, 0x99, 0xFF, 0x01, 0x00, 0x00, 0x00, 0xE0, 0xFF, 
  0x99, 0xFF, 0x03, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x3C, 0xFF, 0x03, 0x00, 
  0x00, 0x18, 0xE0, 0xFF, 0x3C, 0xFF, 0x03, 0x00, 0x00, 0x1C, 0xF0, 0xFF, 
  0x3C, 0xFF, 0x03, 0x00, 0x00, 0x3C, 0xE0, 0x7F, 0x6E, 0xFE, 0x03, 0x00, 
  0x00, 0x3E, 0xE0, 0x7F, 0x66, 0xFE, 0x01, 0x00, 0x00, 0x66, 0x60, 0x00, 
  0xE6, 0x00, 0x01, 0x00, 0x20, 0x67, 0x04, 0x11, 0xC7, 0x20, 0x01, 0x01, 
  0xF8, 0xE3, 0x07, 0xFF, 0xC3, 0x7F, 0xE0, 0x03, 0xF0, 0xC1, 0x8F, 0xFF, 
  0x83, 0x7F, 0xF0, 0x03, 0x00, 0x00, 0x8C, 0x01, 0x18, 0xE0, 0x30, 0x00, 
  0x00, 0x00, 0xDC, 0x11, 0xBC, 0xC2, 0x38, 0x00, 0x00, 0x00, 0xD8, 0xFC, 
  0xFF, 0xCF, 0x18, 0x00, 0x00, 0x00, 0xD8, 0xFC, 0xFF, 0xCF, 0x19, 0x00, 
  0x00, 0x00, 0xF8, 0xF8, 0xFF, 0x8F, 0x0D, 0x00, 0x00, 0x00, 0x78, 0xF0, 
  0xFF, 0x87, 0x0F, 0x00, 0x00, 0x00, 0x70, 0xE0, 0xFF, 0x83, 0x07, 0x00, 
  0x00, 0x00, 0x70, 0xC0, 0xFF, 0x01, 0x07, 0x00, 0x00, 0x00, 0x30, 0x00, 
  0x7F, 0x00, 0x03, 0x00, 0x00, 0x00, 0x20, 0x00, 0x3C, 0x00, 0x02, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, };