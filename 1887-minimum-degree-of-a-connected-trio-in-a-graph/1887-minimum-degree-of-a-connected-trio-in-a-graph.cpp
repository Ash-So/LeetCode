class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1, vector<int>(n+1,0)); 
        vector<int> degree(n+1,0);

        for(int i=0;i<edges.size();i++){
            vector<int> e=edges[i];
            adj[e[0]][e[1]]=1;
            adj[e[1]][e[0]]=1;

            degree[e[0]]++;
            degree[e[1]]++;
        }

        int res=INT_MAX;
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(adj[i][j]==1 && adj[j][k]==1 && adj[k][i]==1){
                        res=min(res,degree[i]+degree[j]+degree[k]-6);
                    }
                }
            }
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};