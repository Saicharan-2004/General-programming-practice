class Solution {
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int end = accumulate(arr.begin(),arr.end(),0);
        int start = *max_element(arr.begin(),arr.end());
        while(start<=end)
        {
            int mid = (start+end)/2;
            int countDays = 1;
            int currSum = 0;
            for(auto it:arr)
            {
                if(currSum + it <= mid)
                {
                    currSum+= it;
                }
                else
                {
                    countDays++;
                    currSum = it;
                }
            }
            if(countDays <= days)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;

            }
        }
        return start;
    }
};