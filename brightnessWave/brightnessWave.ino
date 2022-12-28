#include <FastLED.h>

#define COLOR_ORDER RGB
#define CHIPSET WS2811
#define NUM_LEDS 150
#define LED_PIN 2

#define BRIGHTNESS 30

CRGB leds[NUM_LEDS];
uint8_t colorIndex[NUM_LEDS];

DEFINE_GRADIENT_PALETTE(greenblue_gp){
    0, 0, 255, 245,
    46, 0, 21, 255,
    179, 12, 250, 0,
    255, 0, 255, 245};

CRGBPalette16 greenblue = greenblue_gp;

void setup()
{
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  // Fill the colorIndex array with random numbers
  for (int i = 0; i < NUM_LEDS; i++)
  {
    colorIndex[i] = random8();
  }
}

void loop()
{

  // Creat a sin wave with period of 2 seconds (30bpm) to change the brightness of the strip
  uint8_t sinBeat = beatsin8(30, 50, 255, 0, 0);

  // Color each pixel from the palette using the index from colorIndex[]
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = ColorFromPalette(greenblue, colorIndex[i], sinBeat);
  }

  EVERY_N_MILLISECONDS(15)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      colorIndex[i]++;
    }
  }
  FastLED.show();
}
