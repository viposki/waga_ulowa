#include "screen.hpp"

Screen::Screen(const int pin, const int maxNumCharsPerRow, const int maxNumRows):
  mPin(pin),
  mMaxNumCharsPerRow(maxNumCharsPerRow),
  mMaxNumRows(maxNumRows),
  mLCD(LiquidCrystal_I2C(mPin, mMaxNumCharsPerRow, mMaxNumRows))
{
  // Inicjalizacja LCD
  mLCD.begin();

  mLCD.backlight();
}

void Screen::enableBacklight()
{
  // Turn on the blacklight.
  mLCD.backlight();
}

void Screen::showText(const String& text, const bool beforeClear)
{
  if (beforeClear)
  {
    clear();
  }

  // TODO: Use text with autoscroll if it needed.
  mLCD.print(text);
}

void Screen::clear()
{
  // Jak działa
  mLCD.clear();
}

// void Screen::adjustText(const String& text) const
// {
//   if (text.length() <= mMaxNumCharsPerRow)
//   {
//     return text;
//   }

//   // TODO: Implement wrap algorithm
//   String adjustedText = text;

//   return adjustedText;
// }

void Screen::setCursor(const int numCol, const int numRow)
{
  mLCD.setCursor(numCol, numRow);
}
