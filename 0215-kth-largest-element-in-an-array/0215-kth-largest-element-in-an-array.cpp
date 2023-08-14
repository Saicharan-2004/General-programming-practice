class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        // sort(nums.begin(),nums.end());
        // reverse(nums.begin(),nums.end());
        priority_queue<int,vector<int>>max_heap(nums.begin(),nums.end());
        for(int i=k-1;i>0;i--)
        {
            max_heap.pop();
        }
        return max_heap.top();
    }
};