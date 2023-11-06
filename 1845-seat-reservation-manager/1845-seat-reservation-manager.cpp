class SeatManager {
public:
    set<int>s;
    int marker = 1;
    SeatManager(int n) {
    }
    
    int reserve() {
        if(!s.empty())
        {
            auto ans = s.begin();
            int ret = *ans;
            s.erase(ans);
            return ret;
        }
        int ans = marker++;
        return ans;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */