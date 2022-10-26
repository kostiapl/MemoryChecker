#include "precomp.h"

#include "WinNtDll.h"


// _NtDll is a wil::unique_hmodule which we initialize through constructor as it doesn't have
// copy assignment operator
WinNtDll::WinNtDll()
{
	_hNtDll = LoadLibraryExW(L"ntdll.dll", 
		nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);

	
}

//[[nodiscard]] HANDLE s_NtCurrentProcess()
//{
	
//}

[[nodiscard]] NTSTATUS WinNtDll::s_NtOpenThread(PHANDLE ThreadHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID ClientId)
{
    HMODULE hNtDll = _Instance()._hNtDll;

    if (hNtDll != nullptr)
    {
        typedef NTSTATUS(*PfnNtOpenThread)(PHANDLE ThreadHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID ClientId);

        static PfnNtOpenThread pfn = (PfnNtOpenThread)GetProcAddress(hNtDll, "NtOpenThread");

        if (pfn != nullptr)
        {
            return pfn(ThreadHandle, DesiredAccess, ObjectAttributes, ClientId);
        }
    }

    return STATUS_UNSUCCESSFUL;

}


[[nodiscard]] NTSTATUS WinNtDll::s_GetProcessParentId(_Inout_ PULONG ProcessId)
{
    
    OBJECT_ATTRIBUTES oa;
    InitializeObjectAttributes(&oa, nullptr, 0, nullptr, nullptr);

    CLIENT_ID ClientId;
    ClientId.UniqueProcess = UlongToHandle(*ProcessId);
    ClientId.UniqueThread = nullptr;

    HANDLE ProcessHandle;
    NTSTATUS Status = s_NtOpenProcess(&ProcessHandle, PROCESS_QUERY_LIMITED_INFORMATION, &oa, &ClientId);

    PROCESS_BASIC_INFORMATION BasicInfo = { 0 };
    if (NT_SUCCESS(Status))
    {
        Status = s_NtQueryInformationProcess(ProcessHandle, 
            ProcessBasicInformation, &BasicInfo, 
            sizeof(BasicInfo), nullptr);
        LOG_IF_FAILED(s_NtClose(ProcessHandle));
    }

    if (!NT_SUCCESS(Status))
    {
        *ProcessId = 0;
        return Status;
    }

    // This is the actual field name, but in the public SDK, it's named Reserved3. We need to pursue publishing the real name.
    //*ProcessId = (ULONG)BasicInfo.InheritedFromUniqueProcessId;
    *ProcessId = (ULONG)BasicInfo.Reserved3;
    return STATUS_SUCCESS;
}



[[nodiscard]] NTSTATUS WinNtDll::s_NtOpenProcess(_Out_ PHANDLE ProcessHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_opt_ PCLIENT_ID ClientId)
{

	HMODULE hNtDll = _Instance()._hNtDll;

	if (hNtDll != nullptr)
	{
		typedef NTSTATUS(*PfnNtOpenProcess)(HANDLE ProcessHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID ClientId);

		static PfnNtOpenProcess pfn = (PfnNtOpenProcess)GetProcAddress(hNtDll, "NtOpenProcess");

		if (pfn != nullptr)
		{
			return pfn(ProcessHandle, DesiredAccess, ObjectAttributes, ClientId);
		}
	}

	return STATUS_UNSUCCESSFUL;
}


[[nodiscard]] NTSTATUS WinNtDll::s_NtQueryInformationProcess(_In_ HANDLE ProcessHandle,
    _In_ PROCESSINFOCLASS ProcessInformationClass,
    _Out_ PVOID ProcessInformation,
    _In_ ULONG ProcessInformationLength,
    _Out_opt_ PULONG ReturnLength)
{
    HMODULE hNtDll = _Instance()._hNtDll;

    if (hNtDll != nullptr)
    {
        typedef NTSTATUS(*PfnNtQueryInformationProcess)(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength);

        static PfnNtQueryInformationProcess pfn = (PfnNtQueryInformationProcess)GetProcAddress(hNtDll, "NtQueryInformationProcess");

        if (pfn != nullptr)
        {
            return pfn(ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength, ReturnLength);
        }
    }

    return STATUS_UNSUCCESSFUL;
}

[[nodiscard]] NTSTATUS WinNtDll::s_NtClose(_In_ HANDLE Handle)
{
    HMODULE hNtDll = _Instance()._hNtDll;

    if (hNtDll != nullptr)
    {
        typedef NTSTATUS(*PfnNtClose)(HANDLE Handle);

        static PfnNtClose pfn = (PfnNtClose)GetProcAddress(hNtDll, "NtClose");

        if (pfn != nullptr)
        {
            return pfn(Handle);
        }
    }

    return STATUS_UNSUCCESSFUL;
}



WinNtDll::~WinNtDll()
{
	if (_hNtDll!=nullptr)
	{
		FreeLibrary(_hNtDll);
		_hNtDll = nullptr;
	}
}


WinNtDll& WinNtDll::_Instance()
{
	// C++ 11 and above thread safe singleton pattern realization
	static WinNtDll winNtDll;
	return winNtDll;
}

