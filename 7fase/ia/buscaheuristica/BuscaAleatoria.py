from AlgoritmoBusca import AlgoritmoBusca
import time
from Vizinhanca import Vizinhanca
from Solucao import Solucao


class BuscaAleatoria(AlgoritmoBusca):
    def __init__(self, vizinhanca: Vizinhanca, solucao_otima, solucao: Solucao = None):
        super().__init__("BA"+vizinhanca.nome, vizinhanca.distancias, solucao_otima)
        self.vizinhanca = vizinhanca
        if solucao is None:
            self.solucao = self.gerar_solucao_inicial_aleatoria()
        else:
            self.solucao = solucao

    def buscar_solucao(self) -> list[Solucao]:
        solucao_list = [self.solucao]
        iteracao = self.solucao.iteracao + 1
        melhor_qualidade = self.solucao.qualidade

        while time.time() < self.tempo_limite:
            self.solucao = self.vizinhanca.melhor_vizinho(self.solucao, set())

            if self.solucao.qualidade < melhor_qualidade:
                melhor_qualidade = self.solucao.qualidade
                self.solucao.tempo = time.time() - self.tempo_limite
                self.solucao.iteracao = iteracao
                solucao_list.append(self.solucao)
                if melhor_qualidade == self.solucao_otima:
                    return solucao_list
            else:  # não houve melhoras
                break

            iteracao += 1

        return solucao_list
