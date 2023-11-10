#include<iostream>
#include<vector>
using namespace std;
#define OO INT_MAX


void Merge(vector<int> & A , int l , int r , int mid){
    // We add Big Number in the end of array such that we don't deal with the case when any index is going
    // out of boundaries
    vector<int> L(mid - l + 2 , OO);
    vector<int> R(r - mid + 1 , OO);
    vector<int> mergedArray;
    for(int i = l ; i <= mid ; i++)
        L[i-l] = A[i];
    for(int i = mid+1 ; i <= r ; i++)
        R[i - mid - 1] = A[i];
    int i = 0 , j = 0;
    while(!(L[i] == OO && R[j] == OO)){
        mergedArray.push_back(min(L[i] , R[j]));
        (L[i] <= R[j]) ? i++ : j++ ;
    }
    for(int i = l ; i <= r ; i++)
        A[i] = mergedArray[i-l];
}

void MergeSort(vector<int> & A , int l , int r){
    if(l<r){
        int mid = l + (r-l) / 2;
        //Sort Left Part
        MergeSort(A , l , mid);
        //Sort Right Part
        MergeSort(A , mid+1 , r);
        //Merge Them
        Merge(A,l,r,mid);
    }
}

int main(){
    int n ;
    cin>>n;
    vector<int> A(n);
    for(auto&e:A)
        cin>>e;
    MergeSort(A,0,n-1);
    for(auto&e:A)
        cout<<e<<' ';
    return 0;
}