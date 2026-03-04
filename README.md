# NLD - Nildo Compilador

## Descrição

Linguagem de Programação PT-BR Acentuado s/ Anglicismos.

- Compilador: nld
- Ponto de Entrada: Início()
- Tipagem: Fraca e Estática

## Como Instalar

### Linux/Unix
    Aviso! Nessa somente é possível utilizar usando wine.

### Windows

#### Requisitos
- Algum compilador C (gcc, clang, tcc ...)

- Comando:

````
    win32/construa-nld.bat
````

## Exemplo de Código
### Olá Mundo

````
// Usando biblioteca padrão do C
Externo Inteiro printf(Imutável Caractere*, ...);

#Defina exiba_formatado printf

Inteiro Início() {
    Imutável Caractere* mensagem = "Olá,";
    exiba_formatado("%s %s!\n", mensagem, "Mundo");
    Retorne 0;
}

````

Comando no Powershell
````
nld.exe ola_mundo.nld
./ola_mundo
````

Comando no CMD
````
nld.exe ola_mundo.nld
ola_mundo
````

## Referência Rápida

### Pré-Processadores
- #Aviso
- #Erro
- #Diretiva
- #Inclua
- #Defina
- #SeDefinido
- #SeNãoDefinido
- #Esqueça
- #FimSe

### Especificadores de Âncoragem
- Fixo
- Externo

### Tipos de Dados
- Vazio
- Lógico
- Inteiro
- Real
- Duplo
- Caractere

### Modificadores de Tipos
- Curto
- Longo
- Natural
- Bilateral

### Qualificadores de Variável
- Imutável
- Instável
- Integrado
- Exclusivo

### Estrutura de Dados
- Enumeração
- Estrutura
- Pseudônimo
- União

### Ponteiro
- Sinal de Ponteiro - *
- Operador de Referência - &

### Controle de Fluxo
- Se
- Para
- Retorne
- Execute
-  Obs.: Não existe Senão, SenãoSe, Enquanto, Faça...Enquanto, Troque...Caso nativos.

### Operadores
- Aritméticos: +, -, *, /, %, ++, --
- Atribuição: =, +=, -=, *=, /=, %=
- Bit a Bit: &, |, ^, ~, <<, >>
- Comparação: ==, !=, >, <, >=, <=

### Funções de Compilador
- afirme_constante
- atribua
- compare_tipo_compatível
- deduza
- escolha_expressão
- identifique
- Início
- Genérico
- meça
- Montador
- obtenha_alinhamento
- obtenha_endereço_pilha
- obtenha_endereço_retorno

### MACRO de Compilador
- ARQUIVO
- ARGUMENTOS_VARIÁVEIS
- DATA
- CONTADOR
- FUNÇÃO
- HORA
- LINHA