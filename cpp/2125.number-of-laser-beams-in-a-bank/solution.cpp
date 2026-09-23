// Created by oportunitas at 2026/09/23 07:04
// leetgo: 1.4.18
// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 27.4MB/63th%)
		for a given pair of rows with laser beams, the number of laser beams is equal to
		(laser_device_row_1 & laser_device_row_2)
	*/
    int numberOfBeams(vector<string>& bank) {
        int result {0};
		int last_count {0}; 
		for (const auto& row : bank) {
			int cur_count {0};
			for (const auto& c: row) {
				if (c == '1') cur_count += 1;
			}

			result += last_count * cur_count;
			if (cur_count > 0) last_count = cur_count;
		}
		return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> bank = LeetCodeIO::deserialize<vector<string>>(cin);

		Solution obj;
		auto res = obj.numberOfBeams(bank);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
