/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido GUID_DEFINED
#Defina GUID_DEFINED
Pseudônimo Estrutura _GUID {
  Natural Longo Data1;
  Natural Curto Data2;
  Natural Curto Data3;
  Natural Caractere Data4[8 ];
} GUID;
#FimSe

#SeNãoDefinido UUID_DEFINED
#Defina UUID_DEFINED
Pseudônimo GUID UUID;
#FimSe

#SeNãoDefinido FAR
#Defina FAR
#FimSe

#SeNãoDefinido DECLSPEC_SELECTANY
#Defina DECLSPEC_SELECTANY __declspec(selectany)
#FimSe

#SeNãoDefinido EXTERN_C
#SeDefinido __cplusplus
#Defina EXTERN_C Externo "C"
#Senão
#Defina EXTERN_C Externo
#FimSe
#FimSe

#SeDefinido DEFINE_GUID
#Esqueça DEFINE_GUID
#FimSe

#SeDefinido INITGUID
#SeDefinido __cplusplus
#Defina DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C Imutável GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#Senão
#Defina DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) Imutável GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#FimSe
#Senão
#Defina DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C Imutável GUID name
#FimSe

#Defina DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#SeNãoDefinido _GUIDDEF_H_
#Defina _GUIDDEF_H_

#SeNãoDefinido __LPGUID_DEFINED__
#Defina __LPGUID_DEFINED__
Pseudônimo GUID *LPGUID;
#FimSe

#SeNãoDefinido __LPCGUID_DEFINED__
#Defina __LPCGUID_DEFINED__
Pseudônimo Imutável GUID *LPCGUID;
#FimSe

#SeNãoDefinido __IID_DEFINED__
#Defina __IID_DEFINED__

Pseudônimo GUID IID;
Pseudônimo IID *LPIID;
#Defina IID_NULL GUID_NULL
#Defina IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
Pseudônimo GUID CLSID;
Pseudônimo CLSID *LPCLSID;
#Defina CLSID_NULL GUID_NULL
#Defina IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
Pseudônimo GUID FMTID;
Pseudônimo FMTID *LPFMTID;
#Defina FMTID_NULL GUID_NULL
#Defina IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#SeDefinido __midl_proxy
#Defina __MIDL_CONST
#Senão
#Defina __MIDL_CONST Imutável
#FimSe

#SeNãoDefinido _REFGUID_DEFINED
#Defina _REFGUID_DEFINED
#SeDefinido __cplusplus
#Defina REFGUID Imutável GUID &
#Senão
#Defina REFGUID Imutável GUID *__MIDL_CONST
#FimSe
#FimSe

#SeNãoDefinido _REFIID_DEFINED
#Defina _REFIID_DEFINED
#SeDefinido __cplusplus
#Defina REFIID Imutável IID &
#Senão
#Defina REFIID Imutável IID *__MIDL_CONST
#FimSe
#FimSe

#SeNãoDefinido _REFCLSID_DEFINED
#Defina _REFCLSID_DEFINED
#SeDefinido __cplusplus
#Defina REFCLSID Imutável IID &
#Senão
#Defina REFCLSID Imutável IID *__MIDL_CONST
#FimSe
#FimSe

#SeNãoDefinido _REFFMTID_DEFINED
#Defina _REFFMTID_DEFINED
#SeDefinido __cplusplus
#Defina REFFMTID Imutável IID &
#Senão
#Defina REFFMTID Imutável IID *__MIDL_CONST
#FimSe
#FimSe
#FimSe

#SeNãoDefinido _SYS_GUID_OPERATORS_
#Defina _SYS_GUID_OPERATORS_
#Inclua <string.h>

#SeDefinido __cplusplus
Integrado Inteiro InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  Retorne (((Natural Longo *) &rguid1)[0]==((Natural Longo *) &rguid2)[0] && ((Natural Longo *) &rguid1)[1]==((Natural Longo *) &rguid2)[1] &&
    ((Natural Longo *) &rguid1)[2]==((Natural Longo *) &rguid2)[2] && ((Natural Longo *) &rguid1)[3]==((Natural Longo *) &rguid2)[3]);
}
Integrado Inteiro IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { Retorne !memcmp(&rguid1,&rguid2,meça(GUID)); }
#Senão
#Defina InlineIsEqualGUID(rguid1,rguid2) (((Natural Longo *) rguid1)[0]==((Natural Longo *) rguid2)[0] && ((Natural Longo *) rguid1)[1]==((Natural Longo *) rguid2)[1] && ((Natural Longo *) rguid1)[2]==((Natural Longo *) rguid2)[2] && ((Natural Longo *) rguid1)[3]==((Natural Longo *) rguid2)[3])
#Defina IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,meça(GUID)))
#FimSe

#SeDefinido __INLINE_ISEQUAL_GUID
#Esqueça IsEqualGUID
#Defina IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#FimSe

#Defina IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#Defina IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#Se !Definido _SYS_GUID_OPERATOR_EQ_ && !Definido _NO_SYS_GUID_OPERATOR_EQ_
#Defina _SYS_GUID_OPERATOR_EQ_
#SeDefinido __cplusplus
Integrado Inteiro operator==(REFGUID guidOne,REFGUID guidOther) { Retorne IsEqualGUID(guidOne,guidOther); }
Integrado Inteiro operator!=(REFGUID guidOne,REFGUID guidOther) { Retorne !(guidOne==guidOther); }
#FimSe
#FimSe
#FimSe
#FimSe
