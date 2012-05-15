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

struct gearman_server_job_st
{
  uint8_t retries;
  gearmand_job_priority_t priority;
  bool ignore_job;
  bool job_queued;
  uint32_t job_handle_key;
  uint32_t unique_key;
  uint32_t client_count;
  uint32_t numerator;
  uint32_t denominator;
  size_t data_size;
  int64_t when;
  gearman_server_job_st *next;
  gearman_server_job_st *prev;
  gearman_server_job_st *unique_next;
  gearman_server_job_st *unique_prev;
  gearman_server_job_st *worker_next;
  gearman_server_job_st *worker_prev;
  gearman_server_function_st *function;
  gearman_server_job_st *function_next;
  const void *data;
  gearman_server_client_st *client_list;
  gearman_server_worker_st *worker;
  char job_handle[GEARMAND_JOB_HANDLE_SIZE];
  size_t unique_length;
  char unique[GEARMAN_MAX_UNIQUE_SIZE];
  char reducer[GEARMAN_FUNCTION_MAX_SIZE];
};
