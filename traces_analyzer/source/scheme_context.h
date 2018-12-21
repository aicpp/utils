#pragma once

#include "scheme.h"

#include "helpers/string.h"

#include <afxdockablepane.h>

#include <vector>

class PluginFrame;

class ResultDockablePane :
    public CDockablePane
{
        
protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

    DECLARE_MESSAGE_MAP()

private:
    //CListCtrl
};

class ViewPanel
{
public:
    ViewPanel(PluginFrame* parentWnd, SchemeTemplate* schemeTemplate);
    ~ViewPanel();
    
private:
    PluginFrame*        m_parentWnd;
    ResultDockablePane  m_pane;
};

class SchemeContext
{
public:
    SchemeContext(PluginFrame* parentWnd);

public:
    bool Create(tstring const& filePath);
    Scheme& GetScheme();

private:
    void UpdateViewPanels();

private:
    PluginFrame*            m_parentWnd;

    Scheme                  m_scheme;
    std::vector<std::unique_ptr<ViewPanel>>  m_viewPanels;
};