// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         set<pair<pair<int,int>,int>>pq;
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>>dist(n,vector<int>(m,1e9));//acts as visited array.
//         if(grid[0][0] == 0)
//             dist[0][0] = 0;
//         else
//             return -1;
//         pq.insert({{0,0},0});
//         while(!pq.empty())
//         {
//             auto it = *(pq.begin());
//             int dis = it.first.first;
//             int x = it.first.second;
//             int y = it.second;
//             pq.erase(it);
//             for(int i = -1;i<=1;i++)
//             {
//                 for(int j = -1;j<=1;j++)
//                 {
//                     if(i==0 && j==0)
//                     {
//                         continue;
//                     }
//                     else
//                     {
//                         int row = x + i;
//                         int col = y + j;                                                                                                                                                                           
//                         if(row < n && row >-1 && col < m && col > -1 && dist[row][col] > dis + 1)
//                         {
//                            if(grid[row][col] == 0)
//                            {
//                                 dist[row][col] = dis + 1;
//                                 pq.insert({{dis+1,row},col});
//                            }
//                         }
//                     }
//                 }
//             }
//         }
//         return dist[n-1][m-1] == 1e9 ? -1 : 1 + dist[n-1][m-1];
//     }
// };
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size(); 
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX)); 
        pair<int,int> src= {0,0}; 
        pair<int,int> dest= {n-1,n-1}; 
        dist[0][0]=0; 
        int dr[]= {-1,0,1,0,1,-1,-1,1}; 
        int dc[]= {0,-1,0,1,1,-1,1,-1}; 
        queue<pair<int, pair<int,int>>> q; 
        q.push({1,src}); 
        while(!q.empty()){
            auto it= q.front(); 
            int dis= it.first; 
            int r= it.second.first;
            int c= it.second.second; 
            q.pop(); 
            for(int i=0; i<8; i++){
                int newr= r+ dr[i]; 
                int newc= c+ dc[i]; 
                if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && (1 + dis) < dist[newr][newc]){
                    dist[newr][newc]= min(dist[newr][newc], 1+ dis); 
                    q.push({1+dis, {newr,newc}}); 
                }

            }
        }
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1; 
        }
        if(n==1) return 1; 
        if(dist[n-1][n-1]== INT_MAX){
            return -1; 
        }
        else{
            return dist[n-1][n-1]; 
        }
        
    }
};