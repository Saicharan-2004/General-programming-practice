class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2)   return findMedianSortedArrays(nums2,nums1);
        int left = (n1+n2+1)/2;
        int start = 0;
        int end =n1;
        while(start<=end)
        {
            int mid1 = (start+end)>>1;
            int mid2 = left - mid1;
            double left1 = INT_MIN;
            double left2 = INT_MIN;
            double right1 = INT_MAX;
            double right2 = INT_MAX;
            if(mid1<n1) right1 = nums1[mid1];
            if(mid2<n2) right2 = nums2[mid2];
            if(mid1-1>=0)   left1 = nums1[mid1-1];
            if(mid2-1>=0)   left2 = nums2[mid2-1];
            if(left1<=right2 && left2<=right1)
            {
                if((n1+n2)%2 == 1)
                {
                    return max(left1,left2);
                }
                return (((double)max(left1,left2)) + (double)min(right1,right2))/(double)2.0;
            }
            else if(left1 > right2)
            {
                end = mid1 - 1;
            }
            else if(left2 > right1)
            {
                start = mid1 + 1;
            }
        }
        return 0;
    }
};