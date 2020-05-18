#ifndef broTimerH
#define broTimerH
#include <Arduino.h>

extern "C"
{
	typedef void (*callback)(void);
}

class BroTimer
{
private:
	callback _onTimerElapsedCallback;
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
	void AttachOnElapsed(myTimerCallback callback);
	void Tick();
	bool GetIsWorkInterval();
};

#endif // broTimerH