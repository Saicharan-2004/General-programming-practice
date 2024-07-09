class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if(n<(long)m*k)
        {
            return -1;
        }
        int end = *max_element(arr.begin(),arr.end());
        int start = *min_element(arr.begin(),arr.end());
        // cout<<start<<" "<<end<<endl;
        while(start<=end)
        {
            int mid = (end+start)/2;
            int numBouquets = 0;
            int numFlowers = 0;
            for(int i = 0;i<n;i++)
            {
                if(arr[i] <= mid)
                {
                    numFlowers++;
                }
                else
                {
                    numBouquets += int(numFlowers/k);
                    numFlowers = 0;
                }
            }
            numBouquets += int(numFlowers/k);
            if(numBouquets<m)
            {
                start = mid + 1;
            }
            else
            {
                // ans = min(ans,mid);
                end = mid - 1;
            }
        }
        return end+1;
    }
};