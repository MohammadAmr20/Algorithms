#include <bits/stdc++.h>
using namespace std ;
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

        void recPreOrderFashionPrint(node* ptr){
            if(!ptr)
                return;
            cout<<ptr->data<<' ';
            recPreOrderFashionPrint(ptr->left);
            recPreOrderFashionPrint(ptr->right);
        }

        void recInOrderFashionPrint(node* ptr){
            if(!ptr)
                return;
            recInOrderFashionPrint(ptr->left);
            cout<<ptr->data<<' ';
            recInOrderFashionPrint(ptr->right);
        }

        void recPostOrderFashionPrint(node* ptr){
            if(!ptr)
                return;
            recPostOrderFashionPrint(ptr->left);
            recPostOrderFashionPrint(ptr->right);
            cout<<ptr->data<<' ';
        }

        node* recSearch(node* root , int d){
            if(!root)
                return root;
            if(root->data == d)
                return root;
            if(d>= root->data)
                return recSearch(root->right,d);
            return recSearch(root->left,d);
        }

        int getMaximumSubTree(node* subTree){
            int max = -OO;
            while(subTree){
                max = subTree->data;
                subTree = subTree->right;
            }
            return max;
        }

        int getMinimumSubTree(node* subTree){
            int min = OO;
            while(subTree){
                min = subTree->data;
                subTree = subTree->left;
            }
            return min;
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


        void preOrderFashionPrint(){
            recPreOrderFashionPrint(root);
            cout<<'\n';
        }

        void InOrderFashionPrint(){
            recInOrderFashionPrint(root);
            cout<<'\n';
        }

        void postOrderFashionPrint(){
            recPostOrderFashionPrint(root);
            cout<<'\n';
        }

        node* search(int d){
            return recSearch(root,d);
        }
        
        int getMaximum(){
            return getMaximumSubTree(root);
        }

        int getMinimum(){
            return getMinimumSubTree(root);
        }

        int getTreeSuccessor(int value){
            node* ptr = search(value);
            if(!ptr)
                return OO;
            if(ptr->right)
                return getMinimumSubTree(ptr->right);
            node* par = ptr->parent;
            while(par && ptr == par->right){
                ptr = par;
                par = par->parent;
            }
            if(!par)
                return OO;
            return par->data;
        }

        int getTreePredecessor(int value){
            node* ptr = search(value);
            if(!ptr || !ptr->left)
                return OO;
            ptr = ptr->left;
            if(ptr->right)
                return getMaximumSubTree(ptr);
            return ptr->data;
        }

};

int main(){
    BST myBST;
    vector<int> arr = {5,6,4,2,5};
    for(auto&e:arr)
        myBST.Insert(e);
    myBST.InOrderFashionPrint();
    myBST.preOrderFashionPrint();
    myBST.postOrderFashionPrint();
    cout<<myBST.search(5)->data<<'\n';
    cout<<myBST.getMinimum()<<' '<<myBST.getMaximum()<<'\n';
    cout<<myBST.getTreeSuccessor(5)<<'\n';
    cout<<myBST.getTreePredecessor(5)<<'\n';
    return 0;
}