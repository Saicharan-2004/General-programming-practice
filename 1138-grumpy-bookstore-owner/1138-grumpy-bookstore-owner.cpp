class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int totalCust = 0;
        int n = customers.size();
        for(int i = 0;i<n;i++)
        {
            if(grumpy[i] == 0)
                totalCust+=customers[i];
        }
        int start = 0;
        int end = minutes - 1;
        int tempSum = 0;
        for(int i = start ;i <= end ;i++)
        {
            if(grumpy[i])
            {
                tempSum += customers[i];
            }
        }
        int maxi = tempSum;
        while(end < n)
        {
            if(grumpy[start])
            {
                tempSum -= customers[start];
            }
            if(end+1<n && grumpy[end+1])
            {
                tempSum += customers[end+1];
            }
            start++;
            end++;
            maxi = max(maxi,tempSum);
        }
        return totalCust+maxi;
    }
};