class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
//          TC: O(n)  SC: O(n)
        int n =  temperatures.size();
        vector<int> result(n);
        stack<pair<int, int>> s;
        
        for(int i=0;i<n;i++){
            int currDay = i;
            int currTemp =  temperatures[i];
            
            while(!s.empty() && s.top().second < currTemp){
                int prevDay = s.top().first;
                int prevTemp = s.top().second;
                s.pop();
                
                result[prevDay] = currDay - prevDay;
            }
            s.push({currDay, currTemp});
        }
        return result;
    }
};