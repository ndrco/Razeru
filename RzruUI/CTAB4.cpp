#pragma once
#include "pch.h"
#include "RzruUI.h"
#include "CTAB4.h"

#pragma comment(lib, "gdiplus.lib")

using namespace Gdiplus;



// Dialog box CTAB4
BEGIN_MESSAGE_MAP(CTAB4, CDialogEx)
    ON_CBN_SELCHANGE(IDC_COMBO_LOCAL, &CTAB4::OnCbnSelchangeComboLocal)
    ON_BN_CLICKED(IDC_CHECK_AUTO, &CTAB4::OnBnClickedCheckAutoload)
    ON_WM_CTLCOLOR()
    ON_WM_PAINT()
    ON_MESSAGE(WM_TAB_UPDATE, &CTAB4::OnTabUpdate)
END_MESSAGE_MAP()
IMPLEMENT_DYNAMIC(CTAB4, CDialogEx)


CTAB4::CTAB4(CWnd* pParent /*=nullptr*/) : CDialogEx(IDD_TAB_4, pParent) {
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
}


CTAB4::~CTAB4() {
    GdiplusShutdown(gdiplusToken);
}


void CTAB4::DoDataExchange(CDataExchange* pDX) {
    CDialogEx::DoDataExchange(pDX);
    DDX_Check(pDX, IDC_CHECK_AUTO, m_CheckAutoload);
}


BOOL CTAB4::OnInitDialog()
{
    CDialogEx::OnInitDialog(); // Call of the base method

    // Setting texts
    UINT controlIDs[] = { IDC_CHECK_AUTO, IDC_STATIC4_1, IDC_STATIC4_2, };
    UINT stringIDs[] = { IDS_TAB4_AUTO, IDS_TAB4_1, IDS_TAB4_2, };
    for (int i = 0; i < _countof(controlIDs); ++i) {
        // Loading a string from the String Table
        CString strText;
        if (strText.LoadString(stringIDs[i])) {
            // Setting text in a static control
            CStatic* pStatic = (CStatic*)GetDlgItem(controlIDs[i]);
            if (pStatic != nullptr) {
                pStatic->SetWindowText(strText);
            }
        }
    }
    
    // Initialization of CComboBox
    CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_LOCAL);
    if (pComboBox) {
        // Adding items to the combo box
        int index = pComboBox->AddString(_T("English"));
        if (index != CB_ERR)
            pComboBox->SetItemData(index, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));

        index = pComboBox->AddString(_T("Русский"));
        if (index != CB_ERR)
            pComboBox->SetItemData(index, MAKELANGID(LANG_RUSSIAN, SUBLANG_RUSSIAN_RUSSIA));
    }
    m_CheckAutoload = isInStartup;
    UpdateDataFromLocal();
    return TRUE; // Returning TRUE if the focus does not change manually
}


void CTAB4::OnCbnSelchangeComboLocal() {
    // Getting a pointer to the combo box
    CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_LOCAL);
    if (pComboBox) {
        // Getting the index of the selected item
        int selectedIndex = pComboBox->GetCurSel();
        if (selectedIndex != CB_ERR) {
            // Getting the value associated with the item
            LANGID selectedEffect = (LANGID)pComboBox->GetItemData(selectedIndex);
            // Updating the value in localData
            if (localData != nullptr) {
                localData->g_currentLang = selectedEffect;
            }
        }
    }
}


void CTAB4::OnPaint()
{
    CPaintDC dc(this); // DC for the dialog

    // Creating a GDI+ Graphics object
    Gdiplus::Graphics graphics(dc.m_hDC);

    // Load PNG from resources
    HRSRC hResource = ::FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_PNG1), _T("PNG"));
    if (!hResource) return;

    HGLOBAL hLoadedResource = ::LoadResource(AfxGetResourceHandle(), hResource);
    if (!hLoadedResource) return;
    DWORD imageSize = ::SizeofResource(AfxGetResourceHandle(), hResource);
    const void* pResourceData = ::LockResource(hLoadedResource);
    if (!pResourceData) return; // Check if the resource could be locked

    HGLOBAL hBuffer = ::GlobalAlloc(GMEM_MOVEABLE, imageSize);
    if (!hBuffer) { // Check that the memory was allocated
        return;
    }
    void* pBuffer = ::GlobalLock(hBuffer);
    if (!pBuffer) { // Check that memory was locked
        ::GlobalUnlock(hBuffer);
        ::GlobalFree(hBuffer);
        return;
    }
    memcpy(pBuffer, pResourceData, imageSize);
    ::GlobalUnlock(hBuffer);

    IStream* pStream = NULL;
    if (::CreateStreamOnHGlobal(hBuffer, TRUE, &pStream) == S_OK)
    {
        Gdiplus::Bitmap image(pStream);
        graphics.DrawImage(&image, 195, 10); // Drawing at (10, 10)
        pStream->Release();
    }

    ::GlobalFree(hBuffer);

    CDialogEx::OnPaint();
}


HBRUSH CTAB4::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    if (nCtlColor == CTLCOLOR_STATIC) {
        pDC->SetBkMode(TRANSPARENT);
        return (HBRUSH)::GetStockObject(NULL_BRUSH);
    }
    return hbr;
}


void CTAB4::OnBnClickedCheckAutoload() {
    UpdateData(TRUE);
}


LRESULT CTAB4::OnTabUpdate(WPARAM wParam, LPARAM lParam) {
    UpdateDataFromLocal(); // Reloading data from localData
    Invalidate();          // Redrawing the interface
    return 0;
}


void CTAB4::UpdateDataFromLocal() {
    if (localData != nullptr) {

        int modeValue = static_cast<int>(localData->g_currentLang); // Value from localData
        CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_LOCAL);
        for (int i = 0; i < pComboBox->GetCount(); ++i) {
            if (pComboBox->GetItemData(i) == modeValue) {
                pComboBox->SetCurSel(i); // Set the selected item
                break;
            }
        }
        // Call OnCbnSelchangeComboBlend() to synchronize the state
        OnCbnSelchangeComboLocal();

        UpdateData(FALSE); // Synchronizing the interface
    }
}