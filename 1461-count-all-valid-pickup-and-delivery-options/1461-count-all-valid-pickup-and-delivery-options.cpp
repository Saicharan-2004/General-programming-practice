class Solution {
public:
    int modu=1e9+7;
    int countOrders(int n) 
    {
        long long prev=1;
        for(int i=1;i<=n;i++)
        {
            prev=prev*(2*i-1)*i%modu;
        }
        return prev;
    }
};