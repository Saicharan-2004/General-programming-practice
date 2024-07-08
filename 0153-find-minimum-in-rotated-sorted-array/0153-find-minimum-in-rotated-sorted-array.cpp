class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int mini=INT_MAX;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(arr[start]<=arr[mid] && arr[mid]<=arr[end])
            {
                mini = min(mini,arr[mid]);
                end = mid - 1;
            }
            else
            {
                if(arr[end]>= arr[mid] && arr[start] >= arr[mid])
                {
                    end = mid - 1;
                }
                else if(arr[mid]>=arr[start] && arr[end] <= arr[mid])
                {
                    start = mid + 1;
                }
                mini = min(mini,arr[mid]);
            }
        }
        return mini;
    }
};