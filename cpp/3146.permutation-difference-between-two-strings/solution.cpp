// Created by oportunitas at 2026/09/21 12:11
// leetgo: 1.4.18
// https://leetcode.com/problems/permutation-difference-between-two-strings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 9.3MB/39th%)
		we just store the locations of each character in an array map, then subtract.
	*/
    int findPermutationDifference(string s, string t) {
		vector<int> s_loc (26, 0);
		vector<int> t_loc (26, 0);
		int result {0};

		for (int i {0}; i < s.size(); ++i) {
			s_loc[s[i] - 'a'] = i;
			t_loc[t[i] - 'a'] = i;
		} for (int i = 0; i < 26; ++i) {
			result += abs(s_loc[i] - t_loc[i]);
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);
		string t = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.findPermutationDifference(s, t);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
