#include <iostream>
#include <vector>
#include <set>
using namespace std;


int N,W;
vector<int> weight,value;
/*
    How Does This Function Works:
    In greedy method if there isn't any constraints , we would take all of all items
    so We will have to bruteforce over all possiblities as we have constraints on the total weight
    if idx = n then we don't have more elements to take so i have to check if i can store these items
    i would return the value of them , if i dont simply i will put very low value so i can get the maximum ones from other calls

    Rule : If you want to maximize and the combinarion we check isn't valid , we return minimum value
    Rule : If you want to minimize and the combinarion we check isn't valid , we return maximum value
*/

int rec(int idx,int myWeigh,int reward){
    if(idx==N){
        if(myWeigh<=W){
            return reward;
        }
        return 0;
    }

    int ch1 = rec(idx+1,myWeigh+weight[idx],reward+value[idx]); // Take
    int ch2 = rec(idx+1,myWeigh,reward); //leave;

    return max(ch1,ch2);
}
int main(){
    cin>>N>>W;
    weight= vector<int>(N);
    value= vector<int>(N);

    for(int i=0;i<N;i++){
        cin>>weight[i]>>value[i];
    }
    cout<<rec(0,0,0);
    return 0;
}