class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_map<int,int>>adj(n);
        int maxi=0;
        vector<int>outdegree(n,0);
        for(auto &it: roads){
            adj[it[0]][it[1]]=1;
            adj[it[1]][it[0]]=1;
            outdegree[it[0]]++;
            outdegree[it[1]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=outdegree[i]+outdegree[j];
                if(adj[i].find(j)==adj[i].end()){
                    ans=max(ans,temp);
                }
                else ans=max(ans,temp-1);
            }
        }
        return ans;
        
        
    }
};