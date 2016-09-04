#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    int n = 0;
    cin>>n;
    int **rectangle = new int*[n];
    int **colSum = new int*[n];
    int num = 0;
    for(int i = 0; i < n; ++i) {
        rectangle[i] = new int[n];
        colSum[i] = new int[n];
        for(int j = 0; j < n; ++j) {
            cin>>num;
            rectangle[i][j] = num;
            colSum[i][j] = i==0?num:colSum[i-1][j]+num;
        }
    }

    int col = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            sum = 0;
            for(int k = 0; k < n; ++k) {
                col = (i==0?colSum[j][k]:(colSum[j][k] - colSum[i-1][k]));
                sum += col;
                if(sum<0) sum = max(sum, col);
                maxSum = max(sum, maxSum);
            }
            
        }
    }
    
    cout<<maxSum<<endl;
    
    return 0;
}