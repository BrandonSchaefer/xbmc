#pragma once

#ifndef WINDOW_SYSTEM_MIR_GLES_CONTEXT_H_
#define WINDOW_SYSTEM_MIR_GLES_CONTEXT_H_

#include "GLContextEGL.h"
#include "rendering/gl/RenderSystemGLES.h"
#include "utils/GlobalsHandling.h"
#include "WinSystemMir.h"

class CWinSystemMirGLESContext : public CWinSystemMir, public CRenderSystemGLES
{
public:
  CWinSystemMirGLESContext() = default;
  virtual ~CWinSystemMirGLESContext() = default;

  bool CreateNewWindow(const std::string& name,
                       bool fullScreen,
                       RESOLUTION_INFO& res,
                       PHANDLE_EVENT_FUNC userFunction) override;

  bool SetFullScreen(bool fullScreen, RESOLUTION_INFO& res, bool blankOtherDisplays) override;
  bool IsExtSupported(const char* extension) override;

protected:
  void SetVSyncImpl(bool enable) override;
  void PresentRenderImpl(bool rendered) override;

private:
  CGLContextEGL m_pGLContext;

};

#if defined(HAS_GLES)
XBMC_GLOBAL_REF(CWinSystemMirGLESContext, g_Windowing);
#define g_Windowing XBMC_GLOBAL_USE(CWinSystemMirGLESContext)
#endif

#endif // WINDOW_SYSTEM_MIR_GLES_CONTEXT_H_
