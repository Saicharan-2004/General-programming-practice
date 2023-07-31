class Solution {
public:
    int tribonacci(int n) 
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1||n==2)
        {
            return 1;
        }
        long long zero=0;
        long long one=1;
        long long two=1;
        long long three;
        for(int i=3;i<=n;i++)
        {
            three=two+one+zero;
            zero=one;
            one=two;
            two=three;
        }
        return  three;
    }
};