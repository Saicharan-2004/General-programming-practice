class Solution {
public:
    vector<int>merge(vector<int>left,vector<int>right)
    {
        int p1 = 0;
        int p2 = 0;
        vector<int>ans;
        while(p1<left.size()&&p2<right.size())
        {
            if(left[p1]<right[p2])
            {
                ans.push_back(left[p1]);
                p1++;
            }
            else
            {
                ans.push_back(right[p2]);
                p2++;
            }
        }
        while(p1<left.size())
        {
            ans.push_back(left[p1]);
            p1++;
        }
        while(p2<right.size())
        {
            ans.push_back(right[p2]);
            p2++;
        }
        return ans;
    }
    vector<int>mergeSort(vector<int>nums,int start,int end)
    {
        if(end<start)
        {
            return {};
        }
        if(end==start)
        {
            return {nums[end]};
        }
        int mid = start + (end - start) / 2;
        vector<int>left = mergeSort(nums,start,mid);
        vector<int>right = mergeSort(nums,mid+1,end);
        return merge(left,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }
};