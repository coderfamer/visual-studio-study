
// ex1_03View.h : Cex1_03View 类的接口
//

#pragma once


class Cex1_03View : public CView
{
protected: // 仅从序列化创建
	Cex1_03View();
	DECLARE_DYNCREATE(Cex1_03View)

// 特性
public:
	Cex1_03Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cex1_03View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ex1_03View.cpp 中的调试版本
inline Cex1_03Doc* Cex1_03View::GetDocument() const
   { return reinterpret_cast<Cex1_03Doc*>(m_pDocument); }
#endif

