/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _WINBASE_
#Defina _WINBASE_

#Defina WINADVAPI DECLSPEC_IMPORT
#Defina WINBASEAPI DECLSPEC_IMPORT
#Defina ZAWPROXYAPI DECLSPEC_IMPORT

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#Defina DefineHandleTable(w) ((w),TRUE)
#Defina LimitEmsPages(dw)
#Defina SetSwapAreaSize(w) (w)
#Defina LockSegment(w) GlobalFix((HANDLE)(w))
#Defina UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#Defina GetCurrentTime() GetTickCount()

#Defina Yield()

#Defina INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#Defina INVALID_FILE_SIZE ((DWORD)0xffffffff)
#Defina INVALID_SET_FILE_POINTER ((DWORD)-1)
#Defina INVALID_FILE_ATTRIBUTES ((DWORD)-1)

#Defina FILE_BEGIN 0
#Defina FILE_CURRENT 1
#Defina FILE_END 2

#Defina TIME_ZONE_ID_INVALID ((DWORD)0xffffffff)

#Defina WAIT_FAILED ((DWORD)0xffffffff)
#Defina WAIT_OBJECT_0 ((STATUS_WAIT_0) + 0)
#Defina WAIT_ABANDONED ((STATUS_ABANDONED_WAIT_0) + 0)
#Defina WAIT_ABANDONED_0 ((STATUS_ABANDONED_WAIT_0) + 0)
#Defina WAIT_IO_COMPLETION STATUS_USER_APC
#Defina STILL_ACTIVE STATUS_PENDING
#Defina EXCEPTION_ACCESS_VIOLATION STATUS_ACCESS_VIOLATION
#Defina EXCEPTION_DATATYPE_MISALIGNMENT STATUS_DATATYPE_MISALIGNMENT
#Defina EXCEPTION_BREAKPOINT STATUS_BREAKPOINT
#Defina EXCEPTION_SINGLE_STEP STATUS_SINGLE_STEP
#Defina EXCEPTION_ARRAY_BOUNDS_EXCEEDED STATUS_ARRAY_BOUNDS_EXCEEDED
#Defina EXCEPTION_FLT_DENORMAL_OPERAND STATUS_FLOAT_DENORMAL_OPERAND
#Defina EXCEPTION_FLT_DIVIDE_BY_ZERO STATUS_FLOAT_DIVIDE_BY_ZERO
#Defina EXCEPTION_FLT_INEXACT_RESULT STATUS_FLOAT_INEXACT_RESULT
#Defina EXCEPTION_FLT_INVALID_OPERATION STATUS_FLOAT_INVALID_OPERATION
#Defina EXCEPTION_FLT_OVERFLOW STATUS_FLOAT_OVERFLOW
#Defina EXCEPTION_FLT_STACK_CHECK STATUS_FLOAT_STACK_CHECK
#Defina EXCEPTION_FLT_UNDERFLOW STATUS_FLOAT_UNDERFLOW
#Defina EXCEPTION_INT_DIVIDE_BY_ZERO STATUS_INTEGER_DIVIDE_BY_ZERO
#Defina EXCEPTION_INT_OVERFLOW STATUS_INTEGER_OVERFLOW
#Defina EXCEPTION_PRIV_INSTRUCTION STATUS_PRIVILEGED_INSTRUCTION
#Defina EXCEPTION_IN_PAGE_ERROR STATUS_IN_PAGE_ERROR
#Defina EXCEPTION_ILLEGAL_INSTRUCTION STATUS_ILLEGAL_INSTRUCTION
#Defina EXCEPTION_NONCONTINUABLE_EXCEPTION STATUS_NONCONTINUABLE_EXCEPTION
#Defina EXCEPTION_STACK_OVERFLOW STATUS_STACK_OVERFLOW
#Defina EXCEPTION_INVALID_DISPOSITION STATUS_INVALID_DISPOSITION
#Defina EXCEPTION_GUARD_PAGE STATUS_GUARD_PAGE_VIOLATION
#Defina EXCEPTION_INVALID_HANDLE STATUS_INVALID_HANDLE
#Defina EXCEPTION_POSSIBLE_DEADLOCK STATUS_POSSIBLE_DEADLOCK
#Defina CONTROL_C_EXIT STATUS_CONTROL_C_EXIT
#Defina MoveMemory RtlMoveMemory
#Defina CopyMemory RtlCopyMemory
#Defina FillMemory RtlFillMemory
#Defina ZeroMemory RtlZeroMemory
#Defina SecureZeroMemory RtlSecureZeroMemory

#Defina FILE_FLAG_WRITE_THROUGH 0x80000000
#Defina FILE_FLAG_OVERLAPPED 0x40000000
#Defina FILE_FLAG_NO_BUFFERING 0x20000000
#Defina FILE_FLAG_RANDOM_ACCESS 0x10000000
#Defina FILE_FLAG_SEQUENTIAL_SCAN 0x8000000
#Defina FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#Defina FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#Defina FILE_FLAG_POSIX_SEMANTICS 0x1000000
#Defina FILE_FLAG_OPEN_REPARSE_POINT 0x200000
#Defina FILE_FLAG_OPEN_NO_RECALL 0x100000
#Defina FILE_FLAG_FIRST_PIPE_INSTANCE 0x80000

#Defina CREATE_NEW 1
#Defina CREATE_ALWAYS 2
#Defina OPEN_EXISTING 3
#Defina OPEN_ALWAYS 4
#Defina TRUNCATE_EXISTING 5

#Defina PROGRESS_CONTINUE 0
#Defina PROGRESS_CANCEL 1
#Defina PROGRESS_STOP 2
#Defina PROGRESS_QUIET 3

#Defina CALLBACK_CHUNK_FINISHED 0x0
#Defina CALLBACK_STREAM_SWITCH 0x1

#Defina COPY_FILE_FAIL_IF_EXISTS 0x1
#Defina COPY_FILE_RESTARTABLE 0x2
#Defina COPY_FILE_OPEN_SOURCE_FOR_WRITE 0x4
#Defina COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8

#Defina REPLACEFILE_WRITE_THROUGH 0x1
#Defina REPLACEFILE_IGNORE_MERGE_ERRORS 0x2

#Defina PIPE_ACCESS_INBOUND 0x1
#Defina PIPE_ACCESS_OUTBOUND 0x2
#Defina PIPE_ACCESS_DUPLEX 0x3

#Defina PIPE_CLIENT_END 0x0
#Defina PIPE_SERVER_END 0x1

#Defina PIPE_WAIT 0x0
#Defina PIPE_NOWAIT 0x1
#Defina PIPE_READMODE_BYTE 0x0
#Defina PIPE_READMODE_MESSAGE 0x2
#Defina PIPE_TYPE_BYTE 0x0
#Defina PIPE_TYPE_MESSAGE 0x4

#Defina PIPE_UNLIMITED_INSTANCES 255

#Defina SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#Defina SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#Defina SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#Defina SECURITY_DELEGATION (SecurityDelegation << 16)

#Defina SECURITY_CONTEXT_TRACKING 0x40000
#Defina SECURITY_EFFECTIVE_ONLY 0x80000

#Defina SECURITY_SQOS_PRESENT 0x100000
#Defina SECURITY_VALID_SQOS_FLAGS 0x1f0000

  Pseudônimo Estrutura _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    União {
      Estrutura {
	DWORD Offset;
	DWORD OffsetHigh;
      };
      PVOID Pointer;
    };
    HANDLE hEvent;
  } OVERLAPPED,*LPOVERLAPPED;

  Pseudônimo Estrutura _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    WINBOOL bInheritHandle;
  } SECURITY_ATTRIBUTES,*PSECURITY_ATTRIBUTES,*LPSECURITY_ATTRIBUTES;

  Pseudônimo Estrutura _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
  } PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;

#SeNãoDefinido _FILETIME_
#Defina _FILETIME_
  Pseudônimo Estrutura _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
  } FILETIME,*PFILETIME,*LPFILETIME;
#FimSe

  Pseudônimo Estrutura _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
  } SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

  Pseudônimo DWORD (WINAPI *PTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
  Pseudônimo PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
  Pseudônimo VOID (WINAPI *PFIBER_START_ROUTINE)(LPVOID lpFiberParameter);
  Pseudônimo PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;

  Pseudônimo RTL_CRITICAL_SECTION CRITICAL_SECTION;
  Pseudônimo PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
  Pseudônimo PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
  Pseudônimo RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
  Pseudônimo PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
  Pseudônimo PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

  WINBASEAPI PVOID WINAPI EncodePointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI DecodePointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI EncodeSystemPointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI DecodeSystemPointer(PVOID Ptr);

#SeDefinido I_X86_
  Pseudônimo PLDT_ENTRY LPLDT_ENTRY;
#Senão
  Pseudônimo LPVOID LPLDT_ENTRY;
#FimSe

#Defina MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#Defina MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#Defina SP_SERIALCOMM ((DWORD)0x1)

#Defina PST_UNSPECIFIED ((DWORD)0x0)
#Defina PST_RS232 ((DWORD)0x1)
#Defina PST_PARALLELPORT ((DWORD)0x2)
#Defina PST_RS422 ((DWORD)0x3)
#Defina PST_RS423 ((DWORD)0x4)
#Defina PST_RS449 ((DWORD)0x5)
#Defina PST_MODEM ((DWORD)0x6)
#Defina PST_FAX ((DWORD)0x21)
#Defina PST_SCANNER ((DWORD)0x22)
#Defina PST_NETWORK_BRIDGE ((DWORD)0x100)
#Defina PST_LAT ((DWORD)0x101)
#Defina PST_TCPIP_TELNET ((DWORD)0x102)
#Defina PST_X25 ((DWORD)0x103)

#Defina PCF_DTRDSR ((DWORD)0x1)
#Defina PCF_RTSCTS ((DWORD)0x2)
#Defina PCF_RLSD ((DWORD)0x4)
#Defina PCF_PARITY_CHECK ((DWORD)0x8)
#Defina PCF_XONXOFF ((DWORD)0x10)
#Defina PCF_SETXCHAR ((DWORD)0x20)
#Defina PCF_TOTALTIMEOUTS ((DWORD)0x40)
#Defina PCF_INTTIMEOUTS ((DWORD)0x80)
#Defina PCF_SPECIALCHARS ((DWORD)0x100)
#Defina PCF_16BITMODE ((DWORD)0x200)

#Defina SP_PARITY ((DWORD)0x1)
#Defina SP_BAUD ((DWORD)0x2)
#Defina SP_DATABITS ((DWORD)0x4)
#Defina SP_STOPBITS ((DWORD)0x8)
#Defina SP_HANDSHAKING ((DWORD)0x10)
#Defina SP_PARITY_CHECK ((DWORD)0x20)
#Defina SP_RLSD ((DWORD)0x40)

#Defina BAUD_075 ((DWORD)0x1)
#Defina BAUD_110 ((DWORD)0x2)
#Defina BAUD_134_5 ((DWORD)0x4)
#Defina BAUD_150 ((DWORD)0x8)
#Defina BAUD_300 ((DWORD)0x10)
#Defina BAUD_600 ((DWORD)0x20)
#Defina BAUD_1200 ((DWORD)0x40)
#Defina BAUD_1800 ((DWORD)0x80)
#Defina BAUD_2400 ((DWORD)0x100)
#Defina BAUD_4800 ((DWORD)0x200)
#Defina BAUD_7200 ((DWORD)0x400)
#Defina BAUD_9600 ((DWORD)0x800)
#Defina BAUD_14400 ((DWORD)0x1000)
#Defina BAUD_19200 ((DWORD)0x2000)
#Defina BAUD_38400 ((DWORD)0x4000)
#Defina BAUD_56K ((DWORD)0x8000)
#Defina BAUD_128K ((DWORD)0x10000)
#Defina BAUD_115200 ((DWORD)0x20000)
#Defina BAUD_57600 ((DWORD)0x40000)
#Defina BAUD_USER ((DWORD)0x10000000)

#Defina DATABITS_5 ((WORD)0x1)
#Defina DATABITS_6 ((WORD)0x2)
#Defina DATABITS_7 ((WORD)0x4)
#Defina DATABITS_8 ((WORD)0x8)
#Defina DATABITS_16 ((WORD)0x10)
#Defina DATABITS_16X ((WORD)0x20)

#Defina STOPBITS_10 ((WORD)0x1)
#Defina STOPBITS_15 ((WORD)0x2)
#Defina STOPBITS_20 ((WORD)0x4)
#Defina PARITY_NONE ((WORD)0x100)
#Defina PARITY_ODD ((WORD)0x200)
#Defina PARITY_EVEN ((WORD)0x400)
#Defina PARITY_MARK ((WORD)0x800)
#Defina PARITY_SPACE ((WORD)0x1000)

  Pseudônimo Estrutura _COMMPROP {
    WORD wPacketLength;
    WORD wPacketVersion;
    DWORD dwServiceMask;
    DWORD dwReserved1;
    DWORD dwMaxTxQueue;
    DWORD dwMaxRxQueue;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    WORD wSettableData;
    WORD wSettableStopParity;
    DWORD dwCurrentTxQueue;
    DWORD dwCurrentRxQueue;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#Defina COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  Pseudônimo Estrutura _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD fXoffSent : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cbInQue;
    DWORD cbOutQue;
  } COMSTAT,*LPCOMSTAT;

#Defina DTR_CONTROL_DISABLE 0x0
#Defina DTR_CONTROL_ENABLE 0x1
#Defina DTR_CONTROL_HANDSHAKE 0x2

#Defina RTS_CONTROL_DISABLE 0x0
#Defina RTS_CONTROL_ENABLE 0x1
#Defina RTS_CONTROL_HANDSHAKE 0x2
#Defina RTS_CONTROL_TOGGLE 0x3

  Pseudônimo Estrutura _DCB {
    DWORD DCBlength;
    DWORD BaudRate;
    DWORD fBinary: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD fDsrSensitivity:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD fOutX: 1;
    DWORD fInX: 1;
    DWORD fErrorChar: 1;
    DWORD fNull: 1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    WORD wReserved;
    WORD XonLim;
    WORD XoffLim;
    BYTE ByteSize;
    BYTE Parity;
    BYTE StopBits;
    Caractere XonChar;
    Caractere XoffChar;
    Caractere ErrorChar;
    Caractere EofChar;
    Caractere EvtChar;
    WORD wReserved1;
  } DCB,*LPDCB;

  Pseudônimo Estrutura _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD ReadTotalTimeoutMultiplier;
    DWORD ReadTotalTimeoutConstant;
    DWORD WriteTotalTimeoutMultiplier;
    DWORD WriteTotalTimeoutConstant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  Pseudônimo Estrutura _COMMCONFIG {
    DWORD dwSize;
    WORD wVersion;
    WORD wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dwProviderOffset;
    DWORD dwProviderSize;
    WCHAR wcProviderData[1];
  } COMMCONFIG,*LPCOMMCONFIG;

  Pseudônimo Estrutura _SYSTEM_INFO {
    União {
      DWORD dwOemId;
      Estrutura {
	WORD wProcessorArchitecture;
	WORD wReserved;
      };
    };
    DWORD dwPageSize;
    LPVOID lpMinimumApplicationAddress;
    LPVOID lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD dwNumberOfProcessors;
    DWORD dwProcessorType;
    DWORD dwAllocationGranularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
  } SYSTEM_INFO,*LPSYSTEM_INFO;

#Defina FreeModule(hLibModule) FreeLibrary((hLibModule))
#Defina MakeProcInstance(lpProc,hInstance) (lpProc)
#Defina FreeProcInstance(lpProc) (lpProc)

#Defina GMEM_FIXED 0x0
#Defina GMEM_MOVEABLE 0x2
#Defina GMEM_NOCOMPACT 0x10
#Defina GMEM_NODISCARD 0x20
#Defina GMEM_ZEROINIT 0x40
#Defina GMEM_MODIFY 0x80
#Defina GMEM_DISCARDABLE 0x100
#Defina GMEM_NOT_BANKED 0x1000
#Defina GMEM_SHARE 0x2000
#Defina GMEM_DDESHARE 0x2000
#Defina GMEM_NOTIFY 0x4000
#Defina GMEM_LOWER GMEM_NOT_BANKED
#Defina GMEM_VALID_FLAGS 0x7F72
#Defina GMEM_INVALID_HANDLE 0x8000

#Defina GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#Defina GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#Defina GlobalLRUNewest(h) ((HANDLE)(h))
#Defina GlobalLRUOldest(h) ((HANDLE)(h))
#Defina GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#Defina GMEM_DISCARDED 0x4000
#Defina GMEM_LOCKCOUNT 0xff

  Pseudônimo Estrutura _MEMORYSTATUS {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    SIZE_T dwTotalPhys;
    SIZE_T dwAvailPhys;
    SIZE_T dwTotalPageFile;
    SIZE_T dwAvailPageFile;
    SIZE_T dwTotalVirtual;
    SIZE_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#Defina LMEM_FIXED 0x0
#Defina LMEM_MOVEABLE 0x2
#Defina LMEM_NOCOMPACT 0x10
#Defina LMEM_NODISCARD 0x20
#Defina LMEM_ZEROINIT 0x40
#Defina LMEM_MODIFY 0x80
#Defina LMEM_DISCARDABLE 0xf00
#Defina LMEM_VALID_FLAGS 0xf72
#Defina LMEM_INVALID_HANDLE 0x8000

#Defina LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)
#Defina LPTR (LMEM_FIXED | LMEM_ZEROINIT)

#Defina NONZEROLHND (LMEM_MOVEABLE)
#Defina NONZEROLPTR (LMEM_FIXED)

#Defina LocalDiscard(h) LocalReAlloc((h),0,LMEM_MOVEABLE)

#Defina LMEM_DISCARDED 0x4000
#Defina LMEM_LOCKCOUNT 0xff

#Defina DEBUG_PROCESS 0x1
#Defina DEBUG_ONLY_THIS_PROCESS 0x2
#Defina CREATE_SUSPENDED 0x4
#Defina DETACHED_PROCESS 0x8
#Defina CREATE_NEW_CONSOLE 0x10
#Defina NORMAL_PRIORITY_CLASS 0x20
#Defina IDLE_PRIORITY_CLASS 0x40
#Defina HIGH_PRIORITY_CLASS 0x80
#Defina REALTIME_PRIORITY_CLASS 0x100
#Defina CREATE_NEW_PROCESS_GROUP 0x200
#Defina CREATE_UNICODE_ENVIRONMENT 0x400
#Defina CREATE_SEPARATE_WOW_VDM 0x800
#Defina CREATE_SHARED_WOW_VDM 0x1000
#Defina CREATE_FORCEDOS 0x2000
#Defina BELOW_NORMAL_PRIORITY_CLASS 0x4000
#Defina ABOVE_NORMAL_PRIORITY_CLASS 0x8000
#Defina STACK_SIZE_PARAM_IS_A_RESERVATION 0x10000

#Defina CREATE_BREAKAWAY_FROM_JOB 0x1000000
#Defina CREATE_PRESERVE_CODE_AUTHZ_LEVEL 0x2000000

#Defina CREATE_DEFAULT_ERROR_MODE 0x4000000
#Defina CREATE_NO_WINDOW 0x8000000

#Defina PROFILE_USER 0x10000000
#Defina PROFILE_KERNEL 0x20000000
#Defina PROFILE_SERVER 0x40000000

#Defina CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#Defina THREAD_PRIORITY_LOWEST THREAD_BASE_PRIORITY_MIN
#Defina THREAD_PRIORITY_BELOW_NORMAL (THREAD_PRIORITY_LOWEST+1)
#Defina THREAD_PRIORITY_NORMAL 0
#Defina THREAD_PRIORITY_HIGHEST THREAD_BASE_PRIORITY_MAX
#Defina THREAD_PRIORITY_ABOVE_NORMAL (THREAD_PRIORITY_HIGHEST-1)
#Defina THREAD_PRIORITY_ERROR_RETURN (MAXLONG)

#Defina THREAD_PRIORITY_TIME_CRITICAL THREAD_BASE_PRIORITY_LOWRT
#Defina THREAD_PRIORITY_IDLE THREAD_BASE_PRIORITY_IDLE

#Defina EXCEPTION_DEBUG_EVENT 1
#Defina CREATE_THREAD_DEBUG_EVENT 2
#Defina CREATE_PROCESS_DEBUG_EVENT 3
#Defina EXIT_THREAD_DEBUG_EVENT 4
#Defina EXIT_PROCESS_DEBUG_EVENT 5
#Defina LOAD_DLL_DEBUG_EVENT 6
#Defina UNLOAD_DLL_DEBUG_EVENT 7
#Defina OUTPUT_DEBUG_STRING_EVENT 8
#Defina RIP_EVENT 9

  Pseudônimo Estrutura _EXCEPTION_DEBUG_INFO {
    EXCEPTION_RECORD ExceptionRecord;
    DWORD dwFirstChance;
  } EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;

  Pseudônimo Estrutura _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
  } CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

  Pseudônimo Estrutura _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lpBaseOfImage;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
    LPVOID lpImageName;
    WORD fUnicode;
  } CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;

  Pseudônimo Estrutura _EXIT_THREAD_DEBUG_INFO {
    DWORD dwExitCode;
  } EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;

  Pseudônimo Estrutura _EXIT_PROCESS_DEBUG_INFO {
    DWORD dwExitCode;
  } EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;

  Pseudônimo Estrutura _LOAD_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lpBaseOfDll;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPVOID lpImageName;
    WORD fUnicode;
  } LOAD_DLL_DEBUG_INFO,*LPLOAD_DLL_DEBUG_INFO;

  Pseudônimo Estrutura _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lpBaseOfDll;
  } UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;

  Pseudônimo Estrutura _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lpDebugStringData;
    WORD fUnicode;
    WORD nDebugStringLength;
  } OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;

  Pseudônimo Estrutura _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
  } RIP_INFO,*LPRIP_INFO;

  Pseudônimo Estrutura _DEBUG_EVENT {
    DWORD dwDebugEventCode;
    DWORD dwProcessId;
    DWORD dwThreadId;
    União {
      EXCEPTION_DEBUG_INFO Exception;
      CREATE_THREAD_DEBUG_INFO CreateThread;
      CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
      EXIT_THREAD_DEBUG_INFO ExitThread;
      EXIT_PROCESS_DEBUG_INFO ExitProcess;
      LOAD_DLL_DEBUG_INFO LoadDll;
      UNLOAD_DLL_DEBUG_INFO UnloadDll;
      OUTPUT_DEBUG_STRING_INFO DebugString;
      RIP_INFO RipInfo;
    } u;
  } DEBUG_EVENT,*LPDEBUG_EVENT;

  Pseudônimo PCONTEXT LPCONTEXT;
  Pseudônimo PEXCEPTION_RECORD LPEXCEPTION_RECORD;
  Pseudônimo PEXCEPTION_POINTERS LPEXCEPTION_POINTERS;

