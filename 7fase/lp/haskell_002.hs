x = ["a", "b"]
y = ["c", "d", "e"]

square_the_double_of a = (a * 2) ^ 2
double_the_square_of a = (a ^ 2) * 2
average_of a b c = (a + b + c) / 3

eletric_bill salary qw_spent = (salary / 5) * qw_spent * 0.85

main = do

    -- Defina uma função para calcular o quadrado do dobro do seu argumento.
    print( square_the_double_of 2 )

    -- Defina uma função para calcular o dobro do quadrado do seu argumento.
    print( double_the_square_of 2 )

    -- Faça uma função que receba três notas de um aluno e calcule a média aritmética das notas.
    print( average_of 8 9 10 )

    -- Sabe-se que o valor do quilowatt de energia elétrica custa um quinto do salário mínimo.
    -- Defina uma função que receba o valor do salário mínimo e a quantidade de quilowatts consumida por uma residência,
    -- e resulta no valor a ser pago com desconto de 15%.
    print( eletric_bill 1320 0.01 )

    return 0
