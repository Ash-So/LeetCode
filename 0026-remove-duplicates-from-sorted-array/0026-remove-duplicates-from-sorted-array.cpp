class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Brute force : using set
        // TC: O(nlogn+n) nlogn for set  SC: O(n)
        // set<int> s;
        // for(int i=0;i<nums.size();i++){
        //     s.insert(nums[i]);
        // }
        // int index=0;
        // for(auto it:s){
        //     nums[index]=it;
        //     index++;
        // }
        // nums.erase(nums.begin()+s.size(),nums.end());
        // return nums.size();

        // Optimised : using 2 pointers
        // TC: O(n) SC: O(1)
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};