#Defina DRIVE_UNKNOWN 0
#Defina DRIVE_NO_ROOT_DIR 1
#Defina DRIVE_REMOVABLE 2
#Defina DRIVE_FIXED 3
#Defina DRIVE_REMOTE 4
#Defina DRIVE_CDROM 5
#Defina DRIVE_RAMDISK 6

#Defina GetFreeSpace(w) (0x100000L)
#Defina FILE_TYPE_UNKNOWN 0x0
#Defina FILE_TYPE_DISK 0x1
#Defina FILE_TYPE_CHAR 0x2
#Defina FILE_TYPE_PIPE 0x3
#Defina FILE_TYPE_REMOTE 0x8000

#Defina STD_INPUT_HANDLE ((DWORD)-10)
#Defina STD_OUTPUT_HANDLE ((DWORD)-11)
#Defina STD_ERROR_HANDLE ((DWORD)-12)

#Defina NOPARITY 0
#Defina ODDPARITY 1
#Defina EVENPARITY 2
#Defina MARKPARITY 3
#Defina SPACEPARITY 4

#Defina ONESTOPBIT 0
#Defina ONE5STOPBITS 1
#Defina TWOSTOPBITS 2

#Defina IGNORE 0
#Defina INFINITE 0xffffffff

#Defina CBR_110 110
#Defina CBR_300 300
#Defina CBR_600 600
#Defina CBR_1200 1200
#Defina CBR_2400 2400
#Defina CBR_4800 4800
#Defina CBR_9600 9600
#Defina CBR_14400 14400
#Defina CBR_19200 19200
#Defina CBR_38400 38400
#Defina CBR_56000 56000
#Defina CBR_57600 57600
#Defina CBR_115200 115200
#Defina CBR_128000 128000
#Defina CBR_256000 256000

#Defina CE_RXOVER 0x1
#Defina CE_OVERRUN 0x2
#Defina CE_RXPARITY 0x4
#Defina CE_FRAME 0x8
#Defina CE_BREAK 0x10
#Defina CE_TXFULL 0x100
#Defina CE_PTO 0x200
#Defina CE_IOE 0x400
#Defina CE_DNS 0x800
#Defina CE_OOP 0x1000
#Defina CE_MODE 0x8000

#Defina IE_BADID (-1)
#Defina IE_OPEN (-2)
#Defina IE_NOPEN (-3)
#Defina IE_MEMORY (-4)
#Defina IE_DEFAULT (-5)
#Defina IE_HARDWARE (-10)
#Defina IE_BYTESIZE (-11)
#Defina IE_BAUDRATE (-12)

#Defina EV_RXCHAR 0x1
#Defina EV_RXFLAG 0x2
#Defina EV_TXEMPTY 0x4
#Defina EV_CTS 0x8
#Defina EV_DSR 0x10
#Defina EV_RLSD 0x20
#Defina EV_BREAK 0x40
#Defina EV_ERR 0x80
#Defina EV_RING 0x100
#Defina EV_PERR 0x200
#Defina EV_RX80FULL 0x400
#Defina EV_EVENT1 0x800
#Defina EV_EVENT2 0x1000

#Defina SETXOFF 1
#Defina SETXON 2
#Defina SETRTS 3
#Defina CLRRTS 4
#Defina SETDTR 5
#Defina CLRDTR 6
#Defina RESETDEV 7
#Defina SETBREAK 8
#Defina CLRBREAK 9

#Defina PURGE_TXABORT 0x1
#Defina PURGE_RXABORT 0x2
#Defina PURGE_TXCLEAR 0x4
#Defina PURGE_RXCLEAR 0x8

#Defina LPTx 0x80

#Defina MS_CTS_ON ((DWORD)0x10)
#Defina MS_DSR_ON ((DWORD)0x20)
#Defina MS_RING_ON ((DWORD)0x40)
#Defina MS_RLSD_ON ((DWORD)0x80)

#Defina S_QUEUEEMPTY 0
#Defina S_THRESHOLD 1
#Defina S_ALLTHRESHOLD 2

#Defina S_NORMAL 0
#Defina S_LEGATO 1
#Defina S_STACCATO 2

#Defina S_PERIOD512 0
#Defina S_PERIOD1024 1
#Defina S_PERIOD2048 2
#Defina S_PERIODVOICE 3
#Defina S_WHITE512 4
#Defina S_WHITE1024 5
#Defina S_WHITE2048 6
#Defina S_WHITEVOICE 7

#Defina S_SERDVNA (-1)
#Defina S_SEROFM (-2)
#Defina S_SERMACT (-3)
#Defina S_SERQFUL (-4)
#Defina S_SERBDNT (-5)
#Defina S_SERDLN (-6)
#Defina S_SERDCC (-7)
#Defina S_SERDTP (-8)
#Defina S_SERDVL (-9)
#Defina S_SERDMD (-10)
#Defina S_SERDSH (-11)
#Defina S_SERDPT (-12)
#Defina S_SERDFQ (-13)
#Defina S_SERDDR (-14)
#Defina S_SERDSR (-15)
#Defina S_SERDST (-16)

#Defina NMPWAIT_WAIT_FOREVER 0xffffffff
#Defina NMPWAIT_NOWAIT 0x1
#Defina NMPWAIT_USE_DEFAULT_WAIT 0x0

#Defina FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_NAMES
#Defina FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_SEARCH
#Defina FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#Defina FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#Defina FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#Defina FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#Defina FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#Defina FILE_MAP_COPY SECTION_QUERY
#Defina FILE_MAP_WRITE SECTION_MAP_WRITE
#Defina FILE_MAP_READ SECTION_MAP_READ
#Defina FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#Defina FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT

#Defina OF_READ 0x0
#Defina OF_WRITE 0x1
#Defina OF_READWRITE 0x2
#Defina OF_SHARE_COMPAT 0x0
#Defina OF_SHARE_EXCLUSIVE 0x10
#Defina OF_SHARE_DENY_WRITE 0x20
#Defina OF_SHARE_DENY_READ 0x30
#Defina OF_SHARE_DENY_NONE 0x40
#Defina OF_PARSE 0x100
#Defina OF_DELETE 0x200
#Defina OF_VERIFY 0x400
#Defina OF_CANCEL 0x800
#Defina OF_CREATE 0x1000
#Defina OF_PROMPT 0x2000
#Defina OF_EXIST 0x4000
#Defina OF_REOPEN 0x8000

#Defina OFS_MAXPATHNAME 128
  Pseudônimo Estrutura _OFSTRUCT {
    BYTE cBytes;
    BYTE fFixedDisk;
    WORD nErrCode;
    WORD Reserved1;
    WORD Reserved2;
    CHAR szPathName[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#SeNãoDefinido NOWINBASEINTERLOCK

#SeNãoDefinido _NTOS_

#Se Definido(__ia64__) && !Definido(RC_INVOKED)

#Defina InterlockedIncrement _InterlockedIncrement
#Defina InterlockedIncrementAcquire _InterlockedIncrement_acq
#Defina InterlockedIncrementRelease _InterlockedIncrement_rel
#Defina InterlockedDecrement _InterlockedDecrement
#Defina InterlockedDecrementAcquire _InterlockedDecrement_acq
#Defina InterlockedDecrementRelease _InterlockedDecrement_rel
#Defina InterlockedExchange _InterlockedExchange
#Defina InterlockedExchangeAdd _InterlockedExchangeAdd
#Defina InterlockedCompareExchange _InterlockedCompareExchange
#Defina InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#Defina InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#Defina InterlockedExchangePointer _InterlockedExchangePointer
#Defina InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#Defina InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer_rel
#Defina InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer_acq

#Defina InterlockedIncrement64 _InterlockedIncrement64
#Defina InterlockedDecrement64 _InterlockedDecrement64
#Defina InterlockedExchange64 _InterlockedExchange64
#Defina InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#Defina InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#Defina InterlockedCompareExchange64 _InterlockedCompareExchange64
#Defina InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#Defina InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG Declaração InterlockedIncrement64(LONGLONG Instável *Addend);
  LONGLONG Declaração InterlockedDecrement64(LONGLONG Instável *Addend);
  LONG Declaração InterlockedIncrementAcquire(LONG Instável *Addend);
  LONG Declaração InterlockedDecrementAcquire(LONG Instável *Addend);
  LONG Declaração InterlockedIncrementRelease(LONG Instável *Addend);
  LONG Declaração InterlockedDecrementRelease(LONG Instável *Addend);
  LONGLONG Declaração InterlockedExchange64 (LONGLONG Instável *Target,LONGLONG Value);
  LONGLONG Declaração InterlockedExchangeAcquire64 (LONGLONG Instável *Target,LONGLONG Value);
  LONGLONG Declaração InterlockedExchangeAdd64 (LONGLONG Instável *Addend,LONGLONG Value);
  LONGLONG Declaração InterlockedCompareExchange64 (LONGLONG Instável *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG Declaração InterlockedCompareExchangeAcquire64 (LONGLONG Instável *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG Declaração InterlockedCompareExchangeRelease64 (LONGLONG Instável *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG Declaração InterlockedIncrement(LONG Instável *lpAddend);
  LONG Declaração InterlockedDecrement(LONG Instável *lpAddend);
  LONG Declaração InterlockedExchange(LONG Instável *Target,LONG Value);
  LONG Declaração InterlockedExchangeAdd(LONG Instável *Addend,LONG Value);
  LONG Declaração InterlockedCompareExchange(LONG Instável *Destination,LONG ExChange,LONG Comperand);
  LONG Declaração InterlockedCompareExchangeRelease(LONG Instável *Destination,LONG ExChange,LONG Comperand);
  LONG Declaração InterlockedCompareExchangeAcquire(LONG Instável *Destination,LONG ExChange,LONG Comperand);
  PVOID Declaração InterlockedExchangePointer(PVOID Instável *Target,PVOID Value);
  PVOID Declaração InterlockedCompareExchangePointer(PVOID Instável *Destination,PVOID ExChange,PVOID Comperand);
  PVOID Declaração InterlockedCompareExchangePointerAcquire(PVOID Instável *Destination,PVOID Exchange,PVOID Comperand);
  PVOID Declaração InterlockedCompareExchangePointerRelease(PVOID Instável *Destination,PVOID Exchange,PVOID Comperand);

#SeNãoDefinido InterlockedAnd
#Defina InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG Instável *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    Faça {
      i = j;
      j = InterlockedCompareExchange(Target,i & Set,i);
    } Enquanto(i!=j);
    Retorne j;
  }
#FimSe

#SeNãoDefinido InterlockedOr
#Defina InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG Instável *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    Faça {
      i = j;
      j = InterlockedCompareExchange(Target,i | Set,i);
    } Enquanto(i!=j);
    Retorne j;
  }
#FimSe

#SeNãoDefinido InterlockedXor
#Defina InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG Instável *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    Faça {
      i = j;
      j = InterlockedCompareExchange(Target,i ^ Set,i);
    } Enquanto(i!=j);
    Retorne j;
  }
