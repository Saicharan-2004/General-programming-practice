class Solution {
public:
    bool isMonotonic(vector<int>& arr) 
    {
        bool checker1=true;
        bool checker2=true;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                checker1=false;
                break;
            }
        }
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]<arr[i+1])
            {
                checker2=false;
                break;
            }
        }
        return checker1||checker2;
    }
};