#include <FastLED.h>

#define COLOR_ORDER RGB
#define CHIPSET WS2811
#define NUM_LEDS 150
#define LED_PIN 2

#define BRIGHTNESS 10
CRGB leds[NUM_LEDS];

uint8_t paletteIndex = 0;

CRGBPalette16 purplePalette = CRGBPalette16(
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::DarkViolet,

    CRGB::Magenta,
    CRGB::Magenta,
    CRGB::Linen,
    CRGB::Linen,

    CRGB::Magenta,
    CRGB::Magenta,
    CRGB::DarkViolet,
    CRGB::DarkViolet,

    CRGB::DarkViolet,
    CRGB::DarkViolet,
    CRGB::Linen,
    CRGB::Linen);

CRGBPalette16 myPal = purplePalette;

void setup()
{

  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{

  EVERY_N_MILLISECONDS(20)
  {
    // Switch on an LED at random, choosing a random color from the palette
    leds[random8(0, NUM_LEDS - 1)] = ColorFromPalette(myPal, random8(), 255, LINEARBLEND);
  }

  // Fade all LEDs down by 1 in brightness each time this is called
  fadeToBlackBy(leds, NUM_LEDS, 1);

  FastLED.show();
}
