// Created by oportunitas at 2026/10/14 10:15
// leetgo: 1.4.18
// https://leetcode.com/problems/maximize-sum-of-squares-of-digits/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (3ms/96th% | 47.8MB/100th%)
        + + 
        + +

        + + + 
        + + +
        + + +
        
        we know that for any integer a and b, (a + b)^2 is always greater than a^2 + b^2
        (because (a+b)^2 is a^2 + 2ab + b^2)

        therefore, we only need to follow one rule when creating the good number: get the biggest
        number every time, take from sum, until sum is 0
    */
    string maxSumOfSquares(int num, int sum) {
        // base case, there's not enough digits to get to sum
        if ((9 * num) < sum) return "";

        string result; result.reserve(num + 1);

        // add 9s wherever possible
        int nine_count = sum / 9;
        result.append(nine_count, '9');
        num -= nine_count; sum -= 9 * nine_count;

        // add remainder if any
        if (sum > 0) {
            int remain = sum % 9;
            result.push_back(remain + '0');
            num -= 1;
        }

        // add 0s if theres remaining num
        result.append(num, '0');

        // return
        return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int num = LeetCodeIO::deserialize<int>(cin);
		int sum = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.maxSumOfSquares(num, sum);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
