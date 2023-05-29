class ParkingSystem {
public:
    int a,b,c;
    ParkingSystem(int big, int medium, int small) {
        a = big;
        b = medium;
        c = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && a){
            a--;
            return true;
        }
        if(carType == 2 && b){
            b--;
            return true;
        }
        if(carType == 3 && c){
            c--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */