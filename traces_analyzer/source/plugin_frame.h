#pragma once

#include <afxwin.h>
#include <afxframewndex.h>

#include <string>

#ifdef UNICODE
    #define string wstring
#endif // UNICODE

struct PluginInfo
{
    HWND npp;
    HWND scintillaMain;
    HWND scintillaSecond;
    std::string name;
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
    afx_msg void OnWindowPosChanged(WINDOWPOS* wndPos);
    afx_msg void OnFileOpen();

    void LoadScheme(std::string const& schemeFilePath);
    void CloseScheme();
    bool IsSchemeLoaded() const;

private:
    PluginInfo const m_info;
};