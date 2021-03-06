#ifndef _LEDSTRIP_H_
#define _LEDSTRIP_H_

#include <NeoPixelBus.h>

#define V2_LAYOUT

#ifdef V1_LAYOUT
#define NR_LEDS 133   // Normally 134
#define LED_OFFSET 0  // Normally 1
#define LED_ROW 13    // Nr of leds in a row
#endif

#ifdef V2_LAYOUT
/*
#define NR_LEDS 133   // Normally 134
#define LED_OFFSET 1  // Normally 1
*/
#define NR_LEDS 137
#define LED_OFFSET 3
#define LED_ROW 13    // Nr of leds in a row
#define BOTTOM_TO_TOP
#endif

class LedWord {
  public:
    LedWord() : firstPixelX(0), firstPixelY(0), length(0) {}
    LedWord(int firstPixelX, int firstPixelY, int length) : firstPixelX(firstPixelX), firstPixelY(firstPixelY), length(length) {}
  public:
    int firstPixelX;
    int firstPixelY;
    int length;
};

class LedStrip : private NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> {
public:
  LedStrip();
  void colorWipe(uint8_t wait);
  void enable_led(LedWord  word, const HsbColor &color);
  void enable_led(LedWord  word, const HsbColor &color, float fraction);
  void updateColor(uint16_t index, const HsbColor &color, float fraction);

  // Delegates
  void Begin();
  void Show();
  void ClearTo(RgbColor color);
  void SetPixelColor(uint16_t indexPixel, RgbColor color);
  uint16_t PixelCount() const;
};

#endif // _LEDSTRIP_H_
