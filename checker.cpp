#include <iostream>
#include <assert.h>
#include <unistd.h>
using namespace std;


void Printstar()
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
        Printstar();
        return 0;
    }
    return 1;
    
}

int PulseRate(float pulseRate)
{
    if(pulseRate < 60 || pulseRate > 100)
    {
        cout<<"Pulse Rate is out of range!\n";
        Printstar();
        return 0;
    }
    return 1;
}

int Spo2(float spo2)
{
    if(Spo2 < 90)
    {
        cout << "Oxygen Saturation out of range!\n";
        Printstar();
        return 0;
    }
    return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  if(!TemperatureOfOk(temperature))
    {
        return 0;
    }
    else if(!PulseRate(pulseRate))
    {
        return 0;
    }
    else if(!Spo2(spo2))
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
