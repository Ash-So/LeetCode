class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>>let;
        vector<pair<string, string>>dig;
        for(auto i:logs){
             string f="";
             string s="";
             bool flag=false;
             for(int j=0;j<i.size();j++){
                 if(i[j]==' ' && flag==false){
                     flag=true;
                     continue;
                 }
                 if(flag==false) f+=i[j];
                 else s+=i[j]; 
            }
            if(s[0]>='a' && s[0]<='z') let.push_back({s,f});
            else dig.push_back({s,f});
        }
        sort(let.begin(), let.end());
        vector<string> ans;
        for(auto i :let){
            ans.push_back(i.second+" "+i.first);
        }
        for(auto i :dig){
            ans.push_back(i.second+" "+i.first);
        }
        return ans;
    }
};