#FimSe

#SeNãoDefinido !Definido (InterlockedAnd64)
#Defina InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG Instável *Destination,LONGLONG Value) {
    LONGLONG Old;
    Faça {
      Old = *Destination;
    } Enquanto(InterlockedCompareExchange64(Destination,Old & Value,Old)!=Old);
    Retorne Old;
  }
#FimSe

#SeNãoDefinido InterlockedOr64
#Defina InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG Instável *Destination,LONGLONG Value) {
    LONGLONG Old;
    Faça {
      Old = *Destination;
    } Enquanto(InterlockedCompareExchange64(Destination,Old | Value,Old)!=Old);
    Retorne Old;
  }
#FimSe

#SeNãoDefinido InterlockedXor64
#Defina InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG Instável *Destination,LONGLONG Value) {
    LONGLONG Old;
    Faça {
      Old = *Destination;
    } Enquanto(InterlockedCompareExchange64(Destination,Old ^ Value,Old)!=Old);
    Retorne Old;
  }
#FimSe

#SeNãoDefinido InterlockedBitTestAndSet
#Defina InterlockedBitTestAndSet InterlockedBitTestAndSet_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndSet_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (meça (*Base)*8-1));
    Retorne (BOOLEAN)((InterlockedOr(&Base[Bit/(meça(*Base)*8)],tBit)&tBit)!=0);
  }
#FimSe

#SeNãoDefinido InterlockedBitTestAndReset
#Defina InterlockedBitTestAndReset InterlockedBitTestAndReset_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndReset_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (meça (*Base)*8-1));
    Retorne (BOOLEAN)((InterlockedAnd(&Base[Bit/(meça(*Base)*8)],~tBit)&tBit)!=0);
  }
#FimSe

#SeNãoDefinido InterlockedBitTestAndComplement
#Defina InterlockedBitTestAndComplement InterlockedBitTestAndComplement_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndComplement_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (meça (*Base)*8-1));
    Retorne (BOOLEAN)((InterlockedXor(&Base[Bit/(meça(*Base)*8)],tBit)&tBit)!=0);
  }
#FimSe
#Exceto Definido(__x86_64) && !Definido(RC_INVOKED)

#Defina InterlockedIncrement _InterlockedIncrement
#Defina InterlockedIncrementAcquire InterlockedIncrement
#Defina InterlockedIncrementRelease InterlockedIncrement
#Defina InterlockedDecrement _InterlockedDecrement
#Defina InterlockedDecrementAcquire InterlockedDecrement
#Defina InterlockedDecrementRelease InterlockedDecrement
#Defina InterlockedExchange _InterlockedExchange
#Defina InterlockedExchangeAdd _InterlockedExchangeAdd
#Defina InterlockedCompareExchange _InterlockedCompareExchange
#Defina InterlockedCompareExchangeAcquire InterlockedCompareExchange
#Defina InterlockedCompareExchangeRelease InterlockedCompareExchange
#Defina InterlockedExchangePointer _InterlockedExchangePointer
#Defina InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#Defina InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer
#Defina InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer
#Defina InterlockedAnd64 _InterlockedAnd64
#Defina InterlockedOr64 _InterlockedOr64
#Defina InterlockedXor64 _InterlockedXor64
#Defina InterlockedIncrement64 _InterlockedIncrement64
#Defina InterlockedDecrement64 _InterlockedDecrement64
#Defina InterlockedExchange64 _InterlockedExchange64
#Defina InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#Defina InterlockedCompareExchange64 _InterlockedCompareExchange64
#Defina InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#Defina InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  LONG InterlockedIncrement(LONG Instável *Addend);
  LONG InterlockedDecrement(LONG Instável *Addend);
  LONG InterlockedExchange(LONG Instável *Target,LONG Value);
  LONG InterlockedExchangeAdd(LONG Instável *Addend,LONG Value);
  LONG InterlockedCompareExchange(LONG Instável *Destination,LONG ExChange,LONG Comperand);
  PVOID InterlockedCompareExchangePointer(PVOID Instável *Destination,PVOID Exchange,PVOID Comperand);
  PVOID InterlockedExchangePointer(PVOID Instável *Target,PVOID Value);
  LONG64 InterlockedAnd64(LONG64 Instável *Destination,LONG64 Value);
  LONG64 InterlockedOr64(LONG64 Instável *Destination,LONG64 Value);
  LONG64 InterlockedXor64(LONG64 Instável *Destination,LONG64 Value);
  LONG64 InterlockedIncrement64(LONG64 Instável *Addend);
  LONG64 InterlockedDecrement64(LONG64 Instável *Addend);
  LONG64 InterlockedExchange64(LONG64 Instável *Target,LONG64 Value);
  LONG64 InterlockedExchangeAdd64(LONG64 Instável *Addend,LONG64 Value);
  LONG64 InterlockedCompareExchange64(LONG64 Instável *Destination,LONG64 ExChange,LONG64 Comperand);
#Senão
  LONG WINAPI InterlockedIncrement(LONG Instável *lpAddend);
  LONG WINAPI InterlockedDecrement(LONG Instável *lpAddend);
  LONG WINAPI InterlockedExchange(LONG Instável *Target,LONG Value);

#Defina InterlockedExchangePointer(Target,Value) (PVOID)InterlockedExchange((PLONG)(Target),(LONG)(Value))

  LONG WINAPI InterlockedExchangeAdd(LONG Instável *Addend,LONG Value);
  LONG WINAPI InterlockedCompareExchange(LONG Instável *Destination,LONG Exchange,LONG Comperand);
  LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG Instável *Destination,LONGLONG Exchange,LONGLONG Comperand);

  __CRT_INLINE LONGLONG InterlockedAnd64 (LONGLONG Instável *Destination,LONGLONG Value) {
    LONGLONG Old;
    Faça {
      Old = *Destination;
    } Enquanto(InterlockedCompareExchange64(Destination,Old & Value,Old)!=Old);
    Retorne Old;
  }

  __CRT_INLINE LONGLONG InterlockedOr64 (LONGLONG Instável *Destination,LONGLONG Value) {
    LONGLONG Old;
    Faça {
      Old = *Destination;
    } Enquanto(InterlockedCompareExchange64(Destination,Old | Value,Old)!=Old);
    Retorne Old;
  }

  __CRT_INLINE LONGLONG InterlockedXor64 (LONGLONG Instável *Destination,LONGLONG Value) {
    LONGLONG Old;
    Faça {
      Old = *Destination;
    } Enquanto(InterlockedCompareExchange64(Destination,Old ^ Value,Old)!=Old);

    Retorne Old;
  }

  __CRT_INLINE LONGLONG InterlockedIncrement64(LONGLONG Instável *Addend) {
    LONGLONG Old;
    Faça {
      Old = *Addend;
    } Enquanto(InterlockedCompareExchange64(Addend,Old + 1,Old)!=Old);
    Retorne Old + 1;
  }

  __CRT_INLINE LONGLONG InterlockedDecrement64(LONGLONG Instável *Addend) {
    LONGLONG Old;
    Faça {
      Old = *Addend;
    } Enquanto(InterlockedCompareExchange64(Addend,Old - 1,Old)!=Old);
    Retorne Old - 1;
  }

  __CRT_INLINE LONGLONG InterlockedExchange64(LONGLONG Instável *Target,LONGLONG Value) {
    LONGLONG Old;
    Faça {
      Old = *Target;
    } Enquanto(InterlockedCompareExchange64(Target,Value,Old)!=Old);
    Retorne Old;
  }

  __CRT_INLINE LONGLONG InterlockedExchangeAdd64(LONGLONG Instável *Addend,LONGLONG Value) {
    LONGLONG Old;
    Faça {
      Old = *Addend;
    } Enquanto(InterlockedCompareExchange64(Addend,Old + Value,Old)!=Old);
    Retorne Old;
  }

