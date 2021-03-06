/*
  +----------------------------------------------------------------------+
  | Zan                                                                  |
  +----------------------------------------------------------------------+
  | Copyright (c) 2016-2017 Zan Group                                    |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | zan@zanphp.io so we can mail you a copy immediately.                 |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
  |         Zan Group   <zan@zanphp.io>                                  |
  +----------------------------------------------------------------------+
*/
#ifndef _SW_SIGNAL_H_
#define _SW_SIGNAL_H_

#include "swoole.h"
#include "swReactor.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef void (*swSignalFunc)(int);

swSignalFunc swSignal_set(int sig, swSignalFunc func, int restart, int mask);
void swSignal_add(int signo, swSignalFunc func);
void swSignal_callback(int signo);
void swSignal_clear(void);
void swSignal_none(void);

#ifdef HAVE_SIGNALFD
void swSignalfd_init();
int swSignalfd_setup(swReactor *reactor);
#endif


#ifdef __cplusplus
}
#endif


#endif
