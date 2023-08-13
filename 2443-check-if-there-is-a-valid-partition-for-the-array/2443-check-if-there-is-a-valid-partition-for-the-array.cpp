class Solution {
public:
    int helper(vector<int>arr,int ind,vector<int>&dp)
    {
        int n=arr.size();
        if(ind==n)
        {
            return true;
        }
        // if(ind==n-2)
        // {
        //     return (arr[ind]==arr[ind+1]);
        // }
        // if(ind==n-3)
        // {
        //     if((arr[ind]==arr[ind+1])&&(arr[ind+1]==arr[ind+2]))
        //     {
        //         return true;
        //     }
        //     else if((arr[ind]+1==arr[ind+1])&&(arr[ind+1]+1==arr[ind+2]))
        //     {
        //         return true;
        //     }
        //     return false;
        // }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        if(ind+1<n && arr[ind]==arr[ind+1])
        {
            dp[ind]=helper(arr,ind+2,dp);
            if(dp[ind])
            {
                return true;
            }
        }
        if(ind + 2 < n && arr[ind]==arr[ind+2] && arr[ind]==arr[ind+1])
        {
            dp[ind]=helper(arr,ind+3,dp);
            if(dp[ind])
            {
                return true;
            }
        }
        if(ind+2<n && arr[ind+1]-arr[ind]==1 && arr[ind+2]-arr[ind] == 2)
        {
            dp[ind]=helper(arr,ind+3,dp);
            if(dp[ind])
            {
               return true;
            }
        }
        return dp[ind]= false;
    }
    bool validPartition(vector<int>& nums) 
    {
        int n=nums.size();
        // vector<int>dp(n+1,0);
        // return helper(arr,0,dp);
        // dp[n]=1;
        // for(int ind=n-1;ind>=0;ind--)
        // {
        //     if(ind+1<n && arr[ind]==arr[ind+1])
        //     {
        //         dp[ind]=dp[ind+2];
        //     }
        //     else if(ind + 2 < n && arr[ind]==arr[ind+2] && arr[ind]==arr[ind+1])
        //     {
        //         dp[ind]=dp[ind+3];
        //     }
        //     else if(ind+2<n && arr[ind+1]-arr[ind]==1 && arr[ind+2]-arr[ind] == 2)
        //     {
        //         dp[ind]=dp[ind+3];
        //     }
        //     else
        //     {
        //         dp[ind]= false;
        //     }
        // }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;//Emprt subarray case

        for (int index = 0; index < n; index++)
        {
            int i = index + 1;
            bool twoIdentical = false;
            bool threeIdentical = false;
            bool increasingSeq = false;

            if (index > 0 && nums[index] == nums[index - 1])
            {
                twoIdentical = dp[i - 2];
            }

            if (index > 1 && nums[index] == nums[index - 1] && nums[index - 1] == nums[index - 2] && nums[index] == nums[index - 2])
            {
                threeIdentical = dp[i - 3];
            }

            if (index > 1 && nums[index] == nums[index - 1] + 1 && nums[index - 1] == nums[index - 2] + 1)
            {
                increasingSeq = dp[i - 3];
            }

            dp[i] = twoIdentical || threeIdentical || increasingSeq;
        }
        return dp[n];
        // int n=arr.size();
        // vector<int>dp(n+1,0);
        // dp[n]=1;
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(i+1<n && arr[i]==arr[i+1])
        //     {
        //         dp[i]=dp[i]||dp[i+2];
        //     }
        //     else if(i+2<n && arr[i]==arr[i+2] && arr[i]==arr[i+1])
        //     {
        //         dp[i]=dp[i]||dp[i+3];
        //     }
        //     else if(i+2<n && arr[i]+1==arr[i+1] && arr[i+1]+1==arr[i+2])
        //     {
        //         dp[i]=dp[i]||dp[i+3];
        //     }
        // }
        // return dp[0];
    }
};


// class Solution
// {
// public:
//     bool c(vector<int> &v, vector<int> &dp, int i)
//     {
//         int n = v.size();
//         if (i == v.size())
//             return true;
//         if (dp[i] != -1)
//             return dp[i];

//         if (i + 1 < n && v[i] == v[i + 1])
//         {
//             if (c(v, dp, i + 2))
//                 return dp[i] = true;
//         }

//         if (i + 2 < n && v[i] == v[i + 2] and v[i] == v[i + 1])
//         {
//             if (c(v, dp, i + 3))
//                 return dp[i] = true;
//         }
//         if (i + 2 < n && v[i] + 1 == v[i + 1] && v[i] + 2 == v[i + 2])
//         {
//             if (c(v, dp, i + 3))
//                 return dp[i] = true;
//         }
//         return dp[i] = false;
//     }
//     bool validPartition(vector<int> &v)
//     {
//         int n = v.size();
//         vector<int> dp(n + 1, -1);
//         return c(v, dp, 0);
//     }
// };