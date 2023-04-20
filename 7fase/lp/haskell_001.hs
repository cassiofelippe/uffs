x = ["a", "b"]
y = ["c", "d", "e"]

main = do

    -- Reescreva as listas anteriores utilizando apenas (:) e o construtor de lista vazia [].


    -- Escreva uma expressão que verifica se uma lista está vazia, [], ou se o primeiro elemento é vazio, como [[],[‘a’,‘b’]].
    print( null x || null (head x) )

    -- Escreva uma expressão que verifica se uma lista tem somente um elemento. Ela deve retornar True para [‘a’] e False para [] ou [‘a’, ‘b’].
    print( not (null x) && null (tail x) )

    -- Escreva uma expressão que concatena duas listas dadas dentro de outra lista. Por exemplo, ela deve retornar “abcde” para [“abc”, “de”].
    print( x ++ y )

    return 0