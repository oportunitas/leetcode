// Created by oportunitas at 2026/10/11 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/design-bus-seat-booking-system/
// https://leetcode.com/contest/weekly-contest-523/problems/design-bus-seat-booking-system/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class BusBooking {
public:
    BusBooking(int n) {
        
    }
    
    void toggle(string seat) {
        
    }
    
    int getTotalTime() {
        
    }
    
    int getMinTime() {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		auto method_names = LeetCodeIO::deserialize<vector<string>>(cin);
		auto params = LeetCodeIO::split_array(cin);

		unique_ptr<BusBooking> obj;
		vector<string> output;
		const unordered_map<string, function<void(const vector<string> &)>> methods = {
			{ "BusBooking", [&](const vector<string> &method_params) {
				int n = LeetCodeIO::deserialize<int>(method_params, 0);
				obj = make_unique<BusBooking>(n);
				output.push_back("null");
			} },
			{ "toggle", [&](const vector<string> &method_params) {
				string seat = LeetCodeIO::deserialize<string>(method_params, 0);
				obj->toggle(seat);
				output.push_back("null");
			} },
			{ "getTotalTime", [&](const vector<string> &) {
				output.push_back(LeetCodeIO::serialize(obj->getTotalTime()));
			} },
			{ "getMinTime", [&](const vector<string> &) {
				output.push_back(LeetCodeIO::serialize(obj->getMinTime()));
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
