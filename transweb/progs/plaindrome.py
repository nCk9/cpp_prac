name = input("Enter your name: ")
opt_str = ""
var = len(name)-1
while var >= 0:
    if var == len(name)-1:
        opt_str += name[var].upper()
    elif name[var].isupper():
        opt_str += name[var].lower()
    else:
        opt_str += name[var]
    var -= 1

print (opt_str)
if name.lower() == opt_str.lower():
    print("Plaindrome!")

    