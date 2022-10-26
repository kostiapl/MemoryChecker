
#include "precomp.h"
#include "ProcessEntry.h"


ProcessEntry::ProcessEntry(DWORD dwSize, DWORD cntUsage, DWORD th32ProcessID, ULONG_PTR th32DefaultHeapID,
	DWORD th32ModuleID, DWORD cntThreads, DWORD th32ParentProcessID, DWORD pcPriClassBase, DWORD dwFlags,
	wchar_t* exeFile)

{
	_dwSize = dwSize;
	_cntUsage = cntUsage;
	_th32ProcessID = th32ProcessID;
	_th32DefaultHeapID = th32DefaultHeapID;
	_th32ModuleID = th32ModuleID;
	_cntThreads = cntThreads;
	_th32ParentProcessID = th32ParentProcessID;
	_pcPriClassBase = pcPriClassBase;
	_dwFlags = dwFlags;
	_exeFile = std::wstring(exeFile);
	
}
