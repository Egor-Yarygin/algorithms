from translation.base import prefix_to_infix

prefix_expression = input("Введите префиксное выражение (с пробелами между операндами и операторами): ")
try:
    infix_expression = prefix_to_infix(prefix_expression)
    print("Инфиксное выражение:", infix_expression)
except ValueError as e:
    print(e)