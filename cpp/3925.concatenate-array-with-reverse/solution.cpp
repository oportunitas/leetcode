// Created by oportunitas at 2026/08/24 16:40
// leetgo: 1.4.18
// https://leetcode.com/problems/concatenate-array-with-reverse/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
		auto ans {[n { nums.size() * 2 }] { vector<int> v; v.reserve(n); return v; } () };

		// since leetcode doesnt support .append_range(), we use .insert() instead
		ans.insert(ans.end(), nums.begin(), nums.end());
		ans.insert(ans.end(), nums.rbegin(), nums.rend());
		return ans;

		/*
			// lets use IIFE (immediately-invoked function expression) here for zen and fun 
			// 
			// if this is a bit hard to understand: its creating a vector and reserving
			// 2 times the size of nums vector in memory.
			auto ans { [n { nums.size() * 2 }] { vector<int> v; v.reserve(n); return v; }() };
			
			ans.append_range(nums); ans.append_range(nums | views::reverse);
			return ans;
		*/
		
		/*
			// TIL: CTAD (Class Template Argument Deduction).
			//   this feature enables broad hinting about the data type of an expression 
			//   without needing to go too deep with describing the exact data type
			//   (very layman's explanation)
			// 
			//   in the following line, instead of declaring vector<vector<int>> {...},
			//   we can just declare vector {...} and let the compiler deduce the inner data types.
			//   
			//   this specific use case is especially great, since declaring vector<vector<int>> 
			//   would confuse code readers (i.e. "return type is `vector<int>`, why is there 
			//   `vector<vector<int>>` after the return word?").
			//   
			//   the vector is declared as 2d, but is then flattened with `views::join`. using
			//   vector {...} may avoid this confusion.
			return vector { 
				nums, (nums | views::reverse | ranges::to<vector>())
			} | views::join | ranges::to<vector>();
		*/
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.concatWithReverse(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
