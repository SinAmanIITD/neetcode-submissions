class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto &[num, f] : freq){
            pq.push({f, num});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int val = it.second;
            ans.push_back(val);
        }
        return ans;
    }
};
