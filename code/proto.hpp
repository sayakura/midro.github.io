#include <string>
#include <map>

class Board{
public:
    const int OPERATIONG = 0;
    const int DEBUG = 1;
    double battery_level();
    double getLocation();
    bool   isFunctioning();
    int    systemMode;
private:
    std::map<string, Sensor> sensors;
    Battery battery;
    double longitude;
    double latitude;
}


class Network{
public:
    bool isConnected();
private:
    string user_name;
    string password;
}

class Sensor{
    virtual double getMeasurement();
    virtual bool   isFunctioning();
}

class FillSensor: public Sensor{
public:
    double getMeasurement();
    bool   isFunctioning();
    bool isFull();
private:
    string type;
    double distance;
    double time;
}

class Battery{
public:
    double getPercentage();
    double getRemainingLife();
    double getVoltage();
private:
    double voltage;
    double current;
    double watts;
    double time;
}