class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if((long)n < (long)m*k) return -1;
        int maxi = -1;
        int mini = INT_MAX;
        for(auto it:arr)
        {
            maxi = max(maxi,it);
            mini = min(mini,it);
        }
        int start = mini;
        int end = maxi;
        int ans = INT_MAX;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            int counter = 0;
            int num = 0;
            for(int i = 0;i<n;i++)
            {
                if(arr[i] <= mid)
                {
                    counter++;
                }
                else
                {
                    counter = 0;
                }
                if(counter == k)
                {
                    num++;
                    counter = 0;
                }
            }
            if(num < m)
            {
                start = mid + 1;
            }
            else
            {
                ans = min(ans , mid);
                end = mid - 1;
            }
        }
        return ans;
    }
};