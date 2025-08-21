#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        int n=asteroids.size();
        for (int i=0;i<n;i++) {
            bool destroyed = false;

            while (!stack.empty() && asteroids[i] < 0 && stack.back() > 0) {
                if (stack.back() < -asteroids[i]) {
                    stack.pop_back(); // Right-moving asteroid is smaller, destroy it
                } 
                else if (stack.back() == -asteroids[i]) {
                    stack.pop_back(); // Both are equal, destroy both
                    destroyed = true;
                    break;
                } 
                else {
                    // Right-moving asteroid is larger, destroy incoming left-moving one
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) {
                stack.push_back(asteroids[i]);
            }
        }

        return stack;
    }