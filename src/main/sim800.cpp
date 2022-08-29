#include "sim800.hpp"

Sim800::Sim800():
  mRawSim800(),
  mRTC({})
{
  // Initialize sim800 module
  mRawSim800.begin();
  mRawSim800.reset();

  // Adjust RTC to the Poland UTC timezone (+2)
	mRawSim800.updateRtc(2);
}

void Sim800::getRTCTime() const
{
  mRawSim800.RTCtime(&mRTC.mDay,
                     &mRTC.mMonth,
                     &mRTC.mYear,
                     &mRTC.mHour,
                     &mRTC.mMinute,
                     &mRTC.mSecond);
}

void Sim800::sendSMS(const String& cellNumber, const String& text) const
{
  bool status = mRawSim800.sendSms(cellNumber.c_str(), text.c_str());
  if (status != true)
  {
    Serial.print("Nie udalo sie wyslac wiadomosci!");
    // TODO: Print a something warning into serial.
  }
}