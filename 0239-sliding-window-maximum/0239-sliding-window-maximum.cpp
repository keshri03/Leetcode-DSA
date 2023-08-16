class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && (i-dq.front())>=k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
            if((i+1)>=k){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};