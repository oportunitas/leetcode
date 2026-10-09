# Created by oportunitas at 2026/10/09 11:30
# leetgo: 1.4.18
# https://leetcode.com/problems/reshape-data-melt/

# @lc code=begin

import pandas as pd

def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    # pd.melt(report, id_vars=["product"], value_vars=[col in ])
    return pd.melt(report, 
        id_vars=["product"], var_name="quarter", value_name="sales",
        value_vars=[col for col in report.columns if "quarter" in col])

# @lc code=end
