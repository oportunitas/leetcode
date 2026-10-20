// Created by oportunitas at 2026/10/20 07:41
// leetgo: 1.4.18
// https://leetcode.com/problems/sum-of-sortable-integers/

#include <bits/stdc++.h>
#include <boost/pfr.hpp>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/* idea #1 (13ms/94th% | 95.5MB/35th%)
    lets try to simplify the approach of idea #0 and remove unnecessary calculations:
        - precalculate values, reducing property evaluation of each batch from an o(n) operation
          to o(1)
        - build the entire function around point 1
*/
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        // we find the running drop counts here. instead of using idea #0 which loops
        // through the subarray each time to count the drop count of a subarray, we
        // just subtract the value between the beginning and the end index of interest
        // this is possible due to the strictly non-decreasing nature of the running drop
        // values as we go along the array
        vector<int> running_drops (nums.size(), 0);
        int drops_so_far {0};
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                drops_so_far += 1;
            } running_drops[i] = drops_so_far;
        }

        // we also find the following information:
        //   for any index in nums, what index is its next closest drop?
        // this is useful info for quickly finding the min & max value later on,
        // instead of iterating through the array, we can visualize the batch as such:
        //   !down-!down-!down-down-!down (assume valid array)
        // if the array is valid, the minimum value should always be at the 'down' index,
        // and the max value should always be just before it.
        vector<int> next_drop_idx (nums.size(), nums.size());
        int next_drop_idx_so_far = nums.size();
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] < nums[i - 1]) {
                next_drop_idx_so_far = i;
            }
            next_drop_idx[i] = next_drop_idx_so_far;
        } next_drop_idx[0] = next_drop_idx_so_far;

        // get the k values (same idea as idea #0)
        vector<int> ks; for (int k {1}; k * k <= nums.size(); ++k) {
            if (nums.size() % k == 0) {
                ks.push_back(k); 
                if (k * k != nums.size()) {
                    ks.push_back(nums.size() / k);
                }
            }
        }

        int result {0};
        for (const auto& k : ks) {
            int last_max {0};

            for (int begin {0}; begin < nums.size(); begin += k) {
                int end {begin + (k - 1)}; // range is [begin, end]
                int drops {0};

                // no need to add drops if batch size is 1 (thus the if case)
                if (end > begin) {
                    drops = running_drops[end] - (begin > 0 ? running_drops[begin] : 0);
                } if (drops > 1) goto __proceed; // immediately exit upon invalid batch

                // find min max
                int batch_min {INT_MAX}; int batch_max {0};
                if (drops == 0) {
                    batch_min = nums[begin]; batch_max = nums[end];
                } else {
                    // if last number is bigger than first number, this practically means
                    // that there are in total 2 drops in the batch. thus invalid
                    if (nums[end] > nums[begin]) goto __proceed;

                    // instead of iterating through the array, we can visualize the batch as such:
                    //   !down-!down-!down-down-!down (assume valid array)
                    // if the array is valid, the min value should always be at the 'down' index,
                    // and the max value should always be just before it.
                    batch_min = nums[next_drop_idx[begin]];
                    batch_max = nums[next_drop_idx[begin] - 1];
                }

                if (begin > 0 && batch_min < last_max) goto __proceed; // cannot connect to previous
                last_max = batch_max;
            }

            // if the loop reaches this point, this means that the entire batch sequence is valid
            result += k;

        __proceed:
            void();
        }

        return result;
    }
};

// /* idea #0 (1445ms/11th% | 504.35MB/13th%)
//     for a given sequence of batches, the following must satisfy:
//         - the minimum value of the current batch must not be smaller than the max
//           value of the previous batch (otherwise there's no way to sort non-descendingly)
//         - the number of drops in value in the this batch must never exceed 1.
// */
// struct batch {
//     int min;
//     int max;
//     int dwn;
//     vector<int> nms;
// };

// class Solution {
// private:
//     void _println(unordered_map<int, vector<batch>>& sequence) {
//         cout << "\n-\n-\n";
//         for (const auto& [k, seq] : sequence) {
//             cout << "|| " << k << ": [";
//             for (const auto& [i, node] : seq | views::enumerate) {
//                 cout << "(" << node.min << ", " << node.max << ", " << node.dwn << ", [";
//                 for (size_t j = 0; j < node.nms.size(); ++j) {
//                     cout << node.nms[j];
//                     if (j < node.nms.size() - 1) {
//                         cout << ", ";
//                     }
//                 } cout << "])";
                
//                 if (i < seq.size() - 1) cout << ", ";
//             } cout << format("] ||\n");
//         }
//     }
// public:
//     int sortableIntegers(vector<int>& nums) {
//         unordered_set<int> ks; for (int i {1}; i * i <= nums.size(); ++i) {
//             if (nums.size() % i == 0) {
//                 ks.insert(i); ks.insert(nums.size() / i);
//             }
//         }

//         unordered_map<int, vector<batch>> sequence; 
//         for (const auto& k : ks) {
//             sequence[k].push_back({INT_MAX, 0, 0, {}});
//         }

//         for (const auto& [i, num] : nums | views::enumerate) {
//             // _println(sequence);
//             // if (i == 2) return -1;

//             vector<int> to_erase;
//             for (auto& [k, seq] : sequence) {
//                 auto& node {seq.back()};

//                 if (node.nms.size() > 0 && num < node.nms.back()) {
//                     node.dwn += 1;
//                 }

//                 node.nms.push_back(num);
//                 node.min = min(node.min, num);
//                 node.max = max(node.max, num);

//                 if (((i + 1) % k) == 0) {
//                     if (node.nms.front() < node.nms.back()) {
//                         node.dwn += 1;
//                     }

//                     // if the min of this node is smaller than the max of the previous
//                     // node, we no longer need to track of this node because this is invalid
//                     if (
//                         (seq.size() > 1 && seq.rbegin()->min < (seq.rbegin() + 1)->max) || 
//                         seq.back().dwn > 1
//                     ) {
//                         to_erase.push_back(k);
//                         continue;
//                     }

//                     if (i < nums.size() - 1) {
//                         seq.push_back({INT_MAX, 0, 0, {}});
//                     }
//                 }
//             }

//             for (const auto& k : to_erase) sequence.erase(k);
//         }

//         int result {0};
//         for (const auto& [k, seq] : sequence) {
//             result += k;
//         }

//         // _println(sequence);
        
//         return result;
//     }
// };

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.sortableIntegers(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
