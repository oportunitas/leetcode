// Created by oportunitas at 2026/11/01 09:42
// leetgo: 1.4.18
// https://leetcode.com/problems/minimize-the-maximum-value-of-gcd-connected-array/
// https://leetcode.com/contest/weekly-contest-526/problems/minimize-the-maximum-value-of-gcd-connected-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/*
    tidied up version
*/
class Solution {
private:
    int64_t _mpf(int64_t num) {
        if (num % 2 == 0) return 2;
        for (int64_t i {3}; i * i <= num; i += 2) {
            if (num % i == 0) return i;
        } return num;
    }

    int64_t _maxlen(int64_t num) {
        if (num == 1) return 0; //no need to calc
        if (num % 2 == 0) return num / 2; //even number

        int64_t mpf {_mpf(num)};
        if (mpf == num) return 1; //prime

        return ((num - mpf) / 2) + 1; //num-mpf is even, so even number case + 1
    }
public: 
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) return -1;
        int64_t maxlen {_maxlen(value)};

        if (index + 1 > maxlen) return -1;

        int64_t remain {n - 1 - index};
        if (remain == 0) return value;

        if (value % 2 == 0) {
            return value + 2LL * remain;
        } else {
            int64_t mpf {_mpf(value)};
            return value + mpf + 2ll * (remain - 1);
        }
    }
};

// class Solution {
// public:
//     /*
//         ? ? ? ?
//         ? ? 8 ?
//         ? ? ? 10

//         ? ?
//         ? 3

//         ? ? 
//         3 ?
//         3 6

//         ? ? ? ?
//         1

//         ? ? ?
//         2 4 6
//     */
//     long long minimumMaxValue(int n, int index, int value) {
//         // check if its possible to fill in numbers before index.
//         if (index == 0) goto __continue;
//         for (int i {2}; i < value; ++i) {
//             // println("{} / {}: {}", value, i, value / i);
//             if (value / i > index) {
//                 goto __continue;
//             }
//         } return -1;

//     __continue:
//         if (value == 1) return -1;
//         if (index == n - 1) {
//             return value;
//         }

//         // find first next option
//         int64_t first_next_option {-1};
//         for (int option {value + 1}; option <= value * 2; ++option) {
//             // println("gcd({}, {}): {}", value, option, gcd(value, option));
//             if (gcd(value, option) > 1) {
//                 first_next_option = option;
//                 break;
//             }
//         } if (index == n - 2) {
//             return first_next_option;
//         }
//         // println("first next option: {}", first_next_option);

//         // if first next option is even, we just snowball
//         int64_t second_next_option {-1};
//         if (first_next_option % 2 == 0) {
//             return (first_next_option + (2 * (n - 1 - index - 1)));
//         } else {
//             for (int option = first_next_option + 1; option <= first_next_option * 2; ++option) {
//                 // println("gcd({}, {}): {}", first_next_option, option, gcd(first_next_option, option));
//                 if (gcd(first_next_option, option) > 1) {
//                     second_next_option = option;
//                     break;
//                 }
//             }
//         } 
//         // println("second next option: {}", second_next_option);
        
//         return (second_next_option + (2 * (n - 1 - index - 2)));
//     }
// };

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);
		int index = LeetCodeIO::deserialize<int>(cin);
		int value = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minimumMaxValue(n, index, value);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
