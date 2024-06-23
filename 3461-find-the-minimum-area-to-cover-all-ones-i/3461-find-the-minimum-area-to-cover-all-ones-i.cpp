class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int max_x = -1;
        int max_y = -1;
        int min_x = INT_MAX;
        int min_y = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    max_x = max(max_x,i);
                    min_x = min(min_x,i);
                    min_y = min(min_y,j);
                    max_y = max(max_y,j);
                    // cout<<max_x<<" "<<max_y<<endl;
                }
            }
        }
        return (max_x - min_x + 1)*(max_y - min_y + 1);
    }
};