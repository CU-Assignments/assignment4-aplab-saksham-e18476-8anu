#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res;
        res.push_back(1);
        while (res.size() < n) {
            vector<int> temp;
            for (int i = 0; i < res.size(); i++) {
                int num = res[i] * 2 - 1;
                if (num <= n) temp.push_back(num);
            }
            for (int i = 0; i < res.size(); i++) {
                int num = res[i] * 2;
                if (num <= n) temp.push_back(num);
            }
            res = temp;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> result = sol.beautifulArray(n);
    for (int num : result) cout << num << " ";
    cout << endl;
    return 0;
}