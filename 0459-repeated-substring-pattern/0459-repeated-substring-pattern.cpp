class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        if(s.size()==1) return false;
        int len=s.size();
        for(int i=0;i<len-1;i++){
            string comp=s.substr(0,i+1);
            int rem=len-(i+1);
            if((rem%(i+1))!=0) continue;
            int j=0;
            int k=0;
            int flag=0;
            while(j<len){
                if(s[j]!=comp[k]){
                    flag=1;
                    break;
                }
                j++;
                k++;
                if(k==comp.size()){
                    k=0;
                }
            
            }
            if(j==len) return true;
            continue;     
        }
        return false;
        
    }
};