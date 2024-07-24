class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // int n = arr.size();
        // int lower = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        // if(lower == 0)
        // {
        //     return vector<int>(arr.begin(),arr.begin()+k);
        // }
        // else if(lower == n)
        // {
        //     return vector<int>(arr.begin()+n-k,arr.end());
        // }
        // else
        // {
        //     int ptr1 = lower;
        //     int ptr2 = lower + 1;
        //     int count = 0;
        //     vector<int>ans;
        //     // ans.push_back(arr[lower]);
        //     while(count<k)
        //     {
        //         if(ptr1>=0 && ptr2<n)
        //         {
        //             if(x-arr[ptr1]<=arr[ptr2]-x)
        //             {
        //                 ans.push_back(arr[ptr1]);
        //                 ptr1--;
        //             }
        //             else
        //             {
        //                 ans.push_back(arr[ptr2]);
        //                 ptr2++;
        //             }
        //         }
        //         else if(ptr1>=0)
        //         {
        //             ans.push_back(arr[ptr1]);
        //             ptr1--;
        //         }
        //         else if(ptr2<n)
        //         {
        //             ans.push_back(arr[ptr2]);
        //             ptr2++;
        //         }
        //         count++;
        //     }
        //     sort(ans.begin(),ans.end());
        //     return ans;
        // }
        // return {};
        int n = arr.size();
        int left = 0, right = n - 1;

        // Narrow down the window to size k
        while (right - left >= k) {
            if (abs(arr[left] - x) > abs(arr[right] - x)) {
                left++;
            } else {
                right--;
            }
        }

        // Collect the result
        vector<int> ans(arr.begin() + left, arr.begin() + left + k);
        return ans;
    }
    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //     int n = arr.size();
    //     vector<pair<int,int>>tp(n);
    //     priority_queue<pair<int,int>>tp;
    //     for(int i = 0;i<n;i++)
    //     {
    //         tp[i].first = abs(arr[i]-x);
    //         tp[i].second = arr[i];
    //     }
    //     sort(tp.begin(),tp.end());
    //     vector<int>ans;
    //     for(int i = 0;i<k;i++)
    //     {
    //         ans.push_back(tp[i].second);
    //     }
    //     sort(ans.begin(),ans.end());
    //     return ans;
    // }
};