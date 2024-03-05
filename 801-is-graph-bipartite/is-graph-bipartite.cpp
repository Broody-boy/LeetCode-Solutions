class Solution {
public:

    bool isBipartite(vector<vector<int>>& adj) {

        int n = adj.size();

        vector<int> vis(n,0);
        vector<int> color(n, -1);
        queue<int> q;

        for(int node = 0; node < n; node++){

            if(vis[node]) continue;   //This is for disconnected components

            q.push(node);
            color[node] = 0;           //We start from color 0. Color oscillates between 0 and 1
            vis[node] = 1;

            while(!q.empty()){
                int front = q.front();
                q.pop();
                int alternateColor = !color[front];

                for(auto neighbor : adj[front]){
                    if(!vis[neighbor]){
                        vis[neighbor] = 1;
                        color[neighbor] = alternateColor;
                        q.push(neighbor);
                    }else{ //already visited
                        if(color[neighbor] != alternateColor) return false;
                    }
                }
            }
        }

        return true;

    }
};

//another way(Maddy's way):
// vis[node] -> -1 (not visited)
// vis[node] -> 0 (visited and red)
// vis[node] -> 1 (visited and blue)