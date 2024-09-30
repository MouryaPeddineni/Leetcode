class CustomStack {
private:
    vector<int> vec;
    int limit;
public:
    CustomStack(int maxSize) {
        limit = maxSize;
    }
    
    void push(int x) {
        if(vec.size() == limit) return;
        vec.push_back(x);
    }
    
    int pop() {
        if(vec.size() == 0) return -1;
        int n = vec.back();
        vec.pop_back();
        return n;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<k && i<vec.size(); i++)
            vec[i]+=val;
    }
};