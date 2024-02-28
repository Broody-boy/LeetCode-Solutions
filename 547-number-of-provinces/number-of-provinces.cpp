class Solution {
public:

    int countProvince(vector<int> adj[], int n){

        vector<int> visited(n, 0);
        queue<int> q;
        int provinces = 0;

        for(int num = 0; num < n; num++){   //Scan all nodes

            if(!visited[num]){
                provinces++;

                //BFS
                q.push(num);
                visited[num] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    for(auto neighbor : adj[node]){
                        if(!visited[neighbor]){
                            q.push(neighbor);
                            visited[neighbor] = 1;
                        }
                    }
                }

            }
        }

        return provinces;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(isConnected[i][j]) adj[i].push_back(j);
        
        return countProvince(adj, n);
    }
};