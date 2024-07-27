class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = -1;
        for(auto it:prices)
        {
            if(minPrice > it)
            {
                minPrice = it;
            }
            ans = max(ans,it-minPrice);
        }   
        return ans;
    }
};