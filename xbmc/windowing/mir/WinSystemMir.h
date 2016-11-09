#pragma once

#ifndef WINDOW_SYSTEM_MIR_H_
#define WINDOW_SYSTEM_MIR_H_

#include <mir_toolkit/mir_client_library.h>

#include "threads/CriticalSection.h"
#include "windowing/WinSystem.h"

class IDispResource;

class CWinSystemMir : public CWinSystemBase
{
public:
  CWinSystemMir();
  virtual ~CWinSystemMir() = default;

  bool InitWindowSystem() override;
  bool DestroyWindowSystem() override;

  bool CreateNewWindow(const std::string& name,
                       bool fullScreen,
                       RESOLUTION_INFO& res,
                       PHANDLE_EVENT_FUNC userFunction) override;

  bool DestroyWindow() override;

  bool ResizeWindow(int newWidth, int newHeight, int newLeft, int newTop) override;
  bool SetFullScreen(bool fullScreen, RESOLUTION_INFO& res, bool blankOtherDisplays) override;

  void UpdateResolutions() override;

  bool Hide() override;
  bool Show(bool raise = true) override;
  virtual void Register(IDispResource *resource);
  virtual void Unregister(IDispResource *resource);

protected:
  MirConnection* m_connection;
  MirSurface* m_surface;
  MirPixelFormat m_pixel_format;
};

#endif // WINDOW_SYSTEM_MIR_H_
