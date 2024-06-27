class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>edge1 = edges[0];
        vector<int>edge2 = edges[1];

        if(edge1[0] == edge2[0]) return edge1[0];
        if(edge1[0] == edge2[1]) return edge1[0];
        if(edge1[1] == edge2[0]) return edge1[1];
        if(edge1[1] == edge2[1]) return edge1[1];

        return -1;
    }
};