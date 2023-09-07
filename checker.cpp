#include <iostream>
#include <assert.h>
#include <unistd.h>
#include <string>
#include <unordered_map>
using namespace std;

string getPulseRateCondition(float pulseRate)
{
    unordered_map<string, pair<float, float>> conditions = { {"BRADYCARDIA", {0,59.99}}, 
                                                             {"NEAR BRADYCARDIA", {60, 61.59}}, 
                                                             {"PULSERATE NORMAL", {61.60,98.49}},
                                                             {"NEAR TACHYCARDIA", {98.50,100}},
                                                             {"TACHYCARDIA",{100,300}}
                                                            };
    string pulseCondition;
    for(auto i: conditions)
    {
        if(pulseRate >= i.second.first && pulseRate <= i.second.second)
        {
            pulseCondition = i.first;
        }
    }
    return pulseCondition;
}

string getSpo2Condition(float spo2)
{
    unordered_map<string, pair<float,float>> conditions = { {"HYPOXEMIA", {0,89.99}},
                                                            {"NEAR HYPOXEMIA", {90,91.35}},
                                                            {"Spo2 NORMAL", {91.36,100}},
                                                            };
    string spo2Condition;
    for(auto i: conditions)
    {
        if(spo2 >= i.second.first && spo2 <= i.second.second)
        {
            spo2Condition = i.first;
        }
    }
    return spo2Condition;
    
}

string getTemperatureCondition(float temp)
{
    unordered_map<string, pair<float,float>> conditions = {{"HYPO_THERMIA",{0,94.99}},
                                                           {"NEAR_HYPO",{95,96.53}},
                                                           {"TEMPERATURE NORMAL",{96.54,100.47}},
                                                           {"NEAR_HYPER",{100.48,102}},
                                                           {"HYPER_THERMIA",{102.1,120}}
                                                            };
    string tempertureCondition;
    for(auto i: conditions)
    {
        if(temp >= i.second.first && temp <= i.second.second)
        {
            tempertureCondition = i.first;
        }
    }
    return tempertureCondition;
}

void getAttention()
{
     for (int i = 0; i < 6; i++)
    {
      cout << "\r* " << flush;
      sleep(1);
      cout << "\r *" << flush;
      sleep(1);
    }
}

int isTemperatureOk(float temperature)
{
    cout<<getTemperatureCondition(temperature);
    if(temperature > 102 || temperature <95)
    {
        cout<<"Temperature critical!\n";
        getAttention();
        return 0;
    }
    cout<<endl;
    return 1;
    
}

int isPulseRateOk(float pulseRate)
{
    cout<<getPulseRateCondition(pulseRate);
    if(pulseRate < 60 || pulseRate > 100)
    {
        cout<<"Pulse Rate is out of range!\n";
        getAttention();
        return 0;
    }
    cout<<endl;
    return 1;
}

int isSpo2Ok(float spo2)
{
    cout<<getSpo2Condition(spo2);
    if(spo2 < 90)
    {
        cout << "Oxygen Saturation out of range!\n";
        getAttention();
        return 0;
    }
    cout<<endl;
    return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
     !isTemperatureOk(temperature) || !isPulseRateOk(pulseRate) || !isSpo2Ok(spo2);
}

int main() {
   //temperature
  assert(!vitalsOk(92, 90, 95));
  assert(vitalsOk(95.9, 91, 96));
  assert(vitalsOk(99, 92, 100));
  assert(vitalsOk(101.45, 99, 100));
  assert(!vitalsOk(105, 80, 100));
  
  //pulse Rate
  assert(!vitalsOk(99, 58, 99));
  assert(vitalsOk(97, 61.2, 100));
  assert(vitalsOk(96, 70, 98));
  assert(!vitalsOk(96, 99, 85));
  assert(!vitalsOk(99, 101.2, 98));
  
  //Spo2
  assert(!vitalsOk(98, 70, 85));
  assert(vitalsOk(97, 80, 91.2));
  assert(vitalsOk(98, 70, 100));
  cout << "Done\n";
}
