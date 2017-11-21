#include <iostream>
#include <windows.h>
using namespace std;


int main() {
    SYSTEM_INFO siSysInfo;
    // Copy the hardware information to the SYSTEM_INFO structure.
    GetSystemInfo(&siSysInfo);
    cout << "Hello, World!" << endl;
    // Display the contents of the SYSTEM_INFO structure.
    printf("Hardware information: \n");
    printf("  OEM ID: %u\n", siSysInfo.dwOemId);
    printf("  Number of processors: %u\n",
           siSysInfo.dwNumberOfProcessors);
    printf("  Page size: %u\n", siSysInfo.dwPageSize);
    printf("  Processor type: %u\n", siSysInfo.dwProcessorType);
    printf("  Minimum application address: %lx\n",
           siSysInfo.lpMinimumApplicationAddress);
    printf("  Maximum application address: %lx\n",
           siSysInfo.lpMaximumApplicationAddress);
    printf("  Active processor mask: %u\n",
           siSysInfo.dwActiveProcessorMask);
    HW_PROFILE_INFO   HwProfInfo;
    if (!GetCurrentHwProfile(&HwProfInfo))
    {
        printf(TEXT("GetCurrentHwProfile failed with error %lx\n"),
                 GetLastError());
    }
    printf(TEXT("DockInfo = %d\n"), HwProfInfo.dwDockInfo);
    printf(TEXT("Profile Guid = %s\n"), HwProfInfo.szHwProfileGuid);
    printf(TEXT("Friendly Name = %s\n"), HwProfInfo.szHwProfileName);
    return 0;
}