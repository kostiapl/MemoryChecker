#pragma once

class ProcessEntry
{
public:
	ProcessEntry(DWORD dwSize, DWORD cntUsage, DWORD th32ProcessID, ULONG_PTR th32DefaultHeapID,
		DWORD th32ModuleID, DWORD cntThreads, DWORD th32ParentProcessID, DWORD pcPriClassBase, DWORD dwFlags,
		wchar_t* exeFile
	);

private:

	DWORD     _dwSize;
	DWORD     _cntUsage;
	DWORD     _th32ProcessID;
	ULONG_PTR _th32DefaultHeapID;
	DWORD     _th32ModuleID;
	DWORD     _cntThreads;
	DWORD     _th32ParentProcessID;
	LONG      _pcPriClassBase;
	DWORD     _dwFlags;
	std::wstring _exeFile;
	
	
};
