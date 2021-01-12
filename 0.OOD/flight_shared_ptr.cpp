#include <exception>
#include <assert.h>

using namespace std;

namespace Airline{
    enum Opt{eco,pre,bus};
    enum Airline{delta,southwest,united};
    unordered_map<string,Opt> op = {{"economy",eco}, {"premium",pre}, {"business",bus}} ;
    unordered_map<string,Airline> mp = {{"delta",delta}, {"united",united}, {"southwest",southwest}};
    class BaseCalculator{
    protected:
        virtual ~BaseCalculator() = default;
        
        virtual double getAirlineRate() = 0;
        virtual double getBaseFee(double dist){
            double mile_rate = getAirlineRate();
            return mile_rate * dist;
        }
        virtual double getOptFee(Opt mode, double dist){
            double opt_cost = 0.;
            switch(mode)
            {
                case eco:
                    opt_cost = getEcoOpt(dist);
                    break;
                case pre:
                    opt_cost = getPreOpt(dist);
                    break;
                case bus:
                    opt_cost = getBusOpt(dist);
                    break;
            }
            // cout << opt_cost << endl;
            return opt_cost;
        }
        virtual double getEcoOpt(double d){
            // cout << "eco" << endl;
            return 0.;
        }
        virtual double getPreOpt(double d)
        {
            // cout << "pre" << endl;
            return 25.;
        }
        virtual double getBusOpt(double d){
            // cout << "bus" << endl;
            return 50 + 0.25*d;
        }
    public:
        static shared_ptr<BaseCalculator> getInstance(Airline airline);
        double getTotalFee(Opt mode, double dist){
            return getBaseFee(dist) + getOptFee(mode,dist);
        }
    };
    
    
    class DeltaCalculator : public BaseCalculator{
    
        public:
        // static DeltaCalculator delta;
        DeltaCalculator() = default;
        static shared_ptr<DeltaCalculator> getInstance()
        {
            static shared_ptr<DeltaCalculator> delta_ptr = make_shared<DeltaCalculator>();
            return delta_ptr;
        }
        double mile_rate = 0.5;
        double getAirlineRate() override
        {
            return mile_rate;
        }
    };
    
    class SouthwestCalculator : public BaseCalculator{
    
    public:
        // static SouthwestCalculator sth;
        SouthwestCalculator() = default;
        
        static shared_ptr<SouthwestCalculator> getInstance()
        {
            static shared_ptr<SouthwestCalculator> sth_ptr = make_shared<SouthwestCalculator>();
            return sth_ptr;
        }
        double mile_rate = 0.75;
        double getAirlineRate() override
        {
            return mile_rate;
        }
    };
    
    class UnitedCalculator : public BaseCalculator{
    
    public:
        // static UnitedCalculator uni;
        UnitedCalculator() = default;
        static shared_ptr<UnitedCalculator> getInstance()
        {
            static shared_ptr<UnitedCalculator> uni_ptr = make_shared<UnitedCalculator>();
            return uni_ptr;
        }
        double mile_rate = 1.0;
        double getAirlineRate() override
        {
            return mile_rate;
        }
    };
    
    shared_ptr<BaseCalculator>  BaseCalculator::getInstance(Airline airline){
        switch(airline)
        {
            case delta:
                return DeltaCalculator::getInstance();
            case southwest:
                return SouthwestCalculator::getInstance();
            case united:
                return UnitedCalculator::getInstance();
        }
    }
    
    vector<string> parse(string& s)
    {
        string line;
        stringstream ss(s);
        vector<string> res;
        while(getline(ss,line,' '))
        {
            transform(line.begin(),line.end(),line.begin(),::tolower);
            res.push_back(line);
        }
        return res;
    }
    
    vector<double> getPrice(vector<string>& input)
    {
        vector<double> res;
        for(int i = 0; i < input.size(); i++)
        {
            vector<string> record = parse(input[i]);
            shared_ptr<BaseCalculator> clc = BaseCalculator::getInstance(mp[record[0]]);
            double dist = stod(record[1]);
            res.push_back(clc->getTotalFee(op[record[2]],dist));
        }
        return res;
    }
    

}



int main() {
    std::cout << "Hello World!\n";
    // throw exception();
    // assert(1 == 0);
    vector<string> input{"United 150.0 Premium", "United 120.0 economy","United 100.0 business","Delta 60.0 economy","Delta 60.0 premium","Delta 60.0 Business", "SouthWest 1000.0 Economy", "SouthWest 4000.0 Economy"};
    vector<double> costs = Airline::getPrice(input);
    for(int i = 0 ; i < input.size(); i++){
        cout<< input[i]<<" cost: $"<<costs[i]<<endl;
    }
    return 0;
}