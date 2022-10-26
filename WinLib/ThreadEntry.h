#pragma once


class ThreadEntry
{

public:
	ThreadEntry(DWORD dwSize, DWORD cntUsage, DWORD th32ThreadID,
		DWORD th32OwnerProcessID, LONG  tpBasePri, LONG  tpDeltaPri, DWORD dwFlags);


private:
	DWORD _dwSize;
	DWORD _cntUsage;
	DWORD _th32ThreadID;
	DWORD _th32OwnerProcessID;
	LONG  _tpBasePri;
	LONG  _tpDeltaPri;
	DWORD _dwFlags;


};
