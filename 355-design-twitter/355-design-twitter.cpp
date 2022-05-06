class Twitter {
public:
    
    map<int, set<int>> friendsMap;
    priority_queue<vector<int>> timeline;
    int time;
    
    Twitter() 
    {
        friendsMap.clear();
        time=0;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        timeline.push({time++, userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> feed;
        auto userTimeline = timeline;
        int n=0;
        
        while(!userTimeline.empty() && n<10)
        {
            auto topTweet = userTimeline.top();
            userTimeline.pop();
            
            if(topTweet[1]==userId || friendsMap[userId].count(topTweet[1]))
            {
                feed.push_back(topTweet[2]);
                n++;
            }
        }
        
     return feed;
    }
    
    void follow(int followerId, int followeeId) 
    {
        friendsMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        friendsMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */