class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>>indexes;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    indexes.push_back({i,j});
                }
            }
        }
        for(auto it:indexes)
        {
            int x = it.first;
            int y = it.second;
            // cout<<x<<" "<<y<<" ";
            for(int i = 0;i<n;i++)
            {
                matrix[i][y] = 0;
            }
            for(int i = 0;i<m;i++)
            {
                matrix[x][i] = 0;
            }
        }
        // return matrix;
    }
};