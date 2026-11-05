// Created by oportunitas at 2026/11/05 12:56
// leetgo: 1.4.18
// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 16.4MB/93th%)
        we just loop and use goto to skip.
    */
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans {0};
        for (const auto& num1 : arr1) {
            for (const auto& num2: arr2) {
                if (abs(num1 - num2) <= d) goto __next;
            } ans += 1;
        __next:
        } return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> arr1 = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> arr2 = LeetCodeIO::deserialize<vector<int>>(cin);
		int d = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.findTheDistanceValue(arr1, arr2, d);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
