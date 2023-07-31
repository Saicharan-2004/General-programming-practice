class Solution {
public:
    int fib(int n) 
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        int prev_prev=0;
        int prev=1;
        for(int i=2;i<=n;i++)
        {
            int r=prev+prev_prev;
            prev_prev=prev;
            prev=r;
        }
        return prev;
    }
};