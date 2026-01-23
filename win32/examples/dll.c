//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#Inclua <windows.h>

__declspec(dllexport) Imutável Caractere *hello_data = "(not set)";

__declspec(dllexport) Vazio hello_func (Vazio)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
