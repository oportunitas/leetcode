# Created by oportunitas at 2026/09/19 06:04
# leetgo: 1.4.18
# https://leetcode.com/problems/modify-columns/

# @lc code=begin

import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees["salary"] = employees["salary"] * 2
    return employees

# @lc code=end
