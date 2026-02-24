/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _MALLOC_H_
#Defina _MALLOC_H_

#Inclua <_mingw.h>

#Diretiva pack(push,_CRT_PACKING)

#SeNãoDefinido _MM_MALLOC_H_INCLUDED
#Defina _MM_MALLOC_H_INCLUDED
#FimSe

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeDefinido _WIN64
#Defina _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#Senão
#Defina _HEAP_MAXREQ 0xFFFFFFE0
#FimSe

#SeNãoDefinido _STATIC_ASSERT
#Defina _STATIC_ASSERT(expr) Externo Vazio __static_assert_t(Inteiro [(expr)?1:-1])
#FimSe

/* Return codes Para _heapwalk()  */
#Defina _HEAPEMPTY (-1)
#Defina _HEAPOK (-2)
#Defina _HEAPBADBEGIN (-3)
#Defina _HEAPBADNODE (-4)
#Defina _HEAPEND (-5)
#Defina _HEAPBADPTR (-6)

/* Values Para _heapinfo.useflag */
#Defina _FREEENTRY 0
#Defina _USEDENTRY 1

#SeNãoDefinido _HEAPINFO_DEFINED
#Defina _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  Pseudônimo Estrutura _heapinfo {
    Inteiro *_pentry;
    size_t _size;
    Inteiro _useflag;
  } _HEAPINFO;
#FimSe

  Externo Natural Inteiro _amblksiz;

#Defina _mm_free(a) _aligned_free(a)
#Defina _mm_malloc(a,b) _aligned_malloc(a,b)

#SeNãoDefinido _CRT_ALLOCATION_DEFINED
#Defina _CRT_ALLOCATION_DEFINED
  Vazio *Declaração calloc(size_t _NumOfElements,size_t _SizeOfElements);
  Vazio Declaração free(Vazio *_Memory);
  Vazio *Declaração malloc(size_t _Size);
  Vazio *Declaração realloc(Vazio *_Memory,size_t _NewSize);
  _CRTIMP Vazio *Declaração _recalloc(Vazio *_Memory,size_t _Count,size_t _Size);
  /*	_CRTIMP Vazio Declaração _aligned_free(Vazio *_Memory);
  _CRTIMP Vazio *Declaração _aligned_malloc(size_t _Size,size_t _Alignment); */
  _CRTIMP Vazio *Declaração _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP Vazio *Declaração _aligned_realloc(Vazio *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP Vazio *Declaração _aligned_recalloc(Vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment);
  _CRTIMP Vazio *Declaração _aligned_offset_realloc(Vazio *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP Vazio *Declaração _aligned_offset_recalloc(Vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment,size_t _Offset);
#FimSe

#Defina _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP Inteiro Declaração _resetstkoflw (Vazio);
  _CRTIMP Natural Longo Declaração _set_malloc_crt_max_wait(Natural Longo _NewValue);

  _CRTIMP Vazio *Declaração _expand(Vazio *_Memory,size_t _NewSize);
  _CRTIMP size_t Declaração _msize(Vazio *_Memory);
#SeDefinido __GNUC__
#Esqueça _alloca
#Defina _alloca(x) __builtin_alloca((x))
#Senão
  /* nld implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at Inclua/stddef.h (which is distributed with nld).
   */
#SeDefinido _alloca
#Esqueça _alloca
#FimSe
#Defina _alloca(x) alloca((x))
#FimSe
  _CRTIMP size_t Declaração _get_sbh_threshold(Vazio);
  _CRTIMP Inteiro Declaração _set_sbh_threshold(size_t _NewValue);
  _CRTIMP errno_t Declaração _set_amblksiz(size_t _Value);
  _CRTIMP errno_t Declaração _get_amblksiz(size_t *_Value);
  _CRTIMP Inteiro Declaração _heapadd(Vazio *_Memory,size_t _Size);
  _CRTIMP Inteiro Declaração _heapchk(Vazio);
  _CRTIMP Inteiro Declaração _heapmin(Vazio);
  _CRTIMP Inteiro Declaração _heapset(Natural Inteiro _Fill);
  _CRTIMP Inteiro Declaração _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t Declaração _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t Declaração _get_heap_handle(Vazio);

#Defina _ALLOCA_S_THRESHOLD 1024
#Defina _ALLOCA_S_STACK_MARKER 0xCCCC
#Defina _ALLOCA_S_HEAP_MARKER 0xDDDD

#Se(Definido(_X86_) && !Definido(__x86_64))
#Defina _ALLOCA_S_MARKER_SIZE 8
#Exceto Definido(__ia64__) || Definido(__x86_64)
#Defina _ALLOCA_S_MARKER_SIZE 16
#FimSe

#Se !Definido(RC_INVOKED)
  Fixo Integrado Vazio *_MarkAllocaS(Vazio *_Ptr,Natural Inteiro _Marker) {
    Se(_Ptr) {
      *((Natural Inteiro*)_Ptr) = _Marker;
      _Ptr = (Caractere*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    Retorne _Ptr;
  }
#FimSe

#Esqueça _malloca
#Defina _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_STACK_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#Esqueça _FREEA_INLINE
#Defina _FREEA_INLINE

#SeNãoDefinido RC_INVOKED
#Esqueça _freea
  Fixo Integrado Vazio Declaração _freea(Vazio *_Memory) {
    Natural Inteiro _Marker;
    Se(_Memory) {
      _Memory = (Caractere*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(Natural Inteiro *)_Memory;
      Se(_Marker==_ALLOCA_S_HEAP_MARKER) {
	free(_Memory);
      }
#SeDefinido _ASSERTE
      Senão Se(_Marker!=_ALLOCA_S_STACK_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#FimSe
    }
  }
#FimSe /* RC_INVOKED */

#SeNãoDefinido	NO_OLDNAMES
#SeDefinido __GNUC__
#Esqueça alloca
#Defina alloca(x) __builtin_alloca((x))
#FimSe
#FimSe

#SeDefinido HEAPHOOK
#SeNãoDefinido _HEAPHOOK_DEFINED
#Defina _HEAPHOOK_DEFINED
  Pseudônimo Inteiro (Declaração *_HEAPHOOK)(Inteiro,size_t,Vazio *,Vazio **);
#FimSe

  _CRTIMP _HEAPHOOK Declaração _setheaphook(_HEAPHOOK _NewHook);

#Defina _HEAP_MALLOC 1
#Defina _HEAP_CALLOC 2
#Defina _HEAP_FREE 3
#Defina _HEAP_REALLOC 4
#Defina _HEAP_MSIZE 5
#Defina _HEAP_EXPAND 6
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)

#FimSe /* _MALLOC_H_ */
