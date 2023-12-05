class Solution {
public:
    int numberOfMatches(int n) 
    {
        int cnt=0;
        if(n%2==0)
        {
            while(n>1)
            {
                if(n%2==0)
                 cnt=cnt+n/2;
                else
                    cnt=cnt+(n-1)/2+1;
                n=n/2;
            }
            return cnt;
        }
        else
        {
            
          while(n>1)
          {
              if(n%2==0)
                 cnt=cnt+n/2;
                else
                    cnt=cnt+(n-1)/2+1;
                n=n/2;
          }
            return cnt;
        }
    }
};