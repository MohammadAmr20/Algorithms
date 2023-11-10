#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>&arr,int n){
    for(int i = 1 ; i < n ; i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(auto&e:arr)
        cin>>e;
    InsertionSort(arr,n);
    return 0;
}