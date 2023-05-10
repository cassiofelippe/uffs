module Haskell_005_Lista where


-- 1. Defina uma função que recebe o salário base de um funcionário e resulta no salário líquido a
-- receber, sabendo-se que o funcionário tem gratificação de 10% sobre o salário base e paga
-- imposto de 7% sobre o salário base. Exemplos: salário 1000 -> 1030.0 | 850 -> 875.5

e01 :: Double -> Double
e01 sal = sal * 1.1 - sal * 0.07


-- 2. A nota final de um estudante é calculada a partir de três notas atribuídas respectivamente a
-- um trabalho de laboratório, a uma avaliação semestral e a um exame final. A média
-- ponderada das três notas mencionadas obedece aos pesos a seguir:

-- nota                    | peso
-- ________________________|_____
-- trabalho de laboratório | 2
-- avaliação semestral     | 3
-- exame final             | 5

-- Faça uma função que recebe as três notas, calcula a média ponderada e exibe o conceito
-- obtido pelo aluno conforme a tabela abaixo.

-- média ponderada | conceito
-- ________________|_________
-- [8.0 - 10.0]    | A
-- [7.0 - 8.0[     | B
-- [6.0 - 7.0[     | C
-- [5.0 - 6.0[     | D
-- [0.0 - 5.0[     | E

e02 :: Double -> Double -> Double -> Char
e02 a b c = let d = (a * 0.2 + b * 0.3 + c * 0.5)
    in case () of
          _ | d >= 8.0 && d <= 10.0 -> 'A'
            | d >= 7.0 && d < 8.0 -> 'B'
            | d >= 6.0 && d < 7.0 -> 'C'
            | d >= 5.0 && d < 6.0 -> 'D'
            | d >= 0.0 && d < 5.0 -> 'E'


-- 3. O estúdio fotográfico Boa Imagem cobra de seus clientes por retratos antigos baseando-se
-- no número de indivíduos incluídos no retrato. As tarifas constam da tabela seguinte:

-- individuos no retrato   | preço base
-- 1                       | R$ 100,00
-- 2                       | R$ 130,00
-- 3                       | R$ 150,00
-- 4                       | R$ 165,00
-- 5                       | R$ 175,00
-- 6                       | R$ 180,00
-- 7 ou mais               | R$ 185,00

-- Retratos antigos tirados aos sábados ou aos domingos custam 20% a mais do que o preço
-- base. Defina uma função precoRetrato do tipo Integer -> String -> Double que recebe como
-- argumentos o número de pessoas no retrato e o dia da semana agendado, e calcula o custo do
-- retrato. Exemplos:

-- precoRetrato 4 "quinta" -> 165.0
-- precoRetrato 9 "sexta" -> 185.0
-- precoRetrato 9 "sábado" -> 222.0
-- precoRetrato 2 "domingo" -> 156.0

e03 = precoRetrato

precoRetrato :: Integer -> String -> Double
precoRetrato qtd dia = e03_precoDia (e03_precoBase qtd) dia

e03_precoBase :: Integer -> Double
e03_precoBase a | a == 1 = 100.0
                | a == 2 = 130.0
                | a == 3 = 150.0
                | a == 4 = 165.0
                | a == 5 = 175.0
                | a == 6 = 180.0
                | otherwise = 185.0

e03_precoDia :: Double -> String -> Double
e03_precoDia preco dia | dia == "sábado" || dia == "domingo" = preco * 1.2
                       | otherwise = preco


-- 4. O fatorial duplo de um número natural n é o produto de todos os números de 1 (ou 2) até n,
-- contados de 2 em 2. Por exemplo, o fatorial duplo de 8 é 8 × 6 × 4 × 2 = 384, e o fatorial
-- duplo de 7 é 7 × 5 × 3 × 1 = 105. Defina uma função para calcular o fatorial duplo usando
-- recursividade.

e04 :: Integer -> Integer
e04 0 = 1
e04 1 = 1
e04 a = a * e04 (a - 2);


-- 5. Defina uma função recursiva para calcular a potência de um número, considerando que o
-- expoente é um número natural. Utilize o método das multiplicações sucessivas:
-- x^n = x * x * ... * x

e05 :: Integer -> Integer -> Integer
e05 a 0 = 1
e05 a 1 = a
e05 a b = a * (e05 a (b - 1))


-- 6. Um funcionário de uma empresa recebe aumento salarial anualmente. O primeiro aumento é
-- de 1,5% sobre seu salário inicial. Os aumentos subsequentes sempre correspondem ao dobro
-- do percentual de aumento do ano anterior. Faça uma função onde é informado o salário
-- inicial do funcionário, o ano de contratação e o ano atual, e calcula e exibe o seu salário
-- atual.

e06 :: Double -> Integer -> Integer -> Double
e06 salAtual anoContr anoAtual = let aumento = 0.015
    in case () of
          _ | anoAtual - anoContr == 0 -> salAtual
            | anoAtual - anoContr == 1 -> salAtual + salAtual * aumento
            | otherwise                -> (+salAtual) (e06 (salAtual + salAtual * (fromIntegral (anoAtual - anoContr) * aumento)) anoContr (anoAtual - 1))


-- 7. Defina uma função chamada ultimo que seleciona o último elemento de uma lista não vazia

e07 :: [a] -> [a]
e07 a | null (tail a) && not (null a) = [head a]
      | null (tail (tail a)) = tail a
      | otherwise = e07 (tail a)


-- 8. Defina uma função chamada primeiros que seleciona todos os elementos de uma lista não vazia,
-- exceto o último.
-- obs.: aqui fiquei na dúvida na interpretação, quando tem somente um elemento, deve retorná-lo ou retornar lista vazia?

e08 :: [a] -> [a]
e08 a | null (tail a) = a -- quando tem só um elemento, retornando-o, ao invés de lista vazia
      | null (tail (tail a)) = [head a]
      | otherwise = [head a] ++ e08 (tail a)


-- 9. Faça uma função que receba duas listas e retorne outra lista produto destas duas listas, ou
-- seja, cada posição das listas de entrada devem ser multiplicadas e armazenadas na mesma
-- posição na lista de saída.

e09 :: [Integer] -> [Integer] -> [Integer]
-- e09 a b | null (tail a) = a
e09 a b | null (tail a) = [head a * head b]
        | otherwise = [head a * head b] ++ e09 (tail a) (tail b)


-- 10. Defina um novo tipo de dado chamado Produto, que permita armazenar informações sobre:
--  a. Produto perecível: código, descrição, ano de validade e se é comestível ou não.
--  b. Produto não perecível: código, descrição, fabricante, ano de fabricação.
-- Faça testes com este novo tipo de dado.

data Produto = Perecivel Integer String Integer Bool Unidade Peso
    | NaoPerecivel Integer String String Integer Unidade Peso
    deriving Show

showProduto :: Produto -> String
showProduto produto = case produto of
    Perecivel cod des val com uni pes -> "Codigo: " ++ show cod
                              ++ " | Descricao: " ++ des
                              ++ " | Ano de Validade: " ++ show val
                              ++ " | Comestivel: " ++ show com
                              ++ " | " ++ show uni
                              ++ " | " ++ show pes ++ "kg"
    NaoPerecivel cod des fab ano uni pes -> "Codigo: " ++ show cod
                              ++ " | Descricao: " ++ des
                              ++ " | Fabricante: " ++ fab
                              ++ " | Ano de Fabricacao: " ++ show ano
                              ++ " | " ++ show uni
                              ++ " | " ++ show pes ++ "kg"

validadeProduto :: Produto -> Integer
validadeProduto (Perecivel _ _ val _ _ _) = val
validadeProduto (NaoPerecivel _ _ _ _ _ _) = 0

--  inputs
-- let p1 = Perecivel 1001 "Cerveja Antartica" 2023 True
-- let p2 = NaoPerecivel 1002 "Arroz Prato Fino" "Prato Fino LTDA."


-- 11. Defina um novo tipo de dado para armazenar a forma de comercialização de um produto,
-- com duas opções:
--  a. Unidade
--  b. Peso
-- Adicione este novo tipo de dado às duas opções do produto e refaça os testes anteriores.

data Unidade = Unidade Integer
    deriving Show

data Peso = Peso Double
    deriving Show

--  inputs
-- let p1 = Perecivel 1001 "Cerveja Antartica" 2023 True (Unidade 12) (Peso 5.3)
-- let p2 = NaoPerecivel 1002 "Arroz Prato Fino" "Prato Fino LTDA." 2022 (Unidade 50) (Peso 10.0)


-- 12. Faça uma função que receba um produto e o ano atual e verifique se ele ainda está válido
-- para uso, retornando um valor booleano. Considere que produtos não perecíveis sempre
-- estão válidos.

e12 = validoProduto

validoProduto :: Produto -> Integer -> Bool
validoProduto p anoAtual = case p of
    Perecivel _ _ _ _ _ _ -> (validadeProduto p) >= anoAtual
    NaoPerecivel _ _ _ _ _ _ -> True


-- 13. Escreva as funções and e or usando casamento de padrões.

and' :: Bool -> Bool -> Bool
and' False _ = False
and' _ False = False
and' a b = True

or' :: Bool -> Bool -> Bool
or' True _ = True
or' _ True = True
or' a b = False


-- 14. Usando casamento de padrão, defina uma função que, dada uma lista de números, retorna:
--  a. a soma dos dois primeiros elementos, se a lista tiver pelo menos dois elementos;
--  b. a cabeça da lista, se ela contiver apenas um elemento;
--  c. zero, caso contrário.

e14 :: [Integer] -> Integer
e14 [a, b] = a + b
e14 [a, b, _] = a + b
e14 [a] = a
e14 a = 0


-- 15. Utilize uma função de alta ordem para realizar a contagem de elementos de uma lista.

len :: [a] -> Integer
len [] = 0
len (x:xs) = (+1) (len xs)


-- 16. Identifique qual é o resultado da compilação e avaliação das expressões a seguir, podendo
-- ser um determinado valor ou lista de valores, erro de sintaxe ou erro de tipo.
--     a. if 1 == 2 then "abc" else [’d’, ’e’, ’f’]
--     b. let pot_dois x | x <= 0 = 1
--                       | otherwise = 2 * pot_dois (x-1)
--         in pot_dois 6
--     c. case not (1 /= 2) of
--             True -> 3
--             False -> "fim”
--     d. filter (not . even . (+3)) [5, 6, 7, 8, 9]
--     e. sum (map (logBase 3) [9, 27, 81])
--     f. foldl (\x y -> x + y) 0 [10,20,30]

-- a: error: lexical error at character 'd'
-- b: 64
-- c: error: lexical error in string/character literal at end of input
-- d: [6,8]
-- e: 9.0
-- f: 60