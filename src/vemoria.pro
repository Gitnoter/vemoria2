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
        test-libgit2 \
	libqgit2 \
	test-libqgit2 \

OTHER_FILES = \
	../bin/run-build

main.depends          = libgit2 libqgit2 repository logic gui
unittest.depends      = libgit2 libqgit2 repository logic
test-libqgit2.depends = libgit2 libqgit2
test-libgit2.depends  = libgit2
