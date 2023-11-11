class Solution {
public:
    int countHomogenous(string s) 
    {
        long long int start=0;
        long long int end=1;
        long long int ans=0;
        long long int mod=1e9+7;
        long long int count=0;
        while(end<s.length())
        {
            if(s[end]==s[start])
            {
                end++;
            }
            else
            {
                count=end-start;
                ans+=(((count)*(count+1))%mod)%mod/2;
                cout<<count<<endl;
                start=end;
                end++;
            } 
        }
        count=end-start;
        ans+=((((count%mod)*(count+1))%mod)%mod)/2;
        return ans%mod;
    }
};