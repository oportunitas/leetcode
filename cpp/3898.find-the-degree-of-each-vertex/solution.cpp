// Created by oportunitas at 2026/08/21 09:50
// leetgo: 1.4.18
// https://leetcode.com/problems/find-the-degree-of-each-vertex/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
		vector<int> degrees;
		degrees.resize(matrix.size());

		for (auto [i, node] : matrix | views::enumerate) {
			auto degree = reduce(node.begin(), node.end(), 0, plus<int>());
			// println("{}", degree);
			degrees[i] = degree;
		}

		return degrees;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> matrix = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.findDegrees(matrix);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
