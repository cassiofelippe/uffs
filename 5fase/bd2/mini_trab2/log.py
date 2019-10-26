import re;
arquivo = open('teste03', 'r')
arquivolist = list(arquivo)    
UNDO = []                       
UNDOcheck = []


# DECLARANDO VARIÁVEIS PARA EVITAR UM CÓDIGO MUITO VERBOSO
commit = re.compile(r'commit', re.IGNORECASE) 
start = re.compile(r'start', re.IGNORECASE)
startckpt = re.compile(r'start ckpt', re.IGNORECASE)
endckpt = re.compile(r'end ckpt', re.IGNORECASE)
extracT = re.compile(r'(?!commit\b)(?!CKPT\b)(?!Start\b)\b\w+', re.IGNORECASE) 
words = re.compile(r'\w+', re.IGNORECASE)  

# PRIMEIRA LINHA DO ARQUIVO teste03
# QUE CONTÉM O VALOR INICIAL DOS ITENS
valores = words.findall(arquivolist[0])

# ATRIBUI OS VALORES PARA CADA VARIÁVEL (DE 'A' ATÉ 'H')
variaveis = {}
for i in range(0,len(valores),2): 
    variaveis[valores[i]]= valores[i+1]

end = 0


# ITERA SOBRE CADA "EXECUÇÃO" (LINHA) DO "SGBD"
# COMEÇANDO DE BAIXO PARA CIMA
for linha in reversed(arquivolist):
    # VERIFICA SE A LINHA É UM CHECKPOINT
    if startckpt.search(linha):
        # VERIFICA SE TERMINOU O CHECKPOINT
        if end:
            Tx = extracT.findall(linha)
            print("Start Checkpoint Txc", Tx)
            break
           
    # VERIFICA SE É INÍCIO DE TRANSAÇÃO
    elif start.search(linha):
        # RECUPERA O "NOME" DA TRANCAÇÃO
        Tx = extracT.findall(linha)[0]
        #if Tx not in REDO:
        # ADICIONA A TRANSAÇÃO NUM ARRAY PARA SER DESFEITA
        UNDO.append(Tx)

    # VERIFICA SE A LINHA EM QUESTÃO É O FIM DE UM CHECKPOINT
    elif endckpt.search(linha):
        print(" End  Checkpoint")
        end = 1

print("\nAplicar UNDO:", UNDO)

# PARA CADA LINHA DO ARQUIVO DE LOG
for i in range(len(arquivolist)-1, 0, -1): 
    linha = arquivolist[i]
    # VERIFICA SE É INÍCIO DE TRANSAÇÃO
    if start.search(linha) and not startckpt.search(linha):
        Tx = extracT.findall(linha)[0]
        # VERIFICA SE A TRANSAÇÃO EM QUESTÃO CONSTA
        # NA LISTA DE TRANSAÇÕES QUE DEVEM SER DESFEITAS
        if Tx in UNDO:
            # REMOVE A TRANSAÇÃO DA LISTA
            UNDO.remove(Tx)
            # E ADICIONA EM UMA LISTA DAS QUE FORAM DESFEITAS
            UNDOcheck.append(Tx)
     
        # SE NÃO HÁ MAIS TRANSAÇÕES PARA SEREM DESFEITAS
        # O LOOP É INTERROMPIDO
        if not len(UNDO):
            break

    # SE É UMA TRANSAÇÃO DA LISTA A SEREM DESFEITAS
    elif words.findall(linha)[0] in UNDO:
        # RESTAURA O VALOR DO ITEM PARA O VALOR INICIAL DO LOG
        variaveis[words.findall(linha)[1]] = words.findall(linha)[2]


# ITERA SOB OS CHECKPOINTS QUE FORAM FECHADOS
# NO CASO O ÚNICO É O DA TRANSAÇÃO T6
for j in range(i,len(arquivolist)-1,1):
    linha = arquivolist[j]
  

print("Aplicado UNDO:", UNDOcheck)
print("Resultado:", variaveis)
arquivo.close()
