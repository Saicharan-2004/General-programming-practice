class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int i=0;
        int j=matrix[i].size()-1;
        int temp=-1;
        for(int k=0;k<matrix.size();k++)
        {
            if(target==matrix[k][i])
            {
                return true;
            }
            else if(target>matrix[k][i])
            {
                if(target==matrix[k][j])
                {
                    return true;
                }
                else if(target<matrix[k][j])
                {
                    temp=k;
                    break;
                }
            }
        }
        if(temp==-1)
        {
            return false;
        }
        for(;i<=j;i++)
        {
            if(matrix[temp][i]==target)
            {
                return true;
            }
        }
        return false;
    }
};