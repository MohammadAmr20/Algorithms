#include<bits/stdc++.h>
using namespace std;

/*
    Submission Link Of This Problem : https://leetcode.com/problems/n-queens/description/
*/


// Direction Array for traversing in the 8 directions 

const int drow[8] = { -1,0,1,0,-1,1,1,-1 };
const int dcol[8] = { 0,1,0,-1,1,1,-1,-1 };




vector<string> back;
vector<vector<string>> ans;

bool isValid(int row, int col, int n) {
    return (row>=0 && row < n && col>=0 && col < n);
}

/*
    How Does This function work

    Simply we iterate on our 8 prewritten directions until the cell we test isn't in our grid.
    if the Cell has Queen we return false
    if we finished traversing without finding Queen , This place will be valid  ,Thus we return true.
*/

bool checkNeighbours(int row, int col, int n) {
    for (int k = 0; k < 8; k++) {
        int newRow = row + drow[k], newCol = col + dcol[k];
        while (isValid(newRow, newCol, n)) {
            if (back[newRow][newCol] == 'Q')
                return false;
            newRow += drow[k];
            newCol += dcol[k];
        }
    }
    return true;
}

/*
    How does This function work

    In a very general case it checks if the neighbour cells contains queen or not,If there is a queen , 
    This cell would be invalid to put queen on it . It will check the next Columns
    If it finds a valid cell on the same row, it will call a recursive call with the next row . If not ,
    we will backtrack to the previous row to check another columns.

    A Solution will be Valid if we place all queens and reached row == n so in this case we push our grid in the final answer.
*/

void queenBackTrack(int n, int row = 0, int col = 0) {
    if (row == n) {
        ans.push_back(back);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (checkNeighbours(row, i, n)) {
            //Transition Of our function is to put queen or not.
            back[row][i] = 'Q';
            // Recursive Call to check the next Row
            queenBackTrack(n,row + 1);
            // BackTrack To find New Solutions
            back[row][i] = '.';
        }
    }
}

void solve(int j) {
    int n;
    cin >> n;
    string row;
    
    //Initializing the row with n empty cell
    for (int i = 0; i < n; i++)
        row += '.';
    
    //Initializing the grid with n empty rows
    for (int i = 0; i < n; i++)
        back.push_back(row);

    // The Result now is n*n empty cells so we can now start our call

    queenBackTrack(n);

    //Printing the answers
    for (auto&mat : ans) {
        cout << "\n----------------------------------\n";
        for (auto&str : mat)
            cout << str << '\n';
        cout << "\n----------------------------------\n";
    }
}


int main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}