#SeDefinido __cplusplus
  __CRT_INLINE PVOID Declaração __InlineInterlockedCompareExchangePointer(PVOID Instável *Destination,PVOID ExChange,PVOID Comperand) {
    Retorne((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG Instável *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#Defina InterlockedCompareExchangePointer __InlineInterlockedCompareExchangePointer
#Senão
#Defina InterlockedCompareExchangePointer(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG Instável *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#FimSe

#Defina InterlockedIncrementAcquire InterlockedIncrement
#Defina InterlockedIncrementRelease InterlockedIncrement
#Defina InterlockedDecrementAcquire InterlockedDecrement
#Defina InterlockedDecrementRelease InterlockedDecrement
#Defina InterlockedIncrementAcquire InterlockedIncrement
#Defina InterlockedIncrementRelease InterlockedIncrement
#Defina InterlockedCompareExchangeAcquire InterlockedCompareExchange
#Defina InterlockedCompareExchangeRelease InterlockedCompareExchange
#Defina InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#Defina InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#Defina InterlockedCompareExchangePointerAcquire InterlockedCompareExchangePointer
#Defina InterlockedCompareExchangePointerRelease InterlockedCompareExchangePointer
#FimSe

#Se Definido(_SLIST_HEADER_) && !Definido(_NTOSP_)
  WINBASEAPI VOID WINAPI InitializeSListHead(PSLIST_HEADER ListHead);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPopEntrySList(PSLIST_HEADER ListHead);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPushEntrySList(PSLIST_HEADER ListHead,PSLIST_ENTRY ListEntry);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedFlushSList(PSLIST_HEADER ListHead);
  WINBASEAPI USHORT WINAPI QueryDepthSList(PSLIST_HEADER ListHead);
#FimSe
#FimSe
#FimSe

  WINBASEAPI WINBOOL WINAPI FreeResource(HGLOBAL hResData);
  WINBASEAPI LPVOID WINAPI LockResource(HGLOBAL hResData);

#Defina UnlockResource(hResData) ((hResData),0)
#Defina MAXINTATOM 0xC000
#Defina MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((WORD)(i)))
#Defina INVALID_ATOM ((ATOM)0)

  Inteiro WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,Inteiro nShowCmd);
  WINBASEAPI WINBOOL WINAPI FreeLibrary(HMODULE hLibModule);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dwExitCode);
  WINBASEAPI WINBOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
  WINBASEAPI FARPROC WINAPI GetProcAddress(HMODULE hModule,LPCSTR lpProcName);
  WINBASEAPI DWORD WINAPI GetVersion(VOID);
  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,SIZE_T dwBytes);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,SIZE_T dwBytes,UINT uFlags);
  WINBASEAPI SIZE_T WINAPI GlobalSize(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalLock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI SIZE_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer);

  Pseudônimo Estrutura _MEMORYSTATUSEX {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    DWORDLONG ullTotalPhys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ullTotalPageFile;
    DWORDLONG ullAvailPageFile;
    DWORDLONG ullTotalVirtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX,*LPMEMORYSTATUSEX;

  WINBASEAPI WINBOOL WINAPI GlobalMemoryStatusEx(LPMEMORYSTATUSEX lpBuffer);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,SIZE_T uBytes);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,SIZE_T uBytes,UINT uFlags);
  WINBASEAPI LPVOID WINAPI LocalLock(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI SIZE_T WINAPI LocalSize(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI SIZE_T WINAPI LocalShrink(HLOCAL hMem,UINT cbNewSize);
  WINBASEAPI SIZE_T WINAPI LocalCompact(UINT uMinFree);
  WINBASEAPI WINBOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lpBaseAddress,SIZE_T dwSize);
  WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lpAddress,SIZE_T dwSize,DWORD flAllocationType,DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lpAddress,SIZE_T dwSize,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lpAddress,SIZE_T dwSize,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI SIZE_T WINAPI VirtualQuery(LPCVOID lpAddress,PMEMORY_BASIC_INFORMATION lpBuffer,SIZE_T dwLength);
  WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lpAddress,SIZE_T dwSize,DWORD flAllocationType,DWORD flProtect);
  WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lpBaseAddress,SIZE_T dwRegionSize,PVOID *lpAddresses,ULONG_PTR *lpdwCount,PULONG lpdwGranularity);
  WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lpBaseAddress,SIZE_T dwRegionSize);
  WINBASEAPI SIZE_T WINAPI GetLargePageMinimum(VOID);
  WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD FirmwareTableProviderSignature,PVOID pFirmwareTableEnumBuffer,DWORD BufferSize);
  WINBASEAPI UINT WINAPI GetSystemFirmwareTable(DWORD FirmwareTableProviderSignature,DWORD FirmwareTableID,PVOID pFirmwareTableBuffer,DWORD BufferSize);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lpAddress,SIZE_T dwSize,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lpAddress,SIZE_T dwSize,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI SIZE_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lpAddress,PMEMORY_BASIC_INFORMATION lpBuffer,SIZE_T dwLength);
  WINBASEAPI HANDLE WINAPI HeapCreate(DWORD flOptions,SIZE_T dwInitialSize,SIZE_T dwMaximumSize);
  WINBASEAPI WINBOOL WINAPI HeapDestroy(HANDLE hHeap);
  WINBASEAPI LPVOID WINAPI HeapAlloc(HANDLE hHeap,DWORD dwFlags,SIZE_T dwBytes);
  WINBASEAPI LPVOID WINAPI HeapReAlloc(HANDLE hHeap,DWORD dwFlags,LPVOID lpMem,SIZE_T dwBytes);
  WINBASEAPI WINBOOL WINAPI HeapFree(HANDLE hHeap,DWORD dwFlags,LPVOID lpMem);
  WINBASEAPI SIZE_T WINAPI HeapSize(HANDLE hHeap,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI HeapValidate(HANDLE hHeap,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI SIZE_T WINAPI HeapCompact(HANDLE hHeap,DWORD dwFlags);
  WINBASEAPI HANDLE WINAPI GetProcessHeap(VOID);
  WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD NumberOfHeaps,PHANDLE ProcessHeaps);

  Pseudônimo Estrutura _PROCESS_HEAP_ENTRY {
    PVOID lpData;
    DWORD cbData;
    BYTE cbOverhead;
    BYTE iRegionIndex;
    WORD wFlags;
    União {
      Estrutura {
	HANDLE hMem;
	DWORD dwReserved[3];
      } Block;
      Estrutura {
	DWORD dwCommittedSize;
	DWORD dwUnCommittedSize;
	LPVOID lpFirstBlock;
	LPVOID lpLastBlock;
      } Region;
    };
  } PROCESS_HEAP_ENTRY,*LPPROCESS_HEAP_ENTRY,*PPROCESS_HEAP_ENTRY;

#Defina PROCESS_HEAP_REGION 0x1
#Defina PROCESS_HEAP_UNCOMMITTED_RANGE 0x2
#Defina PROCESS_HEAP_ENTRY_BUSY 0x4
#Defina PROCESS_HEAP_ENTRY_MOVEABLE 0x10
#Defina PROCESS_HEAP_ENTRY_DDESHARE 0x20

  WINBASEAPI WINBOOL WINAPI HeapLock(HANDLE hHeap);
  WINBASEAPI WINBOOL WINAPI HeapUnlock(HANDLE hHeap);
  WINBASEAPI WINBOOL WINAPI HeapWalk(HANDLE hHeap,LPPROCESS_HEAP_ENTRY lpEntry);
  WINBASEAPI WINBOOL WINAPI HeapSetInformation(HANDLE HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,SIZE_T HeapInformationLength);
  WINBASEAPI WINBOOL WINAPI HeapQueryInformation(HANDLE HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,SIZE_T HeapInformationLength,PSIZE_T ReturnLength);

#Defina SCS_32BIT_BINARY 0
#Defina SCS_DOS_BINARY 1
#Defina SCS_WOW_BINARY 2
#Defina SCS_PIF_BINARY 3
#Defina SCS_POSIX_BINARY 4
#Defina SCS_OS216_BINARY 5
#Defina SCS_64BIT_BINARY 6

#SeDefinido UNICODE
#Defina GetBinaryType GetBinaryTypeW
#Defina GetShortPathName GetShortPathNameW
#Defina GetLongPathName GetLongPathNameW
#Defina GetEnvironmentStrings GetEnvironmentStringsW
#Defina SetEnvironmentStrings SetEnvironmentStringsW
#Defina FreeEnvironmentStrings FreeEnvironmentStringsW
#Senão
#Defina GetBinaryType GetBinaryTypeA
#Defina GetShortPathName GetShortPathNameA
#Defina GetLongPathName GetLongPathNameA
#Defina GetEnvironmentStringsA GetEnvironmentStrings
#Defina SetEnvironmentStrings SetEnvironmentStringsA
#Defina FreeEnvironmentStrings FreeEnvironmentStringsA
#FimSe

#SeDefinido _WIN64
#Defina SCS_THIS_PLATFORM_BINARY SCS_64BIT_BINARY
#Senão
#Defina SCS_THIS_PLATFORM_BINARY SCS_32BIT_BINARY
#FimSe

  WINBASEAPI WINBOOL WINAPI GetBinaryTypeA(LPCSTR lpApplicationName,LPDWORD lpBinaryType);
  WINBASEAPI WINBOOL WINAPI GetBinaryTypeW(LPCWSTR lpApplicationName,LPDWORD lpBinaryType);
  WINBASEAPI DWORD WINAPI GetShortPathNameA(LPCSTR lpszLongPath,LPSTR lpszShortPath,DWORD cchBuffer);
  WINBASEAPI DWORD WINAPI GetShortPathNameW(LPCWSTR lpszLongPath,LPWSTR lpszShortPath,DWORD cchBuffer);
  WINBASEAPI DWORD WINAPI GetLongPathNameA(LPCSTR lpszShortPath,LPSTR lpszLongPath,DWORD cchBuffer);
  WINBASEAPI DWORD WINAPI GetLongPathNameW(LPCWSTR lpszShortPath,LPWSTR lpszLongPath,DWORD cchBuffer);
  WINBASEAPI WINBOOL WINAPI GetProcessAffinityMask(HANDLE hProcess,PDWORD_PTR lpProcessAffinityMask,PDWORD_PTR lpSystemAffinityMask);
  WINBASEAPI WINBOOL WINAPI SetProcessAffinityMask(HANDLE hProcess,DWORD_PTR dwProcessAffinityMask);
  WINBASEAPI WINBOOL WINAPI GetProcessHandleCount(HANDLE hProcess,PDWORD pdwHandleCount);
  WINBASEAPI WINBOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lpCreationTime,LPFILETIME lpExitTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI GetProcessWorkingSetSize(HANDLE hProcess,PSIZE_T lpMinimumWorkingSetSize,PSIZE_T lpMaximumWorkingSetSize);
  WINBASEAPI WINBOOL WINAPI GetProcessWorkingSetSizeEx(HANDLE hProcess,PSIZE_T lpMinimumWorkingSetSize,PSIZE_T lpMaximumWorkingSetSize,PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI SetProcessWorkingSetSize(HANDLE hProcess,SIZE_T dwMinimumWorkingSetSize,SIZE_T dwMaximumWorkingSetSize);
  WINBASEAPI WINBOOL WINAPI SetProcessWorkingSetSizeEx(HANDLE hProcess,SIZE_T dwMinimumWorkingSetSize,SIZE_T dwMaximumWorkingSetSize,DWORD Flags);
  WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwProcessId);
  WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT uExitCode);
  WINBASEAPI WINBOOL WINAPI TerminateProcess(HANDLE hProcess,UINT uExitCode);
  WINBASEAPI WINBOOL WINAPI GetExitCodeProcess(HANDLE hProcess,LPDWORD lpExitCode);
  WINBASEAPI VOID WINAPI FatalExit(Inteiro ExitCode);
  /*	WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID); */
  WINBASEAPI LPWCH WINAPI GetEnvironmentStringsW(VOID);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentStringsA(LPCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentStringsW(LPWCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI FreeEnvironmentStringsA(LPCH);
  WINBASEAPI WINBOOL WINAPI FreeEnvironmentStringsW(LPWCH);
  WINBASEAPI VOID WINAPI RaiseException(DWORD dwExceptionCode,DWORD dwExceptionFlags,DWORD nNumberOfArguments,CONST ULONG_PTR *lpArguments);
  WINBASEAPI LONG WINAPI UnhandledExceptionFilter(Estrutura _EXCEPTION_POINTERS *ExceptionInfo);

  Pseudônimo LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(Estrutura _EXCEPTION_POINTERS *ExceptionInfo);
  Pseudônimo PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

  WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);

#Defina FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(SIZE_T dwStackSize,LPFIBER_START_ROUTINE lpStartAddress,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(SIZE_T dwStackCommitSize,SIZE_T dwStackReserveSize,DWORD dwFlags,LPFIBER_START_ROUTINE lpStartAddress,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI ConvertThreadToFiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI ConvertThreadToFiberEx(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI ConvertFiberToThread(VOID);
  WINBASEAPI VOID WINAPI SwitchToFiber(LPVOID lpFiber);
  WINBASEAPI WINBOOL WINAPI SwitchToThread(VOID);
  WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,SIZE_T dwStackSize,LPTHREAD_START_ROUTINE lpStartAddress,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_ATTRIBUTES lpThreadAttributes,SIZE_T dwStackSize,LPTHREAD_START_ROUTINE lpStartAddress,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
  WINBASEAPI WINBOOL WINAPI SetThreadStackGuarantee (PULONG StackSizeInBytes);
  WINBASEAPI DWORD WINAPI GetProcessIdOfThread(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
  WINBASEAPI DWORD WINAPI GetCurrentProcessorNumber(VOID);
  WINBASEAPI DWORD_PTR WINAPI SetThreadAffinityMask(HANDLE hThread,DWORD_PTR dwThreadAffinityMask);
  WINBASEAPI DWORD WINAPI SetThreadIdealProcessor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI SetProcessPriorityBoost(HANDLE hProcess,WINBOOL bDisablePriorityBoost);
  WINBASEAPI WINBOOL WINAPI GetProcessPriorityBoost(HANDLE hProcess,PBOOL pDisablePriorityBoost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_TIME latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwThreadId);
  WINBASEAPI WINBOOL WINAPI SetThreadPriority(HANDLE hThread,Inteiro nPriority);
  WINBASEAPI WINBOOL WINAPI SetThreadPriorityBoost(HANDLE hThread,WINBOOL bDisablePriorityBoost);
  WINBASEAPI WINBOOL WINAPI GetThreadPriorityBoost(HANDLE hThread,PBOOL pDisablePriorityBoost);
  WINBASEAPI Inteiro WINAPI GetThreadPriority(HANDLE hThread);
  WINBASEAPI WINBOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lpCreationTime,LPFILETIME lpExitTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dwExitCode);
  WINBASEAPI WINBOOL WINAPI TerminateThread(HANDLE hThread,DWORD dwExitCode);
  WINBASEAPI WINBOOL WINAPI GetExitCodeThread(HANDLE hThread,LPDWORD lpExitCode);
  WINBASEAPI WINBOOL WINAPI GetThreadSelectorEntry(HANDLE hThread,DWORD dwSelector,LPLDT_ENTRY lpSelectorEntry);
  WINBASEAPI EXECUTION_STATE WINAPI SetThreadExecutionState(EXECUTION_STATE esFlags);
  WINBASEAPI DWORD WINAPI GetLastError(VOID);
  WINBASEAPI VOID WINAPI SetLastError(DWORD dwErrCode);

#SeNãoDefinido RC_INVOKED
#SeDefinido WINBASE_DECLARE_RESTORE_LAST_ERROR
  WINBASEAPI VOID WINAPI RestoreLastError(DWORD dwErrCode);

  Pseudônimo VOID (WINAPI *PRESTORE_LAST_ERROR)(DWORD);

#Defina RESTORE_LAST_ERROR_NAME_A "RestoreLastError"
#Defina RESTORE_LAST_ERROR_NAME_W L"RestoreLastError"
#Defina RESTORE_LAST_ERROR_NAME TEXT("RestoreLastError")
#FimSe
#FimSe

#Defina HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->Internal)!=STATUS_PENDING)

  WINBASEAPI WINBOOL WINAPI GetOverlappedResult(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lpNumberOfBytesTransferred,WINBOOL bWait);
  WINBASEAPI HANDLE WINAPI CreateIoCompletionPort(HANDLE FileHandle,HANDLE ExistingCompletionPort,ULONG_PTR CompletionKey,DWORD NumberOfConcurrentThreads);
  WINBASEAPI WINBOOL WINAPI GetQueuedCompletionStatus(HANDLE CompletionPort,LPDWORD lpNumberOfBytesTransferred,PULONG_PTR lpCompletionKey,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI PostQueuedCompletionStatus(HANDLE CompletionPort,DWORD dwNumberOfBytesTransferred,ULONG_PTR dwCompletionKey,LPOVERLAPPED lpOverlapped);

#Defina SEM_FAILCRITICALERRORS 0x1
#Defina SEM_NOGPFAULTERRORBOX 0x2
#Defina SEM_NOALIGNMENTFAULTEXCEPT 0x4
#Defina SEM_NOOPENFILEERRORBOX 0x8000

  WINBASEAPI UINT WINAPI SetErrorMode(UINT uMode);
  WINBASEAPI WINBOOL WINAPI ReadProcessMemory(HANDLE hProcess,LPCVOID lpBaseAddress,LPVOID lpBuffer,SIZE_T nSize,SIZE_T *lpNumberOfBytesRead);
  WINBASEAPI WINBOOL WINAPI WriteProcessMemory(HANDLE hProcess,LPVOID lpBaseAddress,LPCVOID lpBuffer,SIZE_T nSize,SIZE_T *lpNumberOfBytesWritten);
  WINBASEAPI WINBOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI SetThreadContext(HANDLE hThread,CONST CONTEXT *lpContext);
  WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
  WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);

  Pseudônimo VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI DWORD WINAPI QueueUserAPC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dwData);
  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI WINBOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
  WINBASEAPI VOID WINAPI DebugBreak(VOID);
  WINBASEAPI WINBOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dwContinueStatus);
  WINBASEAPI WINBOOL WINAPI DebugActiveProcess(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI DebugActiveProcessStop(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI DebugSetProcessKillOnExit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount);
  WINBASEAPI DWORD WINAPI SetCriticalSectionSpinCount(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount);
  WINBASEAPI WINBOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI SetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ResetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG lReleaseCount,LPLONG lpPreviousCount);
  WINBASEAPI WINBOOL WINAPI ReleaseMutex(HANDLE hMutex);
  WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
  WINBASEAPI DWORD WINAPI WaitForMultipleObjects(DWORD nCount,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
  WINBASEAPI HGLOBAL WINAPI LoadResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI InitAtomTable(DWORD nSize);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI SetHandleCount(UINT uNumber);
  WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI LockFile(HANDLE hFile,DWORD dwFileOffsetLow,DWORD dwFileOffsetHigh,DWORD nNumberOfBytesToLockLow,DWORD nNumberOfBytesToLockHigh);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile,DWORD dwFileOffsetLow,DWORD dwFileOffsetHigh,DWORD nNumberOfBytesToUnlockLow,DWORD nNumberOfBytesToUnlockHigh);
  WINBASEAPI WINBOOL WINAPI LockFileEx(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD nNumberOfBytesToLockLow,DWORD nNumberOfBytesToLockHigh,LPOVERLAPPED lpOverlapped);

#Defina LOCKFILE_FAIL_IMMEDIATELY 0x1
#Defina LOCKFILE_EXCLUSIVE_LOCK 0x2

  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD nNumberOfBytesToUnlockLow,DWORD nNumberOfBytesToUnlockHigh,LPOVERLAPPED lpOverlapped);

  Pseudônimo Estrutura _BY_HANDLE_FILE_INFORMATION {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD dwVolumeSerialNumber;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD nNumberOfLinks;
    DWORD nFileIndexHigh;
    DWORD nFileIndexLow;
  } BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;

#SeDefinido UNICODE
#Defina SetFileShortName SetFileShortNameW
#Senão
#Defina SetFileShortName SetFileShortNameA
#FimSe

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD WINAPI GetFileSize(HANDLE hFile,LPDWORD lpFileSizeHigh);
  WINBASEAPI WINBOOL WINAPI GetFileSizeEx(HANDLE hFile,PLARGE_INTEGER lpFileSize);
  WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI SetStdHandle(DWORD nStdHandle,HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lpBuffer,DWORD nNumberOfBytesToWrite,LPDWORD lpNumberOfBytesWritten,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dwIoControlCode,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesReturned,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI SetMessageWaitingIndicator(HANDLE hMsgIndicator,ULONG ulMsgCount);
  WINBASEAPI WINBOOL WINAPI SetEndOfFile(HANDLE hFile);
  WINBASEAPI DWORD WINAPI SetFilePointer(HANDLE hFile,LONG lDistanceToMove,PLONG lpDistanceToMoveHigh,DWORD dwMoveMethod);
  WINBASEAPI WINBOOL WINAPI SetFilePointerEx(HANDLE hFile,LARGE_INTEGER liDistanceToMove,PLARGE_INTEGER lpNewFilePointer,DWORD dwMoveMethod);
  WINBASEAPI WINBOOL WINAPI FindClose(HANDLE hFindFile);
  WINBASEAPI WINBOOL WINAPI GetFileTime(HANDLE hFile,LPFILETIME lpCreationTime,LPFILETIME lpLastAccessTime,LPFILETIME lpLastWriteTime);
  WINBASEAPI WINBOOL WINAPI SetFileTime(HANDLE hFile,CONST FILETIME *lpCreationTime,CONST FILETIME *lpLastAccessTime,CONST FILETIME *lpLastWriteTime);
  WINBASEAPI WINBOOL WINAPI SetFileValidData(HANDLE hFile,LONGLONG ValidDataLength);
  WINBASEAPI WINBOOL WINAPI SetFileShortNameA(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI SetFileShortNameW(HANDLE hFile,LPCWSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);
  WINBASEAPI WINBOOL WINAPI DuplicateHandle(HANDLE hSourceProcessHandle,HANDLE hSourceHandle,HANDLE hTargetProcessHandle,LPHANDLE lpTargetHandle,DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwOptions);
  WINBASEAPI WINBOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
  WINBASEAPI WINBOOL WINAPI SetHandleInformation(HANDLE hObject,DWORD dwMask,DWORD dwFlags);

#Defina HANDLE_FLAG_INHERIT 0x1
#Defina HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#Defina HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI LoadModule(LPCSTR lpModuleName,LPVOID lpParameterBlock);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lpCmdLine,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI SetupComm(HANDLE hFile,DWORD dwInQueue,DWORD dwOutQueue);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
  WINBASEAPI WINBOOL WINAPI GetCommMask(HANDLE hFile,LPDWORD lpEvtMask);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI GetCommModemStatus(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI SetCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI SetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dwSize);
  WINBASEAPI WINBOOL WINAPI SetCommMask(HANDLE hFile,DWORD dwEvtMask);
  WINBASEAPI WINBOOL WINAPI SetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI SetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,Caractere cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lpEvtMask,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI SetTapePosition(HANDLE hDevice,DWORD dwPositionMethod,DWORD dwPartition,DWORD dwOffsetLow,DWORD dwOffsetHigh,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI GetTapePosition(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdwPartition,LPDWORD lpdwOffsetLow,LPDWORD lpdwOffsetHigh);
  WINBASEAPI DWORD WINAPI PrepareTape(HANDLE hDevice,DWORD dwOperation,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI EraseTape(HANDLE hDevice,DWORD dwEraseType,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI CreateTapePartition(HANDLE hDevice,DWORD dwPartitionMethod,DWORD dwCount,DWORD dwSize);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dwTapemarkCount,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI GetTapeStatus(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI GetTapeParameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdwSize,LPVOID lpTapeInformation);

#Defina GET_TAPE_MEDIA_INFORMATION 0
#Defina GET_TAPE_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI SetTapeParameters(HANDLE hDevice,DWORD dwOperation,LPVOID lpTapeInformation);

#Defina SET_TAPE_MEDIA_INFORMATION 0
#Defina SET_TAPE_DRIVE_INFORMATION 1

  WINBASEAPI WINBOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
  WINBASEAPI Inteiro WINAPI MulDiv(Inteiro nNumber,Inteiro nNumerator,Inteiro nDenominator);
  WINBASEAPI VOID WINAPI GetSystemTime(LPSYSTEMTIME lpSystemTime);
  WINBASEAPI VOID WINAPI GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime);
  WINBASEAPI WINBOOL WINAPI SetSystemTime(CONST SYSTEMTIME *lpSystemTime);
  WINBASEAPI VOID WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime);
  WINBASEAPI WINBOOL WINAPI SetLocalTime(CONST SYSTEMTIME *lpSystemTime);
  WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI SetSystemFileCacheSize(SIZE_T MinimumFileCacheSize,SIZE_T MaximumFileCacheSize,DWORD Flags);
  WINBASEAPI WINBOOL WINAPI GetSystemFileCacheSize(PSIZE_T lpMinimumFileCacheSize,PSIZE_T lpMaximumFileCacheSize,PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdwQuotaUsed);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lpIdleTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

  Pseudônimo Estrutura _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } TIME_ZONE_INFORMATION,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#SeDefinido UNICODE
#Defina FormatMessage FormatMessageW
#Senão
#Defina FormatMessage FormatMessageA
#FimSe

  WINBASEAPI WINBOOL WINAPI SystemTimeToTzSpecificLocalTime(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpUniversalTime,LPSYSTEMTIME lpLocalTime);
  WINBASEAPI WINBOOL WINAPI TzSpecificLocalTimeToSystemTime(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpLocalTime,LPSYSTEMTIME lpUniversalTime);
  WINBASEAPI DWORD WINAPI GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation);
  WINBASEAPI WINBOOL WINAPI SetTimeZoneInformation(CONST TIME_ZONE_INFORMATION *lpTimeZoneInformation);
  WINBASEAPI WINBOOL WINAPI SystemTimeToFileTime(CONST SYSTEMTIME *lpSystemTime,LPFILETIME lpFileTime);
  WINBASEAPI WINBOOL WINAPI FileTimeToLocalFileTime(CONST FILETIME *lpFileTime,LPFILETIME lpLocalFileTime);
  WINBASEAPI WINBOOL WINAPI LocalFileTimeToFileTime(CONST FILETIME *lpLocalFileTime,LPFILETIME lpFileTime);
  WINBASEAPI WINBOOL WINAPI FileTimeToSystemTime(CONST FILETIME *lpFileTime,LPSYSTEMTIME lpSystemTime);
  WINBASEAPI LONG WINAPI CompareFileTime(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI FileTimeToDosDateTime(CONST FILETIME *lpFileTime,LPWORD lpFatDate,LPWORD lpFatTime);
  WINBASEAPI WINBOOL WINAPI DosDateTimeToFileTime(WORD wFatDate,WORD wFatTime,LPFILETIME lpFileTime);
  WINBASEAPI DWORD WINAPI GetTickCount(VOID);
  WINBASEAPI WINBOOL WINAPI SetSystemTimeAdjustment(DWORD dwTimeAdjustment,WINBOOL bTimeAdjustmentDisabled);
  WINBASEAPI WINBOOL WINAPI GetSystemTimeAdjustment(PDWORD lpTimeAdjustment,PDWORD lpTimeIncrement,PBOOL lpTimeAdjustmentDisabled);
  WINBASEAPI DWORD WINAPI FormatMessageA(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPSTR lpBuffer,DWORD nSize,va_list *Arguments);
  WINBASEAPI DWORD WINAPI FormatMessageW(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPWSTR lpBuffer,DWORD nSize,va_list *Arguments);

#Defina FORMAT_MESSAGE_ALLOCATE_BUFFER 0x100
#Defina FORMAT_MESSAGE_IGNORE_INSERTS 0x200
#Defina FORMAT_MESSAGE_FROM_STRING 0x400
#Defina FORMAT_MESSAGE_FROM_HMODULE 0x800
#Defina FORMAT_MESSAGE_FROM_SYSTEM 0x1000
#Defina FORMAT_MESSAGE_ARGUMENT_ARRAY 0x2000
#Defina FORMAT_MESSAGE_MAX_WIDTH_MASK 0xff

#SeDefinido UNICODE
#Defina CreateMailslot CreateMailslotW
#Defina EncryptFile EncryptFileW
#Defina DecryptFile DecryptFileW
#Defina FileEncryptionStatus FileEncryptionStatusW
#Senão
#Defina CreateMailslot CreateMailslotA
#Defina EncryptFile EncryptFileA
#Defina DecryptFile DecryptFileA
#Defina FileEncryptionStatus FileEncryptionStatusA
#FimSe

  WINBASEAPI WINBOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_ATTRIBUTES lpPipeAttributes,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
  WINBASEAPI WINBOOL WINAPI SetNamedPipeHandleState(HANDLE hNamedPipe,LPDWORD lpMode,LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lpOutBufferSize,LPDWORD lpInBufferSize,LPDWORD lpMaxInstances);
  WINBASEAPI WINBOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lpBuffer,DWORD nBufferSize,LPDWORD lpBytesRead,LPDWORD lpTotalBytesAvail,LPDWORD lpBytesLeftThisMessage);
  WINBASEAPI WINBOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesRead,LPOVERLAPPED lpOverlapped);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD nMaxMessageSize,DWORD lReadTimeout,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD nMaxMessageSize,DWORD lReadTimeout,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lpMaxMessageSize,LPDWORD lpNextSize,LPDWORD lpMessageCount,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI SetMailslotInfo(HANDLE hMailslot,DWORD lReadTimeout);
  WINBASEAPI LPVOID WINAPI MapViewOfFile(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dwFileOffsetHigh,DWORD dwFileOffsetLow,SIZE_T dwNumberOfBytesToMap);
  WINBASEAPI WINBOOL WINAPI FlushViewOfFile(LPCVOID lpBaseAddress,SIZE_T dwNumberOfBytesToFlush);
  WINBASEAPI WINBOOL WINAPI UnmapViewOfFile(LPCVOID lpBaseAddress);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#Defina FILE_ENCRYPTABLE 0
