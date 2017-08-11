
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"



#include <winsvc.h>

#define SERVICE_NO_ERROR 0  
#define OPEN_SCMANAGER_ERROR 2  
#define OPEN_SERVICE_ERROR 3  
#define QUERY_SERVICESTATUS_ERROR 4  
#define STOP_SERVICE_ERROR 5  
#define START_SERVICE_ERROR 6 
#define STOP_NO_ERROR 7

#define Enable_Service 1

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_WM_CLOSE()
	ON_BN_DOUBLECLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnDoubleclickedButton1)
	ON_BN_DOUBLECLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnDoubleclickedButton2)
	ON_BN_DOUBLECLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnDoubleclickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	////������һ����ť
	//HBITMAP   hBitmap1;
	//hBitmap1 = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2));
	//((CButton *)GetDlgItem(IDC_BUTTON1))->SetBitmap(hBitmap1);

	//HBITMAP   hBitmap2;
	//hBitmap2 = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1));
	//((CButton *)GetDlgItem(IDC_BUTTON2))->SetBitmap(hBitmap2);

	//HBITMAP   hBitmap3;
	//hBitmap3 = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3));
	//((CButton *)GetDlgItem(IDC_BUTTON3))->SetBitmap(hBitmap3);


	HICON m_hIcon;//����һ��icon���

	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);//������Դ�ļ�IDΪIDR_MAINFRAME����Դ
		
	f = new CFont;
	f->CreateFont(36,								// nHeight 
		0,											// nWidth 
		0,											// nEscapement 
		0,											// nOrientation 
		FW_BOLD,									// nWeight 
		FALSE,										// bItalic 
		FALSE,										// bUnderline 
		0,											// cStrikeOut 
		ANSI_CHARSET,								// nCharSet 
		OUT_DEFAULT_PRECIS,							// nOutPrecision 
		CLIP_DEFAULT_PRECIS,						// nClipPrecision 
		DEFAULT_QUALITY,							// nQuality 
		DEFAULT_PITCH | FF_SWISS,					// nPitchAndFamily 
		_T("Arial"));								// lpszFac 

	GetDlgItem(IDC_BUTTON1)->SetFont(f);
	GetDlgItem(IDC_BUTTON2)->SetFont(f);
	GetDlgItem(IDC_BUTTON3)->SetFont(f);

	this->ShowWindow(SW_SHOWMAXIMIZED);

	




	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int CMFCApplication1Dlg::CloseMMAPService(WCHAR* pszServiceName)
{
	bool isClosed = false;
	// �򿪷���������  
	SC_HANDLE hSC = ::OpenSCManager(NULL, NULL, GENERIC_EXECUTE);
	if (hSC == NULL)
	{
		return OPEN_SCMANAGER_ERROR;
	}
	// ��apache����  
	SC_HANDLE hSvc = ::OpenService(hSC, pszServiceName, SERVICE_START | SERVICE_QUERY_STATUS | SERVICE_STOP);
	if (hSvc == NULL)
	{
		::CloseServiceHandle(hSC);
		return OPEN_SERVICE_ERROR;
	}
	// ��÷����״̬  
	SERVICE_STATUS status;
	if (::QueryServiceStatus(hSvc, &status) == FALSE)
	{
		::CloseServiceHandle(hSvc);
		::CloseServiceHandle(hSC);
		return QUERY_SERVICESTATUS_ERROR;
	}
	//�����������״̬��ֹͣ����  
	if (status.dwCurrentState == SERVICE_RUNNING)
	{
		// ֹͣ����  
		if (::ControlService(hSvc, SERVICE_CONTROL_STOP, &status) == FALSE)
		{
			::CloseServiceHandle(hSvc);
			::CloseServiceHandle(hSC);
			return STOP_SERVICE_ERROR;
		}
		// �ȴ�����ֹͣ  
		while (::QueryServiceStatus(hSvc, &status) == TRUE)
		{
			::Sleep(status.dwWaitHint);
			if (status.dwCurrentState == SERVICE_STOPPED)
			{
				isClosed = true;
				break;
			}
		}

		if (isClosed)
		{
			return SERVICE_NO_ERROR;
		}
	}

	return SERVICE_NO_ERROR;
}

