import pytest
from translation import prefix_to_infix

def test_prefix_to_infix():
    assert prefix_to_infix("+ - 13 4 55") == "((13 - 4) + 55)"
    assert prefix_to_infix("+ 2 * 2 - 2 1") == "(2 + (2 * (2 - 1)))"
    assert prefix_to_infix("+ + 10 20 30") == "((10 + 20) + 30)"
    assert prefix_to_infix("/ + 3 10 * + 2 3 - 3 5") == "((3 + 10) / ((2 + 3) * (3 - 5)))"
    
    with pytest.raises(ValueError) as ex1:
        prefix_to_infix("- 5 32 67 11")
    assert str(ex1.value) == "Ошибка: Лишние операнды или операторы в выражении"

    with pytest.raises(ValueError) as ex2:
        prefix_to_infix("- - 1 2")
    assert str(ex2.value) == "Ошибка: Недостаточно операндов для оператора"