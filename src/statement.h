/* vim:expandtab:shiftwidth=2:tabstop=2:smarttab:
 * Copyright 2014 Hewlett-Packard Development Company, L.P.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 */

#pragma once

#include "config.h"
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

bool attachsql_stmt_execute(attachsql_stmt_st *stmt);

bool attachsql_stmt_check_buffer_size(attachsql_stmt_st *stmt, size_t required);

attachsql_command_status_t attachsql_stmt_fetch(attachsql_stmt_st *stmt);

bool attachsql_statement_set_param(attachsql_connect_t *con, attachsql_column_type_t type, uint16_t param, size_t length, const void *value, bool is_unsigned, attachsql_error_t **error);

#ifdef __cplusplus
}
#endif
