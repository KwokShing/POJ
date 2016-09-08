#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool cmp(const int &a, const int &b) {
    return a>b;
}

bool dfs(int idx, int restLen, int target, vector<int> &v, vector<bool> &visit, int level, int &count) {
    if(restLen == 0) {
        count -= level;
        if(count == 0)
            return true;
        int i = 0;
        //find first not used stick
        while(visit[i])
            i++;
        visit[i] = true;
        if(dfs(i+1, target-v[i], target, v, visit, 1, count))
            return true;
        visit[i] = false;
        count += level;
    }
    else {
        for(int i = idx; i < v.size(); ++i) {
            if(i>0 && v[i]==v[i-1] && !visit[i-1])
                continue;
            if(!visit[i] && restLen >= v[i]) {
                visit[i] = true;
                if(dfs(i+1, restLen-v[i], target, v, visit, level+1, count))
                    return true;
                visit[i] = false;
                
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    int n = 0;
    int maxt = 0;
    int sum = 0;
    while((cin>>n) && n) {
        sum = 0;
        maxt = 0;
        vector<int> v;
        //vector<bool> visit(n);
        int nn = n;
        while(n--) {
            int stick = 0;
            cin>>stick;
            v.push_back(stick);
            maxt = max(maxt, stick);
            sum += stick;
        }
        sort(v.begin(), v.end(), cmp);
        //int count = visit.size();
        for(int i = maxt; i <= sum; ++i) {
            if(sum%i) continue;
            vector<bool> visit(nn);
            int count = visit.size();
            //cout<<i<<endl;
            if(dfs(0, i, i, v, visit, 0, count)) {
                cout<<i<<endl;
                break;
            }
        }
        
    }
    
    return 0;
}