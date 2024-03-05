class Solution {
public:
    int minimumLength(string s) 
    {
        int start=0;
        int end=s.length()-1;
        while(start<=end)
        {
            int tempstart=start;
            int tempend=end;
            if(start==end)
                return 1;
            if(s[tempstart]!=s[tempend])
            {
                return tempend-tempstart+1;
            }
            while(tempstart<=end && s[tempstart]==s[end])
            {
                tempstart++;
            }
            while(tempend>=start && s[tempend]==s[start])
            {
                tempend--;
            }
            start=tempstart;
            end=tempend;
        }
        return 0;
    }
};