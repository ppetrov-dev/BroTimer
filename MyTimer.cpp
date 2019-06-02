#include "MyTimer.h"

void MyTimer::SetInterval(unsigned long intervalInMilliseconds)
{
	_intervalInMilliseconds = intervalInMilliseconds;
}
void MyTimer::Start()
{
	_timeInMilliseconds = millis();
	_isStarted = true;
}
void MyTimer::Stop()
{
	_isStarted = false;
	_timeInMilliseconds = 0;
}
void MyTimer::AttachOnTick(myTimerCallback callback)
{
	_onTickCallback = callback;
}
void MyTimer::Tick()
{
	if (!_isStarted || !_onTickCallback)
		return;

	auto currentMilliseconds = millis();

	if (currentMilliseconds < _timeInMilliseconds + _intervalInMilliseconds)
		return;

	_timeInMilliseconds = currentMilliseconds;
	_onTickCallback();
}