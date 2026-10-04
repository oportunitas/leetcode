// Created by oportunitas at 2026/10/04 09:42
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-rotations-to-dial-a-number-ii/
// https://leetcode.com/contest/weekly-contest-522/problems/minimum-rotations-to-dial-a-number-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/*
    2916: 2, 3, 2, 5
    2619: 2, 4, 5, 2
*/
class Solution {
private:
    pair<int, int> get_distances(int num1, int num2) {
        int big = max(num1, num2);
        int sml = min(num1, num2);

        return {(big - sml), ((sml + 10) - big)};
    }

public:
    int minRotations(int n, string s) {
        int min_diff {0};
        pair<int, int> swap = {0, 0};

        int result {0};
        for (int i {0}; i < s.size(); ++i) {
            // println("---");
            int num1 = (i == 0) ? 0 : s[i - 1] - '0';
            int num2 = s[i] - '0';
            int num3 = s[s.size() - 1] - '0';

            const auto& [dist12, dist21] = get_distances(num1, num2); 
            // println("d12: {}, d21: {}, min: {}", dist12, dist21, min(dist12, dist21));

            if (i < s.size() - 1) {
                const auto& [dist13, dist31] = get_distances(num1, num3); 
                // println("d13: {}, d31: {}, min: {}", dist13, dist31, min(dist13, dist31));

                if ((min(dist13, dist31) - min(dist12, dist21)) < min_diff) {
                    min_diff = min(dist13, dist31) - min(dist12, dist21);
                    swap = {min(dist12, dist21), min(dist13, dist31)};
                }
            }

            result += min(dist12, dist21);
        }

        // println("swap: {}, {}", swap.first, swap.second);
        result += min(swap.first, swap.second);
        result -= max(swap.first, swap.second);
        return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.minRotations(n, s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
