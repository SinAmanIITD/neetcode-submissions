class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(char task : tasks){
            freq[task-'A']++;
        }
        priority_queue<int> pq;
        for(int i = 0; i<26; i++){
            if(freq[i]>0) pq.push(freq[i]);
        }
        int interval = 0;
        while(!pq.empty()){
            vector<int> batch;
            int cycle = n+1;
            while(cycle>0&&!pq.empty()){
                int f = pq.top();
                pq.pop();
                if(f>1){
                    batch.push_back(f-1);
                }
                cycle--;
                interval++;
            }

            for(int f : batch){
                pq.push(f);
            }

            if(pq.empty()) break;

            interval += cycle;
        }
        return interval;
    }
};
