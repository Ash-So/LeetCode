class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        vector<int> answer;
        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            answer.push_back(prod);
        }
        prod=1;
        for(int i=(nums.size())-1;i>0;i--){
            answer[i]=answer[i-1]*prod;
            prod*=nums[i];
        }
        answer[0]=prod;
        return answer;
    }
};