/*	Benjamin DELPY `gentilkiwi`
	http://blog.gentilkiwi.com
	benjamin@gentilkiwi.com
	Licence : https://creativecommons.org/licenses/by/4.0/
*/
#pragma once
#include <ntstatus.h>
#define WIN32_NO_STATUS
#define SECURITY_WIN32
#define CINTERFACE
#define COBJMACROS
#include <windows.h>
#include <sspi.h>
#include <sddl.h>
#include <wincred.h>
#include <ntsecapi.h>
#include <ntsecpkg.h>
#include <stdio.h>
#include <wchar.h>
#include "../modules/kull_m_output.h"
//#define KERBEROS_TOOLS
//#define SERVICE_INCONTROL
#define NET_MODULE
#define SQLITE3_OMIT
#if defined(_M_ARM64)
	#define MIMIKATZ_ARCH L"arm64"
#elif defined(_M_X64)
	#define MIMIKATZ_ARCH L"x64"
#elif defined(_M_IX86)
	#define MIMIKATZ_ARCH L"x86"
#endif

#ifdef __MINGW32__
#define __try
#define __except if

#define SERVICE_CONTROL_PRESHUTDOWN 0x0000000F

#define KERB_CHECKSUM_HMAC_SHA1_96_AES128         15
#define KERB_CHECKSUM_HMAC_SHA1_96_AES128_Ki      -150
#define KERB_CHECKSUM_HMAC_SHA1_96_AES256         16
#define KERB_CHECKSUM_HMAC_SHA1_96_AES256_Ki      -151
#define KERB_CHECKSUM_SHA1_NEW                    14

#define KERB_ETYPE_AES128_CTS_HMAC_SHA1_96        17
#define KERB_ETYPE_AES128_CTS_HMAC_SHA1_96_PLAIN  -148
#define KERB_ETYPE_AES256_CTS_HMAC_SHA1_96        18
#define KERB_ETYPE_AES256_CTS_HMAC_SHA1_96_PLAIN  -149

// Missing from ntsecapi.h on Mingw :(
#define KerbSubmitTicketMesage           21
#define KerbAddExtraCredentialsExMessage 22

// Fucking typos, really? Thanks mingw
#define KerbSubmitTicketMessage KerbSubmitTicketMesage

#define SCARD_PROVIDER_KSP 3

#ifndef CRYPT_DEFAULT_CONTAINER_OPTIONAL
#define CRYPT_DEFAULT_CONTAINER_OPTIONAL 0x00000080
#endif

#ifndef NTE_NO_MORE_ITEMS
#define NTE_NO_MORE_ITEMS ((HRESULT)0x8009002AL)
#endif

#endif

#define MIMIKATZ				L"mimikatz"
#define MIMIKATZ_VERSION		L"2.2.0"
#define MIMIKATZ_CODENAME		L"A La Vie, A L\'Amour"
#define MIMIKATZ_MAX_WINBUILD	L"18362"
#define MIMIKATZ_FULL			MIMIKATZ L" " MIMIKATZ_VERSION L" (" MIMIKATZ_ARCH L") #" MIMIKATZ_MAX_WINBUILD L" " TEXT(__DATE__) L" " TEXT(__TIME__)
#define MIMIKATZ_SECOND			L"\"" MIMIKATZ_CODENAME L"\""
#define MIMIKATZ_DEFAULT_LOG	MIMIKATZ L".log"
#define MIMIKATZ_DRIVER			L"mimidrv"
#define MIMIKATZ_KERBEROS_EXT	L"kirbi"
#define MIMIKATZ_SERVICE		MIMIKATZ L"svc"

#define _exception_code() 0

#if defined(_WINDLL)
	#define MIMIKATZ_AUTO_COMMAND_START		0
#else
	#define MIMIKATZ_AUTO_COMMAND_START		1
#endif

#if defined(_POWERKATZ)
	#define MIMIKATZ_AUTO_COMMAND_STRING	L"powershell"
#else
	#define MIMIKATZ_AUTO_COMMAND_STRING	L"commandline"
#endif

#if !defined(NT_SUCCESS)
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

#if !defined(PRINT_ERROR)
#define PRINT_ERROR(...) (kprintf(L"ERROR " TEXT(__FUNCTION__) L" ; " __VA_ARGS__))
#endif

#if !defined(PRINT_ERROR_AUTO)
#define PRINT_ERROR_AUTO(func) (kprintf(L"ERROR " TEXT(__FUNCTION__) L" ; " func L" (0x%08x)\n", GetLastError()))
#endif

#if !defined(W00T)
#define W00T(...) (kprintf(TEXT(__FUNCTION__) L" w00t! ; " __VA_ARGS__))
#endif

DWORD MIMIKATZ_NT_MAJOR_VERSION, MIMIKATZ_NT_MINOR_VERSION, MIMIKATZ_NT_BUILD_NUMBER;

#if !defined(MS_ENH_RSA_AES_PROV_XP)
#define MS_ENH_RSA_AES_PROV_XP	L"Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"
#endif

#if !defined(SCARD_PROVIDER_CARD_MODULE)
#define SCARD_PROVIDER_CARD_MODULE 0x80000001
#endif

#define RtlEqualGuid(L1, L2) (RtlEqualMemory(L1, L2, sizeof(GUID)))

#define SIZE_ALIGN(size, alignment)	(size + ((size % alignment) ? (alignment - (size % alignment)) : 0))
#define KIWI_NEVERTIME(filetime)	(*(PLONGLONG) filetime = MAXLONGLONG)

#define LM_NTLM_HASH_LENGTH	16

#define KULL_M_WIN_BUILD_XP		2600
#define KULL_M_WIN_BUILD_2K3	3790
#define KULL_M_WIN_BUILD_VISTA	6000
#define KULL_M_WIN_BUILD_7		7600
#define KULL_M_WIN_BUILD_8		9200
#define KULL_M_WIN_BUILD_BLUE	9600
#define KULL_M_WIN_BUILD_10_1507	10240
#define KULL_M_WIN_BUILD_10_1511	10586
#define KULL_M_WIN_BUILD_10_1607	14393
#define KULL_M_WIN_BUILD_10_1703	15063
#define KULL_M_WIN_BUILD_10_1709	16299
#define KULL_M_WIN_BUILD_10_1803	17134
#define KULL_M_WIN_BUILD_10_1809	17763
#define KULL_M_WIN_BUILD_10_1903	18362


#define KULL_M_WIN_MIN_BUILD_XP		2500
#define KULL_M_WIN_MIN_BUILD_2K3	3000
#define KULL_M_WIN_MIN_BUILD_VISTA	5000
#define KULL_M_WIN_MIN_BUILD_7		7000
#define KULL_M_WIN_MIN_BUILD_8		8000
#define KULL_M_WIN_MIN_BUILD_BLUE	9400
#define KULL_M_WIN_MIN_BUILD_10		9800
