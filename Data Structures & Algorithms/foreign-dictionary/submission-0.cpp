class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for(string &word : words){
            for(char c : word){
                indegree[c] = 0;
            }
        }

        for(int i = 0; i<words.size()-1; i++){
            string u = words[i];
            string v = words[i+1];

            int len = min(u.size(), v.size());
            int j = 0;

            while(j<len&&u[j]==v[j]){
                j++;
            }

            if(u.size()>v.size()&&j==len){
                return "";
            }

            if(j<len){
                char a = u[j];
                char b = v[j];

                if(adj[a].insert(b).second){
                    indegree[b]++;
                }
            }
        }

        queue<char> q;

        for(auto &entry : indegree){
            if(entry.second==0){
                q.push(entry.first);
            }
        }
        
        string order = "";
        while(!q.empty()){
            char c = q.front();
            q.pop();

            order += c;

            for(char ch : adj[c]){
                indegree[ch]--;

                if(indegree[ch]==0){
                    q.push(ch);
                }
            }
        }

        if(order.size()!=indegree.size()) return "";

        return order;
    }
};
