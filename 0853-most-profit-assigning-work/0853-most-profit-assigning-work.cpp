class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>tp;
        int n = difficulty.size();
        int m = worker.size();
        for(int i = 0;i<n;i++)
        {
            tp.push_back({difficulty[i],profit[i]});
        }
        sort(tp.begin(),tp.end());
        sort(difficulty.begin(),difficulty.end());
        vector<int>maxi(n);
        maxi[0] = tp[0].second;
        for(int i = 1;i<n;i++)
        {
            maxi[i] = max(tp[i].second,maxi[i-1]);
        }
        int total = 0;
        for(auto it:worker)
        {
            int ind = upper_bound(difficulty.begin(),difficulty.end(),it)-difficulty.begin()-1;
            if(ind<=-1)
            {
                
            }
            else
            {
                // cout<<difficulty[ind]<<" ";
                total += maxi[ind];
            }
        }
        return total;
    }
};