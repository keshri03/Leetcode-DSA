class Solution {
public:
    double median(vector<int>&nums1,vector<int>&nums2){
        int n=nums1.size();
        int m=nums2.size();
        int req=(m+n)/2;
        if((m+n)%2==1) req++;
        int l=0,h=n;
        while(l<=h){
        
        int mid=(l+h)/2;
        // cout<<l<<" "<<h<<" "<<mid<<" "<<req<<endl;
        int l1,l2,r1,r2;
        int rem=(req-mid);
        if(mid==0) l1=INT_MIN;
        else l1=nums1[mid-1];
        if(rem==0) l2=INT_MIN;
        else l2=nums2[rem-1];
        if(mid+1>n) r1=INT_MAX;
        else r1=nums1[mid];
        if(rem+1>m) r2=INT_MAX;
        else r2=nums2[rem];
        // cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
        if(l1>r2){
            h=mid-1;
        }
        else if(l2>r1){
            l=mid+1;
        }
        else{
            if((m+n)%2==1){
                return max(l1,l2);
            }
            else return 1.0*((max(l1,l2)+min(r1,r2)))/2;
        }                   
        }
        return -1;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        if(n<=m){
            return median(nums1,nums2);
            
        }
        else{
            return median(nums2,nums1);
        }
    
    }
};