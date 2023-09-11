class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) 
    {
        int n=arr.size();
        unordered_map<int,vector<int>>temp;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            temp[arr[i]].push_back(i);
            if(temp[arr[i]].size()==arr[i])
            {
                ans.push_back(temp[arr[i]]);
                temp[arr[i]].clear();
            }
        }
        return ans;
    }
};