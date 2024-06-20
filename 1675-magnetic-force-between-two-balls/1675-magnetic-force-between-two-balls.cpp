class Solution {
public:
    int maxDistance(vector<int>& arr, int m) 
    {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int start = 1;
        int end = *max_element(arr.begin(),arr.end()) - arr[0]; 
        int miniDist = -1;
        while(start<=end)
        {
            int mid  = (end+start)/2;
            int countBalls = 1;
            int startNumber = 0;
            for(int i = 1;i<n;i++)
            {
                if(arr[i] - arr[startNumber] >= mid)
                {
                    startNumber = i;
                    countBalls++;
                }
            }
            if(countBalls < m)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
                miniDist = max(miniDist,mid);
            }
        }
        return miniDist;
    }
};