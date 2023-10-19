class Solution {
public:
    int uniqueLetterString(string s) {
        long long c=0;
        int n=s.size();
        vector<vector<int>> freq(26);

        for(int i=0;i<26;i++) freq[i].push_back(-1);
        for(int i=0;i<n;i++) freq[s[i]-'A'].push_back(i);
        for(int i=0;i<26;i++) freq[i].push_back(n);

        for(int i=0;i<26;i++){
            for(int j=1;j<freq[i].size()-1;j++){
                c+=(freq[i][j]-freq[i][j-1]) * (freq[i][j+1]-freq[i][j]);
            }
        }
        return c;
    }
};