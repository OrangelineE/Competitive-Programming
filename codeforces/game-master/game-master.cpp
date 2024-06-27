#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<unordered_map>
using namespace std;

int main () {
    int tests;
    cin >> tests;
    for(int i = 0 ; i < tests; ++i) {
        int n;
        cin >> n;
        vector<bool> winners(n, false);
        //first->strength, second->index
        vector<pair<int, int>> map1;
        vector<pair<int, int>> map2;
        vector<vector<int>> map;

        for(int a = 0; a < n; a++) {
            int tmp;
            cin >> tmp;
            map1.push_back({tmp, a});
        }
        for(int a = 0; a < n; a++) {
            int tmp;
            cin >> tmp;
            map2.push_back({tmp, a});
            map.push_back({map1[a].first, tmp});
        }
        sort(map1.begin(), map1.end());
        sort(map2.begin(), map2.end());
        winners[map1.back().second] = true;
        winners[map2.back().second] = true;
        int min2 = map[map1.back().second][1];
        int min1 = map[map2.back().second][0];

        for(int i = n-1; i >= 0; i--) {
            if(map1[i].first > min1) {
                winners[map1[i].second] = true;
                //Update the value
                min2 = min(min2, map[map1[i].second][1]);
            }
            if(map2[i].first > min2) {
                winners[map2[i].second] = true;
                min1 = min(min1, map[map2[i].second][0]);
            }
        }

        for(int i = 0; i < winners.size(); i++) {
            cout << winners[i];
        }
        cout << endl;
    }
    return 0;
}