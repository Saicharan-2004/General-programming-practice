class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) 
    {
        int maxi=-1;
        for(auto it:left)
        {
            maxi=max(maxi,it);
        }
        for(auto it:right)
        {
            maxi=max(maxi,abs(n-it));
        }
        return maxi;
    }
};