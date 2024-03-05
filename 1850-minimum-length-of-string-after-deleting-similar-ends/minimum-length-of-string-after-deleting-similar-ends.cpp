class Solution {
public:
    int minimumLength(string s) 
    {
        int start=0;
        int end=s.length()-1;
        while(start<end)
        {
            // int tempstart=start;
            // int tempend=end;
            if(s[start]!=s[end])
            {
                break;
            }
            while(s[end]==s[start] && end>start)
            {
                end--;
            }
            end++;
            while(s[start]==s[end] && start<end)
            {
                start++;
            }
            end--;
        }
        return max(0,end-start+1);
    }
};