class Solution {
public:
    int trap(vector<int>& height) 
    {
        int leftmax = -1;
        int n = height.size();
        vector<int>leftMaxi(n);
        vector<int>rightMaxi(n);
        int rightmax = -1;
        for(int i =0 ;i<n;i++)
        {
            leftmax = max(leftmax,height[i]);
            rightmax = max(rightmax,height[n-i-1]);
            leftMaxi[i] = leftmax;
            rightMaxi[n-i-1] = rightmax;
        }
        int ans = 0;
        for(int i =0 ;i<n;i++)
        {
            if(leftMaxi[i] != -1 && rightMaxi[i] != -1)
                ans+=min(leftMaxi[i],rightMaxi[i])-height[i];
        }
        return ans;
    }
};