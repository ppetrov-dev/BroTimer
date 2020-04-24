#include "MyTimer.h"

void MyTimer::SetInterval(unsigned long intervalInMilliseconds)
{
	SetInterval(intervalInMilliseconds, intervalInMilliseconds);
}

void MyTimer::SetInterval(unsigned long waitTimeoutInMilliseconds, unsigned long workTimeoutInMilliseconds)
{
	_waitIntervalInMilliseconds = waitTimeoutInMilliseconds;
	_workIntervalInMilliseconds = workTimeoutInMilliseconds;
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
void MyTimer::AttachOnElapsed(myTimerCallback callback)
{
	_onTimerElapsedCallback = callback;
}
void MyTimer::Tick()
{
	if (!_isStarted || !_onTimerElapsedCallback)
		return;

	auto currentMilliseconds = millis();

	auto intervalInMilliseconds = (_isWorking ? _workIntervalInMilliseconds : _waitIntervalInMilliseconds);
	if (currentMilliseconds < _timeInMilliseconds + intervalInMilliseconds)
		return;

	_timeInMilliseconds = currentMilliseconds;
	_isWorking = !_isWorking;
	_onTimerElapsedCallback();
}