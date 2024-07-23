class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)  return 0;
        int start = 1;
        int end = x;
        int ans = INT_MIN;
        while(start<=end)
        {
            long int mid = start + (end-start)/2;
            if(mid*mid == x)
            {
                return mid;
            }
            else if(mid*mid < x)
            {
                start = mid + 1;
                ans = max(ans,int(mid));
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};