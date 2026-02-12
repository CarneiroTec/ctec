# Padrão de Projetos CTEC

> **Inspirada em CTEC, mas com identidade própria. Todo o desenvolvimento respeita a [LGPL v2.1](COPYING) e busca inovação sem ferir licenças.**

---

## 1. Básico
- **Compilador:** `ctec`
- **Biblioteca Convencional:** `#Inclua <Convencional/Convencional.ctec>`
- **Função de Entrada:** `Início()`
- **Case Sensitive:** Sim
- **Tipagem:** Forte e Estática
- **Idioma:** Português Brasileiro acentuado (nomes de arquivos sem acentos)

---

## 2. Arquitetura de Pastas
```
./Inicio.ctec           # Ponto de entrada do programa
./LEIAME.md             # Descrição do projeto
./Projeto.nds           # Definição do projeto
./Dependencia/          # Dependências externas
    Autocarregamento.ctec
./Fonte/                # Código-fonte principal
    [Pastas de Módulos]
    [NomeDoProjeto].ctec
./Teste/                # Testes unitários e integração
    Unidade/
    Integracao/
    Testes.ctec
./Documentacao/
./Construcao/
    Depuracao/
    Lancamento/
./Biblioteca/
    Dinamica/
    Estatica/
```

---

## 3. Sintaxe Básica CTEC
### Pré-Processadores
- `#Aviso`, `#ARQUIVO`, `#ARGUMENTOS_VARIÁVEIS`, `#CONTADOR`, `#DATA`, `#Defina`, `#SeDefinido`, `#SeNãoDefinido`, `#FimSe`, `#Diretiva`, `#Erro`, `#Esqueça`, `#LINHA`, `#FUNÇÃO`, `#HORA`, `#Inclua`

### Tipos de Dados
- `Vazio`, `Lógico`, `Inteiro`, `Real`, `Longo`, `Duplo`, `Caractere`

### Modificadores de Tipos
- `Curto`, `Longo`, `Natural`, `Bilateral`

### Qualificadores Semânticos
- `Imutável`, `Instável`, `Integrado`, `Exclusivo`

### Especificadores de Ligação
- `Fixo`, `Externo`

### Estruturas de Dados
- `Pseudônimo`, `Estrutura`, `Enumeração`, `União`

### Ponteiro
- Sinal: `*`  |  Referência: `&`

### Declarações
- Variável: `[Modificador] [Tipo] [Nome] = [Valor];`
- Vetor: `[Modificador] [Tipo] [Nome][Tamanho] = {Valores};`
- Ponteiro: `[Modificador] [Tipo] *[Nome] = [Endereço];`
- Referência: `[Modificador] [Tipo] [Nome] = &[OutraVariável];`
- Inferência: `[Nome] = ([Tipo]) [Expressão];`
- Função: `[TipoRetorno] [Nome]([Parâmetros]) { Corpo }`
- Pseudônimo: `Pseudônimo [Tipo] [Nome];`
- Estrutura: `Estrutura [Nome] { Campos }`
- Enumeração: `Enumeração [Nome] { Valores }`
- União: `União [Nome] { Campos }`
- Pseudo-Classe: `Pseudônimo Estrutura { ... } [Nome];`
- Inclusão: `#Inclua <Arquivo.ctec>` ou `#Inclua "Arquivo.ctec"`

### Controle de Fluxo
- `Se(Condição) { ... }`
- `Para(Inicialização; Condição; Incremento) { ... }`
- `Retorne [Expressão];`
- `[Rótulo]: Execute [Rótulo];`
> **Obs.:** Não existe Senão, SenãoSe, Enquanto, Faça...Enquanto, Troque...Caso nativos.

### Operadores
- **Aritméticos:** `+`, `-`, `*`, `/`, `%`, `++`, `--`
- **Atribuição:** `=`, `+=`, `-=`, `*=`, `/=`, `%=`
- **Bit a Bit:** `&`, `|`, `^`, `~`, `<<`, `>>`
- **Comparação:** `==`, `!=`, `>`, `<`, `>=`, `<=`

### Funções de Compilador (AOT)
- `Atributo`, `Identifique`, `Início`, `Genérico`, `Meça`, `Montador`, `ObtenhaAlinhamento`, `afirme_constante`, `compare_tipo_compatível`, `escolha_expressão`, `espere`, `obtenha_endereço_pilha`, `obtenha_endereço_retorno`

---

## 4. Convenções de Código
- **Arquivos:** CamelCase.ctec
- **Variáveis:** camelCase
- **Constantes:** MAIÚSCULO_SOBRELINHADO
- **Funções:** snake_case()
- **Espaço-nomeado:** Prefixo do módulo ou projeto (Ex: `Unidade_teste()`)
- **Indentação:** 4 espaços
- **Comentários:** `//` linha única, `/* ... */` múltiplas linhas
- **Paradigma:** OO e Procedural
- **Padrões de Projeto:** Singleton, Fábrica, Observador, Estratégia
- **Ciclo de Vida:** Use chaves `{}` para delimitar variáveis

---

## 5. Boas Práticas
- Sempre utilize `#Inclua` para dependências externas.
- Mantenha funções curtas e focadas em uma única tarefa.
- Realize testes unitários para funções críticas.
- Use `#Defina` somente em extrema necessidade, prefira funções.

---

## Exemplo de Código
```ctec
#Inclua <Convencional/Convencional.ctec>

Início() {
    Inteiro a = 10;
    Inteiro b = 20;
    Inteiro soma = a + b;
    // Exibe o resultado
    escreva(soma);
}

Estrutura Ponto {
    Inteiro x;
    Inteiro y;
}

Enumeração Cor {
    VERMELHO,
    VERDE,
    AZUL
}
```

---

## Compilação
### Usando Makefile (Linux/macOS)
```sh
make
```
### Usando Script no Windows
```bat
win32\construa-ctec.bat
```

---

## Licença
Distribuído sob a [LGPL v2.1](COPYING).

---
