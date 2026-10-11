// Created by oportunitas at 2026/10/11 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/prime-subset-selection-i/
// https://leetcode.com/contest/weekly-contest-523/problems/prime-subset-selection-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
    // void traverse(
    //     vector<int>& cur_arr, vector<int>& res_arr, vector<int>& full_arr, 
    //     int i, int64_t cur_sum, int& s, int64_t& max_sum, int depth
    // ) { 
    //     // println("cs: {}, i: {}, ca: {}, ra: {}", cur_sum, i, cur_arr, res_arr);

    //     if (cur_sum <= s && cur_sum >= max_sum) {
    //         println("max sum case, res_arr is now: {}", res_arr);
    //         max_sum = cur_sum;
    //         if (cur_arr.size() > res_arr.size()) {
    //             res_arr = cur_arr;
    //         }
    //     } if (cur_sum == s) {
    //         println("return case, res_arr: {}", res_arr);
    //         return;
    //     }

    //     if (i >= full_arr.size()) {
    //         return;
    //     } 

    //     // case 1: include current number
    //     cur_arr.push_back(full_arr[i]);
    //     traverse(cur_arr, res_arr, full_arr, i + 1, cur_sum + full_arr[i], s, max_sum, depth + 1);
    //     cur_arr.pop_back();
        
    //     // case 2: skip current number
    //     traverse(cur_arr, res_arr, full_arr, i + 1, cur_sum, s, max_sum, depth + 1); 

    //     // fin
    //     return;
    // }
public:
    vector<int> maxPrimes(int n, int s) {
        array<bool, 1000001> is_prime; ranges::fill(is_prime, true);
        is_prime[0] = is_prime[1] = false;

        for (int i {2}; i * i <= n; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        vector<int> full_arr;
        int64_t sum {0};
        for (int i {2}; i <= n; ++i) {
            if (is_prime[i]) {
                if (sum + i > s) break;
                full_arr.push_back(i);
                sum += i;
            }
        } return full_arr;

        /*bro ts flew over my head, we maximize the NUMBER of selected primes not the actual
        sum itself🥀🥀🥀, the traverse() function is completely useless here🥀 we wasted time
        on working on what would be the hard version of this problem (Prime Subset Selection II)
        without having eventually solved any 🥀🥀🥀🥀*/
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);
		int s = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.maxPrimes(n, s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
