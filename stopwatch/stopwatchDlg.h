
// stopwatchDlg.h : header file
//

#pragma once


// CstopwatchDlg dialog
class CstopwatchDlg : public CDialogEx
{
// Construction
public:
	CstopwatchDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STOPWATCH_DIALOG }; // resource window
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeeditbox();
private:
	CEdit m_editbox;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	CButton m_checkbox;
public:
	CButton m_start;
private:
	CButton m_stop;
public:
	afx_msg void OnBnClickedStopbutton();
	afx_msg void OnBnClickedStartbutton();
};
