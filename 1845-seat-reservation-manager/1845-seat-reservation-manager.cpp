class SeatManager {
public:
    priority_queue<int,vector<int>, greater<int>>pq;
    vector<int>arr;
    SeatManager(int n) {
        arr.resize(n);
        fill(arr.begin(), arr.end(), 0);
        for(int i = 1; i <= n; i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        int low = pq.top();
        pq.pop();
        arr[low - 1] = 1;
        return low;
    }
    
    void unreserve(int seatNumber) {
        arr[seatNumber - 1] = 0;
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */