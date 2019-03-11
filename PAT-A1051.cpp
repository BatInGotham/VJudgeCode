// PAT-A1051
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int M, N, K;
// M=capacity, N=inputcount, K=sequencecount

int main()
{
    stack<int> s;
    int arr[1010];
    scanf("%d%d%d", &M, &N, &K);
    for(int i = 0; i < K; i++) {
        while(!s.empty()) {
            s.pop();
        }
        for(int j = 1; j <= N; j++) {
            scanf("%d", &arr[j]);
        }
        int current = 1;
        bool flag = true;
        for(int j = 1; j <= N; j++) {
            s.push(j);
            if(s.size() > M) {
                flag = false;
                break;
            }
            while(!s.empty() && s.top() == arr[current]) {
                s.pop();
                current++;
            }
        }
        if(s.empty() && flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
