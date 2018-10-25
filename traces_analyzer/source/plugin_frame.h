#pragma once

#include "scheme.h"
#include "helpers/string.h"

#include <afxwin.h>
#include <afxframewndex.h>

struct PluginInfo
{
    HWND npp;
    HWND scintillaMain;
    HWND scintillaSecond;
    tstring name;
};

class PluginFrame :
    public CFrameWndEx
{
public:
    PluginFrame(PluginInfo const& info);
    virtual ~PluginFrame();

protected:
    DECLARE_MESSAGE_MAP()

private:
    PluginFrame(PluginFrame const&) = delete;
    PluginFrame& operator=(PluginFrame const&) = delete;

private:
    afx_msg int OnCreate(LPCREATESTRUCT createStruct);
    afx_msg void OnDestroy();
    afx_msg void OnClose();
    afx_msg void OnWindowPosChanged(WINDOWPOS* wndPos);
    afx_msg void OnFileNew();
    afx_msg void OnFileOpen();
    afx_msg void OnFileSave();
    afx_msg void OnFileClose();

    void LoadScheme(tstring const& schemeFilePath);
    bool SaveScheme();
    bool CloseScheme();
    bool IsSchemeLoaded() const;

private:
    PluginInfo const        m_info;
    std::unique_ptr<Scheme> m_scheme;
};