module Haskell_003 where

data Client = Org String
    | Emp String Integer String String
    | Ind Pessoa Bool
    deriving Show -- avoid error printing error after constructing

data Pessoa = Pessoa String String Genero
    deriving Show

data Genero = Masculino
    | Feminino
    | Outro String
    deriving Show

-- naming parameters
data Pointer = Pointer {
        x :: Double,
        y :: Double
    }
    deriving Show

-- let pointer = Pointer 1.0 2.0
-- let pointer = Pointer { x = 1.0, y = 2.0 }
-- x pointer >> 1.0
-- ">>" mean yields

-- pattern matching
nomeCliente :: Client -> String
nomeCliente cliente = case cliente of
    Org nome -> nome
    Emp nome id resp cargo -> nome
    Ind pessoa ads ->
        case pessoa of
            Pessoa nome sobrenome genero -> nome ++ " " ++ sobrenome

-- let org = Org "UFFS"
-- nomeCliente org >> "UFFS"

-- let emp = Emp "Padaria" 1001 "Chefe" "Dono"
-- nomeCliente emp >> "Padaria"

-- let ind = Ind (Pessoa "Cassio" "Felippe" Masculino) True
-- nomeCliente ind >> "Cassio Felippe"


-- type Maybe
nomeEmpresa :: Client -> Maybe String
nomeEmpresa client = case client of
    Emp nome _ _ _ -> Just nome
    _              -> Nothing

-- let emp = Emp "Padaria" 1001 "Chefe" "Dono"
-- nomeEmpresa emp >> Just "Padaria"

-- let org = Org "UFFS"
-- nomeEmpresa org >> Nothing
