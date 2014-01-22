#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(ucltp, 1.0, zhouxg@ucweb.com)
AM_INIT_AUTOMAKE([foreign -Wall])
AC_CONFIG_SRCDIR([type.h])
AC_CONFIG_HEADER([conf.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([pthread], [pthread_rwlock_init])
AC_PROG_LIBTOOL

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_CHECK_FUNCS([memset munmap sqrt strdup])

AC_OUTPUT([Makefile
           util/Makefile
           config/Makefile
           sre/Makefile
           sre/test/Makefile
           dat/Makefile
           dat/test/Makefile
           ner/Makefile
           ner/number/Makefile
           ner/number/test/Makefile
           ner/date/Makefile
           ner/date/test/Makefile])

