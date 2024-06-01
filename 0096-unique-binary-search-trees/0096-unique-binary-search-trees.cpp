class Solution {
public:
    // int helper(int left,int right)
    // {
    //     if(left>right)
    //     {
    //         return 0;
    //     }
    //     if(left==right)
    //     {
    //         return 1;
    //     }
    //     int counter=0;
    //     for(int i=left;i<=right;i++)
    //     {
    //         int leftT=helper(left,i-1);
    //         int rightT=helper(i+1,right);
    //         counter+=leftT+rightT;
    //     }
    //     return counter;
    // }
    int dp[20] = {};
    int numTrees(int n) 
    {
        if(n<=1)
        {
            return 1;
        }
        if(dp[n])
            return dp[n];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=numTrees(i-1)*numTrees(n-i);
        }
        return dp[n]=ans;
    }
};