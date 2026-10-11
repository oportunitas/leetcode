// Created by oportunitas at 2026/10/11 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/prime-subset-selection-ii/
// https://leetcode.com/contest/weekly-contest-523/problems/prime-subset-selection-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);
		int s = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.maxPrimeSubset(n, s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
