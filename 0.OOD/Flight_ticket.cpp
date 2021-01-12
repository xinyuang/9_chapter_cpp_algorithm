#include<iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>
#include <vector>
 
using namespace std;
namespace Airfee{
enum Seat{ eco, pre, bus};
enum Airline{ delta, united, southwest};
map<string, Airline> airlines {{"delta",delta}, {"united",united}, {"southwest",southwest}};
map<string, Seat> seats  {{"economy",eco}, {"premium",pre}, {"business",bus}};
 
class AirlineCalculator{
public:
//    AirlineCalculator() = default;
    static AirlineCalculator* create(Airline air);
    virtual float calcFee(Seat s, float dis) = 0;
    virtual ~AirlineCalculator() = default;
protected:
    virtual float getOpCost (Seat s, float dis) {
        float opCost = 0.;
        switch(s)
        {
            case(eco): 
                opCost = getEcoOpCost(dis);
                break;
            case(pre): 
                opCost = getPreOpCost(dis);
                break;
            case(bus):
                opCost = getBusOpCost(dis);
        }
        return opCost;
    }
    virtual float getEcoOpCost (float d) {
        return 0.;
    }
    virtual float getPreOpCost (float d) {
        return 25.;
    }
    virtual float getBusOpCost (float d) {
        return 50.+ 0.25 * d;
    }
};
 
class DeltaCalculator:public AirlineCalculator{
public:
    float calcFee(Seat s,float dis) override {
        float opCost = getOpCost(s,dis);
        return opCost + dis * 0.5;
    }
    virtual ~DeltaCalculator() = default;
    static AirlineCalculator* instance(){
        static DeltaCalculator calc;
        return &calc;
    }
private:
    DeltaCalculator() = default;
};
 
class UnitedCalculator:public AirlineCalculator{
public:
    float calcFee(Seat s,float dis) override {
        float opCost = getOpCost(s,dis);
        return opCost + dis * 0.75;
    }
    virtual ~UnitedCalculator() = default;
    static AirlineCalculator* instance(){
        static UnitedCalculator calc;
        return &calc;
    }
private:
    UnitedCalculator() = default;
protected:
    float getPreOpCost(float d) override{
        return 25. + 0.1 * d;
    }
};
 
class SouthwestCalculator:public AirlineCalculator{
public:
    virtual ~SouthwestCalculator() = default;
    float calcFee(Seat s,float dis) override{
        return 1. * dis;
    }
    static AirlineCalculator* instance(){
        static SouthwestCalculator calc;
        return &calc;
    }
private:
    SouthwestCalculator() = default;
};
 
 
 
AirlineCalculator*  AirlineCalculator::create(Airline air){
    switch(air) {
        case delta:
            return DeltaCalculator::instance();
        case united:
            return UnitedCalculator::instance();
        case southwest:
            return SouthwestCalculator::instance();
    }
}
 
 
vector<string> split_tolower(string s, char delim = ' ');
vector<string> split_tolower(string s, char delim){
    vector<string> res;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delim) ) {
        if(token != "\0")
        res.push_back(token);
    }
    return res;
}
 
//map<string, AirlineCalculator*> airclcs{{"delta",DeltaCalculator::instance()}, {"united",UnitedCalculator::instance()}, {"southwest",SouthwestCalculator::instance()}};
 
vector<float> processData(vector<string> ticketData){
    vector<float> res;
    for(auto &ticket:ticketData){
        vector<string> data = split_tolower(ticket);
         
        assert(data.size() == 3);
        assert(airlines.count(data[0]));
        assert(seats.count(data[2]));
        float dis;
        try{
            dis = stof(data[1]);  //100a.0->100.0  
        } catch(const char *exception){
            cout << exception;
            throw;
        }
         
        AirlineCalculator* clc = AirlineCalculator::create(airlines[data[0]]);
        //AirlineCalculator* clc = airclcs[data[0]];
        cout<< data[0] << "add: "<<clc<<endl;
        res.push_back(clc->calcFee(seats[data[2]], dis));
 
    }
    return res;
}
}
 
 
int main() {
    vector<string> input{"United 150.0 Premium", "United 120.0 economy","United 100.0 business","Delta 60.0 economy","Delta 60.0 premium","Delta 60.0 Business", "SouthWest 1000.0 Economy", "SouthWest 4000.0 Economy"};
    vector<float> costs = Airfee::processData(input);
    for(int i = 0 ; i < input.size(); i++){
        cout<< input[i]<<" cost: $"<<costs[i]<<endl;
    }
    return 0;
}