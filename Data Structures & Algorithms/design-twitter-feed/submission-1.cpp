class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int timestamp = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> pq;

        if(!tweets[userId].empty()){
            int i = tweets[userId].size()-1;
            auto t = tweets[userId][i];
            pq.push({t.first, t.second, userId, i});
        }

        for(int followee : following[userId]){
            if(!tweets[followee].empty()){
                int i = tweets[followee].size()-1;
                auto t = tweets[followee][i];
                pq.push({t.first, t.second, followee, i});
            }
        }

        vector<int> feed;
        while(!pq.empty()&&feed.size()<10){
            auto [time, tweetId, uid, index] = pq.top();
            pq.pop();

            feed.push_back(tweetId);

            if(index>0){
                auto t = tweets[uid][index-1];
                pq.push({t.first, t.second, uid, index-1});
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            following[followerId].erase(followeeId);
        }
    }
};
