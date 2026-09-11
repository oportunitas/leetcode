// Created by oportunitas at 2026/09/11 13:58
// leetgo: 1.4.18
// https://leetcode.com/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/
// https://leetcode.com/contest/weekly-contest-518/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0
		lets first try to do the most straightforward approach, even though
		im pretty sure this is very time inefficient. 
		we can always make the code better later on.
	*/
    int countRotations(string s, int k) {
		int res {0};
		for (int i {0}; i < s.size(); ++i) {
			struct {char c; int score;} _last {'0', 0};

			int j {i}; do {
				if (_last.c == s[j]) {
					_last.score += 1;
				} else {
					_last.c = s[j];
				}
				// print("{}", s[j]);
			j = (j + 1) % s.size(); } while (j != i);
			// print("\n");

			if (_last.score == k) res += 1;
		} return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.countRotations(s, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
