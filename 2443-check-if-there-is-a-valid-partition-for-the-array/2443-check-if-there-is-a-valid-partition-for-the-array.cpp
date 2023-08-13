class Solution {
public:
    int dp[100004];
    int helper(int i, vector<int>&nums){
        if(i==nums.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        if(i+1<nums.size() && nums[i]==nums[i+1]){
            ans=ans| helper(i+2,nums);
            if(i+2<nums.size() && nums[i+2]==nums[i+1]){
                ans=ans|helper(i+3,nums);
            }
        }
        if(i+2<nums.size() && nums[i]==nums[i+1]-1 && nums[i+1]==nums[i+2]-1){
            ans=ans|helper(i+3,nums);
        }
        return dp[i]=ans;
     
    
        
    }
    bool validPartition(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,nums);
        if(ans) return true;
        return false;   
    }
};