#pragma once
#include "KeyboardKeys.h"
#include "../Razer/ChromaAnimationAPI.h"


using namespace ChromaSDK;


// Dialog class CTAB2
class CTAB2 : public CDialogEx {
	DECLARE_DYNAMIC(CTAB2)
public:
	CTAB2(CWnd* pParent = nullptr);
	virtual ~CTAB2();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB2 };
#endif

protected:
	int m_offsetX = 0;
	int m_offsetY = 0;
		
	ULONG_PTR gdiplusToken;
	CStatic m_StaticKeyboard;
	CBitmap m_bmpKeyboard;
	BOOL m_bCheckBclOn{ TRUE };
	
	CMFCColorButton m_ColorButton;
	COLORREF m_CurrentColor{ 0 };

	CComboBox m_comboMode;
	CComboBox m_comboBlend;

	CString SceneModeToString(EChromaSDKSceneMode mode);
	CString SceneBlendToString(EChromaSDKSceneBlend mode);
	LRESULT OnTabUpdate(WPARAM wParam, LPARAM lParam);
	void UpdateDataFromLocal();

	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);
	afx_msg void OnBnClickedBackOn();
	afx_msg void OnBnClickedColorButton();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnCbnSelchangeComboMode();
	afx_msg void OnCbnSelchangeComboBlend();
	afx_msg void OnBnClickedClean();

	DECLARE_MESSAGE_MAP()

public:

	struct KeyArea {
		CRect rect;
		int row;
		int col;
	};
	std::vector<KeyArea> m_keyboardKeys;
	const int maxCol = 22;
	const int maxRow = 6;

	void GetKeyboardKeys(std::vector<CTAB2::KeyArea>& m_keyboardKeys);

};

