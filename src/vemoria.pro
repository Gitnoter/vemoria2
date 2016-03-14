#-------------------------------------------------
# Project Vemoria
#
# Vemoria aims to be an environment for archiving multimedia files.
#
#
# This project is licensed under the EUPL v.1.1 or a later version.
#-------------------------------------------------

TEMPLATE = subdirs

SUBDIRS = main \
	gui \
	logic \
	repository \
	unittest \
	libgit2 \
	libqgit2 \
#	test-libgit2 \
#	test-libqgit2 \
# Include the tests of libgit2 and libqgti2 only if needed
# Note that they are not yet fully supported:
# - test-libgit2 passes on Linux only, but not on MINGW32
# - test-libqgit2 passes not yet fully on any platform
# This is not necessarily due to problems in the libs but
# mainly (hopefully) due to test environment setup issues.

main.depends          = libgit2 libqgit2 repository logic gui
unittest.depends      = libgit2 libqgit2 repository logic
test-libqgit2.depends = libgit2 libqgit2
test-libgit2.depends  = libgit2

RESOURCES = \
        icons.qrc

OTHER_FILES = \
        ../bin/run-build \
        ../doc/doxygen/Doxyfile \
        ../doc/doxygen/mainpage.dox \
        ../doc/doxygen/libqgit2.dox \
        ../doc/doxygen/modules.dox \

