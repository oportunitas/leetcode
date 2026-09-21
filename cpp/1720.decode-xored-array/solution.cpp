// Created by oportunitas at 2026/09/21 11:10
// leetgo: 1.4.18
// https://leetcode.com/problems/decode-xored-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 29.5MB/75th%)
		lets do the most straightforward solution, which is to just loop over and xor again
	*/
    vector<int> decode(vector<int>& encoded, int first) {
        auto result {[&encoded, &first] () { 
			vector<int> _; 
			_.reserve(encoded.size() + 2); 
			_.push_back(first);
			return _; 
		} ()};

		for (auto&& num : encoded) {
			result.push_back(result.back() ^ num);
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> encoded = LeetCodeIO::deserialize<vector<int>>(cin);
		int first = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.decode(encoded, first);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
