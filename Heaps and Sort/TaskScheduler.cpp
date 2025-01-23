#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> m;
    for (char task : tasks) {
        m[task]++;
    }

    // Max heap to store tasks based on their frequency
    priority_queue<int> pq;
    for (auto& entry : m) {
        pq.push(entry.second);
    }

    int time = 0;
    while (!pq.empty()) {
        vector<int> temp;
        int k = n + 1; // We can schedule n + 1 tasks in one cycle, the task itself and n other tasks

        //pop out that k tasks that we can schedule
        while (k > 0 && !pq.empty()) {
            temp.push_back(pq.top());
            pq.pop();
            k--;
        }

        // Process the tasks we can schedule in this cycle
        for (int count : temp) {
            if (--count > 0) {
                pq.push(count); // If there are remaining tasks, push back to the queue
            }
        }

       // If the queue is empty, we can just add the number of tasks we processed
        if(pq.empty()){
            time +=temp.size(); 
        } 
        else{ // If the queue is not empty, we need to wait for the next cycle
            time+=n+1;
        }
          
    }

    return time;
}    


int main(){
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout<<leastInterval(tasks,n);
}