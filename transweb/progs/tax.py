income = int(input("Please enter your income: "))

tax_amt = 0
if income > 1000:
    income -= 1000
    tax_amt += 0.05 * 1000
else:
    tax_amt += 0.05 * income
    income = 0

if income > 1000:
    income -= 1000
    tax_amt += 0.10 * 1000
else:
    tax_amt += 0.10 * income
    income = 0

if income > 0:
    tax_amt += 0.15 * income

print("The tax owed is: $", tax_amt)