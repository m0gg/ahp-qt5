bin_PROGRAMS = ahp
ahp_SOURCES = main.cpp
ahp_LDADD = ${top_builddir}/ui/libui.a \
            ${top_builddir}/lib/libahp.a \
            ${QT5_LIBS}


ahp_CFLAGS = ${QT5_CFLAGS} \
            -I${top_builddir}/lib/ -L${top_builddir}/lib/ -L${top_builddir}/ui/ \
            -include ${top_builddir}/config.h -fPIC

ahp_CXXFLAGS = ${QT5_CFLAGS} \
              -I${top_builddir}/lib/ -L${top_builddir}/lib/ -L${top_builddir}/ui/ \
              -include ${top_builddir}/config.h -fPIC
