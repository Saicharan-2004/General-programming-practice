class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int mini=arr[0];
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(arr[start] == arr[mid] && arr[mid] == arr[end])
            {
                mini = min(mini,arr[start]);
                start++;
                end--;
                continue;
            }
            if(arr[start]<=arr[mid])
            {
                mini = min(mini,arr[start]);
                start = mid + 1;
            }
            else
            {
                mini = min(mini,arr[mid]);
                end = mid - 1;
            }
        }
        return mini;
    }
};