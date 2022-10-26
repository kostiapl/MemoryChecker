#include "precomp.h"
#include "ProcessEntry.h"
#include "ProcessInfo.h"
#include "ThreadEntry.h"




ProcessInfo::ProcessInfo():hProcessesSnapshot(nullptr), hThreadsSnaphost(nullptr)
{
	hProcessesSnapshot = WinKernel32Dll::s_CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	//hThreadsSnaphost = WinKernel32Dll::s_CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

}

void ProcessInfo::EnumerateProcesses()
{
	PROCESSENTRY32W processEntry32W;
	ZeroMemory(&processEntry32W, 0);
	processEntry32W.dwSize = sizeof(PROCESSENTRY32W);


	// enumerate all processes
	auto nextProcess = WinKernel32Dll::s_Process32FirstW(hProcessesSnapshot, &processEntry32W);

	while (nextProcess)
	{

		ProcessEntry processEntry(
			processEntry32W.dwSize,
			processEntry32W.cntUsage,
			processEntry32W.th32ProcessID,
			processEntry32W.th32DefaultHeapID,
			processEntry32W.th32ModuleID,
			processEntry32W.cntThreads,
			processEntry32W.th32ParentProcessID,
			processEntry32W.pcPriClassBase,
			processEntry32W.dwFlags,
			processEntry32W.szExeFile
		
		);

		_processesList.push_back(std::move(processEntry));


		// get info about next process
		processEntry32W.dwSize = sizeof(PROCESSENTRY32W);
		nextProcess = WinKernel32Dll::s_Process32NextW(hProcessesSnapshot, &processEntry32W);
	}
}





ProcessInfo::~ProcessInfo()
{
	if (hProcessesSnapshot != nullptr)
	{
		CloseHandle(hProcessesSnapshot);
	}

	if (hThreadsSnaphost != nullptr)
	{
		CloseHandle(hThreadsSnaphost);
	}


}

void ProcessInfo::EnumerateThreads()
{
	// enumerate all threads

	THREADENTRY32 threadentry32;
	
	ZeroMemory(&threadentry32, 0);
	threadentry32.dwSize = sizeof(threadentry32);

	auto nextThread = WinKernel32Dll::s_Thread32First(hProcessesSnapshot, &threadentry32);

	while (nextThread)
	{

		ThreadEntry threadEntry(
			threadentry32.dwSize,
			threadentry32.cntUsage,
			threadentry32.th32ThreadID,
			threadentry32.th32OwnerProcessID,
			threadentry32.tpBasePri,
			threadentry32.tpDeltaPri,
			threadentry32.dwFlags
		);

		
		_threadsList.push_back(std::move(threadEntry));
		
		ZeroMemory(&threadentry32, 0);
		threadentry32.dwSize = sizeof(threadentry32);

		auto nextThread = WinKernel32Dll::s_Thread32Next(hProcessesSnapshot, &threadentry32);

	}
	


	
}
