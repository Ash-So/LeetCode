class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp; // val -> index
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int compliment = target - nums[i];
            if (mp.find(compliment) != mp.end()) {
                // return {mp[compliment], i};
                ans.push_back(mp[compliment]);
                ans.push_back(i);
            }
            mp.insert({nums[i], i});
        }
        return ans;
    }
};
