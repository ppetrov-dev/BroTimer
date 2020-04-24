#include <Arduino.h>
#include <MyTimer.h>

MyTimer *timer = new MyTimer();
bool _isOn = false;
void OnTimerElapsed()
{
    Serial.println("Timer elapsed");
    _isOn = !_isOn;
    digitalWrite(13, _isOn ? HIGH : LOW);
}
void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    timer->SetInterval(1000); //1 sec is on, 1 sec is off
    // timer->SetInterval(1000, 500); //1 sec is on, 0.5 sec is off

    timer->AttachOnElapsed(&OnTimerElapsed);
    timer->Start();
}
void loop()
{
    timer->Tick();
}