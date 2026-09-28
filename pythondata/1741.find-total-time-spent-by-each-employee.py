# Created by oportunitas at 2026/09/28 07:57
# leetgo: 1.4.18
# https://leetcode.com/problems/find-total-time-spent-by-each-employee/

# @lc code=begin

import pandas as pd

def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    employees = employees.groupby(["event_day", "emp_id"], as_index=False).sum()
    employees["total_time"] = employees["out_time"] - employees["in_time"]
    employees = employees.drop(columns=["in_time", "out_time"])
    employees = employees.rename(columns={"event_day": "day"})
    return employees
    

# @lc code=end