#Defina FILE_IS_ENCRYPTED 1
#Defina FILE_SYSTEM_ATTR 2
#Defina FILE_ROOT_DIR 3
#Defina FILE_SYSTEM_DIR 4
#Defina FILE_UNKNOWN 5
#Defina FILE_SYSTEM_NOT_SUPPORT 6
#Defina FILE_USER_DISALLOWED 7
#Defina FILE_READ_ONLY 8
#Defina FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI FileEncryptionStatusA(LPCSTR lpFileName,LPDWORD lpStatus);
  WINADVAPI WINBOOL WINAPI FileEncryptionStatusW(LPCWSTR lpFileName,LPDWORD lpStatus);

#Defina EFS_USE_RECOVERY_KEYS (0x1)

  Pseudônimo DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pbData,PVOID pvCallbackContext,ULONG ulLength);
  Pseudônimo DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pbData,PVOID pvCallbackContext,PULONG ulLength);

#Defina CREATE_FOR_IMPORT (1)
#Defina CREATE_FOR_DIR (2)
#Defina OVERWRITE_HIDDEN (4)

#SeDefinido UNICODE
#Defina OpenEncryptedFileRaw OpenEncryptedFileRawW
#Defina lstrcmp lstrcmpW
#Defina lstrcmpi lstrcmpiW
#Defina lstrcpyn lstrcpynW
#Defina lstrcpy lstrcpyW
#Defina lstrcat lstrcatW
#Defina lstrlen lstrlenW
#Senão
#Defina OpenEncryptedFileRaw OpenEncryptedFileRawA
#Defina lstrcmp lstrcmpA
#Defina lstrcmpi lstrcmpiA
#Defina lstrcpyn lstrcpynA
#Defina lstrcpy lstrcpyA
#Defina lstrcat lstrcatA
#Defina lstrlen lstrlenA
#FimSe

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI Inteiro WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI Inteiro WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI Inteiro WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI Inteiro WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,Inteiro iMaxLength);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,Inteiro iMaxLength);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI Inteiro WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI Inteiro WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lpPathName,Inteiro iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lpPathName,Inteiro iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lpBuffer,UINT uBytes);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lpBuffer,UINT uBytes);
  WINBASEAPI Longo WINAPI _hread(HFILE hFile,LPVOID lpBuffer,Longo lBytes);
  WINBASEAPI Longo WINAPI _hwrite(HFILE hFile,LPCCH lpBuffer,Longo lBytes);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG lOffset,Inteiro iOrigin);
  WINADVAPI WINBOOL WINAPI IsTextUnicode(CONST VOID *lpv,Inteiro iSize,LPINT lpiResult);

#Defina FLS_OUT_OF_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID WINAPI FlsGetValue(DWORD dwFlsIndex);
  WINBASEAPI WINBOOL WINAPI FlsSetValue(DWORD dwFlsIndex,PVOID lpFlsData);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dwFlsIndex);

#Defina TLS_OUT_OF_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
  WINBASEAPI LPVOID WINAPI TlsGetValue(DWORD dwTlsIndex);
  WINBASEAPI WINBOOL WINAPI TlsSetValue(DWORD dwTlsIndex,LPVOID lpTlsValue);
  WINBASEAPI WINBOOL WINAPI TlsFree(DWORD dwTlsIndex);

  Pseudônimo VOID (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwErrorCode,DWORD dwNumberOfBytesTransfered,LPOVERLAPPED lpOverlapped);

  WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForMultipleObjectsEx(DWORD nCount,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE hObjectToSignal,HANDLE hObjectToWaitOn,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lpBuffer,DWORD nNumberOfBytesToWrite,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dwLowBytesToSeek,DWORD dwHighBytesToSeek,LPDWORD lpdwLowByteSeeked,LPDWORD lpdwHighByteSeeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lpBuffer,DWORD nNumberOfBytesToWrite,LPDWORD lpNumberOfBytesWritten,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  Pseudônimo Estrutura _WIN32_STREAM_ID {
    DWORD dwStreamId;
    DWORD dwStreamAttributes;
    LARGE_INTEGER Size;
    DWORD dwStreamNameSize;
    WCHAR cStreamName[ANYSIZE_ARRAY];
  } WIN32_STREAM_ID,*LPWIN32_STREAM_ID;

#Defina BACKUP_INVALID 0x0
#Defina BACKUP_DATA 0x1
#Defina BACKUP_EA_DATA 0x2
#Defina BACKUP_SECURITY_DATA 0x3
#Defina BACKUP_ALTERNATE_DATA 0x4
#Defina BACKUP_LINK 0x5
#Defina BACKUP_PROPERTY_DATA 0x6
#Defina BACKUP_OBJECT_ID 0x7
#Defina BACKUP_REPARSE_DATA 0x8
#Defina BACKUP_SPARSE_BLOCK 0x9

#Defina STREAM_NORMAL_ATTRIBUTE 0x0
#Defina STREAM_MODIFIED_WHEN_READ 0x1
#Defina STREAM_CONTAINS_SECURITY 0x2
#Defina STREAM_CONTAINS_PROPERTIES 0x4
#Defina STREAM_SPARSE_ATTRIBUTE 0x8

  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD nNumberOfBytesToRead,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD nNumberOfBytesToWrite,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);

#Defina STARTF_USESHOWWINDOW 0x1
#Defina STARTF_USESIZE 0x2
#Defina STARTF_USEPOSITION 0x4
#Defina STARTF_USECOUNTCHARS 0x8
#Defina STARTF_USEFILLATTRIBUTE 0x10
#Defina STARTF_RUNFULLSCREEN 0x20
#Defina STARTF_FORCEONFEEDBACK 0x40
#Defina STARTF_FORCEOFFFEEDBACK 0x80
#Defina STARTF_USESTDHANDLES 0x100

#Defina STARTF_USEHOTKEY 0x200

  Pseudônimo Estrutura _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOA,*LPSTARTUPINFOA;

  Pseudônimo Estrutura _STARTUPINFOW {
    DWORD cb;
    LPWSTR lpReserved;
    LPWSTR lpDesktop;
    LPWSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOW,*LPSTARTUPINFOW;

#SeDefinido UNICODE
  Pseudônimo STARTUPINFOW STARTUPINFO;
  Pseudônimo LPSTARTUPINFOW LPSTARTUPINFO;
#Senão
  Pseudônimo STARTUPINFOA STARTUPINFO;
  Pseudônimo LPSTARTUPINFOA LPSTARTUPINFO;
#FimSe

#Defina SHUTDOWN_NORETRY 0x1

  Pseudônimo Estrutura _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_PATH];
    CHAR cAlternateFileName[14];
  } WIN32_FIND_DATAA,*PWIN32_FIND_DATAA,*LPWIN32_FIND_DATAA;

  Pseudônimo Estrutura _WIN32_FIND_DATAW {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_PATH];
    WCHAR cAlternateFileName[14];
  } WIN32_FIND_DATAW,*PWIN32_FIND_DATAW,*LPWIN32_FIND_DATAW;

#SeDefinido UNICODE
  Pseudônimo WIN32_FIND_DATAW WIN32_FIND_DATA;
  Pseudônimo PWIN32_FIND_DATAW PWIN32_FIND_DATA;
  Pseudônimo LPWIN32_FIND_DATAW LPWIN32_FIND_DATA;
#Senão
  Pseudônimo WIN32_FIND_DATAA WIN32_FIND_DATA;
  Pseudônimo PWIN32_FIND_DATAA PWIN32_FIND_DATA;
  Pseudônimo LPWIN32_FIND_DATAA LPWIN32_FIND_DATA;
#FimSe

  Pseudônimo Estrutura _WIN32_FILE_ATTRIBUTE_DATA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
  } WIN32_FILE_ATTRIBUTE_DATA,*LPWIN32_FILE_ATTRIBUTE_DATA;

#SeDefinido UNICODE
#Defina CreateMutex CreateMutexW
#Defina OpenMutex OpenMutexW
#Defina CreateEvent CreateEventW
#Defina OpenEvent OpenEventW
#Defina CreateSemaphore CreateSemaphoreW
#Defina OpenSemaphore OpenSemaphoreW
#Senão
#Defina CreateMutex CreateMutexA
#Defina OpenMutex OpenMutexA
#Defina CreateEvent CreateEventA
#Defina OpenEvent OpenEventA
#Defina CreateSemaphore CreateSemaphoreA
#Defina OpenSemaphore OpenSemaphoreA
#FimSe

  WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes,WINBOOL bInitialOwner,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes,WINBOOL bInitialOwner,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes,WINBOOL bManualReset,WINBOOL bInitialState,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes,WINBOOL bManualReset,WINBOOL bInitialState,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,LONG lInitialCount,LONG lMaximumCount,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,LONG lInitialCount,LONG lMaximumCount,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);

  Pseudônimo VOID (WINAPI *PTIMERAPCROUTINE)(LPVOID lpArgToCompletionRoutine,DWORD dwTimerLowValue,DWORD dwTimerHighValue);

