// Online C compiler to run C program online
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<string> board;
    vector<bool> leftDia;
    vector<bool> rightDia;
    vector<bool> col;
    
    bool isSafe(int r,int c, int n){
        bool isCol = col[c];
        bool isLD = leftDia[(r-c) + (n - 1)];
        bool isRD = rightDia[r+c];
        if( !isCol && !isLD && !isRD){
            return true;
        }
        return false;
    }
    bool solve(int row, int n){
        if(row == n){
            return true;
        }
        for(int c=0;c<n;c++){
            
            if(isSafe(row,c,n)){
                board[row][c] = 'Q';
                col[c] = true;
                leftDia[(row-c) + (n - 1)] = true;
                rightDia[row+c] = true;
                
                if(solve(row+1,n)) return true;
                
                board[row][c] = '.';
                col[c] = false;
                leftDia[(row-c) + (n - 1)] = false;
                rightDia[row+c] = false;
                
            }
            
        }
        return false;
    }
    
    void marker(int n){
        board = vector<string>(n,string(n,'.'));
        col = vector<bool>(n,false);
        int dSize = 2*n -1;
        leftDia = vector<bool>(dSize,false);
        rightDia = vector<bool>(dSize,false);
        
        
        solve(0,n);
    }
};

int main() {
    // Write C code here
    Solution s;
    s.marker(4);
    for (int i=0;i<s.board.size();i++){
        cout<<s.board[i]<<endl;
    }
    return 0;
}