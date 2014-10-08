Version History
===============

Version 0.5
-----------

Version 0.5.0 Beta (2014-10-08)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Removed unused network blocking code (`Issue #72 <https://github.com/libattachsql/libattachsql/issues/72>`_)
* Added support for ``NO_BACKSLASH_ESCAPES`` SQL mode (`Issue #63 <https://github.com/libattachsql/libattachsql/issues/63>`_)
* Fixed wrong return state for empty result set (`Issue #83 <https://github.com/libattachsql/libattachsql/issues/83>`_)
* Fixed crash when using multiple threads (`Issue #86 <https://github.com/libattachsql/libattachsql/issues/86>`_)
* Fixed possible double-free on :c:func:`attachsql_query_close` (`Issue #85 <https://github.com/libattachsql/libattachsql/issues/85>`_)
* Added a semi-blocking mode for one connection per thread access (`Issue #89 <https://github.com/libattachsql/libattachsql/issues/89>`_)
* Attempt to error when file descriptors are exhausted (`Issue #92 <https://github.com/libattachsql/libattachsql/issues/92>`_)
* Added the start of troubleshooting documentation
* Fix statement and statement_param test cases when a MySQL server is not present (`Issue #99 <https://github.com/libattachsql/libattachsql/issues/99>`_)
* Examples are now compiled to ensure API compatibility (`Issue #97 <https://github.com/libattachsql/libattachsql/issues/97>`_)
* Added basic API usage documentation (`Issue #96 <https://github.com/libattachsql/libattachsql/issues/96>`_)
* Moved some documentation around to make the sections clearer
* Fixed bad send/receive packets for :c:func:`attachsql_statement_close` (`Issue #102 <https://github.com/libattachsql/libattachsql/issues/102>`_ and `Issue #103 <https://github.com/libattachsql/libattachsql/issues/103>`_)
* Fixed ``./configure --enable-debug`` breaking linkage with C applications (`Issue #104 <https://github.com/libattachsql/libattachsql/issues/104>`_)
* Fixed bad internal state after :c:func:`attachsql_statement_close` (`Issue #106 <https://github.com/libattachsql/libattachsql/issues/106>`_)
* Fixed double-free on close of second call oc :c:func:`attachsql_statement_close` (`Issue #107 <https://github.com/libattachsql/libattachsql/issues/107>`_)
* Fixed minor memory leaks in prepared statements (`Issue #109 <https://github.com/libattachsql/libattachsql/issues/109>`_)
* Added a prepared statement example (`Issue #80 <https://github.com/libattachsql/libattachsql/issues/80>`_)

Incompatible changes
""""""""""""""""""""

  .. warning::

     These changes are API incompatible with version 0.4.0 and below

* Changed error struct to a hidden error type (``attachsql_error_st`` has been replaced by :c:type:`attachsql_error_t`) and added access functions (:c:func:`attachsql_error_code`, :c:func:`attachsql_error_message` and :c:func:`attachsql_error_sqlstate`).
* Changed several functions for a more consistent error handling API.  These are:

  * :c:func:`attachsql_connect`
  * :c:func:`attachsql_connect_set_ssl`
  * :c:func:`attachsql_query`
  * :c:func:`attachsql_statement_prepare`
  * :c:func:`attachsql_statement_execute`
  * :c:func:`attachsql_statement_reset`
  * :c:func:`attachsql_statement_send_long_data`
  * :c:func:`attachsql_statement_set_int`
  * :c:func:`attachsql_statement_set_unsigned_int`
  * :c:func:`attachsql_statement_set_bigint`
  * :c:func:`attachsql_statement_set_unsigned_bigint`
  * :c:func:`attachsql_statement_set_float`
  * :c:func:`attachsql_statement_set_double`
  * :c:func:`attachsql_statement_set_string`
  * :c:func:`attachsql_statement_set_binary`
  * :c:func:`attachsql_statement_set_null`
  * :c:func:`attachsql_statement_set_datetime`
  * :c:func:`attachsql_statement_set_time`
  * :c:func:`attachsql_statement_row_get`

Version 0.4
-----------

Version 0.4.0 Beta (2014-09-22)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Fixed compiler flag for GCC 4.9 (`Issue #65 <https://github.com/libattachsql/libattachsql/issues/65>`_)
* Fix docs building under Python 3.x
* Documentation fixes
* Fixed compiling in RedHat/CentOS 6.x
* Fixed parallel building
* Fixed SSL connect with no server support (`Issue #68 <https://github.com/libattachsql/libattachsql/issues/68>`_)
* Fixed possible buffer pointer breakage (`Issue #67 <https://github.com/libattachsql/libattachsql/issues/67>`_)
* Fixed potential crash on query with empty table/schema (`Issue #75 <https://github.com/libattachsql/libattachsql/issues/75>`_)
* Fixed double packet clear corrupts read buffer (`Issue #73 <https://github.com/libattachsql/libattachsql/issues/73>`_)
* Added prepared statement support (`Issue #32 <https://github.com/libattachsql/libattachsql/issues/32>`_)

Version 0.3
-----------

Version 0.3.0 Alpha (2014-09-01)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Fixed infinite loop memory eater for test run when MySQL server not present (`Issue #48 <https://github.com/libattachsql/libattachsql/issues/48>`_)
* Add UDS test case (`Issue #46 <https://github.com/libattachsql/libattachsql/issues/46>`_).  Note, the ``MYSQL_SOCK`` env variable needs to be set to use it.
* Add protocol compression support (`Issue #9 <https://github.com/libattachsql/libattachsql/issues/9>`_)
* Additional documentation (`Issue #44 <https://github.com/libattachsql/libattachsql/issues/44>`_, `Issue #58 <https://github.com/libattachsql/libattachsql/issues/58>`_ and `Issue #59 <https://github.com/libattachsql/libattachsql/issues/59>`_)
* Fixed case where multiple network writes could overwrite each other
* Add optional SSL support using OpenSSL (`Issue #10 <https://github.com/libattachsql/libattachsql/issues/10>`_)
* Fix valgrind reported problems (`Issue #55 <https://github.com/libattachsql/libattachsql/issues/55>`_)
* Fix cppcheck reported problems
* Fix 32bit CLang compiling
* Overhaul Travis configuration to test many more things

Version 0.2
-----------

Version 0.2.0 Alpha (2014-08-15)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Fixed 2 issues found by Coverity (`Issue #25 <https://github.com/libattachsql/libattachsql/issues/25>`_)
* Cleanup m4 files (`Issue #28 <https://github.com/libattachsql/libattachsql/issues/28>`_)
* Fixed in_query flag status (`Issue #31 <https://github.com/libattachsql/libattachsql/issues/31>`_)
* Add row buffering support (`Issue #8 <https://github.com/libattachsql/libattachsql/issues/8>`_)
* Connect on first query is now non-blocking (`Issue #39 <https://github.com/libattachsql/libattachsql/issues/39>`_)
* Memory alloc/free cleanups
* Default read buffer is 1MB instead of 1GB (big oops!)
* Additional documentation (`Issue #38 <https://github.com/libattachsql/libattachsql/issues/38>`_ and `Issue #30 <https://github.com/libattachsql/libattachsql/issues/30>`_)
* Fixed linking libAttachSQL to C applications

Version 0.1
-----------

Version 0.1.1 Alpha (Never released)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Fixed 2 issues found by Coverity (`Issue #25 <https://github.com/libattachsql/libattachsql/issues/25>`_)

Version 0.1.0 Alpha (2014-08-08)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Initial Alpha version
