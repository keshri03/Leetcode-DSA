class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            
                auto it=q.front();
                q.pop();
                int x=it[0];
                int y=it[1];
                if(x+1<n && dis[x+1][y]>1+dis[x][y]){
                    dis[x+1][y]=1+dis[x][y];
                    q.push({x+1,y});
                }
                if(y+1<m && dis[x][y+1]>1+dis[x][y]){
                    dis[x][y+1]=1+dis[x][y];
                    q.push({x,y+1});
                }
                if(x-1>=0 && dis[x-1][y]>1+dis[x][y]){
                    dis[x-1][y]=1+dis[x][y];
                    q.push({x-1,y});
                }
                if(y-1>=0 && dis[x][y-1]>1+dis[x][y]){
                    dis[x][y-1]=1+dis[x][y];
                    q.push({x,y-1});
                }

            
        }
        return dis;

        
    }
};