# Created by oportunitas at 2026/09/22 14:30
# leetgo: 1.4.18
# https://leetcode.com/problems/daily-leads-and-partners/

# @lc code=begin

import pandas as pd

def daily_leads_and_partners(daily_sales: pd.DataFrame) -> pd.DataFrame:
    result = pd.DataFrame(
        daily_sales.groupby(["date_id", "make_name"])[["lead_id", "partner_id"]]
        .nunique()
        .reset_index()
        .rename(columns={"lead_id": "unique_leads", "partner_id": "unique_partners"}))
    return result

# @lc code=end
