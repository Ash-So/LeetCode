class Solution {
public:
    int partitionString(string s) {
        //  TC: O(n)  SC: O(1)
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