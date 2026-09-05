// Created by oportunitas at 2026/09/05 14:24
// leetgo: 1.4.18
// https://leetcode.com/problems/jewels-and-stones/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 8.3MB/79th%)
		lets use elegant and zen language instead of bare loops here. we shall use ranges::count_if
	*/
    int numJewelsInStones(string jewels, string stones) {
        return ranges::count_if(stones, [&jewels] (char stone) {
			// to clarify confusion "why jewel contains stone? not stone contains jewels?":
			//    in this ranges::count_if, we iterate through (stone : stones), therefore
			//    we check if each stone is in the list of jewels, instead of the other way around
			return jewels.contains(stone);
		});
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string jewels = LeetCodeIO::deserialize<string>(cin);
		string stones = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.numJewelsInStones(jewels, stones);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
