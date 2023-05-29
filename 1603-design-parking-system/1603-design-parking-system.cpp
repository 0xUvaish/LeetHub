class ParkingSystem {
public:
    int size[3], curr[3];
    ParkingSystem(int big, int medium, int small) {
        size[0] = big; size[1] = medium; size[2] = small;
        curr[0] = curr[1] = curr[2] = 0;
    }
    
    bool addCar(int carType) {
        if (curr[carType-1]<size[carType-1]){
            curr[carType-1]++;
            return true;
        }
        else return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */