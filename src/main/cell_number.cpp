#include "cell_number.hpp"
#include "util.hpp"

/*
  IMPORTANT: By default the area code is polish.
*/

CellNumber::CellNumber(int rawCellNumber):
  mAreaCode(""),
  mNumber(0)
{
  if (isCellNumberValid(rawCellNumber))
  {
    validate(rawCellNumber);
  }
  else
  {
    // TODO: Print a warning into serial.
  }
}

CellNumber::CellNumber(String rawCellNumber):
  mAreaCode("+48"),
  mNumber(0)
{
  if (rawCellNumber.length() != 0)
  {
    if (!isAreaCodeValid(rawCellNumber.substring(0, AREA_CODE_LENGTH)))
    {
      mAreaCode = "+48";
    }

    if (isCellNumberValid(rawCellNumber.substring(AREA_CODE_LENGTH)))
    {
      mNumber = rawCellNumber.toInt();
    }
  }
}

CellNumber::CellNumber(String areaCode, int rawCellNumber):
  mAreaCode("+48"),
  mNumber(0)
{
  if (!isAreaCodeValid(areaCode))
  {
    mAreaCode = "+48";
  }

  if (isCellNumberValid(rawCellNumber))
  {
    mNumber = rawCellNumber;
  }
}

void CellNumber::validate(int rawCellNumber)
{
  const int length = util::lengthOfNumber(rawCellNumber);
  if (length == CELL_NUMBER_WITHOUT_PREFIX_LENGTH)
  {
    mNumber = rawCellNumber % (10 * CELL_NUMBER_LENGTH);

    int areaCode = (rawCellNumber - mNumber) / (10 * CELL_NUMBER_LENGTH);
    if (areaCode != POLISH_AREA_CODE_WITHOUT_PREFIX)
    {
      areaCode = POLISH_AREA_CODE;
      // TODO: Print a warning into serial.
    }
  }
  else if (length == CELL_NUMBER_LENGTH)
  {
    mNumber = rawCellNumber;
  }
}

bool CellNumber::isAreaCodeValid(int areaCode) const
{
  // By default the area code is polish.
  return areaCode == POLISH_AREA_CODE_WITHOUT_PREFIX;
}

bool CellNumber::isAreaCodeValid(const String& areaCode) const
{
  if (areaCode.length() == AREA_CODE_LENGTH)
  {
    // By default the area code is polish.
    if (areaCode == POLISH_AREA_CODE)
    {
      return true;
    }
  }

  return false;
}

bool CellNumber::isCellNumberValid(int rawCellNumber) const
{
  const int length = util::lengthOfNumber(rawCellNumber);
  return length == CELL_NUMBER_WITHOUT_PREFIX_LENGTH ||
         length == CELL_NUMBER_LENGTH;
}

bool CellNumber::isCellNumberValid(const String& rawCellNumber) const
{
  return rawCellNumber.length() == CELL_NUMBER_LENGTH ||
         rawCellNumber.length() == CELL_NUMBER_WITHOUT_PREFIX_LENGTH ||
         rawCellNumber.length() == FULL_CELL_NUMBER;
}

