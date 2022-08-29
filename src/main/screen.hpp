#pragma once

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Screen
{
public:
  explicit Screen(const int pin, const int maxNumCharsPerRow, const int maxNumRows);
  Screen(const Screen&);
  Screen(Screen&&);
  ~Screen() = default;

  Screen& operator=(const Screen&);
  Screen& operator=(Screen&&);

  void enableBacklight();
  void showText(const String& text, const bool beforeClear = false);
  void clear();

  // TODO: Move to private section
  void setCursor(const int numCol, const int numRow);

private:
  // String adjustText(const String& text) const;

  // Numer pinu
  const int mPin;

  // Maksymalna liczba znaków w wierszu
  const int mMaxNumCharsPerRow;

  // Maksymalna liczba wierszy
  const int mMaxNumRows;

  // Instancja klasy LiquidCrystal_I2C
  LiquidCrystal_I2C mLCD;
};