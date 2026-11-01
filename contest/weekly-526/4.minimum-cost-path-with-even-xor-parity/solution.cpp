// Created by oportunitas at 2026/11/01 09:42
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-cost-path-with-even-xor-parity/
// https://leetcode.com/contest/weekly-contest-526/problems/minimum-cost-path-with-even-xor-parity/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minActivationCost(vector<vector<int>>& edges, vector<int>& values) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> edges = LeetCodeIO::deserialize<vector<vector<int>>>(cin);
		vector<int> values = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minActivationCost(edges, values);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
