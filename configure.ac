#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
#AC_PREREQ([2.69])
AC_INIT([AHP], [0.0.1a], [marcel@m0gg.org])
AM_INIT_AUTOMAKE([1.11 foreign dist-xz])
LT_INIT

AC_CONFIG_SRCDIR([src/], [lib/])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile lib/Makefile])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
AC_PROG_LIBTOOL
AC_LANG([C++])

# Checks for libraries.
PKG_CHECK_MODULES(QT5, [Qt5Core,Qt5Widgets], [], AC_MSG_ERROR([Qt5Core required]))

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT
