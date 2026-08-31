// Created by oportunitas at 2026/08/31 15:27
// leetgo: 1.4.18
// https://leetcode.com/problems/restore-finishing-order/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0
		store the `friends` array to an unordered set: `friends_set`.
		then we go through the `order` array, and whenever the ith element
		exists in `friends_set` (O(1) search time), we append to the return vector.
	*/
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        auto res = [&friends] () {vector<int> _; _.reserve(friends.size()); return _;} ();
		auto friends_set = ranges::to<unordered_set<int>>(friends);

		for (auto [i, num] : order | views::enumerate) {
			if (friends_set.contains(num)) res.push_back(num);
		}

		// println("{}", res);
		return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> order = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> friends = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.recoverOrder(order, friends);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
