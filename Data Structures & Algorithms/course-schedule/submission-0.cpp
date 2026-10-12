class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i<numCourses; i++){
            for(int c : adj[i]){
                indegree[c]++;
            }
        }
        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int nodes = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            nodes++;
            for(int c : adj[node]){
                indegree[c]--;
                if(indegree[c]==0){
                    q.push(c);
                }
            }
        }
        if(nodes==numCourses){
            return true;
        }
        return false;
    }
};
