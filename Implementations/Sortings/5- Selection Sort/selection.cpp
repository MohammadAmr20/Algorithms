#include <iostream>
#include<vector>
using namespace std;

void SelectionSort(vector<int>&A,int n){
    for(int i = 0 ; i < n ; i++){
        int minimum = i;
        for(int j = i+1 ; j< n ; j++){
            if(A[j] < A[minimum])
                minimum = j;
        }
        swap(A[i],A[minimum]);
    }
}

int main(){
    int n ;
    cin>>n;
    vector<int> A(n);
    for(auto&e:A)
        cin>>e;
    SelectionSort(A,n);
    for(auto&e:A)
        cout<<e<<' ';
    return 0;
}