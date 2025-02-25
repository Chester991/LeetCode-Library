class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int rows = wall.size();
        if(rows == 1){ // side case
            int coulumns = wall[0].size();
            if(coulumns == 1){
                return 1;
            }
            else{
                return 0;
            }
        }
        vector<vector<int>> ps(rows); // prefix sum array
        for (int i = 0; i < rows; i++) {
            int columns = wall[i].size();
            ps[i].resize(columns);
            ps[i][0] = wall[i][0];
            for (int j = 1; j < columns; j++) {
                ps[i][j] = ps[i][j - 1] + wall[i][j];
            }
        }
        unordered_map<int,int>mp;
        for(int i=0;i<rows;i++){
            int columns = wall[i].size();
            for(int j=0;j<columns;j++){
                mp[ps[i][j]]++;
            }
        }
        int mxfreq = 0;
        for(int i=0;i<rows;i++){
            int columns = wall[i].size();
            for(int j=0;j<columns-1;j++){
                if(mp[ps[i][j]] > mxfreq){
                    mxfreq = mp[ps[i][j]];
                }
            }
        }
        return rows - mxfreq;
    }
};