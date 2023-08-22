class Solution {
public:
    int mod=1e9+7;
    int dp[23][2][2][230];
    int helper(int pos,int tight1, int tight2, string &a, string &b,int sum, int min_sum, int max_sum){
        if(pos==a.size()){
            if(sum>=min_sum && sum<=max_sum) return 1;
            return 0;
        }
        if(dp[pos][tight1][tight2][sum]!=-1) return dp[pos][tight1][tight2][sum];
        int mini,maxi;
        if(tight1) mini=a[pos]-'0';
        else mini=0;
        if(tight2) maxi=b[pos]-'0';
        else maxi=9;
        int ans=0;
        for(int i=mini;i<=maxi;i++){
            int newtight1=tight1 && (i==(a[pos]-'0'));
            int newtight2=tight2 && (i==(b[pos]-'0'));
            ans=(ans+helper(pos+1,newtight1,newtight2,a,b,sum+i,min_sum,max_sum)%mod)%mod;
        }
        return dp[pos][tight1][tight2][sum]=ans;

    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int len=num2.size();
        reverse(num1.begin(),num1.end());
        while(num1.size()<num2.size()) num1.push_back('0');
        reverse(num1.begin(),num1.end());
        memset(dp,-1,sizeof(dp));
        return helper(0,1,1,num1,num2,0,min_sum,max_sum);

        
    }
};