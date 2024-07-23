class SnapshotArray {
public:
    // vector<int>arr;
    // unordered_map<int,vector<int>>snapHolder;
    vector<vector<pair<int,int>>>arr;
    int snapCount = 0;
    SnapshotArray(int length) {
        arr = vector<vector<pair<int,int>>>(length);
    }
    void set(int index, int val) {
        if(arr[index].empty() || snapCount != arr[index].back().first)
        {
            arr[index].push_back({snapCount,val});
        }
        else
        {
            arr[index].back().second = val;
        }
    }
    int bs(vector<pair<int,int>>&tp,int num)
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
    int snap() {
        return snapCount++;
    }
    
    int get(int index, int snap_id) {
        int num = bs(arr[index],snap_id);
        return  num == -1 ? 0 : arr[index][num].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */