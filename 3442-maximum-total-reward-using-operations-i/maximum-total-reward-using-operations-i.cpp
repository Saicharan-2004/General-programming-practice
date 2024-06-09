#define ll long long
int dp[2001][4000];

int find(int pos, int sum, vector<int> &nums)
{
    if(pos == nums.size())
        return 0;
    
    int ans = -1;
    
    if(dp[pos][sum]!=-1)
        return dp[pos][sum];
     
    if(nums[pos] > sum) // picking allowed
    {
        ans = max(ans, nums[pos] + find(pos+1, sum+nums[pos], nums)); // picking
        ans = max(ans,  find(pos+1, sum, nums)); // not picking
    }
    else
        ans = max(ans, find(pos+1, sum, nums)); // not picking 
    return dp[pos][sum] = ans;
}
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
        
        vector<int> nums;
        unordered_set<int> s;

        memset(dp, -1, sizeof(dp));
        
        for(int i=0; i<rv.size(); ++i)
            s.insert(rv[i]);
        
        for(auto i=s.begin(); i!=s.end(); ++i) // filtering out duplicate element and sorting the array
            nums.push_back(*i);
        
        sort(nums.begin(), nums.end());
        sort(rv.begin(), rv.end());
        
        int ans = helper(0, 0, rv);
        return ans;
        
    }
};