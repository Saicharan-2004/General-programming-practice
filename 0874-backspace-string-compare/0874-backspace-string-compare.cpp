class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        int i=0,j=0;
        while(i<s.length())
        {
            if(i==0 && s[i]=='#')
                s.erase(i,1);
            else if(s[i]=='#'){
                s.erase(i-1,2);
                i--;
            }
            else
                i++;
        }
        while(j<t.length())
        {
            if(j==0 && t[j]=='#')
                t.erase(j,1);
            else if(t[j]=='#'){
                t.erase(j-1,2);
                j--;
            }
            else
                j++;
        }
        if(s==t)
            return true;
        return false;
    }
        // int n=s.length();
        // int m=t.length();
        // // string ans1,ans2;
        // int i=0,j=0;
        // while(i<n)
        // {
        //     if(i==0 && s[i]=='#')
        //     {
        //         s.erase(i,1);
        //     }
        //     else if(s[i]=='#')
        //     {
        //         s.erase(i-1,2);
        //         i--;
        //     }
        //     else
        //     {
        //         i++;
        //     }
        // }
        // while(j<m)
        // {
        //     if(j==0 && t[j]=='#')
        //     {
        //         t.erase(j,1);
        //     }
        //     else if(t[j]=='#')
        //     {
        //         t.erase(j-1,2);
        //         j--;
        //     }
        //     else
        //     {
        //         j++;
        //     }
        // }
        // return s==t;
        // // stack<char>s1;
        // // stack<char>s2;
        // // for(int i=0;i<n;i++)
        // // {
        // //     if(s[i]!='#')
        // //     {
        // //         s1.push(s[i]);
        // //     }
        // //     else if(!s1.empty())
        // //     {
        // //         s1.pop();
        // //     }
        // // }
        // // for(int i=0;i<m;i++)
        // // {
        // //     if(t[i]!='#')
        // //     {
        // //         s2.push(t[i]);
        // //     }
        // //     else if(!s2.empty())
        // //     {
        // //         s2.pop();
        // //     }
        // // }
        // // while(!s1.empty())
        // // {
        // //     ans1+=s1.top();
        // //     s1.pop();
        // // }
        // // while(!s2.empty())
        // // {
        // //     ans2+=s2.top();
        // //     s2.pop();
        // // }
};