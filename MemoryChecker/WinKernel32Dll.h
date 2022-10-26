
#include "precomp.h"



/// <summary>
/// encapsulate Kernel32.dll API with lazy function initialization when they are called
/// </summary>
class WinKernel32Dll
{
public:
	~WinKernel32Dll();


	[[nodiscard]] static HANDLE s_CreateToolhelp32Snapshot(DWORD dwFlags,DWORD th32ProcessID);
	[[nodiscard]] static BOOL s_Process32FirstW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe);
	[[nodiscard]] static BOOL s_Process32NextW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe);
	[[nodiscard]] static HANDLE s_OpenThread(DWORD dwDesiredAccess, BOOL  bInheritHandle, DWORD dwThreadId);
	[[nodiscard]] static HANDLE s_OpenProcess(DWORD dwDesiredAccess,BOOL  bInheritHandle,DWORD dwProcessId);

	[[nodiscard]] static BOOL s_Thread32First(HANDLE hSnapshot, LPTHREADENTRY32 lpte);
	[[nodiscard]] static BOOL s_Thread32Next(HANDLE hSnapshot, LPTHREADENTRY32 lpte);
	
	
	

private:
	WinKernel32Dll();
	
	static WinKernel32Dll& _Instance();

	HMODULE _hKernel32Dll ;
	
	
};
