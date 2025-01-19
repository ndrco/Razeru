#pragma once

using namespace ChromaSDK;


// Dialog class CTAB3
class CTAB3 : public CDialogEx {
	DECLARE_DYNAMIC(CTAB3)
public:
	CTAB3(CWnd* pParent = nullptr);
	virtual ~CTAB3();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB3 };
#endif
protected:
	
	CMFCColorButton m_ColorButton;
	COLORREF m_CurrentColor{ 0 };
	
	BOOL OnInitDialog();
	LRESULT OnTabUpdate(WPARAM wParam, LPARAM lParam);
	void UpdateDataFromLocal();

	virtual void DoDataExchange(CDataExchange* pDX);
	afx_msg void OnEnUpdateEditNumber();
	afx_msg void OnBnClickedColorButton();
	afx_msg void OnCbnSelchangeComboMode();
	
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void ShowFrameDuration();
	afx_msg void ShowFrames();
};
