#include <WS2812e.h>

#define LED 14
#define neopixel_show neopixel_show_P1_4e

//#define NUM_LEDS 276 // NG
//#define NUM_LEDS 256 // NG
//#define NUM_LEDS 255
#define NUM_LEDS 10
#define COLOR_PER_LEDS 3
#define NUM_BYTES (NUM_LEDS*COLOR_PER_LEDS)

__xdata uint8_t ledData[NUM_BYTES];

uint16_t i;

void setup() {
  pinMode(LED, OUTPUT);
  for (i = 0; i < NUM_LEDS; i++) set_pixel_for_GRB_LED(ledData, i, 0x00, 0x00, 0x00);
  neopixel_show(ledData, NUM_BYTES);
  i = 0;
}

void loop() {
  set_pixel_for_GRB_LED(ledData, i, 0x08, 0x00, 0x00);
  i++;
  if (i == NUM_LEDS){
    for (i = 0; i < NUM_LEDS; i++) set_pixel_for_GRB_LED(ledData, i, 0x00, 0x00, 0x00);
    i = 0;
  }
  neopixel_show(ledData, NUM_BYTES);
  delay(20);
/*
  set_pixel_for_GRB_LED(ledData, 0, 0x08, 0x00, 0x00);
  set_pixel_for_GRB_LED(ledData, 1, 0x00, 0x00, 0x00);
  neopixel_show(ledData, NUM_BYTES);
  delay(500);
  set_pixel_for_GRB_LED(ledData, 0, 0x00, 0x00, 0x00);
  set_pixel_for_GRB_LED(ledData, 1, 0x08, 0x00, 0x00);
  neopixel_show(ledData, NUM_BYTES);
  delay(500);
  set_pixel_for_GRB_LED(ledData, 0, 0x00, 0x00, 0x00);
  set_pixel_for_GRB_LED(ledData, 1, 0x00, 0x00, 0x00);
  neopixel_show(ledData, NUM_BYTES);
  delay(500);
*/
}
