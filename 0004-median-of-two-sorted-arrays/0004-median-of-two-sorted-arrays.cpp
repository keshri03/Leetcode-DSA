class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int tot=nums1.size()+nums2.size();
        int count=0;
        double ans=0;
        while(i<=nums1.size() || j<=nums2.size()){

            if(i<nums1.size() && j<nums2.size()){
                if(nums1[i]<=nums2[j]){
                    count++;
                    if(count==(tot/2)){
                        if(tot%2==0){
                            ans+=nums1[i];
                        }
                    }
                    if(count==(tot/2)+1){
                        if(tot%2==0){
                            ans=(ans+nums1[i])*1.0/2;
                        }
                        else ans+=nums1[i];
                        break;
                    }
                    i++;
                }
                else{
                    count++;
                    if(count==(tot/2)){
                        if(tot%2==0){
                            ans+=nums2[j];
                        }
                    }
                    if(count==(tot/2)+1){
                        if(tot%2==0){
                            ans=(ans+nums2[j])*1.0/2;
                        }
                        else ans+=nums2[j];
                        break;
                    }
                    j++;
                }
            }
            else if(i<nums1.size()){
                count++;
                    if(count==(tot/2)){
                        if(tot%2==0){
                            ans+=nums1[i];
                        }
                    }
                    if(count==(tot/2)+1){
                        if(tot%2==0){
                            ans=(ans+nums1[i])*1.0/2;
                        }
                        else ans+=nums1[i];
                        break;
                    }
                    i++;

            }
            else{
                count++;
                    if(count==(tot/2)){
                        if(tot%2==0){
                            ans+=nums2[j];
                        }
                    }
                    if(count==(tot/2)+1){
                        if(tot%2==0){
                            ans=(ans+nums2[j])*1.0/2;
                        }
                        else ans+=nums2[j];
                        break;
                    }
                    j++;

            }
        }
        return ans;
        
    }
};