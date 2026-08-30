// Created by oportunitas at 2026/08/27 07:37
// leetgo: 1.4.18
// https://leetcode.com/problems/basic-calculator/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin


class Solution {
public:
	int calculate(string s) {
		// "-(-(-(-(-2+(-(2-3)-(2))))))"
		// 5      5      6      5
		// (-2) + (-2) + (+3) + (-2)

		/*
			-(
			  -(
			    -(
				  -(
				    -2+(
					  -(
					    2-3
					  )-(
					    2
					  )
				    )
				  )
			    )
		      ) 
			)
		*/
		// 
		// -( adds 1 to flip_num
		// ) 
		s.push_back(' ');
		int64_t res = 0;
		vector<bool> neg_v {};
		int64_t flip_count = 0;
		int64_t cur_neg = 0;
		
		for (string temp {""}; auto [i, c]: s | views::enumerate) {
			if (isdigit(c)) {
				temp.push_back(c);
			} else {
				if (!temp.empty()) {
					int64_t num = stoll(temp);
					if ((cur_neg + flip_count) % 2 == 1) {
						num *= -1;
					} res += num;
					cur_neg = 0;
					temp.clear();
				}

				if (c == '-') {
					cur_neg += 1;
				} else if (c == '(') {
					if (cur_neg) {
						neg_v.push_back(1);
						cur_neg -= 1;
					} else {
						neg_v.push_back(0);
					} flip_count += neg_v.back();
				} else if (c == ')') {
					flip_count -= neg_v.back();
					neg_v.pop_back();
				}
			}

			// print("{} ", c);
			// println("{}", nums);
			// print("{} ", c);
			// println("{}", neg_v);
			// println();
		}

		return (int) res;
	}
	// int calculate(string s) {
	// 	vector<string> rpn {};
	// 	vector<char> opr {};
	// 	s.append(" ");

	// 	auto eval_once = [&rpn, &opr] () -> void {

	// 		println("evaluating");
	// 		println("rpn: {}", rpn);
	// 		println("opr: {}", opr);
	// 		println("");

	// 		if (rpn.size() < 3) return;
	// 		auto sign = rpn.back()[0];
	// 		if (!ranges::contains("+-", sign)) return;
	// 		rpn.pop_back();

	// 		auto num2 = stoi(rpn.back()); rpn.pop_back();
	// 		auto num1 = stoi(rpn.back()); rpn.pop_back();

	// 		switch (sign) {
	// 			case '+':
	// 				rpn.push_back(to_string(num1 + num2));
	// 				break;
	// 			case '-':
	// 				if (opr.back() == '-') {

	// 				}
	// 				rpn.push_back(to_string(num1 - num2));
	// 				break;
	// 			default:
	// 				break;
	// 		}

	// 		println("evaluation success");
	// 		println("rpn: {}", rpn);
	// 		println("opr: {}", opr);
	// 		println("");
	// 	};

	// 	for (
	// 		struct {string temp_num; char last_scan;} _this {"", 'o'}; 
	// 		auto [i, c]: s | views::enumerate
	// 	) {
	// 		eval_once();

	// 		println("rpn: {}", rpn);
	// 		println("opr: {}", opr);
	// 		println("c  : {}", c);
	// 		println("");

	// 		if (isdigit(c)) {
	// 			_this.temp_num.push_back(c);
	// 		} else {
	// 			// no longer sees number, so we put the temp string to the rpn stack
	// 			if (!_this.temp_num.empty()) {
	// 				rpn.push_back(_this.temp_num);
	// 				_this.temp_num.clear();
	// 			} 
				
	// 			if (!opr.empty()) {
	// 				if (ranges::contains("+-", c) && ranges::contains("+-", opr.back())) {
	// 					rpn.push_back(format("{}", opr.back())); opr.pop_back();
	// 				} else if (opr.back() == ')') {
	// 					while (opr.back() != '(') {
	// 						if (opr.back() != ')') {
	// 							rpn.push_back(format("{}", opr.back()));
	// 						} opr.pop_back(); eval_once();
	// 					} opr.pop_back();
	// 				}
	// 			}
	// 			if (!isspace(c)) opr.push_back(c);

				
	// 		}
	// 	} while (!opr.empty()) {
	// 		rpn.push_back(format("{}", opr.back()));
	// 		eval_once();
	// 		opr.pop_back();
	// 	}

	// 	println("{}", rpn);

	// 	return stoi(rpn.back());
	// }

    // int calculate(string s) {
	// 	vector<char> opr {};
	// 	vector<int> num {};
	// 	s.append("  ");

	// 	auto eval_once = [&opr, &num] () -> void {
	// 		println("");
	// 		while (opr.size() > 0) {
	// 			if (opr.size() == 0 || num.size() == 1) break;
	// 			if (opr.size() > 0 && opr.back() == '(') {
	// 				opr.pop_back();
	// 				break;
	// 			}

	// 			println("doing eval");
	// 			println("    opr: {}", opr);
	// 			println("    num: {}", num);

	// 			int num1 = num.back(); num.pop_back();
	// 			int num2 = num.back(); num.pop_back();
				
	// 			println("eval: {} {} {}", num2, opr.back(), num1);
				
	// 			switch (opr.back()) {
	// 				case '+':
	// 					num.push_back(num2 + num1);
	// 					break;
	// 				case '-':
	// 					num.push_back(num2 - num1);
	// 					break;
	// 				default:
	// 					break;
	// 			}

	// 			opr.pop_back();
	// 		}

	// 		return;
	// 	};

	// 	// `last` is a flag to store what the last thing pushed is (o = opr, n = num)
	// 	// 
    //     for (
	// 		struct {char last_scan; string temp_num; int last_num;} _this {' ', "", 0}; 
	// 		auto [i, c]: s | views::enumerate
	// 	) {
	// 		println("scanning s[{}]: '{}'", i, c);
	// 			println("    last opr: {}", opr);
	// 			println("    last num: {}", num);
	// 			println("    last scn: {}", _this.last_scan);
	// 			println("    temp num: {}", _this.temp_num);

	// 		if (ranges::contains("0123456789", c)) {
	// 			_this.temp_num.push_back(c);
	// 			_this.last_scan = 'n';
	// 		} else {
		
	// 			if (_this.last_scan == 'n') { 
	// 				auto [last_num_p, last_num_e] = from_chars(
	// 					_this.temp_num.data(), 
	// 					_this.temp_num.data() + _this.temp_num.size(), 
	// 					_this.last_num
	// 				);
	// 				num.push_back(_this.last_num);
	// 				println("pushed back {}", _this.last_num);
	// 				_this.temp_num = "";
	// 			}

	// 			if (ranges::contains("+-()", c)) {
	// 				opr.push_back(c);
	// 				_this.last_scan = 'o';
	// 			} else {
	// 				// whitespace/misc characters scan
	// 				_this.last_scan = 'w';
	// 			}
	// 		}
	// 	}

	// 	if (opr.size() > 0) {
	// 		eval_once();
	// 		println("opr is not empty");
	// 	}
	// 	println("result: {}", num.back());

	// 	return num.back();
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.calculate(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
