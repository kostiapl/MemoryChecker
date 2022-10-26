#include "precomp.h"
#include "ThreadEntry.h"


ThreadEntry::ThreadEntry(DWORD dwSize,DWORD cntUsage,DWORD th32ThreadID,
	DWORD th32OwnerProcessID,LONG  tpBasePri,LONG  tpDeltaPri,DWORD dwFlags)
{

	_dwSize = dwSize;
	_cntUsage = cntUsage;
	_th32ThreadID = th32ThreadID;
	_th32OwnerProcessID = th32OwnerProcessID;
	_tpBasePri = tpBasePri;
	_tpDeltaPri = tpDeltaPri;
	_dwFlags = dwFlags;
	
}
