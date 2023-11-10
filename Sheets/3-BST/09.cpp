#include<bits/stdc++.h>
using namespace std;
#define OO INT_MAX 

struct node{
    int data;
    node* left;
    node* right;
    node* parent;

    node(int d ,  node* p = nullptr , node* l = nullptr , node* r = nullptr ){
        data = d;
        left = l;
        parent = p;
        right = r;
    }
};

class BST{
    private:
        node* root;

    public:
        BST(){
            root = nullptr;
        }
        
        void Insert(int d){
            if(!root){
                root = new node(d);
                return;
            }
            node* ptr = root;
            while(ptr){
                if(d >= ptr->data ){
                    if(!ptr->right){
                        ptr->right = new node(d,ptr);
                        break;
                    }
                    ptr = ptr->right;
                }
                else{
                    if(!ptr->left){
                        ptr->left = new node(d,ptr);
                        break;
                    }
                    ptr = ptr->left;
                }
            }
            
        }
        //TODO : Given a binary tree, compute (sum of values at odd heights) - (sum of values at even height).
        //Explaination: Since we care about the height of each node , the BFS will be perfect for it as we keep tracking of the depth of each node
        //Using Queue of pairs of nodes and their heights. initialize the height of root with 0
       int computeDifferenceBetweenSums(){
            if(!root)
                return 0;
            int oddHeight = 0  , evenHeight = 0;
            node* ptr = root;
            queue<pair<node*,int>> queueBFS;
            queueBFS.push({root,0});
            //Process Of BFS
            while(!queueBFS.empty()){
                pair<node*,int> p = queueBFS.front();

                //If there childs in right or left , we push them in queue
                //the height of child = the height of parent + 1
                if(p.first->left)
                    queueBFS.push({p.first->left,p.second+1});
                if(p.first->right)
                    queueBFS.push({p.first->right,p.second+1});
                evenHeight += (p.second&1^1) * (p.first->data);
                oddHeight += (p.second&1) * (p.first->data);
                queueBFS.pop();
            }
            return oddHeight - evenHeight ;
       }
};

int main(){
    vector<int> arr={7,3,2,5,9,10,8};
    BST tree;
    for(auto&e:arr)
        tree.Insert(e);
    cout<<tree.computeDifferenceBetweenSums();
    cout<<'\n';
    return 0;
}