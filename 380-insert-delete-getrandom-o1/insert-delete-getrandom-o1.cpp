class RandomizedSet {
public:
    vector<int> v;
    unordered_set<int>temp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(temp.find(val)==temp.end())
        {
            v.push_back(val);
            temp.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(temp.find(val)==temp.end())
        {
            return false;
        }
        auto it = find(v.begin(), v.end(),val);
        v.erase(it);
        temp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */