class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int tar=arr.size()/4;
        int start=0;
        int end=0;
        int ans=0;
        while(end<arr.size())
        {
            while(end<arr.size() && arr[start]==arr[end])
            {
                end++;
            }
            if(end-start>tar)
            {
                return arr[start];
            }
            start++;
        }
        return 0;
    }
};