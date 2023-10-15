#include<bits/stdc++.h>
using namespace std;

/*
    Submission Link Of This Problem : https://leetcode.com/problems/combination-sum/description/
*/


vector<vector<int>> answer;
vector<int> v;

/*
    How does this function works ?
    Due to the statement of this problem . We can take the same element infinte times. 
    So the recursive tree is divided to two decisions. We take the element and staying in the same index
    or if the sum reached target we skip the element and try another one.
*/
void recCombinationSum(vector<int>&candidates , int target , int i = 0 , int sum = 0){
    //Base Case
    if(sum >= target){
        if(sum == target)
            answer.push_back(v);
        return;
    }
    // We may also reach the bound of array and not getting an answer so we return from this state
    if(i == candidates.size())
        return;

    //Transition
    //Take Element

    sum += candidates[i];
    v.push_back(candidates[i]);
    recCombinationSum(candidates,target,i,sum);
    
    //Backtrack
    sum -= candidates[i];
    v.pop_back();

    //leave element
    
    recCombinationSum(candidates,target , i+1 , sum);
}

void solve(int j) {
    int n,target;
    cin >> n>>target;
    vector<int> candidates(n);
    for(auto&e:candidates)
        cin>>e;
    recCombinationSum(candidates,target);
    for(auto&v:answer){
        for(auto&e:v)
            cout<<e<<' ';
        cout<<'\n';
    }
}


int main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}

