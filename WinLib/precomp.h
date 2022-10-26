#pragma once

#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#endif

#ifndef NOMINAX
#define NOMINAX
#endif

#include "Windows.h"

// remove dependency on the header files that are not compatible with different
// user mode C headers by adding predefined NTSTATUS values
typedef long NTSTATUS;
#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)
#define STATUS_SUCCESS ((DWORD)0x0)
#define STATUS_UNSUCCESSFUL ((DWORD)0xC0000001L)
#define STATUS_SHARING_VIOLATION ((NTSTATUS)0xC0000043L)
#define STATUS_INSUFFICIENT_RESOURCES ((DWORD)0xC000009AL)
#define STATUS_ILLEGAL_FUNCTION ((DWORD)0xC00000AFL)
#define STATUS_PIPE_DISCONNECTED ((DWORD)0xC00000B0L)
#define STATUS_BUFFER_TOO_SMALL ((DWORD)0xC0000023L)
#define STATUS_NOT_FOUND ((NTSTATUS)0xC0000225L)

#include <tlhelp32.h>


#include <intsafe.h>

#include "AdditionalLibraries.h"




