#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



    void createMap(Node* node,map<int,vector<Node*>> &mpp,unordered_map<int,bool> &vis){
        if(mpp.find(node->val)==mpp.end()){
            mpp[node->val]=node->neighbors;
            vis[node->val]=true;
        }
        //node->neighbors
        for(int i=0;i<node->neighbors.size();i++){
            vector<Node*> k=node->neighbors;
            if(!vis[k[i]->val]){
                createMap(k[i],mpp,vis);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        map<int,vector<Node*>> mpp;
        unordered_map<int,bool> vis;
        createMap(node,mpp,vis);
        vector<Node*> helper;
        for(auto i:mpp){
            Node* temp=new Node(i.first);
            helper.push_back(temp);
        }
        for(int i=0;i<helper.size();i++){
            vector<Node*> k=mpp[helper[i]->val];
            vector<Node*> temp;
            for(auto j:k){
                temp.push_back(helper[j->val-1]);
            }     
            helper[i]->neighbors=temp;
        }
        return helper[0];
    }

int main(){
    Node* root1=new Node(1);
    Node* root2=new Node(2);
    Node* root3=new Node(3);
    Node* root4=new Node(4);

    root1->neighbors={root2,root4};
    root2->neighbors={root1,root3};
    root3->neighbors={root2,root4};
    root4->neighbors={root1,root3};

    cloneGraph(root1);


}