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
	myTimerCallback _onTickCallback;
	bool _isStarted;
	unsigned long _timeInMilliseconds = 0;
	unsigned long _intervalInMilliseconds = 1000;

public:
	void SetInterval(unsigned long timeoutInMilliseconds);
	void Start();
	void Stop();
	void AttachOnTick(myTimerCallback callback);
	void Tick();
};

#endif // myTimerH
