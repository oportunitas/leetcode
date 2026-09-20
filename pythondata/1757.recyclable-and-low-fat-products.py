# Created by oportunitas at 2026/09/20 08:34
# leetgo: 1.4.18
# https://leetcode.com/problems/recyclable-and-low-fat-products/

# @lc code=begin

import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    return products[
        (products["low_fats"] == "Y") & (products["recyclable"] == "Y")
    ][["product_id"]]

# @lc code=end
