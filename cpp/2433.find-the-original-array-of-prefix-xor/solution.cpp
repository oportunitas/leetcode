// Created by oportunitas at 2026/09/18 19:01
// leetgo: 1.4.18
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 80.5MB/72th%)
		pref 101 010 000 011 001
		res  101 111 010 011 010

		     101 111 010 011 010	
		
		pref[i + 1] by definition is:
			arr[0] ^ arr[1] ^ ... ^ arr[i] ^ arr[i + 1]
		we can define pref[i + 1] in terms of pref[i]:
			pref[i + 1] = pref[i] ^ arr[i + 1]
		if we shift the index by one, we get the definition of pref[i] in regards of pref[i - 1]:
			pref[i] = pref[i - 1] ^ arr[i]
		we can then simply make a loop from this
	*/
    vector<int> findArray(vector<int>& pref) {
		auto result {[&pref] () {vector<int> _; _.reserve(pref.size() + 2); return _;} ()};
		for (int i {0}; i < pref.size(); ++i) {
			result.push_back(i == 0 ? (pref[i]) : (pref[i] ^ pref[i - 1]));
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> pref = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.findArray(pref);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
