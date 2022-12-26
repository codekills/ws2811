#include <FastLED.h>

#define COLOR_ORDER RGB
#define CHIPSET WS2811
#define NUM_LEDS 50
#define LED_PIN 2

#define BRIGHTNESS 100
#define TRANSITION_DELAY 400

CRGB leds[NUM_LEDS];
uint8_t colorIndex[NUM_LEDS];

DEFINE_GRADIENT_PALETTE(colorPalette_gp){
    0, 0, 255, 245,
    46, 0, 21, 255,
    179, 12, 250, 0,
    255, 0, 255, 245};

CRGBPalette16 colorPalette = ForestColors_p;
// CRGBPalette16 colorPalette = CloudColors_p;

void setup()
{
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  // // Fill the colorIndex array with random numbers
  // for (int i = 0; i < NUM_LEDS; i++)
  // {
  //   colorIndex[i] = random8();
  // }
}

void loop()
{

  // Color each pixel from the palette using the index from colorIndex[]
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = ColorFromPalette(colorPalette, colorIndex[i]);
  }

  EVERY_N_MILLISECONDS(TRANSITION_DELAY)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      colorIndex[i]++;
    }
  }
  FastLED.show();
}
