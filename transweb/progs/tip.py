price = float(input("Enter the price of a meal: "))


tip = (price) * 0.16
total = price + tip
print("A 16% tip would be:", ('%.2f'%tip))
print("The total including tip would be:", ('%.2f'%total))
 