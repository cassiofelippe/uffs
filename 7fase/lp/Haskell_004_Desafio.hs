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
    deriving Show

-- increment Nat
incNat :: Nat -> Nat
incNat Zero = Suc Zero
incNat a = Suc a

-- decrement Nat
decNat :: Nat -> Nat
decNat Zero = Zero
decNat (Suc a) = a

-- addNat :: Nat Nat -> Nat
addNat a Zero = a
addNat a b = addNat (incNat a) (decNat b)

subNat a Zero = a
subNat Zero b = b
subNat a b = subNat (decNat a) (decNat b)

mulNat a Zero = Zero
mulNat a (Suc Zero) = a
mulNat a b = mulNat (addNat a a) (decNat b)