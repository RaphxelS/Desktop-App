#ifndef UNINSTALLER_H
#define UNINSTALLER_H

#include <ShObjIdl.h>
#include "ShlGuid.h"
#include "strsafe.h"
#include "objbase.h"
#include <CommCtrl.h>
#include <algorithm>  
#include <direct.h>
#include <ShlObj.h>
#include "Shlwapi.h"
#include <securitybaseapi.h>
#include <thread>        
#include "../Utils/services.h"
#include "../Utils/applicationinfo.h"
#include "../Utils/registry.h"
#include "../Utils/redirection.h"
#include "../Utils/path.h"
#include "../Utils/directory.h"
#include "../Utils/directories_of_a_windows.h"
#include "../Utils/process1.h"
#include "../Utils/remove_directory.h"
#include "../Utils/paths_to_folders.h"

typedef  HRESULT(WINAPI*  P_SHCreateItemFromParsingName)(
    PCWSTR   pszPath,
    IBindCtx *pbc,
    REFIID   riid,
    void     **ppv
  );


class Uninstaller
{
 private:
    //static InstallMode install_mode;
    static Services services;
    static RemoveDirectory1 remove_directory;
    static Path path;
    static Redirection redirection;

    bool IsAdmin,IsPowerUserOrAdmin;

    //static WNDPROC OldWindowProc;
    static const int  WM_KillFirstPhase;
    static DWORD UninstallExitCode;
    static LRESULT FirstPhaseWindowProc(HWND Wnd, UINT Msg,WPARAM wParam, LPARAM lParam);

    static void ProcessDirsNotRemoved();

    static std::list<std::wstring> DirsNotRemoved;

    static bool DeleteDirProc(const bool DisableFsRedir, const std::wstring DirName);
    static bool DeleteFileProc(const bool DisableFsRedir, const std::wstring FileName);


    static void DelayDeleteFile(const bool DisableFsRedir, const std::wstring Filename,
    const unsigned int MaxTries, const unsigned int FirstRetryDelayMS, const unsigned int SubsequentRetryDelayMS);


    static void DeleteUninstallDataFiles();

    typedef void (*P_DeleteUninstallDataFilesProc)();
    static bool PerformUninstall(const P_DeleteUninstallDataFilesProc DeleteUninstallDataFilesProc,const std::wstring &path_for_installation);

    static bool InitializeUninstall();

    static bool UnpinShellLink(const std::wstring Filename);

    static bool ProcessMsgs();

    static std::wstring UninstExeFile;
	static bool isSilent_;

    static P_SHCreateItemFromParsingName SHCreateItemFromParsingNameFunc;

 public:
    void setUninstExeFile(const std::wstring &exe_file, bool bFirstPhase);
	void setSilent(bool isSilent);
    static void RunSecondPhase();
    Uninstaller();
    ~Uninstaller();
};

#endif // UNINSTALLER_H
