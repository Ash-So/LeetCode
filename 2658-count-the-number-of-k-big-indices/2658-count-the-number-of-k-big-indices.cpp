class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        int count = 0;
        int n=nums.size();
        
        priority_queue<int> maxH;

        // left cond
        vector<bool> left(n, 0);
        for(int i=0;i<n;i++){
            if((maxH.size()) == k && maxH.top() < nums[i]){
                left[i]=true;
            }
            maxH.push(nums[i]);
            if( maxH.size() > k ) maxH.pop();
        }

        while(!maxH.empty()){
            maxH.pop();
        }

        // right cond
        vector<bool> right(n, 0);
        for(int i=n-1;i>=0;i--){
            if((maxH.size()) == k && maxH.top() < nums[i] && left[i]){
                count++;
            }
            maxH.push(nums[i]);
            if( maxH.size() > k ) maxH.pop();
        }
        return count;
    }
};