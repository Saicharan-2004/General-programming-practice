class Solution {
public:
    string largestGoodInteger(string num) 
    {   
        int start=0;
        int end=2;
        string ans="";
        while(end<num.length())
        {
            if(num[start]==num[end] && num[end]==num[start+1])
            {
                ans=max(ans,num.substr(start,3));
            }
            end++;
            start++;
        }
        return ans;
    }
};