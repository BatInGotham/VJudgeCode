// PAT-A1154
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<pair<int,int>> s;
set<int> index;

int main()
{
    int a[10010];
    int M, N;
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        s.push_back(make_pair(a1, a2));
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        index.clear();
        for(int j = 0; j < M; j++) {
            cin >> a[j];
            index.insert(a[j]);
        }
        bool foo = true;
        for(auto it = s.begin(); it != s.end(); it++) {
            if(a[(*it).first] == a[(*it).second]) {
                foo = false;
                break;
            }
        }
        if(!foo) {
            cout << "No" << endl;
        } else {
            cout << index.size() << "-coloring" << endl;
        }
    }
    return 0;
}
