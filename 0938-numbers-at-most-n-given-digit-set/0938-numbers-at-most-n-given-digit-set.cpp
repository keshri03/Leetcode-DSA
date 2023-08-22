class Solution {
public:
    int dp[10][2][2];
    int func(int pos, string &s,int tight, vector<string>digits,int nonzero){
        if(pos==s.size()) return 1;
        if(dp[pos][tight][nonzero]!=-1) return dp[pos][tight][nonzero];
        int ans=0;
        if(tight){
            for(int i=0;i<digits.size();i++){
                int num=stoi(digits[i]);
                if(num==0){
                    if(nonzero==0){
                        ans+=func(pos+1,s,0,digits,nonzero);
                    }
                    continue;

                }
                if(num<(s[pos]-'0')){
                    ans+=func(pos+1,s,0,digits,1);
                }
                else if(num==(s[pos]-'0')){
                    ans+=func(pos+1,s,1,digits,1);
                }
            }
           
            return dp[pos][tight][nonzero]=ans;
        }
        for(int i=0;i<digits.size();i++){ 
            int num=stoi(digits[i]);
            if(num==0){
                if(nonzero==0){
                    ans+=func(pos+1,s,0,digits,0);
                }
                continue;
            }            
            ans+=func(pos+1,s,0,digits,1);              
        }
        return dp[pos][tight][nonzero]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        reverse(digits.begin(),digits.end());
        digits.push_back("0");
        reverse(digits.begin(),digits.end());
        return func(0,s,1,digits,0)-1;
        
    }
};