class Twitter {
private:
    int time;
    unordered_map<int,vector<pair<int , int>>>tweetsMap; 
    unordered_map<int , unordered_set<int>> followMap;
public:

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsMap[userId].push_back({time++ , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>> q ;
        for(const auto& tweet :tweetsMap[userId]){
            q.push(tweet);
        }
        for(int followeeId : followMap[userId]){
            for(const auto&tweet : tweetsMap[followeeId]){
                q.push(tweet);
            }
        }
        while(!q.empty() && res.size() < 10){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followMap[followerId].erase(followeeId);
        }
    }
};
