
// ex1_03View.cpp : Cex1_03View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ex1_03.h"
#endif

#include "ex1_03Doc.h"
#include "ex1_03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cex1_03View

IMPLEMENT_DYNCREATE(Cex1_03View, CView)

BEGIN_MESSAGE_MAP(Cex1_03View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cex1_03View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cex1_03View 构造/析构

Cex1_03View::Cex1_03View()
{
	// TODO: 在此处添加构造代码

}

Cex1_03View::~Cex1_03View()
{
}

BOOL Cex1_03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cex1_03View 绘制

void Cex1_03View::OnDraw(CDC* /*pDC*/)
{
	Cex1_03Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cex1_03View 打印


void Cex1_03View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cex1_03View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cex1_03View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cex1_03View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void Cex1_03View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cex1_03View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cex1_03View 诊断

#ifdef _DEBUG
void Cex1_03View::AssertValid() const
{
	CView::AssertValid();
}

void Cex1_03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cex1_03Doc* Cex1_03View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cex1_03Doc)));
	return (Cex1_03Doc*)m_pDocument;
}
#endif //_DEBUG


// Cex1_03View 消息处理程序
