#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int multiplication(int digitEnd, int baseEnd, int *digit, int *base, int *res) {
    int carry = 0;
    int cur = 0;
    int tmp[200] = {0};
    int k = 0;
    for(int j = 0; j < baseEnd; ++j) {
        k = j;
        carry = 0;
        for(int i = 0; i < digitEnd; ++i) {
            cur = base[j] * digit[i] + carry + tmp[k];
            carry = cur/10;
            tmp[k++] = cur%10;
        }
        if(carry)
            tmp[k] = carry;
    }
    if(carry)
        tmp[k++] = carry;
    for(int i = 0; i < k; ++i)
        res[i] = tmp[i];
    return k;
}

int main(int argc, const char * argv[]) {
    int n = 0;
    string s;
    int digit[200];
    //int base[6];
    while(cin>>s>>n) {
        memset(digit, 0, 200*sizeof(int));
        //memset(base, 0, 6*sizeof(int));
        
        int j = 0;
        int dot = -1;
        int baseEnd = 0;
        for(int i = s.size()-1; i >= 0; --i) {
            if(s[i] != '.') {
                digit[j] = s[i] - '0';
                //base[j] = digit[j];
                j++;
            }
            else {
                if(i == 0) {
                    digit[j] = 0;
                    //base[j] = 0;
                    j++;
                }
                dot = s.size() - i - 1;
            }
        }
        dot *= n;
        baseEnd = j;
        int res[200];
        memset(res, 0, 200*sizeof(int));
        res[0] = 1;
        int resEnd = 1;
        while(n) {
            if(n&1)
                resEnd = multiplication(baseEnd, resEnd, digit, res, res);
            baseEnd = multiplication(baseEnd, baseEnd, digit, digit, digit);
            n >>= 1;
        }
        bool t = false;
        for(int i = 0; i < resEnd; ++i)
            if(res[i]!=0) {
                t = true;
                break;
            }
        if(t) {
            int start = 0;
            bool flag = true;
            while(start < dot && res[start] == 0) {
                start++;
            }
            if(start >= dot)
                flag = false;
            int end = resEnd-1;
            while(end >= dot && res[end] == 0)
                end--;
            
            if(end+1 == dot)
                printf(".");
            for(int i = end; i >= start; --i) {
                printf("%d",res[i]);
                if(flag && i == dot)
                    printf(".");
            }
        }
        else {
            printf("0");
        }
        printf("\n");
    }
    
    return 0;
}