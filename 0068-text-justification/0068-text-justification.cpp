class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        vector<string>temp;
        int j=0;
        int rem=maxWidth;
        while(j<=words.size()){
            // cout<<j<<" "<<rem<<endl;
            if(j==words.size()){
                cout<<ans.size()<<endl;
                // for(auto &it: ans) cout<<it<<" ";
                // cout<<endl;
                string s="";
                for(auto &it: temp){
                    s+=it;
                    s+=" ";                   
                }
                if(s.size()>maxWidth) s.pop_back();
                while(s.size()<maxWidth) s.push_back(' ');
                ans.push_back(s);
                j++;
            }
            else{
               
                if(rem>=(int)words[j].size()){
                    //  cout<<j<<" "<<rem<<endl;

                    rem-=(int)words[j].size();
                    rem--;
                    temp.push_back(words[j++]);
                }
                else{
                    // cout<<j<<" "<<rem<<endl;
                    if(temp.size()==1){
                        string s=temp[0];
                        while(s.size()<maxWidth) s.push_back(' ');
                        ans.push_back(s);
                        temp.clear();
                        rem=maxWidth;
                    }
                    else{
                        cout<<j<<" "<<rem<<endl;
                        int space=rem+(int)temp.size();
                        int q=(space)/((int)temp.size()-1);
                        int remi=space%((int)temp.size()-1);
                        // cout<<q<<" "<<remi<<endl;
                        string s="";
                        for(int i=0;i<temp.size();i++){
                            if(i!=(temp.size()-1)){
                                s+=temp[i];
                                int z=q;
                                while(z>0){
                                    s+=" ";
                                    z--;
                                }
                                if(remi>0){
                                    s+=" ";
                                    remi--;
                                }
                            }
                            else s+=temp[i];
                        }
                        rem=maxWidth;
                        temp.clear();
                        ans.push_back(s);

                    }
                }
            }
        }
        return ans;
    }
};