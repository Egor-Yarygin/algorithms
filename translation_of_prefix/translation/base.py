def is_operator(token):
    return token in ['+', '-', '*', '/']

def prefix_to_infix(expression):
    tokens = expression.split()
    stack = []

    for token in reversed(tokens):
        if token.isnumeric():
            stack.append(token)
        elif is_operator(token):
            if len(stack) < 2:
                raise ValueError("Ошибка: Недостаточно операндов для оператора")
            operand1 = stack.pop()
            operand2 = stack.pop()
            infix_expression = f"({operand1} {token} {operand2})"
            stack.append(infix_expression)

    if len(stack) == 1:
        return stack[0]
    else:
        raise ValueError("Ошибка: Лишние операнды или операторы в выражении")