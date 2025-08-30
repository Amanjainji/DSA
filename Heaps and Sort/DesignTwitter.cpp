#include<bits/stdc++.h>
using namespace std;

class tweet{
public:
    int id;     // tweet ID
    int count;  // global order (like timestamp)

    tweet(int id,int count){
        this->id=id;
        this->count=count;
    }
};

//Comparator for Min-Heap
class comp{
public:
    bool operator()(tweet*a,tweet*b){
         return a->count>b->count;
    }
};

class Twitter {
private:
    int count;  // acts like a global timestamp
public:
    unordered_map<int,vector<tweet*>>Tweets;
    unordered_map<int,vector<int>>followers;
    Twitter() {
        this->count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet*t=new tweet(tweetId,count++);
        Tweets[userId].push_back(t);
        return ;
    }
    
    vector<int> getNewsFeed(int userId) {
    priority_queue<tweet*, vector<tweet*>, comp> pq;

    // Add user’s own tweets
    for(const auto &i:Tweets[userId]){
        pq.push(i);
        if(pq.size()>10) pq.pop();
    }

    // Add tweets from people user follows
    for(const auto &i:followers[userId]){
        for(auto j:Tweets[i]){
            pq.push(j);
            if(pq.size()>10) pq.pop();
        }
    }

    // Extract results (latest 10 tweets)
    vector<int> ans;
    while(!pq.empty()){
        tweet* t = pq.top();
        ans.push_back(t->id);
        pq.pop();
    }

    reverse(ans.begin(),ans.end()); // newest first, extracts tweet IDs in reverse order (latest → oldest).
    return ans;
    }

    //If followerId isn't already following followeeId, adds followeeId to the list.
    void follow(int followerId, int followeeId) {
        auto i=find(followers[followerId].begin(),followers[followerId].end(),followeeId);
        if(i==followers[followerId].end()) followers[followerId].push_back(followeeId);
        return ;
    }

    // If followerId is following followeeId, remove them.
    void unfollow(int followerId, int followeeId) {
        auto i=find(followers[followerId].begin(),followers[followerId].end(),followeeId);
        if(i!=followers[followerId].end()) followers[followerId].erase(i);
        return ;
    }
};

int main(){
    Twitter* obj = new Twitter();
    obj->postTweet(1, 5);         // user 1 posts tweet 5
    obj->postTweet(1, 3);         // user 1 posts tweet 3
    obj->postTweet(2, 101);       // user 2 posts tweet 101

    obj->follow(1, 2);            // user 1 follows user 2

    vector<int> feed = obj->getNewsFeed(1);
    for(auto i:feed)
        cout<<i<<endl;
    cout<<endl;
    obj->unfollow(1, 2);          // user 1 unfollows user 2
    feed = obj->getNewsFeed(1);
    for(auto i:feed)
        cout<<i<<endl;
}