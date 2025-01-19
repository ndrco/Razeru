#pragma once



// Dialog class CTAB4
class CTAB4 : public CDialogEx {
	DECLARE_DYNAMIC(CTAB4)
public:
	CTAB4(CWnd* pParent = nullptr);
	virtual ~CTAB4();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB4 };
#endif
protected:
	ULONG_PTR gdiplusToken;
	
	BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);
	afx_msg void OnCbnSelchangeComboLocal();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
	DECLARE_MESSAGE_MAP()

public:
	BOOL m_CheckAutoload{ FALSE };
	LRESULT OnTabUpdate(WPARAM wParam, LPARAM lParam);
	void UpdateDataFromLocal();

	afx_msg void OnBnClickedCheckAutoload();
};

