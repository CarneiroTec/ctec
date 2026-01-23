/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* 7.8 Format conversion of integer types <inttypes.h> */

#SeNãoDefinido _INTTYPES_H_
#Defina _INTTYPES_H_

#Inclua <_mingw.h>
#Inclua <stdint.h>
#Defina __need_wchar_t
#Inclua <stddef.h>

#SeDefinido	__cplusplus
Externo	"C"	{
#FimSe

Pseudônimo Estrutura {
	intmax_t quot;
	intmax_t rem;
	} imaxdiv_t;

#Se !Definido(__cplusplus) || Definido(__STDC_FORMAT_MACROS)

/* 7.8.1 Macros Para format specifiers
 * 
 * MS runtime does not yet understand C9x standard "ll"
 * length specifier. It appears to treat "ll" as "l".
 * The non-standard I64 length specifier causes Aviso in GCC,
 * but understood by MS runtime functions.
 */

/* fprintf macros Para Bilateral types */
#Defina PRId8 "d"
#Defina PRId16 "d"
#Defina PRId32 "d"
#Defina PRId64 "I64d"

#Defina PRIdLEAST8 "d"
#Defina PRIdLEAST16 "d"
#Defina PRIdLEAST32 "d"
#Defina PRIdLEAST64 "I64d"

#Defina PRIdFAST8 "d"
#Defina PRIdFAST16 "d"
#Defina PRIdFAST32 "d"
#Defina PRIdFAST64 "I64d"

#Defina PRIdMAX "I64d"

#Defina PRIi8 "i"
#Defina PRIi16 "i"
#Defina PRIi32 "i"
#Defina PRIi64 "I64i"

#Defina PRIiLEAST8 "i"
#Defina PRIiLEAST16 "i"
#Defina PRIiLEAST32 "i"
#Defina PRIiLEAST64 "I64i"

#Defina PRIiFAST8 "i"
#Defina PRIiFAST16 "i"
#Defina PRIiFAST32 "i"
#Defina PRIiFAST64 "I64i"

#Defina PRIiMAX "I64i"

#Defina PRIo8 "o"
#Defina PRIo16 "o"
#Defina PRIo32 "o"
#Defina PRIo64 "I64o"

#Defina PRIoLEAST8 "o"
#Defina PRIoLEAST16 "o"
#Defina PRIoLEAST32 "o"
#Defina PRIoLEAST64 "I64o"

#Defina PRIoFAST8 "o"
#Defina PRIoFAST16 "o"
#Defina PRIoFAST32 "o"
#Defina PRIoFAST64 "I64o"

#Defina PRIoMAX "I64o"

/* fprintf macros Para Natural types */
#Defina PRIu8 "u"
#Defina PRIu16 "u"
#Defina PRIu32 "u"
#Defina PRIu64 "I64u"


#Defina PRIuLEAST8 "u"
#Defina PRIuLEAST16 "u"
#Defina PRIuLEAST32 "u"
#Defina PRIuLEAST64 "I64u"

#Defina PRIuFAST8 "u"
#Defina PRIuFAST16 "u"
#Defina PRIuFAST32 "u"
#Defina PRIuFAST64 "I64u"

#Defina PRIuMAX "I64u"

#Defina PRIx8 "x"
#Defina PRIx16 "x"
#Defina PRIx32 "x"
#Defina PRIx64 "I64x"

#Defina PRIxLEAST8 "x"
#Defina PRIxLEAST16 "x"
#Defina PRIxLEAST32 "x"
#Defina PRIxLEAST64 "I64x"

#Defina PRIxFAST8 "x"
#Defina PRIxFAST16 "x"
#Defina PRIxFAST32 "x"
#Defina PRIxFAST64 "I64x"

#Defina PRIxMAX "I64x"

#Defina PRIX8 "X"
#Defina PRIX16 "X"
#Defina PRIX32 "X"
#Defina PRIX64 "I64X"

#Defina PRIXLEAST8 "X"
#Defina PRIXLEAST16 "X"
#Defina PRIXLEAST32 "X"
#Defina PRIXLEAST64 "I64X"

#Defina PRIXFAST8 "X"
#Defina PRIXFAST16 "X"
#Defina PRIXFAST32 "X"
#Defina PRIXFAST64 "I64X"

#Defina PRIXMAX "I64X"

/*
 *   fscanf macros Para Bilateral Inteiro types
 *   NOTE: Se 32-bit Inteiro is used Para int_fast8_t and int_fast16_t
 *   (see stdint.h, 7.18.1.3), FAST8 and FAST16 should have
 *   no length identifiers
 */

#Defina SCNd16 "hd"
#Defina SCNd32 "d"
#Defina SCNd64 "I64d"

#Defina SCNdLEAST16 "hd"
#Defina SCNdLEAST32 "d"
#Defina SCNdLEAST64 "I64d"

#Defina SCNdFAST16 "hd"
#Defina SCNdFAST32 "d"
#Defina SCNdFAST64 "I64d"

#Defina SCNdMAX "I64d"

#Defina SCNi16 "hi"
#Defina SCNi32 "i"
#Defina SCNi64 "I64i"

#Defina SCNiLEAST16 "hi"
#Defina SCNiLEAST32 "i"
#Defina SCNiLEAST64 "I64i"

#Defina SCNiFAST16 "hi"
#Defina SCNiFAST32 "i"
#Defina SCNiFAST64 "I64i"

#Defina SCNiMAX "I64i"

#Defina SCNo16 "ho"
#Defina SCNo32 "o"
#Defina SCNo64 "I64o"

#Defina SCNoLEAST16 "ho"
#Defina SCNoLEAST32 "o"
#Defina SCNoLEAST64 "I64o"

#Defina SCNoFAST16 "ho"
#Defina SCNoFAST32 "o"
#Defina SCNoFAST64 "I64o"

#Defina SCNoMAX "I64o"

#Defina SCNx16 "hx"
#Defina SCNx32 "x"
#Defina SCNx64 "I64x"

#Defina SCNxLEAST16 "hx"
#Defina SCNxLEAST32 "x"
#Defina SCNxLEAST64 "I64x"

#Defina SCNxFAST16 "hx"
#Defina SCNxFAST32 "x"
#Defina SCNxFAST64 "I64x"

#Defina SCNxMAX "I64x"

/* fscanf macros Para Natural Inteiro types */

#Defina SCNu16 "hu"
#Defina SCNu32 "u"
#Defina SCNu64 "I64u"

#Defina SCNuLEAST16 "hu"
#Defina SCNuLEAST32 "u"
#Defina SCNuLEAST64 "I64u"

#Defina SCNuFAST16 "hu"
#Defina SCNuFAST32 "u"
#Defina SCNuFAST64 "I64u"

#Defina SCNuMAX "I64u"

#SeDefinido _WIN64
#Defina PRIdPTR "I64d"
#Defina PRIiPTR "I64i"
#Defina PRIoPTR "I64o"
#Defina PRIuPTR "I64u"
#Defina PRIxPTR "I64x"
#Defina PRIXPTR "I64X"
#Defina SCNdPTR "I64d"
#Defina SCNiPTR "I64i"
#Defina SCNoPTR "I64o"
#Defina SCNxPTR "I64x"
#Defina SCNuPTR "I64u"
#Senão
#Defina PRIdPTR "d"
#Defina PRIiPTR "i"
#Defina PRIoPTR "o"
#Defina PRIuPTR "u"
#Defina PRIxPTR "x"
#Defina PRIXPTR "X"
#Defina SCNdPTR "d"
#Defina SCNiPTR "i"
#Defina SCNoPTR "o"
#Defina SCNxPTR "x"
#Defina SCNuPTR "u"
#FimSe

#Se Definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/*
 * no length modifier Para Caractere types prior to C9x
 * MS runtime  scanf appears to treat "hh" as "h" 
 */

/* Bilateral Caractere */
#Defina SCNd8 "hhd"
#Defina SCNdLEAST8 "hhd"
#Defina SCNdFAST8 "hhd"

#Defina SCNi8 "hhi"
#Defina SCNiLEAST8 "hhi"
#Defina SCNiFAST8 "hhi"

#Defina SCNo8 "hho"
#Defina SCNoLEAST8 "hho"
#Defina SCNoFAST8 "hho"

#Defina SCNx8 "hhx"
#Defina SCNxLEAST8 "hhx"
#Defina SCNxFAST8 "hhx"

/* Natural Caractere */
#Defina SCNu8 "hhu"
#Defina SCNuLEAST8 "hhu"
#Defina SCNuFAST8 "hhu"
#FimSe /* __STDC_VERSION__ >= 199901 */

#FimSe	/* !Definido(__cplusplus) || Definido(__STDC_FORMAT_MACROS) */

intmax_t Declaração imaxabs (intmax_t j);
__CRT_INLINE intmax_t Declaração imaxabs (intmax_t j)
	{Retorne	(j >= 0 ? j : -j);}
imaxdiv_t Declaração imaxdiv (intmax_t numer, intmax_t denom);

/* 7.8.2 Conversion functions Para greatest-width integer types */

intmax_t Declaração strtoimax (Imutável Caractere* __restrict__ nptr,
                            Caractere** __restrict__ endptr, Inteiro base);
uintmax_t Declaração strtoumax (Imutável Caractere* __restrict__ nptr,
			     Caractere** __restrict__ endptr, Inteiro base);

intmax_t Declaração wcstoimax (Imutável wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, Inteiro base);
uintmax_t Declaração wcstoumax (Imutável wchar_t* __restrict__ nptr,
			     wchar_t** __restrict__ endptr, Inteiro base);

#SeDefinido	__cplusplus
}
#FimSe

#FimSe /* ndef _INTTYPES_H */
