/*  vim:expandtab:shiftwidth=2:tabstop=2:smarttab:
 * 
 *  Gearmand client and server library.
 *
 *  Copyright (C) 2011 Data Differential, http://datadifferential.com/
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *      * Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 *      * Redistributions in binary form must reproduce the above
 *  copyright notice, this list of conditions and the following disclaimer
 *  in the documentation and/or other materials provided with the
 *  distribution.
 *
 *      * The names of its contributors may not be used to endorse or
 *  promote products derived from this software without specific prior
 *  written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#pragma once

struct gearman_actions_t
{
  gearman_workload_fn *workload_fn;
  gearman_created_fn *created_fn;
  gearman_data_fn *data_fn;
  gearman_warning_fn *warning_fn;
  gearman_universal_status_fn *status_fn;
  gearman_complete_fn *complete_fn;
  gearman_exception_fn *exception_fn;
  gearman_fail_fn *fail_fn;
};

struct gearman_reducer_t
{
  gearman_reducer_each_fn *each_fn;
};

#ifdef __cplusplus
extern "C" {
#endif

GEARMAN_API
struct gearman_reducer_t gearman_reducer_make(gearman_reducer_each_fn* each);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus // Local only

GEARMAN_LOCAL
gearman_actions_t &gearman_actions_default(void);

GEARMAN_LOCAL
gearman_actions_t &gearman_actions_do_default(void);

GEARMAN_LOCAL
gearman_actions_t &gearman_actions_execute_defaults(void);

#endif
