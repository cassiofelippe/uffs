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

-- e06 :: Double -> Integer -> Integer -> Double
-- e06 salAtual anoContr anoAtual
--     | anoAtual - anoContr == 0 = salAtual
--     | anoAtual - anoContr == 1 = salAtual + salAtual * (0.015 :: Double)
--     | otherwise = e06_aux salAtual anoContr anoAtual (0.015 :: Double)

-- e06_aux :: Double -> Integer -> Integer -> Double -> Double
-- e06_aux salAtual anoContr anoAtual aumento
--     | anoAtual - anoContr == 0 = salAtual
--     | anoAtual - anoContr == 1 = salAtual + (salAtual * (aumento :: Double))
--     | otherwise = salAtual * (e06_aux salAtual anoContr (anoAtual - 1) (aumento * fromIntegral (anoAtual - anoContr)))


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

data Produto = Perecivel Integer String Integer Bool
    | NaoPerecivel Integer String String Integer
    deriving Show

showProduto :: Produto -> String
showProduto produto = case produto of
    Perecivel cod des val com -> "Codigo: " ++ show cod
                              ++ " | Descricao: " ++ des
                              ++ " | Ano de Validade: " ++ show val
                              ++ " | Comestivel: " ++ show com
    NaoPerecivel cod des fab ano -> "Codigo: " ++ show cod
                              ++ " | Descricao: " ++ des
                              ++ " | Fabricante: " ++ fab
                              ++ " | Ano de Fabricacao: " ++ show ano

--  inputs
-- let p1 = Perecivel 1001 "Cerveja Antartica" 2023 True
-- let p2 = NaoPerecivel 1002 "Arroz Prato Fino" "Prato Fino LTDA." 2022
