class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        int n=s.length();
        int count=0;
        for(auto it:s)
        {
            if(it=='1')
                count++;
        }
        int countZeros=n-count;
        count--;
        string ans="";
        while(count--)
        {
            ans+='1';
        }
        while(countZeros--)
        {
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};