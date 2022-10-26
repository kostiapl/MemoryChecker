


// below are different NT structure definitions

extern "C" {


    typedef struct _CLIENT_ID
    {
        HANDLE UniqueProcess;
        HANDLE UniqueThread;
    } CLIENT_ID;
    typedef CLIENT_ID* PCLIENT_ID;

    // Unicode strings are counted 16-bit character strings. If they are
// NULL terminated, Length does not include trailing NULL.
//

    typedef struct _UNICODE_STRING
    {
        USHORT Length;
        USHORT MaximumLength;
#ifdef MIDL_PASS
        [size_is(MaximumLength / 2), length_is((Length) / 2)] USHORT* Buffer;
#else // MIDL_PASS
        _Field_size_bytes_part_(MaximumLength, Length) PWCH Buffer;
#endif // MIDL_PASS
    } UNICODE_STRING;
    typedef UNICODE_STRING* PUNICODE_STRING;
    typedef const UNICODE_STRING* PCUNICODE_STRING;


	#define OBJ_INHERIT             0x00000002L
	#define OBJ_PERMANENT           0x00000010L
	#define OBJ_EXCLUSIVE           0x00000020L
	#define OBJ_CASE_INSENSITIVE    0x00000040L
	#define OBJ_OPENIF              0x00000080L
	#define OBJ_OPENLINK            0x00000100L
	#define OBJ_KERNEL_HANDLE       0x00000200L
	#define OBJ_FORCE_ACCESS_CHECK  0x00000400L
	#define OBJ_VALID_ATTRIBUTES    0x000007F2L


    typedef struct _OBJECT_ATTRIBUTES
    {
        ULONG Length;
        HANDLE RootDirectory;
        PUNICODE_STRING ObjectName;
        ULONG Attributes;
        PVOID SecurityDescriptor; // Points to type SECURITY_DESCRIPTOR
        PVOID SecurityQualityOfService; // Points to type SECURITY_QUALITY_OF_SERVICE
    } OBJECT_ATTRIBUTES;
    typedef OBJECT_ATTRIBUTES* POBJECT_ATTRIBUTES;
    typedef CONST OBJECT_ATTRIBUTES* PCOBJECT_ATTRIBUTES;

	#define InitializeObjectAttributes(p, n, a, r, s) \
    {                                             \
        (p)->Length = sizeof(OBJECT_ATTRIBUTES);  \
        (p)->RootDirectory = r;                   \
        (p)->Attributes = a;                      \
        (p)->ObjectName = n;                      \
        (p)->SecurityDescriptor = s;              \
        (p)->SecurityQualityOfService = NULL;     \
    }


    typedef struct _PROCESS_BASIC_INFORMATION
    {
        PVOID Reserved1;
        PVOID PebBaseAddress;
        PVOID Reserved2[2];
        ULONG_PTR UniqueProcessId;
        ULONG_PTR Reserved3;
    } PROCESS_BASIC_INFORMATION;
    typedef PROCESS_BASIC_INFORMATION* PPROCESS_BASIC_INFORMATION;

	

    // borrowed from processhacker project
    typedef enum _PROCESSINFOCLASS
    {
        ProcessBasicInformation, // q: PROCESS_BASIC_INFORMATION, PROCESS_EXTENDED_BASIC_INFORMATION
        ProcessQuotaLimits, // qs: QUOTA_LIMITS, QUOTA_LIMITS_EX
        ProcessIoCounters, // q: IO_COUNTERS
        ProcessVmCounters, // q: VM_COUNTERS, VM_COUNTERS_EX, VM_COUNTERS_EX2
        ProcessTimes, // q: KERNEL_USER_TIMES
        ProcessBasePriority, // s: KPRIORITY
        ProcessRaisePriority, // s: ULONG
        ProcessDebugPort, // q: HANDLE
        ProcessExceptionPort, // s: PROCESS_EXCEPTION_PORT
        ProcessAccessToken, // s: PROCESS_ACCESS_TOKEN
        ProcessLdtInformation, // qs: PROCESS_LDT_INFORMATION // 10
        ProcessLdtSize, // s: PROCESS_LDT_SIZE
        ProcessDefaultHardErrorMode, // qs: ULONG
        ProcessIoPortHandlers, // (kernel-mode only) // PROCESS_IO_PORT_HANDLER_INFORMATION
        ProcessPooledUsageAndLimits, // q: POOLED_USAGE_AND_LIMITS
        ProcessWorkingSetWatch, // q: PROCESS_WS_WATCH_INFORMATION[]; s: void
        ProcessUserModeIOPL, // qs: ULONG (requires SeTcbPrivilege)
        ProcessEnableAlignmentFaultFixup, // s: BOOLEAN
        ProcessPriorityClass, // qs: PROCESS_PRIORITY_CLASS
        ProcessWx86Information, // qs: ULONG (requires SeTcbPrivilege) (VdmAllowed)
        ProcessHandleCount, // q: ULONG, PROCESS_HANDLE_INFORMATION // 20
        ProcessAffinityMask, // s: KAFFINITY
        ProcessPriorityBoost, // qs: ULONG
        ProcessDeviceMap, // qs: PROCESS_DEVICEMAP_INFORMATION, PROCESS_DEVICEMAP_INFORMATION_EX
        ProcessSessionInformation, // q: PROCESS_SESSION_INFORMATION
        ProcessForegroundInformation, // s: PROCESS_FOREGROUND_BACKGROUND
        ProcessWow64Information, // q: ULONG_PTR
        ProcessImageFileName, // q: UNICODE_STRING
        ProcessLUIDDeviceMapsEnabled, // q: ULONG
        ProcessBreakOnTermination, // qs: ULONG
        ProcessDebugObjectHandle, // q: HANDLE // 30
        ProcessDebugFlags, // qs: ULONG
        ProcessHandleTracing, // q: PROCESS_HANDLE_TRACING_QUERY; s: size 0 disables, otherwise enables
        ProcessIoPriority, // qs: IO_PRIORITY_HINT
        ProcessExecuteFlags, // qs: ULONG
        ProcessResourceManagement, // ProcessTlsInformation // PROCESS_TLS_INFORMATION
        ProcessCookie, // q: ULONG
        ProcessImageInformation, // q: SECTION_IMAGE_INFORMATION
        ProcessCycleTime, // q: PROCESS_CYCLE_TIME_INFORMATION // since VISTA
        ProcessPagePriority, // q: PAGE_PRIORITY_INFORMATION
        ProcessInstrumentationCallback, // qs: PROCESS_INSTRUMENTATION_CALLBACK_INFORMATION // 40
        ProcessThreadStackAllocation, // s: PROCESS_STACK_ALLOCATION_INFORMATION, PROCESS_STACK_ALLOCATION_INFORMATION_EX
        ProcessWorkingSetWatchEx, // q: PROCESS_WS_WATCH_INFORMATION_EX[]
        ProcessImageFileNameWin32, // q: UNICODE_STRING
        ProcessImageFileMapping, // q: HANDLE (input)
        ProcessAffinityUpdateMode, // qs: PROCESS_AFFINITY_UPDATE_MODE
        ProcessMemoryAllocationMode, // qs: PROCESS_MEMORY_ALLOCATION_MODE
        ProcessGroupInformation, // q: USHORT[]
        ProcessTokenVirtualizationEnabled, // s: ULONG
        ProcessConsoleHostProcess, // q: ULONG_PTR // ProcessOwnerInformation
        ProcessWindowInformation, // q: PROCESS_WINDOW_INFORMATION // 50
        ProcessHandleInformation, // q: PROCESS_HANDLE_SNAPSHOT_INFORMATION // since WIN8
        ProcessMitigationPolicy, // s: PROCESS_MITIGATION_POLICY_INFORMATION
        ProcessDynamicFunctionTableInformation,
        ProcessHandleCheckingMode, // qs: ULONG; s: 0 disables, otherwise enables
        ProcessKeepAliveCount, // q: PROCESS_KEEPALIVE_COUNT_INFORMATION
        ProcessRevokeFileHandles, // s: PROCESS_REVOKE_FILE_HANDLES_INFORMATION
        ProcessWorkingSetControl, // s: PROCESS_WORKING_SET_CONTROL
        ProcessHandleTable, // q: ULONG[] // since WINBLUE
        ProcessCheckStackExtentsMode,
        ProcessCommandLineInformation, // q: UNICODE_STRING // 60
        ProcessProtectionInformation, // q: PS_PROTECTION
        ProcessMemoryExhaustion, // PROCESS_MEMORY_EXHAUSTION_INFO // since THRESHOLD
        ProcessFaultInformation, // PROCESS_FAULT_INFORMATION
        ProcessTelemetryIdInformation, // PROCESS_TELEMETRY_ID_INFORMATION
        ProcessCommitReleaseInformation, // PROCESS_COMMIT_RELEASE_INFORMATION
        ProcessDefaultCpuSetsInformation,
        ProcessAllowedCpuSetsInformation,
        ProcessSubsystemProcess,
        ProcessJobMemoryInformation, // PROCESS_JOB_MEMORY_INFO
        ProcessInPrivate, // since THRESHOLD2 // 70
        ProcessRaiseUMExceptionOnInvalidHandleClose, // qs: ULONG; s: 0 disables, otherwise enables
        ProcessIumChallengeResponse,
        ProcessChildProcessInformation, // PROCESS_CHILD_PROCESS_INFORMATION
        ProcessHighGraphicsPriorityInformation,
        ProcessSubsystemInformation, // q: SUBSYSTEM_INFORMATION_TYPE // since REDSTONE2
        ProcessEnergyValues, // PROCESS_ENERGY_VALUES, PROCESS_EXTENDED_ENERGY_VALUES
        ProcessActivityThrottleState, // PROCESS_ACTIVITY_THROTTLE_STATE
        ProcessActivityThrottlePolicy, // PROCESS_ACTIVITY_THROTTLE_POLICY
        ProcessWin32kSyscallFilterInformation,
        ProcessDisableSystemAllowedCpuSets, // 80
        ProcessWakeInformation, // PROCESS_WAKE_INFORMATION
        ProcessEnergyTrackingState, // PROCESS_ENERGY_TRACKING_STATE
        ProcessManageWritesToExecutableMemory, // MANAGE_WRITES_TO_EXECUTABLE_MEMORY // since REDSTONE3
        ProcessCaptureTrustletLiveDump,
        ProcessTelemetryCoverage,
        ProcessEnclaveInformation,
        ProcessEnableReadWriteVmLogging, // PROCESS_READWRITEVM_LOGGING_INFORMATION
        ProcessUptimeInformation, // PROCESS_UPTIME_INFORMATION
        ProcessImageSection, // q: HANDLE
        ProcessDebugAuthInformation, // since REDSTONE4 // 90
        ProcessSystemResourceManagement, // PROCESS_SYSTEM_RESOURCE_MANAGEMENT
        ProcessSequenceNumber, // q: ULONGLONG
        ProcessLoaderDetour, // since REDSTONE5
        ProcessSecurityDomainInformation, // PROCESS_SECURITY_DOMAIN_INFORMATION
        ProcessCombineSecurityDomainsInformation, // PROCESS_COMBINE_SECURITY_DOMAINS_INFORMATION
        ProcessEnableLogging, // PROCESS_LOGGING_INFORMATION
        ProcessLeapSecondInformation, // PROCESS_LEAP_SECOND_INFORMATION
        ProcessFiberShadowStackAllocation, // PROCESS_FIBER_SHADOW_STACK_ALLOCATION_INFORMATION // since 19H1
        ProcessFreeFiberShadowStackAllocation, // PROCESS_FREE_FIBER_SHADOW_STACK_ALLOCATION_INFORMATION
        ProcessAltSystemCallInformation, // qs: BOOLEAN (kernel-mode only) // since 20H1 // 100
        ProcessDynamicEHContinuationTargets, // PROCESS_DYNAMIC_EH_CONTINUATION_TARGETS_INFORMATION
        ProcessDynamicEnforcedCetCompatibleRanges, // PROCESS_DYNAMIC_ENFORCED_ADDRESS_RANGE_INFORMATION // since 20H2
        MaxProcessInfoClass
    } PROCESSINFOCLASS;


}
	
