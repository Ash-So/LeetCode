class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
//         TC: O(n)   SC: O(1)
        vector<int> result;
        int i = 0, j = numbers.size()-1;
        
        while(i<j){
            int sum = numbers[i] + numbers[j];
            if(sum<target) i++;
            else if(sum>target) j--;
            else{
                result.push_back(i+1);
                result.push_back(j+1);
                break;
            }
        }
        return result;
    }
};