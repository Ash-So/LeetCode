class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        // data structure to store forbidden words
        int maxLen = 0;
        unordered_set<string> set;
        for(auto s : forbidden){
            set.insert(s);
            maxLen=max(maxLen, (int)s.size());
        }

        // sliding window
        int ans = 0;
        int l = 0, r = 0;
        int n = word.size();
        while( r < n ){
            string temp ="";
            for(int i = r; (i >= l) && (i > r-maxLen); i-- ){
                temp = word[i] + temp;
                if( set.count(temp) ){
                    l=i+1;
                    break;
                }
            }
            r++;
            ans = max(ans, r-l);
        }
        return ans;
    }
};