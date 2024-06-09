class Solution {
public:
    int numberOfChild(int n, int k) {
        // // if(n>=k)
        // // {
        // //     return k;
        // // }
        // // else
        // // {
        int num = (k)/(n-1);
        if((num) % 2 == 1)
        {
            return (n-1) - (k)%(n-1);
        }
        else
        {
            return k%(n-1);
        }
        // //     // int i = 0;
        // //     // bool t = true;
        // //     // int counter = 0;
        // //     // while(counter!=k)
        // //     // {
        // //     //     if(t)
        // //     //     {
        // //     //         i++;
        // //     //     }
        // //     //     else
        // //     //     {
        // //     //         i--;
        // //     //     }
        // //     //     if(i==n-1)
        // //     //     {
        // //     //         t = !t;
        // //     //     }
        // //     //     counter++;
        // //     // }
        // //     // return i;
        // // }
        // int r = k/n-1;
        // k = k % (n-1);
        // if(r%2 == 0)
        // {
        //     return k;
        // }
        // return n-k-1;
        // int position = 0;
        // int direction = 1; 

        // for (int i = 0; i < k; ++i) 
        // {
        //     position += direction;
        //     if (position == 0 || position == n - 1)
        //     {
        //         direction *= -1;
        //     }
        // }
        // return position;
    }
};