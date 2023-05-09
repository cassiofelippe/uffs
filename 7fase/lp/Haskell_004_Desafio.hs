-- Desafio
-- ● Implementar o tipo algébrico Nat para representar números naturais.
    -- ○ Deve possuir dois construtores de tipo: Zero e o sucessor de um número (Suc).
    -- ○ Este tipo deve ser recursivo.
    -- ○ Exemplos:
        -- ■ Zero representa o número zero.
        -- ■ Suc Zero representa o número um.
        -- ■ Suc (Suc Zero) representa o número dois.
-- ● Crie algumas funções sobre esse tipo:
    -- ○ Representação dos números de 1 à 4.
    -- ○ Conversões nat2integer e integer2nat.
    -- ○ Funções: natAdd, natSub, natMul.


module Haskell_004_Desafio where

data Nat = Zero
    | Suc Nat
    deriving (Show, Eq)

-- increment Nat
incNat :: Nat -> Nat
incNat Zero = Suc Zero
incNat a = Suc a

-- decrement Nat
decNat :: Nat -> Nat
decNat Zero = Zero
decNat (Suc a) = a

addNat :: Nat -> Nat -> Nat
addNat a Zero = a
addNat a b = addNat (incNat a) (decNat b)

subNat :: Nat -> Nat -> Nat
subNat a Zero = a
subNat Zero b = b
subNat a b = subNat (decNat a) (decNat b)

mulNat :: Nat -> Nat -> Nat
mulNat a Zero = Zero
mulNat a (Suc Zero) = a
mulNat a b = mulNat (addNat a a) (decNat b)

incInt :: Int -> Int
incInt a = a + 1

decInt :: Int -> Int
decInt a = a - 1

intToNat :: Int -> Nat
intToNat a = if a == 0 then Zero else intToNatAux a Zero

intToNatAux :: Int -> Nat -> Nat
intToNatAux a b = if a == 0 then b else intToNatAux (decInt a) (incNat b)

natToInt :: Nat -> Int
natToInt a = if a == Zero then 0 else natToIntAux a 0

natToIntAux :: Nat -> Int -> Int
natToIntAux a b = if a == Zero then b else natToIntAux (decNat a) (incInt b)

nat1to4 :: IO ()
nat1to4 = nat1to4Aux Zero 0

nat1to4Aux :: Nat -> Int -> IO ()
nat1to4Aux a b = if b == 4 then
        -- print (a, b)
        putStrLn ((show a) ++ " == " ++ (show b))
    else do
        putStrLn ((show a) ++ " == " ++ (show b))
        nat1to4Aux (incNat a) (incInt b)
