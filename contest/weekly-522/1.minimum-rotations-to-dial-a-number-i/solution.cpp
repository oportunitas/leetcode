// Created by oportunitas at 2026/10/04 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-rotations-to-dial-a-number-i/
// https://leetcode.com/contest/weekly-contest-522/problems/minimum-rotations-to-dial-a-number-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
    pair<int, int> get_distances(int num1, int num2) {
        int big = max(num1, num2);
        int sml = min(num1, num2);

        return {(big - sml), ((sml + 10) - big)};
    }

public:
    int minRotations(string s) {
        int result {0};
        for (int i {0}; i < s.size(); ++i) {
            int num1 = (i == 0) ? 0 : s[i - 1] - '0';
            int num2 = s[i] - '0';

            const auto& [dist1, dist2] = get_distances(num1, num2);
            result += min(dist1, dist2);
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.minRotations(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
