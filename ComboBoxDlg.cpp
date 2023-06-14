
// ComboBoxDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ComboBox.h"
#include "ComboBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CComboBoxDlg dialog



CComboBoxDlg::CComboBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COMBOBOX_DIALOG, pParent)
	, m_input_value(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_comboBox1);
	DDX_Control(pDX, IDC_COMBO2, m_comboBox2);
	DDX_Control(pDX, IDC_COMBO3, m_comboBox3);
	DDX_Control(pDX, IDC_EDIT1, m_InputField);
	DDX_Text(pDX, IDC_EDIT1, m_input_value);
	DDX_Control(pDX, IDC_TEST, test_InputField);
	DDX_Text(pDX, IDC_TEST, test_input_value);
}

BEGIN_MESSAGE_MAP(CComboBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO3, &CComboBoxDlg::OnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CComboBoxDlg::OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CComboBoxDlg::OnSelchangeCombo2)
	//ON_BN_CLICKED(IDCANCEL, &CComboBoxDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_AddItems, &CComboBoxDlg::OnBnClickedAdditems)
END_MESSAGE_MAP()


// CComboBoxDlg message handlers

BOOL CComboBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	m_comboBox1.SetWindowTextW(L"Hello");
	m_comboBox2.SetWindowTextW(L"Desktop");
	m_comboBox3.SetWindowTextW(L"Keyboard");

	//test_InputField.SetWindowTextW(L"Hello");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CComboBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CComboBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CComboBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CComboBoxDlg::OnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	//m_comboBox1.SetCurSel(1);
	int comboBox1SelectedIndex = m_comboBox1.GetCurSel();
	if (comboBox1SelectedIndex != -1) {
		//CString str;
		m_comboBox1.GetLBText(comboBox1SelectedIndex, m_input_value);
		m_input_value = L"Box1:" + m_input_value;
		UpdateData(FALSE);

	}
	
}

void CComboBoxDlg::OnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	int comboBox2SelectedIndex = m_comboBox2.GetCurSel();
	if (comboBox2SelectedIndex != -1){
		//CString str;
		m_comboBox2.GetLBText(comboBox2SelectedIndex, m_input_value);
		//AfxMessageBox(str);
		m_input_value = L"Box2:" + m_input_value;
		UpdateData(FALSE);
	}
}

void CComboBoxDlg::OnSelchangeCombo3()
{
	// TODO: Add your control notification handler code here
	int comboBox3SelectedIndex = m_comboBox3.GetCurSel();
	if (comboBox3SelectedIndex != -1) {
		CString str;
		m_comboBox3.GetLBText(comboBox3SelectedIndex, m_input_value);
		//AfxMessageBox(str);
		m_input_value = L"Box3:" + m_input_value;
		UpdateData(FALSE);
	}
}




//void CComboBoxDlg::OnBnClickedCancel()
//{
//	// TODO: Add your control notification handler code here
//	CDialogEx::OnCancel();
//}


void CComboBoxDlg::OnBnClickedAdditems()
{
	// TODO: Add your control notification handler code here
	test_InputField.GetWindowTextW(test_input_value);
	m_comboBox1.AddString(test_input_value);
	m_comboBox2.AddString(test_input_value);


}
