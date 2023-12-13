class Solution {
public:
    bool isValid(string s) {
//         TC: O(n) SC: O(n)
        stack<char> st;
        unordered_map<char, char> mp={
            {')','('},
            {'}','{'},
            {']','['}
        };
        
        for(const auto& c:s){
            if(mp.find(c) != mp.end()){
                if(st.empty()) return false;
                if(st.top() != mp[c]) return false;
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        return st.empty();
    }
};