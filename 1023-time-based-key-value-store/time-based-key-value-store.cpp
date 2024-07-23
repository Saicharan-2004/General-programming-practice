class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>tp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tp[key].push_back({timestamp,value});
    }
    int bs(vector<pair<int,string>>&tp,int num)
    {
        int start = 0;
        int end = tp.size()-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(tp[mid].first<=num)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return end;
    }
    string get(string key, int timestamp) {
        auto & curr = tp[key];
        int num = bs(curr,timestamp);
        return num == -1 ? "" : curr[num].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */