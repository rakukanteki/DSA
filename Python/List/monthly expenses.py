# My monthly expenses.

exp = [2200, 2350, 2600, 2130, 2190]

# 1) How much dollar spent extra compared to Januray.
print("Extra money spent in Feburary compared to Januray: ", exp[1]-exp[0])

# 2) Total expenses in first 3 months.
print("Total cost in first 3 months: ", exp[0]+exp[1]+exp[2])

# 3) If I had spent 2000$ in any month.
print("2000$ spent in any month? ", 2000 in exp)

# 4) After June month, adding the expense 1980 in the list.
exp.append(1980)
print("After June, Total expense list: ", exp)

# 5) Got a refund in April of 200$.
exp[3] = exp[3] - 200
print("Expense list after the refund: ", exp)
