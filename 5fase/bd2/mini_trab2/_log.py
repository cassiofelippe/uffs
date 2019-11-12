import re;
arquivo = open('teste03', 'r')
arquivolist = list(arquivo)    
UNDO = []                       
UNDOcheck = []


  
commit = re.compile(r'commit', re.IGNORECASE) 
start = re.compile(r'start', re.IGNORECASE)
startckpt = re.compile(r'start ckpt', re.IGNORECASE)
endckpt = re.compile(r'end ckpt', re.IGNORECASE)
extracT = re.compile(r'(?!commit\b)(?!CKPT\b)(?!Start\b)\b\w+', re.IGNORECASE) 
words = re.compile(r'\w+', re.IGNORECASE)  

valores = words.findall(arquivolist[0])
variaveis = {}
for i in range(0,len(valores),2): 
    variaveis[valores[i]]= valores[i+1]

print("", variaveis)
end = 0

for linha in reversed(arquivolist): 
    if startckpt.search(linha):
        if end:
            Tx = extracT.findall(linha)
            print("Start Checkpoint Txc", Tx)
           
           
            break
    elif start.search(linha):   
        Tx = extracT.findall(linha)[0]
        #if Tx not in REDO:
        UNDO.append(Tx)

    elif endckpt.search(linha):
        print(" End  Checkpoint")
        end = 1

print("\nAplicar UNDO:", UNDO)

for i in range(len(arquivolist)-1, 0, -1): 
    linha = arquivolist[i]
    if start.search(linha) and not startckpt.search(linha):
        Tx = extracT.findall(linha)[0]
        if Tx in UNDO:
            UNDO.remove(Tx)
            UNDOcheck.append(Tx)
     
        if not len(UNDO):
            break
    elif words.findall(linha)[0] in UNDO:
        variaveis[words.findall(linha)[1]] = words.findall(linha)[2]

for j in range(i,len(arquivolist)-1,1):
    linha = arquivolist[j]
  

print("Aplicado UNDO:", UNDOcheck)
print("Resultado:", variaveis)
arquivo.close()
