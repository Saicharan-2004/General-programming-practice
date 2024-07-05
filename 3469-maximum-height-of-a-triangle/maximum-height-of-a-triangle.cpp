class Solution {
public:
    int helper(int a,int b)
    {
        int height = 0;
        for(int i = 0;i<100;i++)
        {
            if(i%2 == 0)
            {
                if(a >= i+1)
                {
                    height+=1;
                    a-=(i+1);
                }
                else
                {
                    return height;
                }
            }
            else
            {
                if(b >= i+1)
                {
                    height+=1;
                    b-=(i+1);
                }
                else
                {
                    return height;
                }
            }
        }
        return height;
    }
    
    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red,blue),helper(blue,red));
    }
};