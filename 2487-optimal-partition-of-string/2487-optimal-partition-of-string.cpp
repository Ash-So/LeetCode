class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> set;
        int res=1;

        for(int i=0;i<s.size();i++){
            if(set.count(s[i])){
                res++;
                set.clear();
                set.insert(s[i]);
            }
            else set.insert(s[i]);
        }
        return res;
    }
};