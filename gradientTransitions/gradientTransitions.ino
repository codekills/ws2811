#include <FastLED.h>

#define COLOR_ORDER RGB
#define CHIPSET WS2811
#define NUM_LEDS 150
#define LED_PIN 2

#define BRIGHTNESS 10
#define TRANSITION_DELAY 500

CRGB leds[NUM_LEDS];
uint8_t colorIndex[NUM_LEDS];

// Purps and purps
DEFINE_GRADIENT_PALETTE(BlurpHaze){
    0, 100, 143, 169,
    46, 131, 76, 142,
    179, 95, 76, 142,
    255, 130, 149, 193};

// Blue and purps
DEFINE_GRADIENT_PALETTE(Codi){
    0, 10, 189, 198,  // light blue
    46, 113, 28, 145, // dark purp
    179, 19, 62, 124, // medium blue
    255, 9, 24, 51};  // Blue

DEFINE_GRADIENT_PALETTE(Ocean){
    0, 25, 180, 188,   // light blue
    46, 22, 81, 97,    // Off white
    179, 12, 116, 137, // greyish blue
    255, 24, 46, 70};  // light blue

// Blues and a lil purp
DEFINE_GRADIENT_PALETTE(Midoriya){
    0, 30, 109, 82,   // Darkish green
    46, 8, 219, 137,  // teal
    179, 15, 15, 15,  // purpish
    255, 45, 94, 75}; // light blue

DEFINE_GRADIENT_PALETTE(Azul){
    0, 44, 235, 230,
    46, 0, 77, 135,
    179, 0, 117, 205,
    255, 0, 184, 229};

DEFINE_GRADIENT_PALETTE(Greens){
    0, 1, 198, 66,
    85, 44, 112, 1,
    170, 0, 129, 46,
    255, 18, 239, 91};

DEFINE_GRADIENT_PALETTE(Blue_Purp_Green){
    0, 129, 244, 153,
    85, 12, 126, 72,
    170, 153, 197, 181,
    255, 18, 239, 91};

DEFINE_GRADIENT_PALETTE(Helix){
    0, 138, 242, 252,    // light teal
    85, 124, 95, 129,    // mid purp
    170, 140, 129, 200,  // light purp
    255, 186, 193, 210}; // greyish white

// CRGBPalette16 colorPalette = ForestColors_p;
CRGBPalette16 colorPalette = CloudColors_p;

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
