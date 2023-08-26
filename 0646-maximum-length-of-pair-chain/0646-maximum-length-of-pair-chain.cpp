class Solution {
public:
    int dp[1001];
    int helper(int i, vector<vector<int>>&pairs,int last){
        if(i>=pairs.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        vector<int>temp={pairs[i][1]+1,-1001};
        auto it=lower_bound(pairs.begin()+i,pairs.end(),temp)-pairs.begin();
        int take=1+helper(it,pairs,pairs[i][1]);
        int not_take=helper(i+1,pairs,last);
        return dp[i]=max(take,not_take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());
        return helper(0,pairs,-1001);
        
    }
};