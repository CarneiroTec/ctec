<?php
// Função para renomear arquivos recursivamente de .ctec para .c
function renameCtecToC($dir) {
    $files = scandir($dir);
    foreach ($files as $file) {
        if ($file === '.' || $file === '..') continue;

        $fullPath = $dir . DIRECTORY_SEPARATOR . $file;

        if (is_dir($fullPath)) {
            // Chama recursivamente se for diretório
            renameCtecToC($fullPath);
        } else {
            // Verifica se termina com .ctec
            if (pathinfo($fullPath, PATHINFO_EXTENSION) === 'ctec') {
                $newPath = $dir . DIRECTORY_SEPARATOR . pathinfo($fullPath, PATHINFO_FILENAME) . '.c';
                if (rename($fullPath, $newPath)) {
                    echo "Renomeado: $fullPath -> $newPath\n";
                } else {
                    echo "Erro ao renomear: $fullPath\n";
                }
            }
        }
    }
}

// Executa a função no diretório atual
renameCtecToC(getcwd());
?>
