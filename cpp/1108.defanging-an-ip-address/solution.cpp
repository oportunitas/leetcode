// Created by oportunitas at 2026/09/03 12:36
// leetgo: 1.4.18
// https://leetcode.com/problems/defanging-an-ip-address/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0 (Runtime: 0ms/100th% | Memory: 7.6MB/95th%)
		cpp strings are contiguous arrays, trying to insert a character in between an existing string might be very computationaly expensive. a better and more zen approach (in the cost of slight memory overhead, which is fine imo since this is a small overhead, is to create a new string and sequentially push back characters.
	*/
    string defangIPaddr(string address) {
		// the most amount of characters in a defanged ipv4 address is 21 (4x3 numbers + 3x3 "[.]")
        auto result {[] () {string _; _.reserve(21); return _;} ()};
		for (auto c : address) {
			if (c == '.') {
				result.append("[.]");
			} else {
				result.push_back(c);
			}
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string address = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.defangIPaddr(address);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
