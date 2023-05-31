class UndergroundSystem {
public:
    map<pair<string,string>,vector<double>>mp; 
    unordered_map<int,pair<string,int>>reg;
    UndergroundSystem() {
        
    }
    void checkIn(int id, string stationName, int t) {
        reg[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        mp[{reg[id].first, stationName}].push_back(t - reg[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans = 0;
        int n = mp[{startStation,endStation}].size();
        for(int i = 0; i<n;i++)
        {
            ans+=mp[{startStation, endStation}][i];
        }
        return ans/n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */