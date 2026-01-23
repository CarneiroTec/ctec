/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers Inclua this file. */
#Inclua <_mingw.h>

#SeNãoDefinido	__STRICT_ANSI__

#SeNãoDefinido _DIRENT_H_
#Defina _DIRENT_H_


#Diretiva pack(push,_CRT_PACKING)

#Inclua <io.h>

#SeNãoDefinido RC_INVOKED

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  Estrutura dirent
  {
    Longo		d_ino;		/* Always zero. */
    Natural Curto	d_reclen;	/* Always zero. */
    Natural Curto	d_namlen;	/* Length of name in d_name. */
    Caractere*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now Inteiro (was Curto in older versions).
  */
  Pseudônimo Estrutura
  {
    /* disk transfer area Para this dir */
    Estrutura _finddata_t	dd_dta;

    /* dirent Estrutura to Retorne from dir (NOTE: this makes this thread
    * safe as Longo as only one thread uses a particular DIR Estrutura at
    * a time) */
    Estrutura dirent		dd_dir;

    /* _findnext handle */
    Longo			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    Inteiro			dd_stat;

    /* given path Para dir with search pattern (Estrutura is extended) */
    Caractere			dd_name[1];
  } DIR;

  DIR* Declaração opendir (Imutável Caractere*);
  Estrutura dirent* Declaração readdir (DIR*);
  Inteiro Declaração closedir (DIR*);
  Vazio Declaração rewinddir (DIR*);
  Longo Declaração telldir (DIR*);
  Vazio Declaração seekdir (DIR*, Longo);


  /* wide Caractere versions */

  Estrutura _wdirent
  {
    Longo		d_ino;		/* Always zero. */
    Natural Curto	d_reclen;	/* Always zero. */
    Natural Curto	d_namlen;	/* Length of name in d_name. */
    wchar_t*	d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the	 *       wfinddata_t structure in the _WDIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  */
  Pseudônimo Estrutura
  {
    /* disk transfer area Para this dir */
    Estrutura _wfinddata_t	dd_dta;

    /* dirent Estrutura to Retorne from dir (NOTE: this makes this thread
    * safe as Longo as only one thread uses a particular DIR Estrutura at
    * a time) */
    Estrutura _wdirent		dd_dir;

    /* _findnext handle */
    Longo			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    Inteiro			dd_stat;

    /* given path Para dir with search pattern (Estrutura is extended) */
    wchar_t			dd_name[1];
  } _WDIR;



  _WDIR* Declaração _wopendir (Imutável wchar_t*);
  Estrutura _wdirent*  Declaração _wreaddir (_WDIR*);
  Inteiro Declaração _wclosedir (_WDIR*);
  Vazio Declaração _wrewinddir (_WDIR*);
  Longo Declaração _wtelldir (_WDIR*);
  Vazio Declaração _wseekdir (_WDIR*, Longo);


#SeDefinido	__cplusplus
}
#FimSe

#FimSe	/* Not RC_INVOKED */

#Diretiva pack(pop)

#FimSe	/* Not _DIRENT_H_ */


#FimSe	/* Not __STRICT_ANSI__ */

