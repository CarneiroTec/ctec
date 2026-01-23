<?php
// Função para renomear arquivos recursivamente
function renameCtoCtec($dir) {
    // Abre o diretório
    $files = scandir($dir);
    foreach ($files as $file) {
        // Ignora '.' e '..'
        if ($file === '.' || $file === '..') continue;

        $fullPath = $dir . DIRECTORY_SEPARATOR . $file;

        if (is_dir($fullPath)) {
            // Se for diretório, chama recursivamente
            renameCtoCtec($fullPath);
        } else {
            // Se for arquivo e terminar com .c
            if (pathinfo($fullPath, PATHINFO_EXTENSION) === 'c') {
                $newPath = $dir . DIRECTORY_SEPARATOR . pathinfo($fullPath, PATHINFO_FILENAME) . '.ctec';
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
renameCtoCtec(getcwd());
?>
