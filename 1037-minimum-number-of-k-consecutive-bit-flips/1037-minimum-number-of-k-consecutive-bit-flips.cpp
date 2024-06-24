class Solution {
public:
    int minKBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        int ans = 0;
        // vector<bool>check(n,false);
        for(int i = 0;i<n;i++)
        {
            if(i>=k)
            {
                if(arr[i-k] == 2)
                {
                    count--;
                }
            }
            if(arr[i] == 0 && count%2 == 0 || arr[i] == 1 && count%2 == 1)
            {
                if(i>n-k)   return -1;
                arr[i] = 2;
                count++;
                ans++;
            }
        }
        return ans;
    }
};