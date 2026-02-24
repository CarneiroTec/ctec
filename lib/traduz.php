<?php
/**
 * Script PHP para substituir palavras-chave em arquivos C/assembly
 * 
 * Ele percorre o diretório atual e todos os subdiretórios,
 * e substitui palavras-chave definidas no array $keywords.
 */

// Array de palavras-chave e seus "substitutos"
$keywords = [
        // Preprocessor
    "defined" => "Definido",
    "define" => "Defina",
    "include" => "Inclua",
    "include_next" => "Inclua_Próximo",
    "ifdef" => "SeDefinido",
    "ifndef" => "SeNãoDefinido",
    "elif" => "Exceto",
    "endif" => "FimSe",
    "error" => "Erro",
    "warning" => "Aviso",
    "line" => "Linha",
    "pragma" => "Diretiva",
    "undef" => "Esqueça",

    "int" => "Inteiro",
    "void" => "Vazio",
    "char" => "Caractere",
    "if" => "Se",
    "else" => "Senão",
    "while" => "Enquanto",
    "break" => "Interrompa",
    "return" => "Retorne",
    "for" => "Para",
    "extern" => "Externo",
    "static" => "Fixo",
    "unsigned" => "Natural",
    "goto" => "VáPara",
    "do" => "Faça",
    "continue" => "Continue",
    "switch" => "Troque",
    "case" => "Caso",
    "const" => "Imutável",
    "__const" => "__const",
    "__const__" => "__const__",
    "volatile" => "Instável",
    "__volatile" => "__volatile",
    "__volatile__" => "__volatile__",
    "long" => "Longo",
    "register" => "Prioridade",
    "signed" => "Bilateral",
    "__signed" => "__signed",
    "__signed__" => "__signed__",
    "auto" => "Automático",
    "inline" => "Integrado",
    "__inline" => "__inline",
    "__inline__" => "__inline__",
    "restrict" => "Restrito",
    "__restrict" => "__restrict",
    "__restrict__" => "__restrict__",
    "__extension__" => "__extension__",
    "float" => "Real",
    "double" => "Duplo",
    "bool" => "Lógico",
    "short" => "Curto",
    "struct" => "Estrutura",
    "union" => "União",
    "typedef" => "Pseudônimo",
    "default" => "Padrão",
    "enum" => "Enumeração",
    "sizeof" => "meça",
    "__attribute" => "__attribute",
    "__attribute__" => "__attribute__",
    "__alignof" => "__alignof",
    "__alignof__" => "__alignof__",
    "typeof" => "identifique",
    "__typeof" => "__typeof",
    "__typeof__" => "__typeof__",
    "__label__" => "__label__",
    "asm" => "Montador",
    "__asm" => "__asm",
    "__asm__" => "__asm__",
    "__uint128_t" => "__uint128_t",


];

/**
 * Função para percorrer diretórios e aplicar callback em arquivos encontrados
 */
function processDirectory($dir, $callback, $extensions = ['c','h','s','S']) {
    $iterator = new RecursiveIteratorIterator(new RecursiveDirectoryIterator($dir));
    foreach ($iterator as $file) {
        if ($file->isFile()) {
            $ext = pathinfo($file->getFilename(), PATHINFO_EXTENSION);
            if (in_array($ext, $extensions)) {
                $callback($file->getPathname());
            }
        }
    }
}

/**
 * Função para substituir palavras-chave em um arquivo
 */
function replaceKeywordsInFile($filename, $keywords) {
    $content = file_get_contents($filename);
    if ($content === false) {
        echo "Erro ao ler arquivo: $filename\n";
        return;
    }

    // Substituir cada palavra-chave usando regex para não afetar partes de outras palavras
    foreach ($keywords as $key => $value) {
        $pattern = '/\b' . preg_quote($key, '/') . '\b/';
        $content = preg_replace($pattern, $value, $content);
    }

    file_put_contents($filename, $content);
    echo "Arquivo processado: $filename\n";
}

// Executa o script no diretório atual
processDirectory(getcwd(), function($file) use ($keywords) {
    replaceKeywordsInFile($file, $keywords);
});

echo "Substituição concluída!\n";
