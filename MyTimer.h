#ifndef myTimerH
#define myTimerH
#include <Arduino.h>

extern "C"
{
	typedef void (*myTimerCallback)(void);
}

class MyTimer
{
private:
	myTimerCallback _onTimerElapsedCallback;
	bool _isStarted = false;
	bool _isWorking = false;
	unsigned long _timeInMilliseconds = 0;
	unsigned long _workIntervalInMilliseconds = 1000;
	unsigned long _waitIntervalInMilliseconds = 1000;

public:
	void SetInterval(unsigned long timeoutInMilliseconds);
	void SetInterval(unsigned long waitTimeoutInMilliseconds, unsigned long workTimeoutInMilliseconds);
	void Start();
	void Stop();
	void AttachOnElapsed(myTimerCallback callback);
	void Tick();
};

#endif // myTimerH
