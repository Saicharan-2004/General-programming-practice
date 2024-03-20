class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums2.size();
        stack<int>temp;
        unordered_map<int,int>ans;
        for(int i=n-1;i>=0;i--)
        {
            while(!temp.empty() && nums2[temp.top()]<=nums2[i])
            {
                temp.pop();
            }
            if(temp.empty())
            {
                ans[nums2[i]]=-1;
            }
            else
            {
                ans[nums2[i]]=nums2[temp.top()];
            }
            temp.push(i);
        }
        for(int i=0;i<nums1.size();i++)
        {
            nums1[i]=ans[nums1[i]];
        }
        return nums1;
    }
};