int CMFCApplication1Dlg::OpenMMAPService(WCHAR* pszServiceName)
{

	// �򿪷���������  
	SC_HANDLE hSC = ::OpenSCManager(NULL, NULL, GENERIC_EXECUTE);
	if (hSC == NULL)
	{
		return OPEN_SCMANAGER_ERROR;
	}
	// ��apache����  
	SC_HANDLE hSvc = ::OpenService(hSC, pszServiceName, SERVICE_START | SERVICE_QUERY_STATUS | SERVICE_STOP);
	if (hSvc == NULL)
	{
		::CloseServiceHandle(hSC);
		return OPEN_SERVICE_ERROR;
	}
	// ��÷����״̬  
	SERVICE_STATUS status;
	if (::QueryServiceStatus(hSvc, &status) == FALSE)
	{
		::CloseServiceHandle(hSvc);
		::CloseServiceHandle(hSC);
		return QUERY_SERVICESTATUS_ERROR;
	}
	//�����������״̬��ֹͣ����  
	if (status.dwCurrentState == SERVICE_RUNNING)
	{
		// ֹͣ����  
		if (::ControlService(hSvc,
			SERVICE_CONTROL_STOP, &status) == FALSE)
		{
			::CloseServiceHandle(hSvc);
			::CloseServiceHandle(hSC);
			return STOP_SERVICE_ERROR;
		}
		// �ȴ�����ֹͣ  
		while (::QueryServiceStatus(hSvc, &status) == TRUE)
		{
			::Sleep(status.dwWaitHint);
			if (status.dwCurrentState == SERVICE_STOPPED)
			{
				break;
			}
		}
		//return STOP_NO_ERROR;
	}

	// ��������  
	if (::StartService(hSvc, NULL, NULL) == FALSE)
	{
		::CloseServiceHandle(hSvc);
		::CloseServiceHandle(hSC);
		return START_SERVICE_ERROR;
	}
	// �ȴ���������  
	while (::QueryServiceStatus(hSvc, &status) == TRUE)
	{
		::Sleep(status.dwWaitHint);
		if (status.dwCurrentState == SERVICE_RUNNING)
		{
			break;
		}
	}

	::CloseServiceHandle(hSvc);
	::CloseServiceHandle(hSC);
	return SERVICE_NO_ERROR;

}


void CMFCApplication1Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

	int firstbuttonpos_px = ((cx)-700) / 2;
	if (firstbuttonpos_px > 0)
	{
		if (GetDlgItem(IDC_BUTTON1))
		{
			GetDlgItem(IDC_BUTTON1)->MoveWindow(firstbuttonpos_px, (cy - 150) / 2, 200, 150);
		}
		if (GetDlgItem(IDC_BUTTON2))
		{
			GetDlgItem(IDC_BUTTON2)->MoveWindow(firstbuttonpos_px + 250, (cy - 150) / 2, 200, 150);
		}
		if (GetDlgItem(IDC_BUTTON3))
		{
			GetDlgItem(IDC_BUTTON3)->MoveWindow(firstbuttonpos_px + 500, (cy - 150) / 2, 200, 150);
		}

	}

}


void CMFCApplication1Dlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: Add your message handler code here and/or call default

	lpMMI->ptMinTrackSize.x = 750;

	lpMMI->ptMinTrackSize.y = 200;

	//�������߶�����,�����Ҫ�Ļ�

	//lpMMI->ptMaxTrackSize.x = 1366;

	//lpMMI->ptMaxTrackSize.y = 768;


	CDialogEx::OnGetMinMaxInfo(lpMMI);
}


void CMFCApplication1Dlg::OnClose()
{
	if (::MessageBox(NULL, _T("ȷ��Ҫ�˳���"), _T("�����˳�"), MB_YESNO) == IDYES)
	{
		//CDialog::OnCLose();  //OnCLose�¼�
#if Enable_Service
		int ret_close = CloseMMAPService(_TEXT("STEPVR_MMAP_SERVICE"));
		if (0 != ret_close)
		{
			AfxMessageBox(L"�رն�λ����ʧ��");
		}
		int ret_close_mocap = CloseMMAPService(_TEXT("STEPVR_MMAP_SERVICE_MOCAP"));
		if (0 != ret_close_mocap)
		{
			AfxMessageBox(L"�رն�������ʧ��");
		}
#endif
		delete f;
		CDialogEx::OnClose();
	}

}


void CMFCApplication1Dlg::OnBnDoubleclickedButton1()
{
	int k = 0;
}


void CMFCApplication1Dlg::OnBnDoubleclickedButton2()
{
	int k = 0;
}


void CMFCApplication1Dlg::OnBnDoubleclickedButton3()
{
	int k = 0;
}

