class Solution {
public:
    int hIndex(vector<int>& arr) {
        // int start = 0;
        // int end = arr.size()-1;
        // int n = end+1;
        // int ans = 0;
        // while(start<=end)
        // {
        //     int mid = start + (end-start)/2;
        //     if(n-mid>=arr[mid])
        //     {
        //         start = mid + 1;
        //         ans = max(ans,n-mid);
        //     }
        //     else
        //     {
        //         end = mid - 1;
        //     }
        // }
        // return ans;
        int ans = 0;
        int n = arr.size();
        for(int i = 0;i<=1000;i++)
        {
            int num = lower_bound(arr.begin(),arr.end(),i)-arr.begin();
            if(n-num >= i)
            {
                ans = max(ans,i);
            }
        }
        return ans;
        // if(end == -1)
        // {
        //     return n;
        // }
        // return arr[end];
    }
};