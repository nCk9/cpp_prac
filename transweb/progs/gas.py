no_of_gallons = int(input("Enter the number of gallons of gasoline: "));

in_liters = no_of_gallons*3.7854
no_oil_barrrels = no_of_gallons/(19.5)
price_usd = no_of_gallons*3.65

print("Equivalent number of liters is: ", ('%.4f'%in_liters))
print("Number of barrels of oil req. to produce it: ", ('%.3f'%no_oil_barrrels))
print("Price in U.S.dollars: ", ('%.2f'%price_usd))