class Solution {
public:

int countp(vector<int>& nums, int p){
    int s = 1;
    long long ps = 0;
    for(int i =0;i<nums.size();i++){
        if(ps+nums[i]<=p){
            ps += nums[i];
        }
        else{
            s += 1;
            ps = nums[i];
        }
    }
    return s;
}

int findp(vector<int>& nums, int n, int m){
    if(m>n) return -1;
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        int s = countp(nums,mid);
        if(s>m){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
    int splitArray(vector<int>& nums, int k) {
        return findp(nums,nums.size(),k);
        
    }
};