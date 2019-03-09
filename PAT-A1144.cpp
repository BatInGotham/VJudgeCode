// PAT-A1144
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
    set<int> nums;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;
        if(t > 0)
            nums.insert(t);
    }
    bool flag = false;
    int k = 1;
    for(auto it = nums.begin(); it != nums.end(); it++) {
        if(*it != k) {
            printf("%d", k);
            return 0;
        }
        k++;
    }
    printf("%d", k);
    return 0;
}
