#include "BroTimer.h"

void BroTimer::SetInterval(unsigned long intervalInMilliseconds)
{
	SetInterval(intervalInMilliseconds, intervalInMilliseconds);
}

void BroTimer::SetInterval(unsigned long waitIntervalInMilliseconds, unsigned long workIntervalInMilliseconds)
{
	_waitInterval = waitIntervalInMilliseconds;
	_workInterval = workIntervalInMilliseconds;
}

void BroTimer::Start()
{
	_lastTimestamp = millis();
	_isStarted = true;
}
void BroTimer::Stop()
{
	_isStarted = false;
	_lastTimestamp = 0;
}
void BroTimer::AttachOnElapsed(callback callback)
{
	_onTimerElapsedCallback = callback;
}
bool BroTimer::GetIsWorkInterval()
{
	return _isWorkInterval;
}
void BroTimer::Tick()
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