#SeDefinido UNICODE
#Defina CreateWaitableTimer CreateWaitableTimerW
#Defina OpenWaitableTimer OpenWaitableTimerW
#Defina CreateFileMapping CreateFileMappingW
#Defina OpenFileMapping OpenFileMappingW
#Defina GetLogicalDriveStrings GetLogicalDriveStringsW
#Defina LoadLibrary LoadLibraryW
#Defina LoadLibraryEx LoadLibraryExW
#Defina GetModuleFileName GetModuleFileNameW
#Defina GetModuleHandle GetModuleHandleW
#Senão
#Defina CreateWaitableTimer CreateWaitableTimerA
#Defina OpenWaitableTimer OpenWaitableTimerA
#Defina CreateFileMapping CreateFileMappingA
#Defina OpenFileMapping OpenFileMappingA
#Defina GetLogicalDriveStrings GetLogicalDriveStringsA
#Defina LoadLibrary LoadLibraryA
#Defina LoadLibraryEx LoadLibraryExA
#Defina GetModuleFileName GetModuleFileNameA
#Defina GetModuleHandle GetModuleHandleA
#FimSe

  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_ATTRIBUTES lpTimerAttributes,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_ATTRIBUTES lpTimerAttributes,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpTimerName);
  WINBASEAPI WINBOOL WINAPI SetWaitableTimer(HANDLE hTimer,Imutável LARGE_INTEGER *lpDueTime,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lpArgToCompletionRoutine,WINBOOL fResume);
  WINBASEAPI WINBOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_ATTRIBUTES lpFileMappingAttributes,DWORD flProtect,DWORD dwMaximumSizeHigh,DWORD dwMaximumSizeLow,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_ATTRIBUTES lpFileMappingAttributes,DWORD flProtect,DWORD dwMaximumSizeHigh,DWORD dwMaximumSizeLow,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI DWORD WINAPI GetLogicalDriveStringsA(DWORD nBufferLength,LPSTR lpBuffer);
  WINBASEAPI DWORD WINAPI GetLogicalDriveStringsW(DWORD nBufferLength,LPWSTR lpBuffer);

  Pseudônimo Enumeração _MEMORY_RESOURCE_NOTIFICATION_TYPE {
    LowMemoryResourceNotification,HighMemoryResourceNotification
  } MEMORY_RESOURCE_NOTIFICATION_TYPE;

  WINBASEAPI HANDLE WINAPI CreateMemoryResourceNotification(MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType);
  WINBASEAPI WINBOOL WINAPI QueryMemoryResourceNotification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
  WINBASEAPI HMODULE WINAPI LoadLibraryA(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI LoadLibraryW(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI LoadLibraryExA(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI LoadLibraryExW(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#Defina DONT_RESOLVE_DLL_REFERENCES 0x1
#Defina LOAD_LIBRARY_AS_DATAFILE 0x2
#Defina LOAD_WITH_ALTERED_SEARCH_PATH 0x8
#Defina LOAD_IGNORE_CODE_AUTHZ_LEVEL 0x10
#Defina LOAD_LINRARY_AS_IMAGE_RESOURCE 0x20
#Defina LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE 0x40

  WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD nSize);
  WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
  WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

#SeNãoDefinido RC_INVOKED
#Defina GET_MODULE_HANDLE_EX_FLAG_PIN (0x1)
#Defina GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x2)
#Defina GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS (0x4)

  Pseudônimo WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  Pseudônimo WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);

#SeDefinido UNICODE
#Defina PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#Defina GetModuleHandleEx GetModuleHandleExW
#Senão
#Defina PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#Defina GetModuleHandleEx GetModuleHandleExA
#FimSe

  WINBASEAPI WINBOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  WINBASEAPI WINBOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);
#FimSe

#SeDefinido UNICODE
#Defina NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathW
#Defina CreateProcess CreateProcessW
#Defina FatalAppExit FatalAppExitW
#Defina GetStartupInfo GetStartupInfoW
#Defina GetCommandLine GetCommandLineW
#Defina GetEnvironmentVariable GetEnvironmentVariableW
#Defina SetEnvironmentVariable SetEnvironmentVariableW
#Defina ExpandEnvironmentStrings ExpandEnvironmentStringsW
#Defina GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#Defina SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableW
#Defina OutputDebugString OutputDebugStringW
#Defina FindResource FindResourceW
#Defina FindResourceEx FindResourceExW
#Senão
#Defina NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathA
#Defina CreateProcess CreateProcessA
#Defina FatalAppExit FatalAppExitA
#Defina GetStartupInfo GetStartupInfoA
#Defina GetCommandLine GetCommandLineA
#Defina GetEnvironmentVariable GetEnvironmentVariableA
#Defina SetEnvironmentVariable SetEnvironmentVariableA
#Defina ExpandEnvironmentStrings ExpandEnvironmentStringsA
#Defina GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#Defina SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableA
#Defina OutputDebugString OutputDebugStringA
#Defina FindResource FindResourceA
#Defina FindResourceEx FindResourceExA
#FimSe

  WINBASEAPI WINBOOL WINAPI NeedCurrentDirectoryForExePathA(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI NeedCurrentDirectoryForExePathW(LPCWSTR ExeName);
  WINBASEAPI WINBOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI WINBOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI DWORD WINAPI AddLocalAlternateComputerNameA(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI AddLocalAlternateComputerNameW(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI SetProcessShutdownParameters(DWORD dwLevel,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI DWORD WINAPI GetProcessVersion(DWORD ProcessId);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lpMessageText);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lpMessageText);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
  WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
  WINBASEAPI LPSTR WINAPI GetCommandLineA(VOID);
  WINBASEAPI LPWSTR WINAPI GetCommandLineW(VOID);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lpBuffer,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lpBuffer,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentVariableA(LPCSTR lpName,LPCSTR lpValue);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpValue);
  WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsA(LPCSTR lpSrc,LPSTR lpDst,DWORD nSize);
  WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsW(LPCWSTR lpSrc,LPWSTR lpDst,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID pBuffer,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID pBuffer,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID pValue,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID pValue,DWORD nSize);
  WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
  WINBASEAPI HRSRC WINAPI FindResourceA(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI FindResourceW(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI FindResourceExA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,WORD wLanguage);
  WINBASEAPI HRSRC WINAPI FindResourceExW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage);

#SeDefinido UNICODE
#Defina ENUMRESTYPEPROC ENUMRESTYPEPROCW
#Defina ENUMRESNAMEPROC ENUMRESNAMEPROCW
#Defina ENUMRESLANGPROC ENUMRESLANGPROCW
#Defina EnumResourceTypes EnumResourceTypesW
#Defina EnumResourceNames EnumResourceNamesW
#Defina EnumResourceLanguages EnumResourceLanguagesW
#Defina BeginUpdateResource BeginUpdateResourceW
#Defina UpdateResource UpdateResourceW
#Defina EndUpdateResource EndUpdateResourceW
#Defina GlobalAddAtom GlobalAddAtomW
#Defina GlobalFindAtom GlobalFindAtomW
#Defina GlobalGetAtomName GlobalGetAtomNameW
#Defina AddAtom AddAtomW
#Defina FindAtom FindAtomW
#Defina GetAtomName GetAtomNameW
#Defina GetProfileInt GetProfileIntW
#Defina GetProfileString GetProfileStringW
#Defina WriteProfileString WriteProfileStringW
#Defina GetProfileSection GetProfileSectionW
#Defina WriteProfileSection WriteProfileSectionW
#Defina GetPrivateProfileInt GetPrivateProfileIntW
#Defina GetPrivateProfileString GetPrivateProfileStringW
#Defina WritePrivateProfileString WritePrivateProfileStringW
#Defina GetPrivateProfileSection GetPrivateProfileSectionW
#Defina WritePrivateProfileSection WritePrivateProfileSectionW
#Defina GetPrivateProfileSectionNames GetPrivateProfileSectionNamesW
#Defina GetPrivateProfileStruct GetPrivateProfileStructW
#Defina WritePrivateProfileStruct WritePrivateProfileStructW
#Defina GetDriveType GetDriveTypeW
#Defina GetSystemDirectory GetSystemDirectoryW
#Defina GetTempPath GetTempPathW
#Defina GetTempFileName GetTempFileNameW
#Defina GetWindowsDirectory GetWindowsDirectoryW
#Defina GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#Defina AddLocalAlternateComputerName AddLocalAlternateComputerNameW
#Senão
#Defina ENUMRESTYPEPROC ENUMRESTYPEPROCA
#Defina ENUMRESNAMEPROC ENUMRESNAMEPROCA
#Defina ENUMRESLANGPROC ENUMRESLANGPROCA
#Defina EnumResourceTypes EnumResourceTypesA
#Defina EnumResourceNames EnumResourceNamesA
#Defina EnumResourceLanguages EnumResourceLanguagesA
#Defina BeginUpdateResource BeginUpdateResourceA
#Defina UpdateResource UpdateResourceA
#Defina EndUpdateResource EndUpdateResourceA
#Defina GlobalAddAtom GlobalAddAtomA
#Defina GlobalFindAtom GlobalFindAtomA
#Defina GlobalGetAtomName GlobalGetAtomNameA
#Defina AddAtom AddAtomA
#Defina FindAtom FindAtomA
#Defina GetAtomName GetAtomNameA
#Defina GetProfileInt GetProfileIntA
#Defina GetProfileString GetProfileStringA
#Defina WriteProfileString WriteProfileStringA
#Defina GetProfileSection GetProfileSectionA
#Defina WriteProfileSection WriteProfileSectionA
#Defina GetPrivateProfileInt GetPrivateProfileIntA
#Defina GetPrivateProfileString GetPrivateProfileStringA
#Defina WritePrivateProfileString WritePrivateProfileStringA
#Defina GetPrivateProfileSection GetPrivateProfileSectionA
#Defina WritePrivateProfileSection WritePrivateProfileSectionA
#Defina GetPrivateProfileSectionNames GetPrivateProfileSectionNamesA
#Defina GetPrivateProfileStruct GetPrivateProfileStructA
#Defina WritePrivateProfileStruct WritePrivateProfileStructA
#Defina GetDriveType GetDriveTypeA
#Defina GetSystemDirectory GetSystemDirectoryA
#Defina GetTempPath GetTempPathA
#Defina GetTempFileName GetTempFileNameA
#Defina GetWindowsDirectory GetWindowsDirectoryA
#Defina GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#Defina AddLocalAlternateComputerName AddLocalAlternateComputerNameA
#FimSe

  Pseudônimo WINBOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
  Pseudônimo WINBOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
  Pseudônimo WINBOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
  Pseudônimo WINBOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
  Pseudônimo WINBOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,WORD wLanguage,LONG_PTR lParam);
  Pseudônimo WINBOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage,LONG_PTR lParam);

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceNamesA(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceNamesW(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,WORD wLanguage,LPVOID lpData,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage,LPVOID lpData,DWORD cb);
  WINBASEAPI WINBOOL WINAPI EndUpdateResourceA(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI EndUpdateResourceW(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI GlobalAddAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalAddAtomW(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalFindAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalFindAtomW(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lpBuffer,Inteiro nSize);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lpBuffer,Inteiro nSize);
  WINBASEAPI ATOM WINAPI AddAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI AddAtomW(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI FindAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI FindAtomW(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lpBuffer,Inteiro nSize);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lpBuffer,Inteiro nSize);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lpKeyName,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lpKeyName,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetPrivateProfileIntA(LPCSTR lpAppName,LPCSTR lpKeyName,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI GetPrivateProfileIntW(LPCWSTR lpAppName,LPCWSTR lpKeyName,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD nSize,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD nSize,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD nSize,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD nSize,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileSectionA(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesA(LPSTR lpszReturnBuffer,DWORD nSize,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesW(LPWSTR lpszReturnBuffer,DWORD nSize,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI GetPrivateProfileStructA(LPCSTR lpszSection,LPCSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI GetPrivateProfileStructW(LPCWSTR lpszSection,LPCWSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStructA(LPCSTR lpszSection,LPCSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStructW(LPCWSTR lpszSection,LPCWSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCWSTR szFile);
  WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lpRootPathName);
  WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lpRootPathName);
  WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lpBuffer,UINT uSize);
  WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lpBuffer,UINT uSize);
  WINBASEAPI DWORD WINAPI GetTempPathA(DWORD nBufferLength,LPSTR lpBuffer);
  WINBASEAPI DWORD WINAPI GetTempPathW(DWORD nBufferLength,LPWSTR lpBuffer);
  WINBASEAPI UINT WINAPI GetTempFileNameA(LPCSTR lpPathName,LPCSTR lpPrefixString,UINT uUnique,LPSTR lpTempFileName);
  WINBASEAPI UINT WINAPI GetTempFileNameW(LPCWSTR lpPathName,LPCWSTR lpPrefixString,UINT uUnique,LPWSTR lpTempFileName);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lpBuffer,UINT uSize);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lpBuffer,UINT uSize);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lpBuffer,UINT uSize);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lpBuffer,UINT uSize);

#SeNãoDefinido RC_INVOKED
#SeDefinido UNICODE
#Defina GetSystemWow64Directory GetSystemWow64DirectoryW
#Senão
#Defina GetSystemWow64Directory GetSystemWow64DirectoryA
#FimSe

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lpBuffer,UINT uSize);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lpBuffer,UINT uSize);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *OldValue);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID OlValue);

  Pseudônimo UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lpBuffer,UINT uSize);
  Pseudônimo UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lpBuffer,UINT uSize);

#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T TEXT("GetSystemWow64DirectoryA")
#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T TEXT("GetSystemWow64DirectoryW")

#SeDefinido UNICODE
#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#Senão
#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#Defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#FimSe
#FimSe

#SeDefinido UNICODE
#Defina SetCurrentDirectory SetCurrentDirectoryW
#Defina GetCurrentDirectory GetCurrentDirectoryW
#Defina SetDllDirectory SetDllDirectoryW
#Defina GetDllDirectory GetDllDirectoryW
#Defina GetDiskFreeSpace GetDiskFreeSpaceW
#Defina GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#Defina CreateDirectory CreateDirectoryW
#Defina CreateDirectoryEx CreateDirectoryExW
#Defina RemoveDirectory RemoveDirectoryW
#Defina GetFullPathName GetFullPathNameW
#Defina DefineDosDevice DefineDosDeviceW
#Defina QueryDosDevice QueryDosDeviceW
#Defina CreateFile CreateFileW
#Defina SetFileAttributes SetFileAttributesW
#Defina GetFileAttributes GetFileAttributesW
#Senão
#Defina SetCurrentDirectory SetCurrentDirectoryA
#Defina GetCurrentDirectory GetCurrentDirectoryA
#Defina SetDllDirectory SetDllDirectoryA
#Defina GetDllDirectory GetDllDirectoryA
#Defina GetDiskFreeSpace GetDiskFreeSpaceA
#Defina GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#Defina CreateDirectory CreateDirectoryA
#Defina CreateDirectoryEx CreateDirectoryExA
#Defina RemoveDirectory RemoveDirectoryA
#Defina GetFullPathName GetFullPathNameA
#Defina DefineDosDevice DefineDosDeviceA
#Defina QueryDosDevice QueryDosDeviceA
#Defina CreateFile CreateFileA
#Defina SetFileAttributes SetFileAttributesA
#Defina GetFileAttributes GetFileAttributesA
#FimSe

  WINBASEAPI WINBOOL WINAPI SetCurrentDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI SetCurrentDirectoryW(LPCWSTR lpPathName);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD nBufferLength,LPSTR lpBuffer);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD nBufferLength,LPWSTR lpBuffer);
  WINBASEAPI WINBOOL WINAPI SetDllDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI SetDllDirectoryW(LPCWSTR lpPathName);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD nBufferLength,LPSTR lpBuffer);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD nBufferLength,LPWSTR lpBuffer);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lpRootPathName,LPDWORD lpSectorsPerCluster,LPDWORD lpBytesPerSector,LPDWORD lpNumberOfFreeClusters,LPDWORD lpTotalNumberOfClusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lpRootPathName,LPDWORD lpSectorsPerCluster,LPDWORD lpBytesPerSector,LPDWORD lpNumberOfFreeClusters,LPDWORD lpTotalNumberOfClusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lpFreeBytesAvailableToCaller,PULARGE_INTEGER lpTotalNumberOfBytes,PULARGE_INTEGER lpTotalNumberOfFreeBytes);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lpFreeBytesAvailableToCaller,PULARGE_INTEGER lpTotalNumberOfBytes,PULARGE_INTEGER lpTotalNumberOfFreeBytes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lpPathName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lpPathName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lpPathName);
  WINBASEAPI DWORD WINAPI GetFullPathNameA(LPCSTR lpFileName,DWORD nBufferLength,LPSTR lpBuffer,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI GetFullPathNameW(LPCWSTR lpFileName,DWORD nBufferLength,LPWSTR lpBuffer,LPWSTR *lpFilePart);

#Defina DDD_RAW_TARGET_PATH 0x1
#Defina DDD_REMOVE_DEFINITION 0x2
#Defina DDD_EXACT_MATCH_ON_REMOVE 0x4
#Defina DDD_NO_BROADCAST_SYSTEM 0x8
#Defina DDD_LUID_BROADCAST_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lpTargetPath);
  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lpTargetPath);
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lpTargetPath,DWORD ucchMax);
  WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lpTargetPath,DWORD ucchMax);

#Defina EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dwShareMode,DWORD dwFlagsAndAttributes);
  WINBASEAPI WINBOOL WINAPI SetFileAttributesA(LPCSTR lpFileName,DWORD dwFileAttributes);
  WINBASEAPI WINBOOL WINAPI SetFileAttributesW(LPCWSTR lpFileName,DWORD dwFileAttributes);
  WINBASEAPI DWORD WINAPI GetFileAttributesA(LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetFileAttributesW(LPCWSTR lpFileName);

  Pseudônimo Enumeração _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard,GetFileExMaxInfoLevel
  } GET_FILEEX_INFO_LEVELS;

