Version History
===============

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
