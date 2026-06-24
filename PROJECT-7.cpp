//Smart Traffic Signal

#include<iostream>

using namespace std;

class TrafficSignal
{
    private:
        string signalID;
        string location;
    protected:
        int greenDuration;
        int redDuration;
    public:
        TrafficSignal(string id, string loc, int green, int red)
        {
            signalID= id;
            location = loc;
            greenDuration = green;
            redDuration = red;
        }
        virtual void displayStatus() = 0;

        string getsignalID() const
        {
            return signalID;
        }
        string getlocation() const
        {
            return location;
        }
};

class VehicleSensorSignal: public TrafficSignal
{
    private:
        int vehicleCount;
    public:
        VehicleSensorSignal(string id, string loc, int green, int red, int count): TrafficSignal(id, loc, green, red)
        {
            vehicleCount = count;
        } 
        
        void displayStatus() override
        {
            cout<<"Vehicle Sensor Signal Information"<<endl;
            cout<<"Signal ID: "<<getsignalID()<<endl;
            cout<<"Location: "<<getlocation()<<endl;
            cout<<"Green Duration: "<<greenDuration<<endl;
            cout<<"Red Duration: "<<redDuration<<endl;
            cout<<"Vehical Count: "<<vehicleCount<<endl;
        }

        float calculateEfficiency()
        {
            return (float)greenDuration/(greenDuration + redDuration)* 100;
        }
};

class PedestrianSensorSignal: public TrafficSignal
{
    private:
        int pedestrianCount;
        bool emergencyMode;
    public:
        PedestrianSensorSignal(string id, string loc, int green, int red, int count, bool emergency): TrafficSignal(id, loc, green, red)
        {
            pedestrianCount = count;
            emergencyMode = emergency;
        }
       
        void displayStatus() override
        {
            cout<<"Pedestrian Sensor Signal Information"<<endl;
            cout<<"Signal ID: "<<getsignalID()<<endl;
            cout<<"Location: "<<getlocation()<<endl;
            cout<<"Green Duration: "<<greenDuration<<endl;
            cout<<"Red Duration: "<<redDuration<<endl;
            cout<<"Pedestrian Count: "<<pedestrianCount<<endl;
            cout<<"Emergency Mode: "<<boolalpha<<emergencyMode<<endl;
        }
        int getGreenDuration()
        {
            return greenDuration;
        }
};

int main()
{
    VehicleSensorSignal V("V715","Main Street", 60, 40, 25);
    PedestrianSensorSignal P("P715", "Central Park", 50, 60, 30, true);

    cout<<endl;
    cout<<"--WELCOME TO DIAMOND LUXE SMART TRAFFIC SIGNAL--"<<endl<<endl;
    V.displayStatus();
    cout<<endl;
    P.displayStatus();
    cout<<endl;


    cout<<"Signal Efficiency: "<<V.calculateEfficiency()<<"%"<<endl;
    cout<<"Green Duration of Pedestrian Signal: "<<P.getGreenDuration()<<endl<<endl;

    cout<<"Thank YOU for using Our Traffic Signals ^-^"<<endl;

    return 0;

}