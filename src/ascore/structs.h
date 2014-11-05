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

#include "constants.h"
#include "buffer.h"
#include "return.h"
#include <sys/types.h>
#include <stdint.h>
#ifdef _WIN32

typedef uint16_t in_port_t;

#else
# include <sys/socket.h>
# include <arpa/inet.h>
#endif

#include <uv.h>

#ifdef HAVE_OPENSSL
# include <openssl/ssl.h>
#endif

#ifdef __cplusplus
#include <cstddef>
extern "C" {
#endif

typedef struct ascon_st ascon_st;

struct column_t
{
  char schema[ASCORE_MAX_SCHEMA_SIZE];
  char table[ASCORE_MAX_TABLE_SIZE];
  char origin_table[ASCORE_MAX_TABLE_SIZE];
  char column[ASCORE_MAX_COLUMN_SIZE];
  char origin_column[ASCORE_MAX_COLUMN_SIZE];
  uint16_t charset;
  uint32_t length;
  ascore_column_type_t type;
  ascore_column_flags_t flags;
  uint8_t decimals;
  char default_value[ASCORE_MAX_DEFAULT_VALUE_SIZE];
  size_t default_size;
};

struct result_t
{
  uint16_t column_count;
  uint64_t extra;
  column_t *columns;
  uint16_t current_column;
  char *row_data;
  size_t row_length;

  result_t() :
    column_count(0),
    extra(0),
    columns(NULL),
    current_column(0),
    row_data(NULL),
    row_length(0)
  { }
};

struct ascore_datetime_st
{
  uint16_t year;
  uint8_t month;
  uint32_t day;
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
  uint32_t microsecond;
  bool is_negative;

  ascore_datetime_st ():
    year(0),
    month(0),
    day(0),
    hour(0),
    minute(0),
    second(0),
    microsecond(0),
    is_negative(false)
  { }
};

struct ascore_stmt_param_st
{
  ascore_column_type_t type;
  size_t length;
  bool is_long_data;
  bool is_unsigned;
  bool datetime_alloc;
  union data_t
  {
    uint8_t tinyint_data;
    uint16_t smallint_data;
    uint32_t int_data;
    uint64_t bigint_data;
    float float_data;
    double double_data;
    ascore_datetime_st *datetime_data;
    char *string_data;
  } data;

  ascore_stmt_param_st() :
    type(ASCORE_COLUMN_TYPE_NULL),
    length(0),
    is_long_data(false),
    is_unsigned(false),
    datetime_alloc(false)
  { }
};

struct ascore_stmt_st
{
  ascon_st *con;
  uint32_t id;
  uint16_t column_count;
  column_t *columns;
  uint16_t current_column;
  uint16_t param_count;
  column_t *params;
  uint16_t current_param;
  ascore_stmt_state_t state;
  char *exec_buffer;
  size_t exec_buffer_length;
  ascore_stmt_param_st *param_data;
  bool new_bind;

  ascore_stmt_st():
    con(NULL),
    id(0),
    column_count(0),
    columns(NULL),
    current_column(0),
    param_count(0),
    params(NULL),
    current_param(0),
    state(ASCORE_STMT_STATE_NONE),
    exec_buffer(NULL),
    exec_buffer_length(0),
    param_data(NULL),
    new_bind(true)
  { }
};

struct ascon_st
{
  const char *host;
  in_port_t port;
  char str_port[6];
  const char *user;
  const char *pass;
  const char *schema;
  struct options_t
  {
    bool compression;
    ascore_con_protocol_t protocol;
    bool semi_block;

    options_t() :
      compression(false),
      protocol(ASCORE_CON_PROTOCOL_UNKNOWN),
      semi_block(false)
    { }
  } options;

  ascore_con_status_t status;
  char errmsg[ASCORE_ERROR_BUFFER_SIZE];
  asret_t local_errcode;
  buffer_st *read_buffer;
  buffer_st *read_buffer_compress;
  char write_buffer[ASCORE_WRITE_BUFFER_SIZE];
  uint8_t write_buffer_extra; /* for extra bytes in packet header due to prepared statement */
  uint8_t packet_number;
  uint32_t thread_id;
  char server_version[ASCORE_MAX_SERVER_VERSION_LEN];
  unsigned char scramble_buffer[20];
  char packet_header[4];
  ascore_capabilities_t server_capabilities;
  int client_capabilities;
  uint32_t packet_size;
  uint64_t affected_rows;
  uint64_t insert_id;
  uint16_t server_status;
  uint16_t warning_count;
  uint16_t server_errno;
  char server_message[ASCORE_MAX_MESSAGE_LEN];
  char sqlstate[ASCORE_SQLSTATE_SIZE];
  uint8_t charset;
  struct result_t result;
  ascore_command_status_t command_status;
  ascore_packet_type_t *next_packet_queue;
  size_t next_packet_queue_size;
  size_t next_packet_queue_used;
  char *uncompressed_buffer;
  size_t uncompressed_buffer_len;
  char *compressed_buffer;
  size_t compressed_buffer_len;
  char compressed_packet_header[7];
  uint8_t compressed_packet_number;
  struct uv_objects_t
  {
    uv_loop_t *loop;
    uv_check_t check;
    struct addrinfo hints;
    uv_getaddrinfo_t resolver;
    uv_connect_t connect_req;
    uv_stream_t *stream;
    union socket_t
    {
      uv_tcp_t tcp;
      uv_pipe_t uds;
    } socket;

    uv_objects_t() :
      loop(NULL),
      stream(NULL)
    { }
  } uv_objects;
#ifdef HAVE_OPENSSL
  struct ssl_t
  {
    SSL *ssl;
    SSL_CTX *context;
    bool no_verify;
    bool enabled; // set to true after first handshake to signify send/receive should be encrypted.
    bool handshake_done;
    BIO* read_bio;
    BIO* write_bio;
    char ssl_read_buffer[1024*16];
    char ssl_write_buffer[1024*16];
    buffer_st *write_buffer;
    char* bio_buffer;
    size_t bio_buffer_size;

    ssl_t() :
      ssl(NULL),
      context(NULL),
      no_verify(false),
      enabled(false),
      handshake_done(false),
      read_bio(NULL),
      write_bio(NULL),
      write_buffer(NULL),
      bio_buffer(NULL),
      bio_buffer_size(0)
    {
      ssl_read_buffer[0]= '\0';
      ssl_write_buffer[0]= '\0';
    }
  } ssl;
#endif
  bool in_statement;
  ascore_stmt_st *stmt;
  bool in_group;

  ascon_st() :
    host(NULL),
    port(0),
    user(NULL),
    pass(NULL),
    schema(NULL),
    status(ASCORE_CON_STATUS_NOT_CONNECTED),
    local_errcode(ASRET_OK),
    read_buffer(NULL),
    read_buffer_compress(NULL),
    write_buffer_extra(0),
    packet_number(0),
    thread_id(0),
    server_capabilities(ASCORE_CAPABILITY_NONE),
    client_capabilities(0),
    packet_size(0),
    affected_rows(0),
    insert_id(0),
    server_status(0),
    warning_count(0),
    server_errno(0),
    charset(0),
    command_status(ASCORE_COMMAND_STATUS_NONE),
    next_packet_queue(NULL),
    next_packet_queue_size(0),
    next_packet_queue_used(0),
    uncompressed_buffer(NULL),
    uncompressed_buffer_len(0),
    compressed_buffer(NULL),
    compressed_buffer_len(0),
    compressed_packet_number(0),
    in_statement(false),
    stmt(NULL),
    in_group(false)
  {
    str_port[0]= '\0';
    errmsg[0]= '\0';
    server_version[0]= '\0';
    scramble_buffer[0]= '\0';
    packet_header[0]= '\0';
    server_message[0]= '\0';
    sqlstate[0]= '\0';
    write_buffer[0]= '\0';
    compressed_packet_header[0]= '\0';
  }
};

#ifdef __cplusplus
}
#endif
