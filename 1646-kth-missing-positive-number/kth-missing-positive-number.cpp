class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>diff;
        int num = 1;
        for(auto it:arr)
        {
            // cout<<it-num<<" ";
            diff.push_back(it-num);
            num += 1;
        }
        int start = 0;
        int end = diff.size()-1;
        while(start<=end)
        {
            int mid = start + (end - start)/2;
            if(diff[mid] < k)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        if(arr[0]>k)
        {
            return k;
        }
        if(end == -1)
        {
            return k;
        }
        return arr[end] + k - diff[end];
    }
};