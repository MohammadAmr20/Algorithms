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
        void printLeavesInOrderFashion(node* subRoot){
            if(!subRoot)
                return;
            printLeavesInOrderFashion(subRoot->left);
            if(!(subRoot->left || subRoot->right))
                cout<<subRoot->data<<' ';
            printLeavesInOrderFashion(subRoot->right);
        }
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
        void printPerimeterNodes(){
            node* ptr = root;
            while(ptr){
                if(ptr->left || ptr->right)
                    cout<<ptr->data<<' ';
                if(ptr->left)
                    ptr = ptr->left;
                else if(ptr->right)
                    ptr = ptr->right;
                else    
                    ptr = nullptr;
            }
            printLeavesInOrderFashion(root);
            stack<int> rev;
            ptr = root;
            while(ptr){
                if(ptr->left || ptr->right)
                    if(ptr != root)
                        rev.push(ptr->data);
                if(ptr->right)
                    ptr = ptr->right;
                else if(ptr->left)
                    ptr = ptr->right;
                else    
                    ptr = nullptr;
            }
            while(!rev.empty()){
                cout<<rev.top()<<' ';
                rev.pop();
            }
        }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto&e:arr)
        cin>>e;
    BST tree;
    for(auto&e:arr)
        tree.Insert(e);
    tree.printPerimeterNodes();
    cout<<'\n';
    return 0;
}