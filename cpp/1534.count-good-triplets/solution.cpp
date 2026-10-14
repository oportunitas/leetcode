// Created by oportunitas at 2026/10/14 12:07
// leetgo: 1.4.18
// https://leetcode.com/problems/count-good-triplets/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (4ms/90th% | 11MB/71th%)
        we can do semi-bruteforce here, we enter the deepest loop only in case any
        of the values inside can be true (hence the if statement between j and k loop)
    */
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count {0};
        for (int i {0}; i < arr.size() - 2; ++i) {
            for (int j {i + 1}; j < arr.size() - 1; ++j) {
                if (abs(arr[i] - arr[j]) <= a) {
                    for (int k {j + 1}; k < arr.size(); ++k) {
                        if (abs(arr[j] - arr[k]) <= b && abs(arr[k] - arr[i]) <= c) {
                            count += 1;
                        }
                    }
                }
            }
        } return count;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> arr = LeetCodeIO::deserialize<vector<int>>(cin);
		int a = LeetCodeIO::deserialize<int>(cin);
		int b = LeetCodeIO::deserialize<int>(cin);
		int c = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.countGoodTriplets(arr, a, b, c);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
