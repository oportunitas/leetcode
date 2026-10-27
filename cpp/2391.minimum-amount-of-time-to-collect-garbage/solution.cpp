// Created by oportunitas at 2026/10/27 08:39
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/* idea #0 (0ms/100th% | 107.1MB/85th%)
    1. precompute running sum, find number of garbage type, and last index
    2. sum + number
*/
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char, int> last {};
        for (const auto& [i, house] : garbage | views::enumerate | views::reverse) {
            for (const char& g : house) {
                if (!last.contains(g)) last[g] = i;
                if (last.size() == 3) goto __end_lastfind;
            }
        }
    __end_lastfind:
        for (size_t i {1}; i < travel.size(); ++i) {
            travel[i] += travel[i-1];
        }

        int result {0};
        for (const auto& house : garbage) {
            result += house.size();
        }

        for (const auto& [type, last_i] : last) {
            result += last_i == 0 ? 0 : travel[last_i-1];
        }

        return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> garbage = LeetCodeIO::deserialize<vector<string>>(cin);
		vector<int> travel = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.garbageCollection(garbage, travel);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