#SeDefinido UNICODE
#Defina GetFileAttributesEx GetFileAttributesExW
#Defina GetCompressedFileSize GetCompressedFileSizeW
#Defina DeleteFile DeleteFileW
#Defina CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#Senão
#Defina GetFileAttributesEx GetFileAttributesExA
#Defina GetCompressedFileSize GetCompressedFileSizeA
#Defina DeleteFile DeleteFileA
#Defina CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#FimSe

  WINBASEAPI WINBOOL WINAPI GetFileAttributesExA(LPCSTR lpFileName,GET_FILEEX_INFO_LEVELS fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI GetFileAttributesExW(LPCWSTR lpFileName,GET_FILEEX_INFO_LEVELS fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI DWORD WINAPI GetCompressedFileSizeA(LPCSTR lpFileName,LPDWORD lpFileSizeHigh);
  WINBASEAPI DWORD WINAPI GetCompressedFileSizeW(LPCWSTR lpFileName,LPDWORD lpFileSizeHigh);
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD OemNameSize,PBOOL pbNameContainsSpaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD OemNameSize,PBOOL pbNameContainsSpaces,PBOOL pbNameLegal);

  Pseudônimo Enumeração _FINDEX_INFO_LEVELS {
    FindExInfoStandard,FindExInfoMaxInfoLevel
  } FINDEX_INFO_LEVELS;

  Pseudônimo Enumeração _FINDEX_SEARCH_OPS {
    FindExSearchNameMatch,FindExSearchLimitToDirectories,FindExSearchLimitToDevices,FindExSearchMaxSearchOp
  } FINDEX_SEARCH_OPS;

#Defina FIND_FIRST_EX_CASE_SENSITIVE 0x1

#SeDefinido UNICODE
#Defina FindFirstFileEx FindFirstFileExW
#Defina FindFirstFile FindFirstFileW
#Defina FindNextFile FindNextFileW
#Defina SearchPath SearchPathW
#Defina CopyFile CopyFileW
#Defina CopyFileEx CopyFileExW
#Defina MoveFile MoveFileW
#Defina MoveFileEx MoveFileExW
#Defina MoveFileWithProgress MoveFileWithProgressW
#Defina ReplaceFile ReplaceFileW
#Defina CreateHardLink CreateHardLinkW
#Defina CreateNamedPipe CreateNamedPipeW
#Defina GetNamedPipeHandleState GetNamedPipeHandleStateW
#Defina CallNamedPipe CallNamedPipeW
#Defina WaitNamedPipe WaitNamedPipeW
#Defina SetVolumeLabel SetVolumeLabelW
#Defina GetVolumeInformation GetVolumeInformationW
#Defina ClearEventLog ClearEventLogW
#Defina BackupEventLog BackupEventLogW
#Defina OpenEventLog OpenEventLogW
#Defina RegisterEventSource RegisterEventSourceW
#Defina OpenBackupEventLog OpenBackupEventLogW
#Defina ReadEventLog ReadEventLogW
#Defina ReportEvent ReportEventW
#Defina AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#Defina AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#Defina AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmW
#Defina AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleW
#Defina ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#Defina ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#Defina ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#Defina ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#Defina PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#Defina SetFileSecurity SetFileSecurityW
#Defina GetFileSecurity GetFileSecurityW
#Defina FindFirstChangeNotification FindFirstChangeNotificationW
#Defina IsBadStringPtr IsBadStringPtrW
#Defina LookupAccountSid LookupAccountSidW
#Defina LookupAccountName LookupAccountNameW
#Defina LookupPrivilegeValue LookupPrivilegeValueW
#Defina LookupPrivilegeName LookupPrivilegeNameW
#Defina LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#Defina BuildCommDCB BuildCommDCBW
#Defina BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#Defina CommConfigDialog CommConfigDialogW
#Defina GetDefaultCommConfig GetDefaultCommConfigW
#Defina SetDefaultCommConfig SetDefaultCommConfigW
#Defina GetComputerName GetComputerNameW
#Defina SetComputerName SetComputerNameW
#Defina GetComputerNameEx GetComputerNameExW
#Defina SetComputerNameEx SetComputerNameExW
#Defina DnsHostnameToComputerName DnsHostnameToComputerNameW
#Defina GetUserName GetUserNameW
#Senão
#Defina FindFirstFileEx FindFirstFileExA
#Defina FindFirstFile FindFirstFileA
#Defina FindNextFile FindNextFileA
#Defina SearchPath SearchPathA
#Defina CopyFile CopyFileA
#Defina CopyFileEx CopyFileExA
#Defina MoveFile MoveFileA
#Defina MoveFileEx MoveFileExA
#Defina MoveFileWithProgress MoveFileWithProgressA
#Defina ReplaceFile ReplaceFileA
#Defina CreateHardLink CreateHardLinkA
#Defina CreateNamedPipe CreateNamedPipeA
#Defina GetNamedPipeHandleState GetNamedPipeHandleStateA
#Defina CallNamedPipe CallNamedPipeA
#Defina WaitNamedPipe WaitNamedPipeA
#Defina SetVolumeLabel SetVolumeLabelA
#Defina GetVolumeInformation GetVolumeInformationA
#Defina ClearEventLog ClearEventLogA
#Defina BackupEventLog BackupEventLogA
#Defina OpenEventLog OpenEventLogA
#Defina RegisterEventSource RegisterEventSourceA
#Defina OpenBackupEventLog OpenBackupEventLogA
#Defina ReadEventLog ReadEventLogA
#Defina ReportEvent ReportEventA
#Defina AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#Defina AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#Defina AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmA
#Defina AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleA
#Defina ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#Defina ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#Defina ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#Defina ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#Defina PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#Defina SetFileSecurity SetFileSecurityA
#Defina GetFileSecurity GetFileSecurityA
#Defina FindFirstChangeNotification FindFirstChangeNotificationA
#Defina IsBadStringPtr IsBadStringPtrA
#Defina LookupAccountSid LookupAccountSidA
#Defina LookupAccountName LookupAccountNameA
#Defina LookupPrivilegeValue LookupPrivilegeValueA
#Defina LookupPrivilegeName LookupPrivilegeNameA
#Defina LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#Defina BuildCommDCB BuildCommDCBA
#Defina BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#Defina CommConfigDialog CommConfigDialogA
#Defina GetDefaultCommConfig GetDefaultCommConfigA
#Defina SetDefaultCommConfig SetDefaultCommConfigA
#Defina GetComputerName GetComputerNameA
#Defina SetComputerName SetComputerNameA
#Defina GetComputerNameEx GetComputerNameExA
#Defina SetComputerNameEx SetComputerNameExA
#Defina DnsHostnameToComputerName DnsHostnameToComputerNameA
#Defina GetUserName GetUserNameA
#FimSe

  WINBASEAPI HANDLE WINAPI FindFirstFileExA(LPCSTR lpFileName,FINDEX_INFO_LEVELS fInfoLevelId,LPVOID lpFindFileData,FINDEX_SEARCH_OPS fSearchOp,LPVOID lpSearchFilter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI FindFirstFileExW(LPCWSTR lpFileName,FINDEX_INFO_LEVELS fInfoLevelId,LPVOID lpFindFileData,FINDEX_SEARCH_OPS fSearchOp,LPVOID lpSearchFilter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI FindFirstFileA(LPCSTR lpFileName,LPWIN32_FIND_DATAA lpFindFileData);
  WINBASEAPI HANDLE WINAPI FindFirstFileW(LPCWSTR lpFileName,LPWIN32_FIND_DATAW lpFindFileData);
  WINBASEAPI WINBOOL WINAPI FindNextFileA(HANDLE hFindFile,LPWIN32_FIND_DATAA lpFindFileData);
  WINBASEAPI WINBOOL WINAPI FindNextFileW(HANDLE hFindFile,LPWIN32_FIND_DATAW lpFindFileData);
  WINBASEAPI DWORD WINAPI SearchPathA(LPCSTR lpPath,LPCSTR lpFileName,LPCSTR lpExtension,DWORD nBufferLength,LPSTR lpBuffer,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI SearchPathW(LPCWSTR lpPath,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD nBufferLength,LPWSTR lpBuffer,LPWSTR *lpFilePart);
  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  Pseudônimo DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER TotalFileSize,LARGE_INTEGER TotalBytesTransferred,LARGE_INTEGER StreamSize,LARGE_INTEGER StreamBytesTransferred,DWORD dwStreamNumber,DWORD dwCallbackReason,HANDLE hSourceFile,HANDLE hDestinationFile,LPVOID lpData);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileWithProgressA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileWithProgressW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,DWORD dwFlags);

#Defina MOVEFILE_REPLACE_EXISTING 0x1
#Defina MOVEFILE_COPY_ALLOWED 0x2
#Defina MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#Defina MOVEFILE_WRITE_THROUGH 0x8
#Defina MOVEFILE_CREATE_HARDLINK 0x10
#Defina MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);

  Pseudônimo Enumeração _STREAM_INFO_LEVELS {
    FindStreamInfoStandard,FindStreamInfoMaxInfoLevel
  } STREAM_INFO_LEVELS;

  Pseudônimo Estrutura _WIN32_FIND_STREAM_DATA {
    LARGE_INTEGER StreamSize;
    WCHAR cStreamName[MAX_PATH + 36];
  } WIN32_FIND_STREAM_DATA,*PWIN32_FIND_STREAM_DATA;

  HANDLE WINAPI FindFirstStreamW(LPCWSTR lpFileName,STREAM_INFO_LEVELS InfoLevel,LPVOID lpFindStreamData,DWORD dwFlags);
  WINBOOL WINAPI FindNextStreamW(HANDLE hFindStream,LPVOID lpFindStreamData);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dwOpenMode,DWORD dwPipeMode,DWORD nMaxInstances,DWORD nOutBufferSize,DWORD nInBufferSize,DWORD nDefaultTimeOut,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dwOpenMode,DWORD dwPipeMode,DWORD nMaxInstances,DWORD nOutBufferSize,DWORD nInBufferSize,DWORD nDefaultTimeOut,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout,LPSTR lpUserName,DWORD nMaxUserNameSize);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout,LPWSTR lpUserName,DWORD nMaxUserNameSize);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesRead,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesRead,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI SetVolumeLabelA(LPCSTR lpRootPathName,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI SetVolumeLabelW(LPCWSTR lpRootPathName,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI SetFileApisToOEM(VOID);
  WINBASEAPI VOID WINAPI SetFileApisToANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lpRootPathName,LPSTR lpVolumeNameBuffer,DWORD nVolumeNameSize,LPDWORD lpVolumeSerialNumber,LPDWORD lpMaximumComponentLength,LPDWORD lpFileSystemFlags,LPSTR lpFileSystemNameBuffer,DWORD nFileSystemNameSize);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lpRootPathName,LPWSTR lpVolumeNameBuffer,DWORD nVolumeNameSize,LPDWORD lpVolumeSerialNumber,LPDWORD lpMaximumComponentLength,LPDWORD lpFileSystemFlags,LPWSTR lpFileSystemNameBuffer,DWORD nFileSystemNameSize);
  WINBASEAPI WINBOOL WINAPI CancelIo(HANDLE hFile);
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI DeregisterEventSource(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI GetNumberOfEventLogRecords(HANDLE hEventLog,PDWORD NumberOfRecords);
  WINADVAPI WINBOOL WINAPI GetOldestEventLogRecord(HANDLE hEventLog,PDWORD OldestRecord);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lpSourceName);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
  WINADVAPI HANDLE WINAPI RegisterEventSourceA(LPCSTR lpUNCServerName,LPCSTR lpSourceName);
  WINADVAPI HANDLE WINAPI RegisterEventSourceW(LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dwRecordOffset,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,DWORD *pnBytesRead,DWORD *pnMinNumberOfBytesNeeded);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dwRecordOffset,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,DWORD *pnBytesRead,DWORD *pnMinNumberOfBytesNeeded);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD wNumStrings,DWORD dwDataSize,LPCSTR *lpStrings,LPVOID lpRawData);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD wNumStrings,DWORD dwDataSize,LPCWSTR *lpStrings,LPVOID lpRawData);

