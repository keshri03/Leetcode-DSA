class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if(x==0 || nums.size()==1) return 0;
        
        set<int>s;
        int i=0;
        int j=x-1;
        int ans=1e9;
        while(j<nums.size()){
            auto it=s.lower_bound(nums[j]);
            if(it!=s.end()){
                ans=min(ans,(*it)-nums[j]);
            }
            if(it!=s.begin()){
                it--;
                ans=min(ans,nums[j]-(*it));
            }
            s.insert(nums[i++]);
            j++;
                  
        }
        return ans;
        
    }
};