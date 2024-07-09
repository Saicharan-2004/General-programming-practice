class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int end = *max_element(arr.begin(),arr.end());
        int start = 1;
        // cout<<start<<" "<<end<<endl;
        int ans = INT_MAX;
        while(start<=end)
        {
            int mid = (end+start)/2;
            int sum = 0;
            for(auto it:arr)
            {
                sum += (it/mid);
                if(it % mid !=0)
                {
                    sum++;
                }
            }
            if(sum<=k)
            {
                ans = min(ans,mid);
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};