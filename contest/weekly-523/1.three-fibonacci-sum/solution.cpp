// Created by oportunitas at 2026/10/11 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/three-fibonacci-sum/
// https://leetcode.com/contest/weekly-contest-523/problems/three-fibonacci-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /*
        we can just find the fibonacci numbers first.
    */
    bool threeFibonacciSum(int n) {
        if (n % 2 == 1) return false;
        
        unordered_set<int64_t> is_fib; is_fib.insert(0);
        int64_t n1 {0};
        int64_t n2 {0};
        int64_t n3 {1};
        while (n1 <= n && n2 <= n && n3 <= n) {
            if (n1 + n2 + n3 == n) return true;
            int64_t temp_n3 {n2 + n3};
            n1 = n2; n2 = n3; n3 = temp_n3;
        } return false;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.threeFibonacciSum(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
