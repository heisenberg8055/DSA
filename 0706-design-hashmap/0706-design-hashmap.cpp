class MyHashMap {
public:
    int arr[1000001]={0};
    bool brr[1000001]={false};
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        brr[key]=true;
        arr[key]=value;
    }
    
    int get(int key) {
        if(arr[key]==0&&brr[key]==false)
        {
            return -1;
        }
        return arr[key];
    }
    
    void remove(int key) {
        brr[key]=false;
        arr[key]=0;
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */