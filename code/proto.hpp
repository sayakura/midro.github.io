#include <string>
#include <map>

// Sets up the overall waste system to encapsulate all the parts of the system
class WasteSystem{
public:
    bool runDiagnostics();

private:
    std::map<int, Board> boards;
};

// The Board Class contains all the necessary components to operate
class Board{
    const int OPERATING = 0;
    const int DEBUG = 1;
public:
    double battery_level();
    string getLocation();
    bool   isFunctioning();
    int    systemMode;
private:

    std::map<string, Sensor> sensors;
    Battery battery;
    double longitude;
    double latitude
};

// Sets up the basic Network abstraction layer
class Network{
public:
    bool isConnected();
private:
    string user_name;
    string password;
};

class Sensor{
    virtual double getMeasurement();
    virtual bool   isFunctioning();
};

// Sets the general parameters for the fill sensor
class FillSensor: public Sensor{
public:
    double getMeasurement();
    bool   isFunctioning();
    bool   isFull();
private:
    string type;
    double distance;
    double time;
};

// Design the battery levels and calculations for power
class Battery{
public:
    double getRemainingLife();
    double getPowerDraw();
private:
    double voltage;
    double current;
    double watts;
    double time;
};