class Solution {
public:
    int dp[101][101][201];
    int helper(int i, int j, int k,string &s1, string &s2, string &s3){
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            return 1;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=0;
        if(i<s1.size() && s1[i]==s3[k]){
            ans=ans| helper(i+1,j,k+1,s1,s2,s3);
        }
        if(j<s2.size() && s2[j]==s3[k]){
            ans=ans| helper(i,j+1,k+1,s1,s2,s3);
        }
        return dp[i][j][k]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int i=0,j=0,k=0;
        if(s1.size()+s2.size()!=s3.size()) return false;
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,s1,s2,s3);
        
    }
};