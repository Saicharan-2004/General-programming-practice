class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int>temp;
        for(auto it:arr)
        {
            temp[it]++;
        }
        unordered_set<int>r;
        for(auto it:temp)
        {
            if(r.find(it.second)==r.end())
            {
                r.insert(it.second);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};