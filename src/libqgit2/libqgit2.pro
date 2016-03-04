# qmake project file to build the static library libqgit2

QT -= gui
TARGET = qgit2
TEMPLATE = lib
CONFIG += staticlib C++11

# note: paths relative to _PRO_FILE_PWD_ which is the profile path of
# the subprojects in src/*
INCLUDEPATH += \
  src \
  ../libgit2/include \

# Currently qmake (version 3.0) does not remove a library
# target if the destination directory is not the build directory,
# so we try to add this. Unfortunately it may be non-platform-portable
# as we need to guess the real filename.
# See target 'distclean' in build/app-lib/Makefile
QMAKE_DISTCLEAN += $${DESTDIR}/$${QMAKE_PREFIX_STATICLIB}$${TARGET}.$${QMAKE_EXTENSION_STATICLIB}

*-g++ {
    # standard GNU c++ behaviour is to complain about this, but the
    # libgit2 headers we need are not prepared to fullfill all initializations
    QMAKE_CXXFLAGS += \
        -Wno-missing-field-initializers \

}

HEADERS += \
  ./qgit2.h \
  ./src/private/annotatedcommit.cpp \
  ./src/private/buffer.cpp \
  ./src/private/pathcodec.cpp \
  ./src/private/remotecallbacks.cpp \
  ./src/private/strarray.cpp \
  ./src/qgitblob.cpp \
  ./src/qgitcheckoutoptions.cpp \
  ./src/qgitcherrypickoptions.cpp \
  ./src/qgitcommit.cpp \
  ./src/qgitconfig.cpp \
  ./src/qgitcredentials.cpp \
  ./src/qgitdatabasebackend.cpp \
  ./src/qgitdatabase.cpp \
  ./src/qgitdiff.cpp \
  ./src/qgitdiffdelta.cpp \
  ./src/qgitdifffile.cpp \
  ./src/qgitexception.cpp \
  ./src/qgitglobal.cpp \
  ./src/qgitindex.cpp \
  ./src/qgitindexentry.cpp \
  ./src/qgitindexmodel.cpp \
  ./src/qgitmergeoptions.cpp \
  ./src/qgitobject.cpp \
  ./src/qgitoid.cpp \
  ./src/qgitrebase.cpp \
  ./src/qgitrebaseoptions.cpp \
  ./src/qgitref.cpp \
  ./src/qgitremote.cpp \
  ./src/qgitrepository.cpp \
  ./src/qgitrevwalk.cpp \
  ./src/qgitsignature.cpp \
  ./src/qgitstatus.cpp \
  ./src/qgitstatusentry.cpp \
  ./src/qgitstatuslist.cpp \
  ./src/qgitstatusoptions.cpp \
  ./src/qgittag.cpp \
  ./src/qgittree.cpp \
  ./src/qgittreeentry.cpp \
  ./src/credentials_p.h \
  ./src/libqgit2_config.h \
  ./src/private/annotatedcommit.h \
  ./src/private/buffer.h \
  ./src/private/pathcodec.h \
  ./src/private/remotecallbacks.h \
  ./src/private/strarray.h \
  ./src/qgitblob.h \
  ./src/qgitcheckoutoptions.h \
  ./src/qgitcherrypickoptions.h \
  ./src/qgitcommit.h \
  ./src/qgitconfig.h \
  ./src/qgitcredentials.h \
  ./src/qgitdatabasebackend.h \
  ./src/qgitdatabase.h \
  ./src/qgitdiffdelta.h \
  ./src/qgitdifffile.h \
  ./src/qgitdiff.h \
  ./src/qgitexception.h \
  ./src/qgitglobal.h \
  ./src/qgitindexentry.h \
  ./src/qgitindex.h \
  ./src/qgitindexmodel.h \
  ./src/qgitmergeoptions.h \
  ./src/qgitobject.h \
  ./src/qgitoid.h \
  ./src/qgitrebase.h \
  ./src/qgitrebaseoptions.h \
  ./src/qgitref.h \
  ./src/qgitremote.h \
  ./src/qgitrepository.h \
  ./src/qgitrevwalk.h \
  ./src/qgitsignature.h \
  ./src/qgitstatusentry.h \
  ./src/qgitstatus.h \
  ./src/qgitstatuslist.h \
  ./src/qgitstatusoptions.h \
  ./src/qgittag.h \
  ./src/qgittreeentry.h \
  ./src/qgittree.h \

SOURCES += \
  ./src/private/annotatedcommit.cpp \
  ./src/private/buffer.cpp \
  ./src/private/pathcodec.cpp \
  ./src/private/remotecallbacks.cpp \
  ./src/private/strarray.cpp \
  ./src/qgitblob.cpp \
  ./src/qgitcheckoutoptions.cpp \
  ./src/qgitcherrypickoptions.cpp \
  ./src/qgitcommit.cpp \
  ./src/qgitconfig.cpp \
  ./src/qgitcredentials.cpp \
  ./src/qgitdatabasebackend.cpp \
  ./src/qgitdatabase.cpp \
  ./src/qgitdiff.cpp \
  ./src/qgitdiffdelta.cpp \
  ./src/qgitdifffile.cpp \
  ./src/qgitexception.cpp \
  ./src/qgitglobal.cpp \
  ./src/qgitindex.cpp \
  ./src/qgitindexentry.cpp \
  ./src/qgitindexmodel.cpp \
  ./src/qgitmergeoptions.cpp \
  ./src/qgitobject.cpp \
  ./src/qgitoid.cpp \
  ./src/qgitrebase.cpp \
  ./src/qgitrebaseoptions.cpp \
  ./src/qgitref.cpp \
  ./src/qgitremote.cpp \
  ./src/qgitrepository.cpp \
  ./src/qgitrevwalk.cpp \
  ./src/qgitsignature.cpp \
  ./src/qgitstatus.cpp \
  ./src/qgitstatusentry.cpp \
  ./src/qgitstatuslist.cpp \
  ./src/qgitstatusoptions.cpp \
  ./src/qgittag.cpp \
  ./src/qgittree.cpp \
  ./src/qgittreeentry.cpp \

OTHER_FILES += \
  ./tests/TestHelpers.h \
  ./tests/Checkout.cpp \
  ./tests/Clone.cpp \
  ./tests/Diff.cpp \
  ./tests/Fetch.cpp \
  ./tests/Init.cpp \
  ./tests/Push.cpp \
  ./tests/Rebase.cpp \
  ./tests/Repository.cpp \
  ./tests/Revision.cpp \
  ./tests/TestHelpers.cpp \
