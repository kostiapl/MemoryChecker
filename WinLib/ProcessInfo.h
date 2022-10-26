#pragma once

#include "WinKernel32Dll.h"
#include "WinNtDll.h"

#include "ProcessEntry.h"
#include "ThreadEntry.h"

// TODO: will include low level API class and wrapp returned C data into C++ types
class ProcessInfo
{
public:
	ProcessInfo();
	void EnumerateProcesses();


	~ProcessInfo();
	void EnumerateThreads();
	// CreateProcessesSnapshot - will enumerate all processes and retrieve all data. Arguments of method may set flags
	// that indicate which data need to be retrieved


	// GetExeNameByPid
	// GetCommandLineByPid
	// 
private:

	std::vector<ProcessEntry> _processesList;
	std::vector<ThreadEntry> _threadsList;

	HANDLE hProcessesSnapshot;
	HANDLE hThreadsSnaphost;


};
