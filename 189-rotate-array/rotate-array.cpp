class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int start = 0;
        int n = nums.size();
        k = k%n;
        int end = n-k-1;
        while(start>=0 && end < n && start<end)
        {
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        start = n-k;
        end = n-1;
        while(start>=0 && end < n && start<end)
        {
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        start = 0;
        end = n-1;
        while(start>=0 && end < n && start<end)
        {
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        return ;
    }
};