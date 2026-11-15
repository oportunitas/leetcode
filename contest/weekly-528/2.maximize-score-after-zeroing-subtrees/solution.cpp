// Created by oportunitas at 2026/11/15 10:10
// leetgo: 1.4.18
// https://leetcode.com/problems/maximize-score-after-zeroing-subtrees/
// https://leetcode.com/contest/weekly-contest-528/problems/maximize-score-after-zeroing-subtrees/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> parent = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> op = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> score = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.maxScore(parent, op, score);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
