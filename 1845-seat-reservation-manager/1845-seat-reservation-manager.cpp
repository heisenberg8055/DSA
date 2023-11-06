class SeatManager {
public:
    set<int>s;
    SeatManager(int n) {
        for(int i = 0 ; i < n; i++)
        {
            s.insert(i+1);
        }
    }
    
    int reserve() {
        auto it = s.begin();
        int ans = *it;
        s.erase(it);
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