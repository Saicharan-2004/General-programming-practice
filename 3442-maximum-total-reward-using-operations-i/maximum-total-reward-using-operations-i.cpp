#define ll long long
int dp[2001][4000];

int helper(int ind,int sum,vector<int>&arr)
{
    if(ind == arr.size())
    {
        return dp[ind][sum] = sum;
    }
    if(dp[ind][sum] != -1)  return dp[ind][sum];
    int nottake = helper(ind + 1,sum,arr);
    int take = -1;
    if(sum < arr[ind])
    {
        take = helper(ind+1,sum+arr[ind],arr);
    }
    return dp[ind][sum] = max(take,nottake);
}
class Solution {
public:
    int maxTotalReward(vector<int>& rv) {

        memset(dp, -1, sizeof(dp));
        
        sort(rv.begin(), rv.end());
        
        int ans = helper(0, 0, rv);
        return ans;
        
    }
};