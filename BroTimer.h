#ifndef broTimerH
#define broTimerH
#include <Arduino.h>

class BroTimer
{
private:
	void (*_onTimerElapsedCallbackFunc)() = nullptr;
	bool _isStarted = false;
	bool _isWorkInterval = false;
	unsigned long _lastTimestamp = 0;
	unsigned long _workInterval = 1000;
	unsigned long _waitInterval = 1000;

public:
	void SetInterval(unsigned long intervalInMilliseconds);
	void SetInterval(unsigned long waitIntervalInMilliseconds, unsigned long workIntervalInMilliseconds);
	void Start();
	void Stop();
	void AttachOnElapsed(void (*newFunction)());
	void Tick();
	bool GetIsWorkInterval();
};

#endif // broTimerH
