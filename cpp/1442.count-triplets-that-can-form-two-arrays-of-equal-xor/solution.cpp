// Created by oportunitas at 2026/11/08 11:34
// leetgo: 1.4.18
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 10.8MB/32th%)
        we essentially just check for ranges i to k
        where i to k's xor is 0. this problem is similar 
        to asking: pick i, j, k, i to j must have the same
        even-oddness as j to k. we just need to check if i to k
        is even, since this would always divide into either 2 
        even numbers or 2 odd numbers.
    */
    int countTriplets(vector<int>& arr) {
        vector<int> prefix_sum (arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); ++i) {
            prefix_sum[i+1] = prefix_sum[i] ^ arr[i];
        }

        // println("{}", prefix_sum);
        // return -2;

        // vector<int> suffix_sum (arr.size(), 0);
        // for (int i = arr.size() - 1; i >= 0; --i) {
        //     suffix_sum[i] = arr[i] ^ (i == arr.size() - 1 ? 0 : suffix_sum[i+1]);
        // }

        int ans {0};
        for (int i = 0; i < arr.size() - 1; ++i) {
            for (int k = i + 1; k < arr.size(); ++k) {
                // equivalent of checking if sum(0->k) - (sum(0->i)) is even (i -> k sum is even)
                if ((prefix_sum[k + 1] ^ prefix_sum[i]) == 0) ans += (k - i);
            }
        } return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> arr = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.countTriplets(arr);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
