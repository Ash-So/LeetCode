class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         TC: O(m*n*26)  SC:O(26*n) m: no. of input strings n:no. of letters in 1 input string
        unordered_map<string,vector<string>> m;

    for(int i=0;i<strs.size();i++){
        string key=getKey(strs[i]);
        m[key].push_back(strs[i]);
    }
    vector<vector<string>> result;
    for(auto it=m.begin();it != m.end(); it++){
        result.push_back(it->second);
    }
    return result;
    }
private:
    string getKey(string str){
        vector<int> count(26);
        for(int j=0;j<str.size();j++){
            count[str[j]-'a']++;
        }
        string key="";
        for(int i=0;i<count.size();i++){
            key.append(to_string(count[i])+'#');
        }
        return key;
    }
};