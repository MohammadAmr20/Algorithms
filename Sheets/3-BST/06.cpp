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
        right = r;
        parent = p;
    }
};

class BST{
    private:
        node* root;

        // TODO : Given a BST and two values v1 and v2, return all nodes that are between these two values (inclusive).
        // Just Apply InOrder Traversal and in root of subtree ask if the value satisfies the condition or not
        void recGetNodesInRange(int value1 , int value2 , node* ptr , vector<int>& answer){
            if(!ptr)
                return;
            recGetNodesInRange(value1,value2,ptr->left,answer);
            if(ptr->data >= value1 && ptr->data <= value2)
                answer.push_back(ptr->data);
            recGetNodesInRange(value1,value2,ptr->right,answer);
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

       
        // TODO : Given a BST and two values v1 and v2, return all nodes that are between these two values (inclusive).
        vector<int> getNodesInRange(int value1 , int value2){
            vector<int> answer;
            recGetNodesInRange(value1 , value2 ,root,answer);
            return answer;
        }
};

int main(){
    vector<int> arr={7,3,2,5,9,10,8};
    BST tree;
    for(auto&e:arr)
        tree.Insert(e);
    int value1 , value2;
    cin>>value1>>value2;
    vector<int> values = tree.getNodesInRange(value1,value2);
    for(auto&e:values)
        cout<<e<<' ';
    cout<<'\n';
    return 0;
}