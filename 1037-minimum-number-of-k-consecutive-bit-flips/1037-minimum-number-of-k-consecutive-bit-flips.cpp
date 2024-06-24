class Solution {
public:
    int minKBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        int ans = 0;
        vector<bool>check(n,false);
        for(int i = 0;i<n;i++)
        {
            if(i>=k)
            {
                if(check[i-k])
                {
                    count--;
                }
            }
            if(i<=n-k)
            {
                if(arr[i] == 0 && count%2 == 0 || arr[i] == 1 && count%2 == 1)
                {
                    check[i] = true;
                    count++;
                    ans++;
                }
            }
            else
            {
                if(arr[i] == 0 && count%2 == 0 || arr[i] == 1 && count%2 == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};