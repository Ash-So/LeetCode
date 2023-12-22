class Solution {
public:
    void generate(int n, int open, int close, string s, vector<string>& result){
        if(open == n && close == n){
            result.push_back(s);
            return;
        }
        if(open < n){
            generate(n, open+1, close, s+'(', result);
        }
        if(open > close){
            generate(n, open, close+1, s+')', result);
        }
    }
    vector<string> generateParenthesis(int n) {
//         TC: O(2^n)  SC: O(n)
        vector<string> result;
        
        generate(n,0,0,"",result);
        return result;
    }
};