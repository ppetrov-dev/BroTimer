#include "MyTimer.h"

void MyTimer::SetInterval(unsigned long intervalInMilliseconds)
{
	SetInterval(intervalInMilliseconds, intervalInMilliseconds);
}

void MyTimer::SetInterval(unsigned long waitIntervalInMilliseconds, unsigned long workIntervalInMilliseconds)
{
	_waitInterval = waitIntervalInMilliseconds;
	_workInterval = workIntervalInMilliseconds;
}

void MyTimer::Start()
{
	_lastTimestamp = millis();
	_isStarted = true;
}
void MyTimer::Stop()
{
	_isStarted = false;
	_lastTimestamp = 0;
}
void MyTimer::AttachOnElapsed(myTimerCallback callback)
{
	_onTimerElapsedCallback = callback;
}
bool MyTimer::GetIsWorkInterval()
{
	return _isWorkInterval;
}
void MyTimer::Tick()
{
	if (!_isStarted || !_onTimerElapsedCallback)
		return;

	register auto currentTimeStamp = millis();
	register auto interval = (_isWorkInterval ? _workInterval : _waitInterval);
	if (currentTimeStamp < _lastTimestamp + interval)
		return;

	_lastTimestamp = currentTimeStamp;
	_isWorkInterval = !_isWorkInterval;
	_onTimerElapsedCallback();
}