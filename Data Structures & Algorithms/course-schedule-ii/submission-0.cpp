class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> ans;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int c : adj[node]){
                indegree[c]--;
                if(indegree[c]==0){
                    q.push(c);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};
