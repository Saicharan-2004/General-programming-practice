class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<pair<int,int>>tp(n);
        for(int i = 0;i<n;i++)
        {
            tp[i].first = abs(arr[i]-x);
            tp[i].second = arr[i];
        }
        sort(tp.begin(),tp.end());
        vector<int>ans;
        for(int i = 0;i<k;i++)
        {
            ans.push_back(tp[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};