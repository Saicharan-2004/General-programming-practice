class Solution {
public:
    int helper(vector<int>arr,int ind,int n,vector<int>&dp)
    {
        if(ind>=n)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int curr=ind+1;
        int temp_sum=arr[ind];
        while(curr<n&&arr[curr]==arr[ind])
        {
            temp_sum+=arr[curr];
            curr++;
        }
        while(curr<n&&arr[curr]==arr[ind]+1)
        {
            curr++;
        }
        return dp[ind]= max(temp_sum+helper(arr,curr,n,dp),helper(arr,ind+1,n,dp));
    }
    int deleteAndEarn(vector<int>& arr) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>dp(arr.size()+1,0);
        // return helper(arr,0,arr.size(),dp);
        for(int ind=n-1;ind>=0;ind--)
        {
            int curr=ind+1;
            int temp_sum=arr[ind];
            while(curr<n&&arr[curr]==arr[ind])
            {
                temp_sum+=arr[curr];
                curr++;
            }
            while(curr<n&&arr[curr]==arr[ind]+1)
            {
                curr++;
            }
            dp[ind]= max(temp_sum+dp[curr],dp[ind+1]);
        }
        return dp[0];
    }
};