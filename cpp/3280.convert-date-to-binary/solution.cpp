// Created by oportunitas at 2026/09/15 14:55
// leetgo: 1.4.18
// https://leetcode.com/problems/convert-date-to-binary/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #1 (0ms/100th% | 11.2MB/6th%)
		idea #0 was too verbose, and not modern enough. lets significantly lean down the code.
		a rule to follow for modern programming: if you want to write a loop, there should be
		something better to substitute it.
	*/
	string convertDateToBinary(string date) {
		return format("{:b}-{:b}-{:b}", 
			stoi(date.substr(0, 4)),
			stoi(date.substr(5, 7)),
			stoi(date.substr(8, 10))
		);
	}

	// /* idea #0
	// 	lets try to implement first, then lean down later
	// */
    // string convertDateToBinary(string date) {
    //     auto result {[] () {string _; _.reserve(128); return _;} ()};

	// 	for (
	// 		struct {
	// 			int i; 
	// 			vector<int> pow;
	// 			vector<int> num_cache;
	// 		} _l {
	// 			0,
	// 			{3, 1, 1},
	// 			{0, 0, 0}
	// 		}; 
	// 		auto [i, c] : date | views::enumerate
	// 	) {
	// 		if (c == '-') {
	// 			result.push_back('-');
	// 			continue;
	// 		} else {
	// 			// println("pow: {}", _l.pow[_l.i]);
	// 			// println("ta: {}", (c - '0') * pow(10, _l.pow[_l.i]));
	// 			_l.num_cache[_l.i] += (c - '0') * pow(10, _l.pow[_l.i]);
	// 			_l.pow[_l.i] -= 1;
	// 		}

	// 		if (i == date.size() - 1 || date[i + 1] == '-') {
	// 			// println("nc: {}", _l.num_cache[_l.i]);
	// 			result.append(format("{:b}", _l.num_cache[_l.i]));
	// 			_l.i += 1;
	// 		} 
	// 	} return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string date = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.convertDateToBinary(date);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
