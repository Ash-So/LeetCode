class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int curr = 0;
        
        for(int i=0;i<nums.size();i++){
            curr += nums[i];
            prefixSum.push_back(curr);
        }
    }
    
    int sumRange(int left, int right) {
        int rightSum = prefixSum[right];
        int leftSum = (left > 0) ? prefixSum[left-1] : 0; 
        
        return rightSum - leftSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */