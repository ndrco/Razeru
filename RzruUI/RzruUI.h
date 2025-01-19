// RzruUI.h: Main header file for the RzruUI DLL library
//
// This file contains declarations and definitions necessary for the RzruUI
// dynamic-link library (DLL), including global variables and exported functions.

#pragma once // Ensures the header file is included only once during compilation

// Ensure that the MFC core and standard components are included before this file
#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"			// Contains resource definitions (e.g., dialog IDs, string IDs)	
#include "../ChromaPlaying.h"	// Includes the ChromaPlaying library for handling Chroma configurations
#include "CTAB1.h"
#include "CTAB2.h"
#include "CTAB3.h"
#include "CTAB4.h"

#pragma comment(lib, "gdiplus.lib")

using namespace Gdiplus;

// Define the number of tabs in the configuration dialog
#define PAGE_NUMBERS_IN_TAB 4
#define WM_TAB_UPDATE (WM_USER + 101) // Пользовательское сообщение для обновления вкладок

// Alias for the nlohmann::json library to simplify JSON handling
using json = nlohmann::json;

// Global Constants and Variables
static const char* CONFIG_FILE = "Razeru.json"; // Path to the configuration file used by the DLL
static const char* APP_NAME = "Razeru NDR Co"; // App name
static bool g_waitForResponse = false; // Flag indicating whether the DLL is waiting for a response from the calling program
static HANDLE g_responseEvent = nullptr; // Handle to a Windows event object used for synchronization (e.g., signaling when a response is ready)
static HWND g_notifyWindow{ nullptr }; // Handle to the window that will receive notifications about configuration changes
static UINT WM_CHANGED{ 0 }; // Custom Windows message identifier for notifying to the the calling program about configuration changes
extern std::unique_ptr<ChromaPlaying::ConfigData> localData; // Pointer to hold the local configuration data loaded from or saved to the configuration file
extern BOOL isInStartup;


// Declaration of exported functions

/**
 * @brief Initializes the DLL with the parent window handle and the message ID for configuration changes.
 *
 * @param parent Handle to the parent window.
 * @param configChangedMessage The message ID to be sent when the configuration changes.
 */
extern "C" __declspec(dllexport) void InitializeDLL(HWND parent, UINT configChangedMessage);

/**
 * @brief Displays the configuration window to the user.
 */
extern "C" __declspec(dllexport) void ShowConfigWindow();

/**
 * @brief Loads the configuration settings from the configuration file.
 *
 * @return true if the configuration was loaded successfully, false otherwise.
 * 
 * You need call SetConfiguration() before.
 */
extern "C" __declspec(dllexport) bool LoadConfiguration();

/**
 * @brief Saves the current configuration settings to the configuration file.
 *
 * @return true if the configuration was saved successfully, false otherwise.
 * 
 * You can get loaded data by GetConfiguration() after.
 */
extern "C" __declspec(dllexport) bool SaveConfiguration();

/**
 * @brief Retrieves a pointer to the current configuration data.
 *
 * @return Pointer to the current ChromaPlaying::ConfigData structure.
 * 
 * You need call SetConfiguration() before.
 */
extern "C" __declspec(dllexport) ChromaPlaying::ConfigData* GetConfiguration();

/**
 * @brief Sets the current configuration data with the provided configuration data.
 *
 * @param configData Pointer to a ChromaPlaying::ConfigData structure containing configuration data.
 */
extern "C" __declspec(dllexport) void SetConfiguration(ChromaPlaying::ConfigData* configData);

/**
 * @brief Signal confirming that changes have been accepted by the calling program
 * after configChangedMessage was received.
 */
extern "C" __declspec(dllexport) void SignalResponseReady();

// Retrieves the full path to the executable file
std::string SetExecutableFile();
// Retrieves the directory path of the executable
std::string SetExecutablePath();


// CRzruUIApp
class CRzruUIApp : public CWinApp {
public:
	CRzruUIApp();
	~CRzruUIApp();
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	DECLARE_MESSAGE_MAP()
};


//CConfigDialog
class CConfigDialog : public CDialogEx {
public:
	// Construction
	CConfigDialog(CWnd* pParent = nullptr);
	//Destructor
	virtual ~CConfigDialog();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONFIG_DIALOG };
#endif
	void SendUpdateMessage();

protected:

	HICON m_hIcon;
	CDialog* m_tabPages[PAGE_NUMBERS_IN_TAB]{ nullptr }; // Pointers to tab pages
	CTabCtrl* pTabCtrl; // Pointer to tab control
	std::unique_ptr<ChromaPlaying::ConfigData> backupLocalData;
	
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnInitDialog();
	void AddToStartup();
	BOOL IsInStartup();
	void UpdateAllTabs();
	
	afx_msg void OnTcnSelchangeTabControl(NMHDR* pNMHDR, LRESULT* pResult); // Tab switch handler
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedApply();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedLoad();
	afx_msg void AddTab(int tabIndex, CDialogEx* pDlg, UINT dlgResID, UINT strResID);

	DECLARE_MESSAGE_MAP()
};





