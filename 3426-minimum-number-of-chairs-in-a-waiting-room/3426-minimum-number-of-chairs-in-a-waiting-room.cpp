class Solution {
public:
    int minimumChairs(string s) {
        int maxi = -1;
        int count = 0 ;
        for(int i = 0 ;i<s.length();i++)
        {
            if(s[i] == 'E')
            {
                count++;
            }
            else
            {
                count--;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};