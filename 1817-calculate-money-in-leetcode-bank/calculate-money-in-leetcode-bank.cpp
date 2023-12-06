class Solution {
public:
    int totalMoney(int n) 
    {
        int count=0;
        int amt=1;
        int ans=0;
        while(count<n)
        {
            int i=0;
            int r=amt;
            while(i<7 && count<n)
            {
                ans+=(r++);
                i++;
                count++;
            }
            if(count%7==0)
            {
                amt+=1;
            }
        }
        return ans;
    }
};