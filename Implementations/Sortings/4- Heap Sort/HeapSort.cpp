#include<iostream>
#include<vector>
using namespace std;
#define OO INT_MAX
#define Parent(i) (i-1)>>1
#define Left(i) (i<<1) + 1
#define Right(i) ((i+1)<<1) // L (i-1)/2 ]

void MaxHeapify(vector<int>& A , int parent){
    int l = Left(parent);
    int r = Right(parent);
    int largest = parent;
    if(l<A.size() && A[l] > A[largest])
        largest = l;
    if(r<A.size() && A[r] > A[largest])
        largest = r;
    if(largest ^ parent){
        swap(A[largest],A[parent]);
        MaxHeapify(A,largest);
    }    
}

void BuildMaxHeap(vector<int>&A){
    int lastElement = A.size()-1;
    for(int i = Parent(lastElement) ; i>-1 ; i--)
        MaxHeapify(A,i);
}



int main(){
    int n ;
    cin>>n;
    vector<int> A(n);
    for(auto&e:A)
        cin>>e;
    BuildMaxHeap(A);
    for(auto&e:A)
        cout<<e<<' ';
    return 0;
}