class Solution {
public:
    string reorganizeString(string s) {
        if(s.size()==1) return s;
        priority_queue<pair<int,char>>pq;
        vector<int>count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        string ans="";
        int maxi=0;
        for(int i=0;i<26;i++){
            if(count[i]>0){
                maxi=max(maxi,count[i]);
                pq.push({count[i],char(i+'a')});
            }
        }
        // cout<<maxi<<endl;
        if(pq.size()==1 || ((2*maxi-(int)s.size())>1)) return "";
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(ans.size()==0 || ans.back()!=it.second){
                // cout<<it.second<<endl;
                ans.push_back(it.second);
                it.first--;
                if(it.first>0) pq.push(it);
            }
            else{
                auto it2=pq.top();
                pq.pop();
               
                ans.push_back(it2.second);
                it2.first--;
                 
                if(it2.first>0){
                    pq.push(it2);
                }
                pq.push(it);

            }
        }
        return ans;
        
    }
};