class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>temp(n,0);
        for(auto it:roads)
        {
            temp[it[0]]++;
            temp[it[1]]++;
        }
        sort(temp.begin(),temp.end());
        long long int ans = 0;
        for(int i = 0;i<n;i++)
        {
            ans += (long long) temp[i]*(i+1);
        }
        return ans;
    }
};