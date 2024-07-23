class Solution {
public:
    int arrangeCoins(int n) {
        int start = 0;
        int end = n;
        int ans = INT_MAX;
        while(start<=end)
        {
            long int mid = start + (end - start)/2;
            long int curr = mid*(mid+1)/2;
            if(n == curr)
            {
                return mid;
            }
            if(n>curr)
            {
                start = mid + 1;
                ans = mid;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};