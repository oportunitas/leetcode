// Created by oportunitas at 2026/10/24 10:24
// leetgo: 1.4.18
// https://leetcode.com/problems/count-days-spent-together/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/* idea #0
    convert the timestamps to day of year, then simply find difference
*/
class Solution {
private:
    const array<int, 12> _mo_days {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int _get_daynum(string& time) {
        int day {(time[3] - '0') * 10 + (time[4] - '0')};
        int mo {_mo_days[(time[0] - '0') * 10 + (time[1] - '0') - 1]};
        return mo + day;
    }
public:
    int countDaysTogether(
        string arriveAlice, string leaveAlice, string arriveBob, string leaveBob
    ) {
        return(max(0, (
            min(_get_daynum(leaveAlice), _get_daynum(leaveBob)) - 
            max(_get_daynum(arriveAlice), _get_daynum(arriveBob)) + 1
        )));
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string arriveAlice = LeetCodeIO::deserialize<string>(cin);
		string leaveAlice = LeetCodeIO::deserialize<string>(cin);
		string arriveBob = LeetCodeIO::deserialize<string>(cin);
		string leaveBob = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
