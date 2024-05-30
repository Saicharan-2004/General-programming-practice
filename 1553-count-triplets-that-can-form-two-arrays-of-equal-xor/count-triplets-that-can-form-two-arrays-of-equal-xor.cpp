class Solution {
public:
    // int helper(int ind,vector<int>arr,int xoro)
    // {
        
    // }
    int countTriplets(vector<int>& arr) 
    {
        int n = arr.size();
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            int xoro = arr[i];
            for(int j = i+1;j<n;j++)
            {
                xoro = xoro ^ arr[j];
                if(xoro == 0)
                {
                    ans += j - i;
                }
            }
        }
        return ans;
        // vector<int>aage(n);
        // vector<int>piche(n);
        // int xoro=0;
        // for(int i = 0;i<n;i++)
        // {
        //     xoro = xoro ^ arr[i];
        //     aage[i]=xoro;
        // }
        // xoro = 0;
        // for(int i = n-1;i>=0;i--)
        // {
        //     xoro = xoro ^ arr[i];
        //     piche[i]=xoro;
        // }
        // int ans = 0;
        // for(int i = 0;i<n;i++)
        // {
        //     if(aage[i]==piche[i])
        //         ans++;
        // }
        // return ans;
    }
};