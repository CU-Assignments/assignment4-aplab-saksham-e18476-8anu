#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (auto& b : buildings) {
            events.emplace_back(b[0], -b[2]);
            events.emplace_back(b[1], b[2]);
        }
        sort(events.begin(), events.end());
        multiset<int> heights = {0};
        vector<vector<int>> res;
        int prev = 0;
        for (auto& e : events) {
            if (e.second < 0) heights.insert(-e.second);
            else heights.erase(heights.find(e.second));
            int cur = *heights.rbegin();
            if (cur != prev) {
                res.push_back({e.first, cur});
                prev = cur;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int>> buildings(n, vector<int>(3));
    for (int i = 0; i < n; i++) cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];
    vector<vector<int>> result = sol.getSkyline(buildings);
    for (auto& point : result) cout << point[0] << " " << point[1] << endl;
    return 0;
}
