class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        int sum=0;
        sort(piles.rbegin(),piles.rend());
        for(int i=0;i<(piles.size())/3;i++)
        {
            sum+=piles[2*i+1];
        }
        return sum;
    }
};