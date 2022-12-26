#include <FastLED.h>

#define COLOR_ORDER RGB
#define CHIPSET WS2811
#define NUM_LEDS 50
#define LED_PIN 2

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
  FastLED.setBrightness(50);

  // Fill the colorIndex array with random numbers
  for (int i = 0; i < NUM_LEDS; i++)
  {
    colorIndex[i] = random8();
  }
}

void loop()
{

  // Color each pixel from the palette using the index from colorIndex[]
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = ColorFromPalette(greenblue, colorIndex[i]);
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