class WinNtDll
{
public:

    [[nodiscard]] static HANDLE s_NtCurrentProcess();


    [[nodiscard]] static NTSTATUS s_NtOpenThread(PHANDLE ThreadHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID ClientId);
	

	
	[[nodiscard]] static NTSTATUS s_GetProcessParentId(_Inout_ PULONG ProcessId);
	
	[[nodiscard]] static NTSTATUS NtQueryInformationProcess(
        HANDLE           ProcessHandle,
        PROCESSINFOCLASS ProcessInformationClass,
        PVOID            ProcessInformation,
        ULONG            ProcessInformationLength,
        PULONG           ReturnLength
    );

    [[nodiscard]] static NTSTATUS s_NtOpenProcess(_Out_ PHANDLE ProcessHandle,
        _In_ ACCESS_MASK DesiredAccess,
        _In_ POBJECT_ATTRIBUTES ObjectAttributes,
        _In_opt_ PCLIENT_ID ClientId);

    [[nodiscard]] static NTSTATUS s_NtQueryInformationProcess(_In_ HANDLE ProcessHandle,
        _In_ PROCESSINFOCLASS ProcessInformationClass,
        _Out_ PVOID ProcessInformation,
        _In_ ULONG ProcessInformationLength,
        _Out_opt_ PULONG ReturnLength);

    [[nodiscard]] static NTSTATUS s_NtClose(_In_ HANDLE Handle);


    ~WinNtDll();

private:
    WinNtDll();
    //WinNtDll(WinNtDll const&) = delete;
    //void operator= (WinNtDll const&) = delete;

    static WinNtDll& _Instance();


    // we use HMODULE instead of wil::unique_hmodule to simplify code reading
	// we could use constructor initializer list and could make _hNtDll constant but code
	// then become hard to read
	
	
    HMODULE _hNtDll = nullptr;
	

};


