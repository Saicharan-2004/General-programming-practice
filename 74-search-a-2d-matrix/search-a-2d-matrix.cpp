class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0;
        int end = n-1;
        while(start<=end)
        {
            int mid = (start + end)/2;
            if(matrix[mid][0]<target)
            {
                start = mid + 1;
            }
            else
            {
                if(matrix[mid][0] == target)
                {
                    return true;
                }
                end = mid - 1;
            }
        }
        if(end == -1)
        {
            return false;
        }
        int idx = end;
        start = 0;
        end = m - 1;
        while(start<=end)
        {
            int mid = (start + end)/2;
            if(matrix[idx][mid]<target)
            {
                start = mid + 1;
            }
            else
            {
                if(matrix[idx][mid] == target)
                {
                    return true;
                }
                end = mid - 1;
            }
        }
        return false;
    }
};