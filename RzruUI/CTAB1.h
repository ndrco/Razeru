#pragma once


// Dialog class CTAB1
class CTAB1 : public CDialogEx {
	DECLARE_DYNAMIC(CTAB1)
public:
	CTAB1(CWnd* pParent = nullptr);
	virtual ~CTAB1();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB1 };
#endif
protected:
	std::vector<CEdit*> editControls;
	std::map<int, size_t> buttonToEditIndex;
	CComboBox m_comboLangs;
	CSliderCtrl m_sliderSpeed;
	BOOL m_bCheckDevAn{ TRUE };

	virtual BOOL OnInitDialog();
	LRESULT OnTabUpdate(WPARAM wParam, LPARAM lParam);
	void UpdateDataFromLocal();
	void SynchronizeKeyboardEffects();
	virtual void DoDataExchange(CDataExchange* pDX);
	void SelectLayoutData(LANGID selIndex);
	void SetSlider();

	afx_msg void OnCbnSelchangeComboLang();
	afx_msg CString OpenFileDialog();
	afx_msg void OnBnClickedButton();
	afx_msg void OnEditChange();
	afx_msg void OnBnClickedCheckDevAn();
	afx_msg void OnSliderSpeedChange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();

	DECLARE_MESSAGE_MAP()

public:
	int m_layoutIndex{ -1 }; // Active keyboard animation index
};