#Defina EVENTLOG_FULL_INFO 0

  Pseudônimo Estrutura _EVENTLOG_FULL_INFORMATION {
    DWORD dwFull;
  } EVENTLOG_FULL_INFORMATION,*LPEVENTLOG_FULL_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lpBuffer,DWORD cbBufSize,LPDWORD pcbBytesNeeded);
  WINADVAPI WINBOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
  WINADVAPI WINBOOL WINAPI GetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength,LPDWORD lpnLengthNeeded);
  WINADVAPI WINBOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
  WINADVAPI WINBOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
  WINADVAPI WINBOOL WINAPI RevertToSelf(VOID);
  WINADVAPI WINBOOL WINAPI SetThreadToken (PHANDLE Thread,HANDLE Token);
  WINADVAPI WINBOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,LPDWORD PrivilegeSetLength,LPDWORD GrantedAccess,LPBOOL AccessStatus);
  WINADVAPI WINBOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,LPDWORD PrivilegeSetLength,LPDWORD GrantedAccess,LPBOOL AccessStatus);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultList(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,LPDWORD PrivilegeSetLength,LPDWORD GrantedAccessList,LPDWORD AccessStatusList);
  WINADVAPI WINBOOL WINAPI OpenProcessToken(HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI OpenThreadToken(HANDLE ThreadHandle,DWORD DesiredAccess,WINBOOL OpenAsSelf,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI GetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD TokenInformationLength,PDWORD ReturnLength);
  WINADVAPI WINBOOL WINAPI SetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD TokenInformationLength);
  WINADVAPI WINBOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle,WINBOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD BufferLength,PTOKEN_PRIVILEGES PreviousState,PDWORD ReturnLength);
  WINADVAPI WINBOOL WINAPI AdjustTokenGroups(HANDLE TokenHandle,WINBOOL ResetToDefault,PTOKEN_GROUPS NewState,DWORD BufferLength,PTOKEN_GROUPS PreviousState,PDWORD ReturnLength);
  WINADVAPI WINBOOL WINAPI PrivilegeCheck(HANDLE ClientToken,PPRIVILEGE_SET RequiredPrivileges,LPBOOL pfResult);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmByHandleA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmByHandleW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_SET Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_SET Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI IsWellKnownSid(PSID pSid,WELL_KNOWN_SID_TYPE WellKnownSidType);
  WINADVAPI WINBOOL WINAPI CreateWellKnownSid(WELL_KNOWN_SID_TYPE WellKnownSidType,PSID DomainSid,PSID pSid,DWORD *cbSid);
  WINADVAPI WINBOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,WINBOOL *pfEqual);
  WINADVAPI WINBOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD *cbDomainSid);
  WINADVAPI WINBOOL WINAPI IsValidSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI EqualSid(PSID pSid1,PSID pSid2);
  WINADVAPI WINBOOL WINAPI EqualPrefixSid(PSID pSid1,PSID pSid2);
  WINADVAPI DWORD WINAPI GetSidLengthRequired (UCHAR nSubAuthorityCount);
  WINADVAPI WINBOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE nSubAuthorityCount,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,DWORD nSubAuthority7,PSID *pSid);
  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI InitializeSid(PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE nSubAuthorityCount);
  WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID pSid);
  WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID pSid,DWORD nSubAuthority);
  WINADVAPI PUCHAR WINAPI GetSidSubAuthorityCount(PSID pSid);
  WINADVAPI DWORD WINAPI GetLengthSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI CopySid(DWORD nDestinationSidLength,PSID pDestinationSid,PSID pSourceSid);
  WINADVAPI WINBOOL WINAPI AreAllAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI WINBOOL WINAPI AreAnyAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI VOID WINAPI MapGenericMask(PDWORD AccessMask,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI IsValidAcl(PACL pAcl);
  WINADVAPI WINBOOL WINAPI InitializeAcl(PACL pAcl,DWORD nAclLength,DWORD dwAclRevision);
  WINADVAPI WINBOOL WINAPI GetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD nAclInformationLength,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI SetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD nAclInformationLength,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI AddAce(PACL pAcl,DWORD dwAceRevision,DWORD dwStartingAceIndex,LPVOID pAceList,DWORD nAceListLength);
  WINADVAPI WINBOOL WINAPI DeleteAce(PACL pAcl,DWORD dwAceIndex);
  WINADVAPI WINBOOL WINAPI GetAce(PACL pAcl,DWORD dwAceIndex,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI AddAccessAllowedAce(PACL pAcl,DWORD dwAceRevision,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessAllowedAceEx(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessDeniedAce(PACL pAcl,DWORD dwAceRevision,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessDeniedAceEx(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAuditAccessAce(PACL pAcl,DWORD dwAceRevision,DWORD dwAccessMask,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI AddAuditAccessAceEx(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dwAccessMask,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI AddAccessAllowedObjectAce(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessDeniedObjectAce(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAuditAccessObjectAce(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI FindFirstFreeAce(PACL pAcl,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
  WINADVAPI WINBOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorLength(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest,SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bDaclPresent,PACL pDacl,WINBOOL bDaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bSaclPresent,PACL pSacl,WINBOOL bSaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,WINBOOL bOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pGroup,WINBOOL bGroupDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pGroup,LPBOOL lpbGroupDefaulted);
  WINADVAPI DWORD WINAPI SetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI WINBOOL WINAPI CreatePrivateObjectSecurity(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,WINBOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI ConvertToAutoInheritPrivateObjectSecurity(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI CreatePrivateObjectSecurityEx(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID *ObjectType,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI CreatePrivateObjectSecurityWithMultipleInheritance(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID **ObjectTypes,ULONG GuidCount,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI SetPrivateObjectSecurity (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI SetPrivateObjectSecurityEx (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI GetPrivateObjectSecurity(PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD DescriptorLength,PDWORD ReturnLength);
  WINADVAPI WINBOOL WINAPI DestroyPrivateObjectSecurity(PSECURITY_DESCRIPTOR *ObjectDescriptor);
  WINADVAPI WINBOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdwBufferLength);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdwAbsoluteSecurityDescriptorSize,PACL pDacl,LPDWORD lpdwDaclSize,PACL pSacl,LPDWORD lpdwSaclSize,PSID pOwner,LPDWORD lpdwOwnerSize,PSID pPrimaryGroup,LPDWORD lpdwPrimaryGroupSize);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdwBufferSize);
  WINADVAPI WINBOOL WINAPI SetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI SetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength,LPDWORD lpnLengthNeeded);
  WINADVAPI WINBOOL WINAPI GetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength,LPDWORD lpnLengthNeeded);
  WINADVAPI WINBOOL WINAPI SetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
  WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationA(LPCSTR lpPathName,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationW(LPCWSTR lpPathName,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI WINBOOL WINAPI FindNextChangeNotification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI FindCloseChangeNotification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lpBuffer,DWORD nBufferLength,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lpBytesReturned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI VirtualLock(LPVOID lpAddress,SIZE_T dwSize);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lpAddress,SIZE_T dwSize);
  WINBASEAPI LPVOID WINAPI MapViewOfFileEx(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dwFileOffsetHigh,DWORD dwFileOffsetLow,SIZE_T dwNumberOfBytesToMap,LPVOID lpBaseAddress);
  WINBASEAPI WINBOOL WINAPI SetPriorityClass(HANDLE hProcess,DWORD dwPriorityClass);
  WINBASEAPI DWORD WINAPI GetPriorityClass(HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadCodePtr(FARPROC lpfn);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
  WINADVAPI WINBOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeValueA(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeValueW(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeNameA(LPCSTR lpSystemName,PLUID lpLuid,LPSTR lpName,LPDWORD cchName);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeNameW(LPCWSTR lpSystemName,PLUID lpLuid,LPWSTR lpName,LPDWORD cchName);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeDisplayNameA(LPCSTR lpSystemName,LPCSTR lpName,LPSTR lpDisplayName,LPDWORD cchDisplayName,LPDWORD lpLanguageId);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeDisplayNameW(LPCWSTR lpSystemName,LPCWSTR lpName,LPWSTR lpDisplayName,LPDWORD cchDisplayName,LPDWORD lpLanguageId);
  WINADVAPI WINBOOL WINAPI AllocateLocallyUniqueId(PLUID Luid);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBA(LPCSTR lpDef,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBW(LPCWSTR lpDef,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBAndTimeoutsA(LPCSTR lpDef,LPDCB lpDCB,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBAndTimeoutsW(LPCWSTR lpDef,LPDCB lpDCB,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI CommConfigDialogA(LPCSTR lpszName,HWND hWnd,LPCOMMCONFIG lpCC);
  WINBASEAPI WINBOOL WINAPI CommConfigDialogW(LPCWSTR lpszName,HWND hWnd,LPCOMMCONFIG lpCC);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
  WINBASEAPI WINBOOL WINAPI SetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dwSize);
  WINBASEAPI WINBOOL WINAPI SetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dwSize);

#Defina MAX_COMPUTERNAME_LENGTH 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lpBuffer,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lpBuffer,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetComputerNameA(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI SetComputerNameW(LPCWSTR lpComputerName);

  Pseudônimo Enumeração _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPSTR lpBuffer,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPWSTR lpBuffer,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPCSTR lpBuffer);
  WINBASEAPI WINBOOL WINAPI SetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPCWSTR lpBuffer);
  WINBASEAPI WINBOOL WINAPI DnsHostnameToComputerNameA(LPCSTR Hostname,LPSTR ComputerName,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI DnsHostnameToComputerNameW(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD nSize);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lpBuffer,LPDWORD pcbBuffer);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lpBuffer,LPDWORD pcbBuffer);

#Defina LOGON32_LOGON_INTERACTIVE 2
#Defina LOGON32_LOGON_NETWORK 3
#Defina LOGON32_LOGON_BATCH 4
#Defina LOGON32_LOGON_SERVICE 5
#Defina LOGON32_LOGON_UNLOCK 7
#Defina LOGON32_LOGON_NETWORK_CLEARTEXT 8
#Defina LOGON32_LOGON_NEW_CREDENTIALS 9

#Defina LOGON32_PROVIDER_DEFAULT 0
#Defina LOGON32_PROVIDER_WINNT35 1
#Defina LOGON32_PROVIDER_WINNT40 2
#Defina LOGON32_PROVIDER_WINNT50 3

#SeDefinido UNICODE
#Defina LogonUser LogonUserW
#Defina LogonUserEx LogonUserExW
#Defina CreateProcessAsUser CreateProcessAsUserW
#Senão
#Defina LogonUser LogonUserA
#Defina LogonUserEx LogonUserExA
#Defina CreateProcessAsUser CreateProcessAsUserA
#FimSe

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *ppProfileBuffer,LPDWORD pdwProfileLength,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *ppProfileBuffer,LPDWORD pdwProfileLength,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserW(HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);

#Defina LOGON_WITH_PROFILE 0x1
#Defina LOGON_NETCREDENTIALS_ONLY 0x2
#Defina LOGON_ZERO_PASSWORD_BUFFER 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lpCommandLine,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lpCommandLine,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI ImpersonateAnonymousToken(HANDLE ThreadHandle);
  WINADVAPI WINBOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_ATTRIBUTES lpTokenAttributes,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
  WINADVAPI WINBOOL WINAPI CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD DisableSidCount,PSID_AND_ATTRIBUTES SidsToDisable,DWORD DeletePrivilegeCount,PLUID_AND_ATTRIBUTES PrivilegesToDelete,DWORD RestrictedSidCount,PSID_AND_ATTRIBUTES SidsToRestrict,PHANDLE NewTokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI CheckTokenMembership(HANDLE TokenHandle,PSID SidToCheck,PBOOL IsMember);

  Pseudônimo WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI RegisterWaitForSingleObject(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI RegisterWaitForSingleObjectEx(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI QueueUserWorkItem(LPTHREAD_START_ROUTINE Function,PVOID Context,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI CreateTimerQueue(VOID);
  WINBASEAPI WINBOOL WINAPI CreateTimerQueueTimer(PHANDLE phNewTimer,HANDLE TimerQueue,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD DueTime,DWORD Period,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI ChangeTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer,ULONG DueTime,ULONG Period);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueueEx(HANDLE TimerQueue,HANDLE CompletionEvent);
  WINBASEAPI HANDLE WINAPI SetTimerQueueTimer(HANDLE TimerQueue,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD DueTime,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI CancelTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueue(HANDLE TimerQueue);

#Defina HW_PROFILE_GUIDLEN 39
#Defina MAX_PROFILE_LEN 80

#Defina DOCKINFO_UNDOCKED (0x1)
#Defina DOCKINFO_DOCKED (0x2)
#Defina DOCKINFO_USER_SUPPLIED (0x4)
#Defina DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#Defina DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  Pseudônimo Estrutura tagHW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  Pseudônimo Estrutura tagHW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

#SeDefinido UNICODE
  Pseudônimo HW_PROFILE_INFOW HW_PROFILE_INFO;
  Pseudônimo LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#Senão
  Pseudônimo HW_PROFILE_INFOA HW_PROFILE_INFO;
  Pseudônimo LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#FimSe

#SeDefinido UNICODE
#Defina GetCurrentHwProfile GetCurrentHwProfileW
#Defina GetVersionEx GetVersionExW
#Defina VerifyVersionInfo VerifyVersionInfoW
#Senão
#Defina GetCurrentHwProfile GetCurrentHwProfileA
#Defina GetVersionEx GetVersionExA
#Defina VerifyVersionInfo VerifyVersionInfoA
#FimSe

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
  WINBASEAPI WINBOOL WINAPI GetVersionExA(LPOSVERSIONINFOA lpVersionInformation);
  WINBASEAPI WINBOOL WINAPI GetVersionExW(LPOSVERSIONINFOW lpVersionInformation);
  WINBASEAPI WINBOOL WINAPI VerifyVersionInfoA(LPOSVERSIONINFOEXA lpVersionInformation,DWORD dwTypeMask,DWORDLONG dwlConditionMask);
  WINBASEAPI WINBOOL WINAPI VerifyVersionInfoW(LPOSVERSIONINFOEXW lpVersionInformation,DWORD dwTypeMask,DWORDLONG dwlConditionMask);

#Inclua <winerror.h>

#Defina TC_NORMAL 0
#Defina TC_HARDERR 1
#Defina TC_GP_TRAP 2
#Defina TC_SIGNAL 3

#Defina AC_LINE_OFFLINE 0x0
#Defina AC_LINE_ONLINE 0x1
#Defina AC_LINE_BACKUP_POWER 0x2
#Defina AC_LINE_UNKNOWN 0xff

#Defina BATTERY_FLAG_HIGH 0x1
#Defina BATTERY_FLAG_LOW 0x2
#Defina BATTERY_FLAG_CRITICAL 0x4
#Defina BATTERY_FLAG_CHARGING 0x8
#Defina BATTERY_FLAG_NO_BATTERY 0x80
#Defina BATTERY_FLAG_UNKNOWN 0xff

#Defina BATTERY_PERCENTAGE_UNKNOWN 0xff

#Defina BATTERY_LIFE_UNKNOWN 0xffffffff

  Pseudônimo Estrutura _SYSTEM_POWER_STATUS {
    BYTE ACLineStatus;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD BatteryLifeTime;
    DWORD BatteryFullLifeTime;
  } SYSTEM_POWER_STATUS,*LPSYSTEM_POWER_STATUS;

#SeDefinido UNICODE
#Defina CreateJobObject CreateJobObjectW
#Defina OpenJobObject OpenJobObjectW
#Defina FindFirstVolume FindFirstVolumeW
#Defina FindNextVolume FindNextVolumeW
#Defina FindFirstVolumeMountPoint FindFirstVolumeMountPointW
#Defina FindNextVolumeMountPoint FindNextVolumeMountPointW
#Defina SetVolumeMountPoint SetVolumeMountPointW
#Defina DeleteVolumeMountPoint DeleteVolumeMountPointW
#Defina GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointW
#Defina GetVolumePathName GetVolumePathNameW
#Defina GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameW
#Senão
#Defina CreateJobObject CreateJobObjectA
#Defina OpenJobObject OpenJobObjectA
#Defina FindFirstVolume FindFirstVolumeA
#Defina FindNextVolume FindNextVolumeA
#Defina FindFirstVolumeMountPoint FindFirstVolumeMountPointA
#Defina FindNextVolumeMountPoint FindNextVolumeMountPointA
#Defina SetVolumeMountPoint SetVolumeMountPointA
#Defina DeleteVolumeMountPoint DeleteVolumeMountPointA
#Defina GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointA
#Defina GetVolumePathName GetVolumePathNameA
#Defina GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameA
#FimSe

  WINBOOL WINAPI GetSystemPowerStatus(LPSYSTEM_POWER_STATUS lpSystemPowerStatus);
  WINBOOL WINAPI SetSystemPowerState(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI AllocateUserPhysicalPages(HANDLE hProcess,PULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI FreeUserPhysicalPages(HANDLE hProcess,PULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI MapUserPhysicalPages(PVOID VirtualAddress,ULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI MapUserPhysicalPagesScatter(PVOID *VirtualAddresses,ULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI HANDLE WINAPI CreateJobObjectA(LPSECURITY_ATTRIBUTES lpJobAttributes,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateJobObjectW(LPSECURITY_ATTRIBUTES lpJobAttributes,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenJobObjectA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenJobObjectW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI AssignProcessToJobObject(HANDLE hJob,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI TerminateJobObject(HANDLE hJob,UINT uExitCode);
  WINBASEAPI WINBOOL WINAPI QueryInformationJobObject(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cbJobObjectInformationLength,LPDWORD lpReturnLength);
  WINBASEAPI WINBOOL WINAPI SetInformationJobObject(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cbJobObjectInformationLength);
  WINBASEAPI WINBOOL WINAPI IsProcessInJob(HANDLE ProcessHandle,HANDLE JobHandle,PBOOL Result);
  WINBASEAPI WINBOOL WINAPI CreateJobSet(ULONG NumJob,PJOB_SET_ARRAY UserJobSet,ULONG Flags);
  WINBASEAPI PVOID WINAPI AddVectoredExceptionHandler (ULONG First,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID Handle);
  WINBASEAPI PVOID WINAPI AddVectoredContinueHandler (ULONG First,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID Handle);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeA(LPSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeW(LPWSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindNextVolumeA(HANDLE hFindVolume,LPSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindNextVolumeW(HANDLE hFindVolume,LPWSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindVolumeClose(HANDLE hFindVolume);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointA(LPCSTR lpszRootPathName,LPSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointW(LPCWSTR lpszRootPathName,LPWSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindNextVolumeMountPointA(HANDLE hFindVolumeMountPoint,LPSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindNextVolumeMountPointW(HANDLE hFindVolumeMountPoint,LPWSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindVolumeMountPointClose(HANDLE hFindVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI SetVolumeMountPointA(LPCSTR lpszVolumeMountPoint,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI SetVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI DeleteVolumeMountPointA(LPCSTR lpszVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI DeleteVolumeMountPointW(LPCWSTR lpszVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI GetVolumeNameForVolumeMountPointA(LPCSTR lpszVolumeMountPoint,LPSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI GetVolumeNameForVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,LPWSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNameA(LPCSTR lpszFileName,LPSTR lpszVolumePathName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNameW(LPCWSTR lpszFileName,LPWSTR lpszVolumePathName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNamesForVolumeNameA(LPCSTR lpszVolumeName,LPCH lpszVolumePathNames,DWORD cchBufferLength,PDWORD lpcchReturnLength);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNamesForVolumeNameW(LPCWSTR lpszVolumeName,LPWCH lpszVolumePathNames,DWORD cchBufferLength,PDWORD lpcchReturnLength);

#Defina ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#Defina ACTCTX_FLAG_LANGID_VALID 0x2
#Defina ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#Defina ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#Defina ACTCTX_FLAG_SET_PROCESS_DEFAULT 0x10
#Defina ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#Defina ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF 0x40
#Defina ACTCTX_FLAG_HMODULE_VALID 0x80

  Pseudônimo Estrutura tagACTCTXA {
    ULONG cbSize;
    DWORD dwFlags;
    LPCSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXA,*PACTCTXA;

  Pseudônimo Estrutura tagACTCTXW {
    ULONG cbSize;
    DWORD dwFlags;
    LPCWSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXW,*PACTCTXW;

  Pseudônimo Imutável ACTCTXA *PCACTCTXA;
  Pseudônimo Imutável ACTCTXW *PCACTCTXW;

#SeDefinido UNICODE
  Pseudônimo ACTCTXW ACTCTX;
  Pseudônimo PACTCTXW PACTCTX;
  Pseudônimo PCACTCTXW PCACTCTX;
#Senão
  Pseudônimo ACTCTXA ACTCTX;
  Pseudônimo PACTCTXA PACTCTX;
  Pseudônimo PCACTCTXA PCACTCTX;
#FimSe

#SeDefinido UNICODE
#Defina CreateActCtx CreateActCtxW
#Senão
#Defina CreateActCtx CreateActCtxA
#FimSe

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI AddRefActCtx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#Defina DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  Pseudônimo Estrutura tagACTCTX_SECTION_KEYED_DATA_2600 {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;
  } ACTCTX_SECTION_KEYED_DATA_2600,*PACTCTX_SECTION_KEYED_DATA_2600;

  Pseudônimo Imutável ACTCTX_SECTION_KEYED_DATA_2600 *PCACTCTX_SECTION_KEYED_DATA_2600;

  Pseudônimo Estrutura tagACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lpSectionBase;
    ULONG ulSectionLength;
    PVOID lpSectionGlobalDataBase;
    ULONG ulSectionGlobalDataLength;
  } ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;

  Pseudônimo Imutável ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;

  Pseudônimo Estrutura tagACTCTX_SECTION_KEYED_DATA {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_DATA,*PACTCTX_SECTION_KEYED_DATA;

  Pseudônimo Imutável ACTCTX_SECTION_KEYED_DATA *PCACTCTX_SECTION_KEYED_DATA;

#Defina FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX 0x1
#Defina FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS 0x2
#Defina FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA 0x4

#SeDefinido UNICODE
#Defina FindActCtxSectionString FindActCtxSectionStringW
#Senão
#Defina FindActCtxSectionString FindActCtxSectionStringA
#FimSe

  WINBASEAPI WINBOOL WINAPI FindActCtxSectionStringA(DWORD dwFlags,Imutável GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
  WINBASEAPI WINBOOL WINAPI FindActCtxSectionStringW(DWORD dwFlags,Imutável GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
  WINBASEAPI WINBOOL WINAPI FindActCtxSectionGuid(DWORD dwFlags,Imutável GUID *lpExtensionGuid,ULONG ulSectionId,Imutável GUID *lpGuidToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);

#SeNãoDefinido RC_INVOKED
#SeNãoDefinido ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  Pseudônimo Estrutura _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  Pseudônimo Imutável Estrutura _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#Defina ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#FimSe
#FimSe

#Defina QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX 0x4
#Defina QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#Defina QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS 0x10
#Defina QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pvBuffer,SIZE_T cbBuffer,SIZE_T *pcbWrittenOrRequired);

  Pseudônimo WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pvBuffer,SIZE_T cbBuffer,SIZE_T *pcbWrittenOrRequired);

  WINBASEAPI WINBOOL WINAPI ProcessIdToSessionId(DWORD dwProcessId,DWORD *pSessionId);
  WINBASEAPI DWORD WINAPI WTSGetActiveConsoleSessionId();
  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer,PDWORD ReturnedLength);
  WINBASEAPI WINBOOL WINAPI GetNumaHighestNodeNumber(PULONG HighestNodeNumber);
  WINBASEAPI WINBOOL WINAPI GetNumaProcessorNode(UCHAR Processor,PUCHAR NodeNumber);
  WINBASEAPI WINBOOL WINAPI GetNumaNodeProcessorMask(UCHAR Node,PULONGLONG ProcessorMask);
  WINBASEAPI WINBOOL WINAPI GetNumaAvailableMemoryNode(UCHAR Node,PULONGLONG AvailableBytes);

#SeDefinido __cplusplus
}
#FimSe
#FimSe
