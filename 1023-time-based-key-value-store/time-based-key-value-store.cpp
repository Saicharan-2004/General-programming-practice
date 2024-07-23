class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>tp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tp[key].push_back({timestamp,value});
    }
    string get(string key, int timestamp) {
        if(tp.find(key) == tp.end())    return "";
        int start = 0;
        int end = tp[key].size()-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(tp[key][mid].first<=timestamp)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return end == -1 ? "" : tp[key][end].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */