/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#Se !Definido(_BASETYPS_H_)
#Defina _BASETYPS_H_

#SeDefinido __cplusplus
#Defina EXTERN_C Externo "C"
#Senão
#Defina EXTERN_C Externo
#FimSe

#Defina STDMETHODCALLTYPE WINAPI
#Defina STDMETHODVCALLTYPE Declaração

#Defina STDAPICALLTYPE WINAPI
#Defina STDAPIVCALLTYPE Declaração

#Defina STDAPI EXTERN_C HRESULT WINAPI
#Defina STDAPI_(type) EXTERN_C type WINAPI

#Defina STDMETHODIMP HRESULT WINAPI
#Defina STDMETHODIMP_(type) type WINAPI

#Defina STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#Defina STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#Defina STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#Defina STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#Se Definido(__cplusplus) && !Definido(CINTERFACE)

#Defina __STRUCT__ Estrutura
#Defina STDMETHOD(method) virtual HRESULT WINAPI method
#Defina STDMETHOD_(type,method) virtual type WINAPI method
#Defina STDMETHODV(method) virtual HRESULT STDMETHODVCALLTYPE method
#Defina STDMETHODV_(type,method) virtual type STDMETHODVCALLTYPE method
#Defina PURE = 0
#Defina THIS_
#Defina THIS Vazio
#Defina DECLARE_INTERFACE(iface) __STRUCT__ iface
#Defina DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : public baseiface
#Senão

#SeNãoDefinido __OBJC__
#Defina interface Estrutura
#FimSe

#Defina STDMETHOD(method) HRESULT (WINAPI *method)
#Defina STDMETHOD_(type,method) type (WINAPI *method)
#Defina STDMETHODV(method) HRESULT (STDMETHODVCALLTYPE *method)
#Defina STDMETHODV_(type,method) type (STDMETHODVCALLTYPE *method)

#Defina PURE
#Defina THIS_ INTERFACE *This,
#Defina THIS INTERFACE *This
#SeDefinido CONST_VTABLE
#Defina DECLARE_INTERFACE(iface) Pseudônimo Estrutura iface { \
  Imutável Estrutura iface##Vtbl *lpVtbl; } iface; \
  Pseudônimo Imutável Estrutura iface##Vtbl iface##Vtbl; \
  Imutável Estrutura iface##Vtbl
#Senão
#Defina DECLARE_INTERFACE(iface) Pseudônimo Estrutura iface { \
    Estrutura iface##Vtbl *lpVtbl; \
  } iface; \
  Pseudônimo Estrutura iface##Vtbl iface##Vtbl; \
  Estrutura iface##Vtbl
#FimSe
#Defina DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#FimSe

#Inclua <guiddef.h>

#SeNãoDefinido _ERROR_STATUS_T_DEFINED
#Defina _ERROR_STATUS_T_DEFINED
Pseudônimo Natural Longo error_status_t;
#FimSe

#SeNãoDefinido _WCHAR_T_DEFINED
Pseudônimo Natural Curto wchar_t;
#Defina _WCHAR_T_DEFINED
#FimSe
#FimSe
