class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long int end = *max_element(piles.begin(),piles.end());
        long int start = 1;
        long int ans = INT_MAX;
        while(start<=end)
        {
            long int k = start + (end-start)/2;
            long int hrs = 0;
            for(auto it:piles)
            {
                hrs += (it/k);
                if(it%k != 0)   
                    hrs+=1;
            }
            if(hrs <= h)
            {
                end = k - 1;
            }
            else
            {
                start = k + 1;
            }
        }
        return end+1;
    }
};