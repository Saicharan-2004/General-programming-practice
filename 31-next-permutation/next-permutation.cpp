class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int ind = -1;
        int n=arr.size();
        if(n == 1)
        {
            return ;
        }
        else if(n == 2)
        {
            swap(arr[0],arr[1]);
            return ;
        }
        for(int i = n-2;i>=0;i--)
        {
            if(arr[i+1]>arr[i])
            {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            reverse(arr.begin(), arr.end());
        } else {
            for (int j = n - 1; j > ind; j--) { 
                if (arr[j] > arr[ind]) {
                    swap(arr[j], arr[ind]);
                    break;
                }
            }
            reverse(arr.begin() + ind + 1, arr.end());
        }
    }
};