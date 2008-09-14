#include "TimerWrapper.hpp"

namespace org_pqrs_KeyRemap4MacBook {
  void
  TimerWrapper::initialize(IOWorkLoop *_workLoop, OSObject *owner, IOTimerEventSource::Action func)
  {
    if (timer) terminate();

    if (! _workLoop) return;

    workLoop = _workLoop;
    timer = IOTimerEventSource::timerEventSource(owner, func);

    if (workLoop->addEventSource(timer) != kIOReturnSuccess) {
      timer->release();
      timer = NULL;
    }
  }

  void
  TimerWrapper::terminate(void)
  {
    if (timer) {
      timer->cancelTimeout();
      if (workLoop) {
        workLoop->removeEventSource(timer);
      }
      timer->release();
      timer = NULL;
    }
    workLoop = NULL;
  }
}
