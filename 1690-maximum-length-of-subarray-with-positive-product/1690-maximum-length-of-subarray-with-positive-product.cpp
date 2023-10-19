class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos=0, neg=0, ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) pos=neg=0;
            else if(nums[i]>0){
                pos++;
                if(neg!=0) neg++;
                ans=max(ans,pos);
            }
            else{
                swap(pos, neg);
                neg++;
                if(pos!=0){
                    pos++;
                    neg+1;
                }
                ans=max(ans, pos);   
            }
        }
        return ans;
    }
};