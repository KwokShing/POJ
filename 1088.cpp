#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int search(int x, int y, int **matrix, int **dp, const int &row, const int &col) {
        if(dp[x][y] > 0)
            return dp[x][y];
        int val = 1;
        if(x-1 >= 0 && matrix[x-1][y] < matrix[x][y])
            val = max( search(x-1, y, matrix , dp, row, col)+1, val);
        if(y-1 >= 0 && matrix[x][y-1] < matrix[x][y])
            val = max( search(x, y-1, matrix , dp, row, col)+1, val);
        if(x+1 < row  && matrix[x+1][y] < matrix[x][y])
            val = max( search(x+1, y, matrix , dp, row, col)+1, val);
        if(y+1 < col && matrix[x][y+1] < matrix[x][y])
            val = max( search(x, y+1, matrix, dp, row, col)+1, val);
        dp[x][y] = val;
        return val;
    
}

int main(int argc, const char * argv[]) {
    int r = 0, c = 0;
    cin>>r>>c;
    int **matrix = new int*[r];
    int **dp = new int*[r];
    for(int i = 0; i < r; ++i) {
        matrix[i] = new int[c];
        dp[i] = new int[c];
    }
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j) {
            int height = 0;
            cin>>height;
            matrix[i][j] = height;
            dp[i][j] = -1;
        }
    int res = 0;
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j) {
            res = max(res, search(i, j, matrix, dp, r, c));
        }
    cout<<res;
    return 0;
}