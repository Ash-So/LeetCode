class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans=keysPressed[0];
        int t=releaseTimes[0];
        for(int i=1;i<keysPressed.size();i++){
            int d=releaseTimes[i]-releaseTimes[i-1];
            if(d==t) ans=max(ans,keysPressed[i]);
            if(d>t) {
                ans=keysPressed[i];
                t=d;
            }
        }
        return ans;
    }
};