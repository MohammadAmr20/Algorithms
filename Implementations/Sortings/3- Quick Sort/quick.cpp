#include <iostream>
#include<vector>
using namespace std;


    int Partition(vector<int>& A , int left , int right){
        int pivot = A[right];
        int i = left - 1;
        for(int j = left ; j < right ; j++){
            if(A[j]<=pivot){
                i++;
                swap(A[i],A[j]);
            }
        }
        i++;
        swap(A[i],A[right]);
        return i;
    }


    void QuickSort(vector<int>&A,int left,int right){
        if(left<right){
            int pivot = Partition(A,left,right);
            QuickSort(A,left,pivot-1);
            QuickSort(A,pivot,right);
        }
    }
int main(){
    int n ;
    cin>>n;
    vector<int> A(n);
    for(auto&e:A)
        cin>>e;
    QuickSort(A,0,n-1);
    for(auto&e:A)
        cout<<e<<' ';
    return 0;
}