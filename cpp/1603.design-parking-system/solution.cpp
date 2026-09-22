// Created by oportunitas at 2026/09/22 10:49
// leetgo: 1.4.18
// https://leetcode.com/problems/design-parking-system/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class ParkingSystem {
/* idea #0 (0ms/100th% | 38.6MB/100th%)
	lets use the most straightforward approach
*/
private:
	array<int, 4> slots {{0}};
public:
    ParkingSystem(int big, int medium, int small) {
        slots[1] += big;
		slots[2] += medium;
		slots[3] += small;
    }
    
    bool addCar(int carType) {
		if ((slots[carType]--) > 0) return true;
		return false;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		auto method_names = LeetCodeIO::deserialize<vector<string>>(cin);
		auto params = LeetCodeIO::split_array(cin);

		unique_ptr<ParkingSystem> obj;
		vector<string> output;
		const unordered_map<string, function<void(const vector<string> &)>> methods = {
			{ "ParkingSystem", [&](const vector<string> &method_params) {
				int big = LeetCodeIO::deserialize<int>(method_params, 0);
				int medium = LeetCodeIO::deserialize<int>(method_params, 1);
				int small = LeetCodeIO::deserialize<int>(method_params, 2);
				obj = make_unique<ParkingSystem>(big, medium, small);
				output.push_back("null");
			} },
			{ "addCar", [&](const vector<string> &method_params) {
				int carType = LeetCodeIO::deserialize<int>(method_params, 0);
				output.push_back(LeetCodeIO::serialize(obj->addCar(carType)));
			} },
		};
		if (method_names.size() != params.size()) {
			throw LeetCodeIO::Error("method and parameter counts differ");
		}
		for (size_t i = 0; i < method_names.size(); ++i) {
			auto method_params = LeetCodeIO::split_array(params[i]);
			methods.at(method_names[i])(method_params);
		}
		cout << "\noutput: " << LeetCodeIO::join_array(output) << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
