class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for(auto pair : prerequisites){
            adj[pair[1]].push_back(pair[0]);
        }

        vector<int> inDegree(numCourses);
        for(int node = 0; node < numCourses; node++){
            for(int recipient : adj[node]){
                inDegree[recipient]++;
            }
        }

        queue<int> q;
        for(int node = 0; node < numCourses; node++){
            if(inDegree[node]==0) q.push(node);
        }

        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(int neighbor : adj[front]){
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) q.push(neighbor);
            }

        }

        vector<int> empty;
        return (ans.size() != numCourses) ? empty : ans;
    }
};