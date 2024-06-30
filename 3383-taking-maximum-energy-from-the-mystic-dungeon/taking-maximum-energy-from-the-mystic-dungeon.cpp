class Solution {
public:
    int helper(int ind,vector<int>arr,int k,vector<int>&dp)
    {
        if(ind >= arr.size())
        {
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int take = -1e9;
        take = arr[ind] + helper(ind+k,arr,k,dp);
        return dp[ind] = take;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        int n = energy.size();
        // for(int i = 0;i<n-k;i++)
        // {
        //     int anss = energy[i];
        //     for(int ind = i+k;ind<n;ind+=k)
        //     {
        //         anss += energy[ind];
        //     }
        //     ans = max(ans,anss);
        // }
        // for(int i = n-k;i<n;i++)
        // {
        //     ans = max(ans,energy[i]);
        // }
        vector<int>arr(n,0);
        int maxi = INT_MIN;
        for(int i = n-1;i>=0;i--)
        {
            if(i+k>=n)
            {
                arr[i] = energy[i];
            }
            else
            {
                arr[i] = energy[i] + arr[i+k];
            }
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }
};