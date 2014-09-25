#! /bin/sh

test -n "$srcdir" || srcdir=`dirname "$0"`
test -n "$srcdir" || srcdir=.
(
  cd "$srcdir" &&
  autoreconf --force -v --install &&
  cd ui &&
  qmake
) || exit
test -n "$NOCONFIGURE" || "$srcdir/configure" "$@"
