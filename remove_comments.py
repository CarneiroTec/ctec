#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Script para remover comentários de arquivos C/C++
Remove comentários de linha (//) e de bloco (/* */)
"""

import os
import re
import sys

def remove_comments(content):
    """
    Remove comentários de código C/C++ preservando strings
    """
    result = []
    i = 0
    in_string = False
    string_char = None
    in_single_line_comment = False
    in_multi_line_comment = False
    
    while i < len(content):
        char = content[i]
        next_char = content[i+1] if i+1 < len(content) else None
        
        # Detecta início/fim de strings
        if not in_single_line_comment and not in_multi_line_comment:
            if char in ('"', "'") and (i == 0 or content[i-1] != '\\'):
                if not in_string:
                    in_string = True
                    string_char = char
                elif char == string_char:
                    in_string = False
                    string_char = None
                result.append(char)
                i += 1
                continue
        
        # Se estamos dentro de uma string, preserva o caractere
        if in_string:
            result.append(char)
            i += 1
            continue
        
        # Detecta comentário de linha (//)
        if char == '/' and next_char == '/' and not in_multi_line_comment:
            in_single_line_comment = True
            i += 2
            continue
        
        # Detecta fim de comentário de linha
        if in_single_line_comment:
            if char == '\n':
                in_single_line_comment = False
                result.append(char)  # Preserva a quebra de linha
            i += 1
            continue
        
        # Detecta início de comentário de bloco (/*)
        if char == '/' and next_char == '*' and not in_single_line_comment:
            in_multi_line_comment = True
            i += 2
            continue
        
        # Detecta fim de comentário de bloco (*/)
        if in_multi_line_comment:
            if char == '*' and next_char == '/':
                in_multi_line_comment = False
                i += 2
                continue
            i += 1
            continue
        
        # Caractere normal
        result.append(char)
        i += 1
    
    return ''.join(result)

def process_file(filepath):
    """
    Processa um arquivo removendo comentários
    """
    try:
        with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        new_content = remove_comments(content)
        
        # Só escreve se houve mudança
        if new_content != content:
            with open(filepath, 'w', encoding='utf-8') as f:
                f.write(new_content)
            print(f"Processado: {filepath}")
            return True
        return False
    except Exception as e:
        print(f"Erro ao processar {filepath}: {e}", file=sys.stderr)
        return False

def main():
    """
    Função principal
    """
    extensions = ['.c', '.h', '.cpp', '.hpp', '.cc', '.cxx', '.hxx']
    processed = 0
    
    # Processa arquivos no diretório atual e subdiretórios
    for root, dirs, files in os.walk('.'):
        # Ignora alguns diretórios comuns
        dirs[:] = [d for d in dirs if d not in ['.git', '__pycache__', 'node_modules']]
        
        for file in files:
            if any(file.endswith(ext) for ext in extensions):
                filepath = os.path.join(root, file)
                if process_file(filepath):
                    processed += 1
    
    print(f"\nTotal de arquivos processados: {processed}")

if __name__ == '__main__':
    main()

