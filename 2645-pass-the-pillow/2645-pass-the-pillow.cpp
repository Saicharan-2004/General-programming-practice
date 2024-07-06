class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n)
        {
            return time+1;
        }
        else
        {
            int mult = time/(n-1);
            if(mult%2 == 1)
            {
                return n - time%(n-1);
            }
            else
            {
                return time%(n-1) + 1;
            }
        }
    }
};