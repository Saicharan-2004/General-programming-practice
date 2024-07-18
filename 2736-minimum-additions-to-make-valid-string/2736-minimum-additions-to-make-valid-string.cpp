class Solution {
public:
    int addMinimum(string word) {
        // map<char,int>tp;
        // int max_freq=-1;
        // for(auto it:word)
        // {
        //     max_freq = max(max_freq,++tp[it]);
        // }
        // int ans = 0;
        // for(char start = 'a';start<='c';start++)
        // {
        //     ans += max_freq-tp[start];
        // }
        // return ans;
        // int i = 0;
        // int n = word.size();
        // int ans = 0;
        // while(i<n-1)
        // {
        //     if(word[i] == 'a' && word[i+1] =='b')
        //     {
        //         if(i+2<n && word[i+2] == 'c')
        //             i+=3;
        //         else
        //         {
        //             ans+=1;
        //             i+=2;
        //         }
        //     }
        //     if(word[i] == 'a' && word[i+1] == 'a')
        //     {
        //         ans+=2;
        //         i+=1;
        //     }
        //     if(word[i] == 'a' && word[i+1] == 'c')
        //     {
        //         ans+=1;
        //         i+=2;
        //     }
        //     if(word[i]=='b' && word[i+1] == 'b')
        //     {
        //         ans+=2;
        //         i+=1;
        //     }
        //     if(word[i] == 'b' && word[i+1] == 'c')
        //     {
        //         ans+=1;
        //         i+=2;
        //     }
        //     if(word[i] == 'b' && word[i+1] == 'a')
        //     {
        //         ans+=2;
        //         i+=1;
        //     }
        //     if(word[i] == 'c' && word[i+1] == 'a')
        //     {
        //         ans+=2;
        //         i+=1;
        //     }
        //     if(word[i] == 'c' && word[i+1] == 'b')
        //     {
        //         ans+=2;
        //         i+=1;
        //     }
        //     if(word[i] == 'c' && word[i+1] == 'c')
        //     {
        //         ans+=2;
        //         i+=1;
        //     }
        // }
        // return ans;
        int i = 0;
        int n = word.size();
        int ans = 0;
        while(i<n)
        {
            if(word[i] == 'a')
            {
                ans+=2;
                if(i+1<n &&  word[i+1] == 'b')
                {
                    ans--;
                    if(i+2<n && word[i+2] == 'c')
                    {
                        ans--;
                        i+=3;
                    }
                    else
                    {
                        i+=2;
                    }
                }
                else if(i+1<n && word[i+1] =='c')
                {
                    ans--;
                    i+=2;
                }
                else
                {
                    i+=1;
                }
            }
            if(word[i]=='b')
            {
                ans+=2;
                if(i+1<n && word[i+1] == 'c')
                {
                    ans--;
                    i+=2;
                }
                else
                {
                    i+=1;
                }
            }
            if(word[i] == 'c')
            {
                ans+=2;
                i+=1;
            }
        }
        return ans;
    }
};