#pragma once

#include <Arduino.h>

constexpr int FULL_CELL_NUMBER = 12;
constexpr int CELL_NUMBER_WITHOUT_PREFIX_LENGTH = 11;
constexpr int CELL_NUMBER_LENGTH = 9;
constexpr int AREA_CODE_LENGTH = 3;

constexpr const char* POLISH_AREA_CODE = "+48";
constexpr int POLISH_AREA_CODE_WITHOUT_PREFIX = 48;

class CellNumber
{
public:
  CellNumber(int rawCellNumber);
  CellNumber(String rawCellNumber);
  CellNumber(String areaCode, int rawCellNumber);

  ~CellNumber() = default;

  CellNumber(const CellNumber&) = default;
  CellNumber(CellNumber&&) = default;

  CellNumber& operator=(const CellNumber&) = default;
  CellNumber& operator=(CellNumber&&) = default;

  // TODO: Add getters of area code and cell number.

private:
  void validate(int rawCellNumber);

  // Stupid simple checks if the cell number is correct.
  bool isCellNumberValid(int rawCellNumber) const;
  bool isCellNumberValid(const String& rawCellNumber) const;
  bool isAreaCodeValid(int areaCode) const;
  bool isAreaCodeValid(const String& areaCode) const;

  String mAreaCode;
  int mNumber;
};