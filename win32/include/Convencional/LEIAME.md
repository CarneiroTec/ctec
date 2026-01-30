# Biblioteca Convencional para CTEC

A **Biblioteca Convencional** é o núcleo de funcionalidades essenciais para o desenvolvimento de aplicações na linguagem **CTEC**. Ela fornece uma interface organizada e intuitiva para interação com o sistema operacional, manipulação de arquivos, gerenciamento de memória e muito mais.

Este guia ensina como utilizar os principais módulos da biblioteca de forma didática.

---

## 1. O Objeto Global `Sistema`

O coração da biblioteca é o objeto global `Sistema`. Ele centraliza diversos "Gerenciadores", cada um responsável por uma área específica do ambiente de execução.

### Estrutura do `Sistema`:
- **`Sistema.terminal`**: Interface para entrada e saída de dados no console.
- **`Sistema.arquivo`**: Gerenciador para operações em arquivos.
- **`Sistema.memoria`**: Controle de alocação e liberação de memória.
- **`Sistema.ambiente`**: Acesso a variáveis de ambiente e configurações.
- **`Sistema.diretorio`**: Manipulação de pastas e caminhos.
- **`Sistema.processo`**: Gerenciamento de processos e execução.

---

## 2. Entrada e Saída (Terminal)

Para interagir com o usuário, utilizamos o `Sistema.terminal`. Ele oferece métodos para exibir textos formatados e ler entradas.

### Exemplo: Olá Mundo e Entrada de Dados
```ctec
#Inclua "Convencional.ctec"

Inteiro Início() {
    // Exibindo texto simples
    Sistema.terminal->exiba_texto("Bem-vindo ao CTEC!");

    // Exibindo texto formatado
    Sistema.terminal->exiba_formatado("Digite seu nome: ");

    Caractere nome[50];
    Sistema.terminal->leia_texto(nome);

    Sistema.terminal->exiba_formatado("Olá, %s! Seja bem-vindo.\n", nome);

    Retorne 0;
}
```

---

## 3. Manipulação de Arquivos

O módulo `Arquivo` permite criar, ler e escrever dados em disco de forma estruturada através do gerenciador disponível em `GerenciadorArquivo` (acessível também via `Sistema`).

### Operações Comuns:
- `abra(nome, modo)`: Abre um arquivo existente.
- `crie(nome, modo)`: Cria um novo arquivo.
- `escreva(ponteiro, tamanho, quantidade, arquivo)`: Escreve dados.
- `leia(ponteiro, tamanho, quantidade, arquivo)`: Lê dados.
- `feche(arquivo)`: Fecha o descritor de arquivo.

### Exemplo: Gravando em um Arquivo
```ctec
#Inclua "Convencional.ctec"

Inteiro Início() {
    Arquivo *meu_arquivo = Sistema.arquivo->crie("notas.txt", "w");

    Se (meu_arquivo) {
        Caractere *conteudo = "Estudando a biblioteca Convencional.";
        Sistema.arquivo->escreva(conteudo, 1, 36, meu_arquivo);
        Sistema.arquivo->feche(meu_arquivo);
        Sistema.terminal->exiba_texto("Arquivo gravado com sucesso!");
    } Senão {
        Sistema.terminal->exiba_texto("Erro ao criar arquivo.");
    }

    Retorne 0;
}
```

---

## 4. Tratamento de Erros

A biblioteca fornece o `GerenciadorErro` para monitorar problemas ocorridos durante a execução de chamadas de sistema.

- `Sistema.erro->obtenha_erro()`: Retorna o código do último erro ocorrido.
- `Sistema.erro->defina_erro(valor)`: Define manualmente um código de erro.

---

## 5. Módulos Adicionais

- **Dados**: Define a estrutura base `Dados` para transporte e processamento de informações.
- **Variadicos**: Facilita a criação de funções que aceitam um número variável de argumentos.

---

## Melhores Práticas
1. **Sempre Verifique Retornos**: Ao abrir arquivos ou alocar memória, verifique se a operação foi bem-sucedida.
2. **Use o Objeto Sistema**: Prefira acessar as funcionalidades através do objeto `Sistema` para manter o código organizado e modular.
3. **Limpeza**: Sempre feche arquivos e libere memória alocada dinamicamente para evitar vazamentos de recursos.

---
*Este documento faz parte da documentação oficial da biblioteca Convencional para CTEC.*