#include <string.h>
#include <Windows.h>
#include <TlHelp32.h>
bool CMFCApplication1Dlg::FindPro(WCHAR* wscProcessName)
{

	PROCESSENTRY32 pe32;
	//���ô�С
	pe32.dwSize = sizeof(pe32);
	//����ϵͳ���̿���
	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		//printf("����ʧ�ܣ�\n");
		return false;
	}
	//��������
	BOOL bMORE = ::Process32First(hProcessSnap, &pe32);
	while (bMORE)
	{
		if (wcscmp(pe32.szExeFile, wscProcessName) == 0)
		{
			return true;
		}
		bMORE = ::Process32Next(hProcessSnap, &pe32);

	}
	CloseHandle(hProcessSnap);
	return false;

}

void CMFCApplication1Dlg::OnBnClickedButton1()
{
	if (FindPro(L"kangfu.exe"))
	{
		AfxMessageBox(L"����ѵ����������,�����ظ�����.");
		return;
	}
	if (FindPro(L"jiedu.exe"))
	{
		AfxMessageBox(L"�䶾ѵ����������,��ر�.");
		return;
	}
	if (FindPro(L"Start.exe"))
	{
		AfxMessageBox(L"�ָ�ѵ����������,��ر�.");
		return;
	}

#if Enable_Service
	int ret_close = CloseMMAPService(_TEXT("STEPVR_MMAP_SERVICE"));
	if (0 != ret_close)
	{
		AfxMessageBox(L"�رն�λ����ʧ��");
	}
	int ret_open = OpenMMAPService(_TEXT("STEPVR_MMAP_SERVICE_MOCAP"));
	if (0 != ret_open)
	{
		AfxMessageBox(L"������������ʧ��");
	}
#endif

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	TCHAR szCommandLine[] = L"Train\\kangfu.exe";

	if (CreateProcess(nullptr, szCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		//int ret = GetLastError();
		AfxMessageBox(L"����������Ϸʧ��!");
		HANDLE hProcess = GetCurrentProcess();//get current process
		TerminateProcess(hProcess, 0);         //close process
	}
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	if (FindPro(L"kangfu.exe"))
	{
		AfxMessageBox(L"����ѵ����������,��ر�.");
		return;
	}
	if (FindPro(L"jiedu.exe"))
	{
		AfxMessageBox(L"�䶾ѵ����������,�����ظ�����.");
		return;
	}
	if (FindPro(L"Start.exe"))
	{
		AfxMessageBox(L"�ָ�ѵ����������,��ر�.");
		return;
	}

#if Enable_Service
	int ret_close = CloseMMAPService(_TEXT("STEPVR_MMAP_SERVICE_MOCAP"));
	if (0 != ret_close)
	{
		AfxMessageBox(L"�رն�������ʧ��");
	}
	int ret_open = OpenMMAPService(_TEXT("STEPVR_MMAP_SERVICE"));
	if (0 != ret_open)
	{
		AfxMessageBox(L"������λ����ʧ��");
	}
#endif
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	TCHAR szCommandLine[] = L"Train\\jiedu.exe";

	if (CreateProcess(nullptr, szCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		//int ret = GetLastError();
		AfxMessageBox(L"�����䶾��Ϸʧ��!");
		HANDLE hProcess = GetCurrentProcess();//get current process
		TerminateProcess(hProcess, 0);         //close process
	}
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	if (FindPro(L"kangfu.exe"))
	{
		AfxMessageBox(L"����ѵ����������,��ر�.");
		return;
	}
	if (FindPro(L"jiedu.exe"))
	{
		AfxMessageBox(L"�䶾ѵ����������,��ر�.");
		return;
	}
	if (FindPro(L"Start.exe"))
	{
		AfxMessageBox(L"�ָ�ѵ����������,�����ظ�����.");
		return;
	}

#if Enable_Service
	int ret_close = CloseMMAPService(_TEXT("STEPVR_MMAP_SERVICE_MOCAP"));
	if (0 != ret_close)
	{
		AfxMessageBox(L"�رն�������ʧ��");
	}
	int ret_open = OpenMMAPService(_TEXT("STEPVR_MMAP_SERVICE"));
	if (0 != ret_open)
	{
		AfxMessageBox(L"������λ����ʧ��");
	}
#endif

	//bool isfine = FindPro(L"");

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	TCHAR szCommandLine[] = L"Train\\Start.exe";

	if (CreateProcess(nullptr, szCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		//int ret = GetLastError();
		AfxMessageBox(L"�����ָ���Ϸʧ��!");
		HANDLE hProcess = GetCurrentProcess();//get current process
		TerminateProcess(hProcess, 0);         //close process
	}
}
