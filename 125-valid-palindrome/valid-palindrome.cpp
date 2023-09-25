class Solution {
public:
    bool checker(char s)
    {
        int r=s;
        if(r>=97 && r<=122)
            return true;
        if(r>=65 && r<=90)
            return true;
        return false;
    }
    char converter(char r)
    {
        if( 'a'<=r && r<='z' )
        {
            return r;
        }
        int e=r-'A';
        return 'a'+ e;
    }
    bool isPalindrome(string s) 
    {
        if(s.size()==0)
        {
            return true;
        }
        int start=0;
        int end=s.length()-1;
        while(start<=end)
        {
            if(!isalnum(s[start]))
            {
                start++;
                continue;
            }
            else if(!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if(tolower(s[start])!=tolower(s[end]))
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        return true;
        // while(start<=end)
        // {
        //     if(s[start]!=s[end])
        //     {
        //         return false;
        //     }
        //     start++;
        //     end--;
        // }
        // return true;
    }
};