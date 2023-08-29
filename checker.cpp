#include <iostream>
#include <assert.h>
#include <unistd.h>
using namespace std;


void Sleep()
{
     for (int i = 0; i < 6; i++)
    {
      cout << "\r* " << flush;
      sleep(1);
      cout << "\r *" << flush;
      sleep(1);
    }
}

int TemperatureOfOk(float temperature)
{
    if(temperature > 102 || temperature <95)
    {
        cout<<"Temperature critical!\n";
        Sleep();
        return 0;
    }
    return 1;
    
}

int PulseRate(float pulseRate)
{
    if(pulseRate < 60 || pulseRate > 100)
    {
        cout<<"Pulse Rate is out of range!\n";
        Sleep();
        return 0;
    }
    return 1;
}

int Spo2(float spo2)
{
    if(spo2 < 90)
    {
        cout << "Oxygen Saturation out of range!\n";
        Sleep();
        return 0;
    }
    return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  if(!TemperatureOfOk(temperature) || !PulseRate(pulseRate) || !Spo2(spo2))
    {
        return 0;
    }
  return 1;
}

int main() {
  assert(!vitalsOk(99, 102, 70));
  assert(!vitalsOk(90, 80, 100));
  assert(!vitalsOk(105, 80, 100));
  assert(!vitalsOk(96, 70, 85));
  assert(vitalsOk(98.1, 70, 98));
  cout << "Done\n";
}
