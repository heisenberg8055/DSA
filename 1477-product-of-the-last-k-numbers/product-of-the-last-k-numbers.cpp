class ProductOfNumbers {
public:
vector<int>a = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num) {
            a.push_back(a.back() * num);
        }
        else{
            a = {1};
        }
    }
    
    int getProduct(int k) {
        return k < a.size() ? a.back() / a[a.size() - k - 1]: 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */