#include "precomp.h"
#include "WinKernel32Dll.h"


WinKernel32Dll::WinKernel32Dll():_hKernel32Dll(nullptr)
{
	_hKernel32Dll = LoadLibraryExW(L"kernel32.dll",
		nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);

	
}

WinKernel32Dll::~WinKernel32Dll()
{
	if (nullptr!=_hKernel32Dll)
	{
		FreeLibrary(_hKernel32Dll);
		_hKernel32Dll = nullptr;
		
	}
}

[[nodiscard]] HANDLE WinKernel32Dll::s_OpenProcess(DWORD dwDesiredAccess, BOOL  bInheritHandle, DWORD dwProcessId)
{
	HMODULE hKernel32Dll = _Instance()._hKernel32Dll;

	if (hKernel32Dll != nullptr)
	{
		typedef HANDLE(*PfnOpenProcess)(DWORD dwDesiredAccess, BOOL  bInheritHandle, DWORD dwProcessId);

		static PfnOpenProcess pfn = (PfnOpenProcess)GetProcAddress(hKernel32Dll, "OpenProcess");

		if (pfn != nullptr)
		{
			return pfn(dwDesiredAccess, bInheritHandle, dwProcessId);
		}
		else
		{
			THROW_HR_MSG(HRESULT_FROM_WIN32(GetLastError()), "GetProcAddress -> OpenProcess  error");
		}
	}

	THROW_HR_MSG(HRESULT_FROM_WIN32(GetLastError()), "_Instance()._hKernel32Dll error");

	
}



[[nodiscard]] HANDLE WinKernel32Dll::s_CreateToolhelp32Snapshot(DWORD dwFlags, DWORD th32ProcessID)
{
	HMODULE hKernel32Dll = _Instance()._hKernel32Dll;

	if (hKernel32Dll != nullptr)
	{
		typedef HANDLE(*PfnCreateToolhelp32Snapshot)(DWORD dwFlags, DWORD th32ProcessID);

		static PfnCreateToolhelp32Snapshot pfn = (PfnCreateToolhelp32Snapshot)GetProcAddress(hKernel32Dll, "CreateToolhelp32Snapshot");

		if (pfn != nullptr)
		{
			return pfn(dwFlags, th32ProcessID);
		}
		else
		{
			THROW_HR_MSG(HRESULT_FROM_WIN32(GetLastError()), "GetProcAddress -> CreateToolhelp32Snapshot  error");
		}
	}

	THROW_HR_MSG(HRESULT_FROM_WIN32(GetLastError()), "_Instance()._hKernel32Dll error");
	
}


[[nodiscard]] BOOL WinKernel32Dll::s_Process32FirstW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe)
{
	HMODULE hKernel32Dll = _Instance()._hKernel32Dll;

	if (hKernel32Dll != nullptr)
	{
		typedef BOOL(*PfnProcess32FirstW)(HANDLE hSnapshot, LPPROCESSENTRY32W lppe);

		static PfnProcess32FirstW pfn = (PfnProcess32FirstW)GetProcAddress(hKernel32Dll, "Process32FirstW");
		if (pfn!=nullptr)
		{
			return pfn(hSnapshot, lppe);
		}
		else
		{
			THROW_HR_MSG(
				HRESULT_FROM_WIN32(GetLastError()),
				"GetProcAddress -> Process32FirstW");
		}

	}

	THROW_HR_MSG( HRESULT_FROM_WIN32(GetLastError()), "_Instance()._hKernel32Dll error");


}

[[nodiscard]] BOOL WinKernel32Dll::s_Process32NextW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe)
{
	HMODULE hKernel32Dll = _Instance()._hKernel32Dll;

	if (hKernel32Dll != nullptr)
	{
		typedef BOOL(*PfnProcess32NextW)(HANDLE hSnapshot, LPPROCESSENTRY32W lppe);

		static PfnProcess32NextW pfn = (PfnProcess32NextW)GetProcAddress(hKernel32Dll, "Process32NextW");
		if (pfn != nullptr)
		{
			return pfn(hSnapshot, lppe);
		}
		else
		{
			THROW_HR_MSG(
				HRESULT_FROM_WIN32(GetLastError()),
				"GetProcAddress -> Process32NextW");
		}

	}

	THROW_HR_MSG(HRESULT_FROM_WIN32(GetLastError()), "_Instance()._hKernel32Dll error");
	
}


[[nodiscard]] HANDLE WinKernel32Dll::s_OpenThread(
	DWORD dwDesiredAccess,
	BOOL  bInheritHandle,
	DWORD dwThreadId
)
{
	HMODULE hKernel32Dll = _Instance()._hKernel32Dll;

	if (hKernel32Dll != nullptr)
	{
		typedef HANDLE(*PfnOpenThread)(DWORD dwDesiredAccess,BOOL  bInheritHandle,DWORD dwThreadId);

		static PfnOpenThread pfn = (PfnOpenThread)GetProcAddress(hKernel32Dll, "OpenThread");

		if (pfn != nullptr)
		{
			return pfn(dwDesiredAccess, bInheritHandle, dwThreadId);
		}
		else
		{
			THROW_HR_MSG(HRESULT_FROM_WIN32(GetLastError()), "GetProcAddress -> OpenThread error");
		}
	}

	THROW_HR_MSG(HRESULT_FROM_WIN32(GetLastError()), "_Instance()._hKernel32Dll error");
}


[[nodiscard]]  BOOL WinKernel32Dll::s_Thread32First(HANDLE hSnapshot, LPTHREADENTRY32 lpte)
{
	HMODULE hKernel32Dll = _Instance()._hKernel32Dll;

	if (hKernel32Dll != nullptr)
	{
		typedef BOOL(*PfnThread32First)(HANDLE hSnapshot, LPTHREADENTRY32 lpte);

		static PfnThread32First pfn = (PfnThread32First)GetProcAddress(hKernel32Dll, "Thread32First");

		if (pfn != nullptr)
		{
			return pfn(hSnapshot,lpte);
		}
		else
		{
			THROW_HR_MSG(HRESULT_FROM_WIN32(GetLastError()), "GetProcAddress -> Thread32First error");
		}
	}

	THROW_HR_MSG(HRESULT_FROM_WIN32(GetLastError()), "_Instance()._hKernel32Dll error");
}

[[nodiscard]] BOOL WinKernel32Dll::s_Thread32Next(HANDLE hSnapshot, LPTHREADENTRY32 lpte)
{
	HMODULE hKernel32Dll = _Instance()._hKernel32Dll;

	if (hKernel32Dll != nullptr)
	{
		typedef BOOL(*PfnThread32Next)(HANDLE hSnapshot, LPTHREADENTRY32 lpte);

		static PfnThread32Next pfn = (PfnThread32Next)GetProcAddress(hKernel32Dll, "Thread32Next");

		if (pfn != nullptr)
		{
			return pfn(hSnapshot, lpte);
		}
		else
		{
			THROW_HR_MSG(HRESULT_FROM_WIN32(GetLastError()), "GetProcAddress -> Thread32Next error");
		}
	}

	THROW_HR_MSG(HRESULT_FROM_WIN32(GetLastError()), "_Instance()._hKernel32Dll error");
}


WinKernel32Dll& WinKernel32Dll::_Instance()
{
	static WinKernel32Dll instance;

	return instance;
}


