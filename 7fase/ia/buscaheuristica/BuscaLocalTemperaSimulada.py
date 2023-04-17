from Vizinhanca2opt import Vizinhanca2opt
from Solucao import Solucao

params = {
    "vizinhanca": None,
    "custo_solucao_otima": None,
    "tipo_progressao_resfriamento": None, # geometrica, linear
    "progressao_resfriamento": None,
    "velocidade_resfriamento": None,
    "solucao_inicial": None
}

initial_values = {
    "temperatura_inicial": 1
}

print('>>', Solucao)