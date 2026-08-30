// Created by oportunitas at 2026/08/30 17:17
// leetgo: 1.4.18
// https://leetcode.com/problems/digit-frequency-score/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int digitFrequencyScore(int n) {
		int res = 0;
		while (n > 0) {
			res += n % 10;
			n /= 10;
		} return res;

        /*scratchpad (python-esque)

		idea #0:
			freq = None

			for num in n:
				freq[num] += 1
			
			res = 0
			for i, f in freq.enumerate():
				res += (i * f)
			
			return res

		idea #1:
			res = 0
			for num in n:
				res += num

		idea #2:
			res = 0
			while num > 0:
				res += num % 10
				num /= 10
		*/
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.digitFrequencyScore(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
