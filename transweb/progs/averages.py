import math

print("Enter two numbers: ")
a, b = map(int, input().split())
print("Enter 1 for arithmetic mean.")
print("Enter 2 for geometric mean.")
print("Enter 3 for root-mean-square.")
get_inpt = int(input("Your input: "))

if get_inpt == 1:
    print("Answer is: ", (a+b)//2)
elif get_inpt == 2:
    print("Answer is: ", math.sqrt(a*b))
elif get_inpt == 3:
    print("Answer is: ", math.sqrt(((a*a) + (b*b))/2))
else:
    print("Invalid input.")