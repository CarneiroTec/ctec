<?php
/**
 * Script PHP para substituir palavras-chave em arquivos C/assembly
 * Baseado nas definições de ctectok.h
 * 
 * Ele percorre o diretório especificado e todos os subdiretórios,
 * e substitui palavras-chave de C para CTEC (português brasileiro).
 */

// Array de palavras-chave extraídas de ctectok.h
// Ordem: palavras maiores primeiro para evitar substituições parciais
$keywords = [
    // Variantes com underscores devem vir primeiro (mais longas)
    "__builtin_types_compatible_p" => "CompareTipo",
    "__builtin_choose_expr" => "EscolhaExpressão",
    "__builtin_constant_p" => "AfirmeConstante",
    "__builtin_frame_address" => "EndereçoQuadro",
    "__builtin_return_address" => "EndereçoRetorno",
    "__builtin_va_start" => "InicieArgumentosVariáveis",
    "__builtin_va_arg_types" => "TiposArgumentosVariáveis",
    "__builtin_va_list" => "ListaArgumentosVariáveis",
    "__builtin_expect" => "Espere",
    "__va_start" => "InicieArgumentosVariáveis",
    "__va_arg" => "ArgumentoVariável",
    
    // Variantes com duplo underscore
    "__attribute__" => "Atributo",
    "__attribute" => "Atributo",
    "__alignof__" => "Alinhe",
    "__alignof" => "Alinhe",
    "__typeof__" => "Identifique",
    "__typeof" => "Identifique",
    "__asm__" => "Montador",
    "__asm" => "Montador",
    "__inline__" => "Integrado",
    "__inline" => "Integrado",
    "__const__" => "Imutável",
    "__const" => "Imutável",
    "__volatile__" => "Instável",
    "__volatile" => "Instável",
    "__signed__" => "Bilateral",
    "__signed" => "Bilateral",
    "__restrict__" => "Exclusivo",
    "__restrict" => "Exclusivo",
    "__extension__" => "Extensão",
    "__extension" => "Extensão",
    "__label__" => "Rótulo",
    
    // Macros de preprocessador especiais
    "__LINE__" => "LINHA",
    "__FILE__" => "ARQUIVO",
    "__DATE__" => "DATA",
    "__TIME__" => "HORA",
    "__FUNCTION__" => "FUNÇÃO",
    "__func__" => "FUNÇÃO_ATUAL",
    "__VA_ARGS__" => "ARGUMENTOS_VARIÁVEIS",
    "__COUNTER__" => "CONTADOR",
    "__NAN__" => "NÃO_NUMÉRICO",
    "__SNAN__" => "NÃO_NUMÉRICO_SILENCIOSO",
    "__INF__" => "INFINITO",
    
    // Palavras-chave principais (em ordem decrescente de tamanho)
    "include_next" => "IncluaPróximo",
    "typedef" => "Pseudônimo",
    "unsigned" => "Natural",
    "continue" => "Continue",
    "register" => "Prioridade",
    "volatile" => "Instável",
    "restrict" => "Exclusivo",
    "_Generic" => "Genérico",
    "_Alignof" => "Alinhe",
    "default" => "Padrão",
    "defined" => "Definido",
    "include" => "Inclua",
    "warning" => "Aviso",
    "typedef" => "Pseudônimo",
    "struct" => "Estrutura",
    "sizeof" => "Meça",
    "switch" => "Troque",
    "return" => "Retorne",
    "extern" => "Externo",
    "static" => "Fixo",
    "inline" => "Integrado",
    "typeof" => "Identifique",
    "double" => "Duplo",
    "signed" => "Bilateral",
    "pragma" => "Diretiva",
    "define" => "Defina",
    "ifndef" => "SeNãoDefinido",
    "error" => "Erro",
    "endif" => "FimSe",
    "undef" => "Esqueça",
    "ifdef" => "SeDefinido",
    "while" => "Enquanto",
    "break" => "Interrompa",
    "float" => "Real",
    "union" => "União",
    "short" => "Curto",
    "_Bool" => "Lógico",
    "const" => "Imutável",
    "case" => "Caso",
    "void" => "Vazio",
    "char" => "Caractere",
    "long" => "Longo",
    "auto" => "Local",
    "enum" => "Enumeração",
    "else" => "Senão",
    "elif" => "Exceto",
    "bool" => "Lógico",
    "goto" => "Execute",
    "line" => "Linha",
    "for" => "Para",
    "int" => "Inteiro",
    "asm" => "Montador",
    "do" => "Faça",
    "if" => "Se",
];

// Ordenar por tamanho decrescente para evitar substituições parciais
uksort($keywords, function($a, $b) {
    return strlen($b) - strlen($a);
});

/**
 * Função para percorrer diretórios e aplicar callback em arquivos encontrados
 */
function processDirectory($dir, $callback, $extensions = ['c', 'h', 's', 'S', 'ctec', 'int']) {
    if (!is_dir($dir)) {
        echo "Diretório não encontrado: $dir\n";
        return;
    }
    
    $iterator = new RecursiveIteratorIterator(
        new RecursiveDirectoryIterator($dir, RecursiveDirectoryIterator::SKIP_DOTS)
    );
    
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
 * Usa regex com word boundaries para não afetar partes de outras palavras
 */
function replaceKeywordsInFile($filename, $keywords) {
    $content = file_get_contents($filename);
    if ($content === false) {
        echo "Erro ao ler arquivo: $filename\n";
        return;
    }

    $original = $content;
    
    // Substituir cada palavra-chave usando regex
    foreach ($keywords as $key => $value) {
        // Pattern especial para palavras com underscores
        if (strpos($key, '__') === 0) {
            // Para tokens com __, substituir exatamente
            $pattern = '/' . preg_quote($key, '/') . '/';
        } else {
            // Para outras palavras, usar word boundaries
            $pattern = '/\b' . preg_quote($key, '/') . '\b/';
        }
        
        $content = preg_replace($pattern, $value, $content);
    }

    if ($content !== $original) {
        file_put_contents($filename, $content);
        echo "Modificado: $filename\n";
        return true;
    }
    return false;
}

// Verifica argumentos de linha de comando
$targetDir = getcwd();
if (isset($argv[1]) && is_dir($argv[1])) {
    $targetDir = realpath($argv[1]);
}

$extensions = ['c', 'h'];
if (isset($argv[2])) {
    $extensions = explode(',', $argv[2]);
}

echo "=== CTEC Refatorador de Código ===\n";
echo "Diretório: $targetDir\n";
echo "Extensões: " . implode(', ', $extensions) . "\n";
echo "Palavras-chave: " . count($keywords) . "\n";
echo "==================================\n\n";

$count = 0;

// Executa o script no diretório especificado
processDirectory($targetDir, function($file) use ($keywords, &$count) {
    if (replaceKeywordsInFile($file, $keywords)) {
        $count++;
    }
}, $extensions);

echo "\n==================================\n";
echo "Arquivos modificados: $count\n";
echo "Refatoração concluída!\n";
