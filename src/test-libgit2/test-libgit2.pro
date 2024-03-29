# qmake project file of libqgit2 examples

QT -= gui core
CONFIG -= app_bundle    # for Mac users

TARGET = run-test-libgit2
TEMPLATE = app

*-g++ {
    # standard GNU c++ behaviour is to complain about this, but the
    # sources are not prepared to fullfill all initializations
    # Some flags just taken from the original CMakeLists.txt settings
    QMAKE_CFLAGS += \
        -Wall \
        -Wextra \
        -Wno-missing-field-initializers \
        -Wno-unused-function \
        -Wno-parentheses \
        -Wno-unused-parameter \
        -Wno-implicit-function-declaration \
        -Wno-unused-result \

    DEFINES += _GNU_SOURCE
}

contains(QT_ARCH, .*64.*) {
    DEFINES += GIT_ARCH_64
} else {
    DEFINES += GIT_ARCH_32
}

DEFINES += STDC
DEFINES += _FILE_OFFSET_BITS=64

DEFINES += CLAR_FIXTURE_PATH=\\\"$$_PRO_FILE_PWD_/../libgit2/tests/resources\\\" \
        CLAR_RESOURCES=\\\"$$_PRO_FILE_PWD_/../libgit2/tests/resources\\\" \
        CLAR_TMPDIR=\\\"libgit2_tests\\\"

INCLUDEPATH += \
  ../libgit2/include \
  ../libgit2/src \
  ../libgit2/deps/zlib \
  ../libgit2/tests \

win32-g++ {
  DEFINES += WIN32
  DEFINES += _WIN32_WINNT=0x0501

  INCLUDEPATH += \
    ../libgit2/deps/regex \
}

HEADERS += \
  ../libgit2/tests/clar.h \
  ../libgit2/tests/clar_libgit2.h \
  ../libgit2/tests/clar/fixtures.h \
  ../libgit2/tests/clar/fs.h \
  ../libgit2/tests/clar/print.h \
  ../libgit2/tests/clar/sandbox.h \
  ../libgit2/tests/attr/attr_expect.h \
  ../libgit2/tests/blame/blame_helpers.h \
  ../libgit2/tests/checkout/checkout_helpers.h \
  ../libgit2/tests/config/config_helpers.h \
  ../libgit2/tests/describe/describe_helpers.h \
  ../libgit2/tests/diff/diff_helpers.h \
  ../libgit2/tests/fetchhead/fetchhead_data.h \
  ../libgit2/tests/filter/crlf.h \
  ../libgit2/tests/merge/merge_helpers.h \
  ../libgit2/tests/object/raw/data.h \
  ../libgit2/tests/odb/loose_data.h \
  ../libgit2/tests/odb/pack_data.h \
  ../libgit2/tests/odb/pack_data_one.h \
  ../libgit2/tests/online/push_util.h \
  ../libgit2/tests/refs/ref_helpers.h \
  ../libgit2/tests/repo/repo_helpers.h \
  ../libgit2/tests/reset/reset_helpers.h \
  ../libgit2/tests/stash/stash_helpers.h \
  ../libgit2/tests/status/status_data.h \
  ../libgit2/tests/status/status_helpers.h \
  ../libgit2/tests/submodule/submodule_helpers.h \
  ../libgit2/tests/threads/thread_helpers.h \

SOURCES += \
  ../libgit2/tests/main.c \
  ../libgit2/tests/attr/file.c \
  ../libgit2/tests/attr/flags.c \
  ../libgit2/tests/attr/ignore.c \
  ../libgit2/tests/attr/lookup.c \
  ../libgit2/tests/attr/repo.c \
  ../libgit2/tests/blame/blame_helpers.c \
  ../libgit2/tests/blame/buffer_blame.c \
  ../libgit2/tests/blame/getters.c \
  ../libgit2/tests/blame/harder.c \
  ../libgit2/tests/blame/simple.c \
  ../libgit2/tests/buf/basic.c \
  ../libgit2/tests/buf/oom.c \
  ../libgit2/tests/buf/splice.c \
  ../libgit2/tests/checkout/binaryunicode.c \
  ../libgit2/tests/checkout/checkout_helpers.c \
  ../libgit2/tests/checkout/conflict.c \
  ../libgit2/tests/checkout/crlf.c \
  ../libgit2/tests/checkout/head.c \
  ../libgit2/tests/checkout/icase.c \
  ../libgit2/tests/checkout/index.c \
  ../libgit2/tests/checkout/nasty.c \
  ../libgit2/tests/checkout/tree.c \
  ../libgit2/tests/checkout/typechange.c \
  ../libgit2/tests/cherrypick/bare.c \
  ../libgit2/tests/cherrypick/workdir.c \
  ../libgit2/tests/clone/empty.c \
  ../libgit2/tests/clone/local.c \
  ../libgit2/tests/clone/nonetwork.c \
  ../libgit2/tests/clone/transport.c \
  ../libgit2/tests/commit/commit.c \
  ../libgit2/tests/commit/write_commit.c \
  ../libgit2/tests/commit/parent.c \
  ../libgit2/tests/commit/parse.c \
  ../libgit2/tests/commit/signature.c \
  ../libgit2/tests/config/add.c \
  ../libgit2/tests/config/backend.c \
  ../libgit2/tests/config/config_helpers.c \
  ../libgit2/tests/config/configlevel.c \
  ../libgit2/tests/config/global.c \
  ../libgit2/tests/config/include.c \
  ../libgit2/tests/config/multivar.c \
  ../libgit2/tests/config/new.c \
  ../libgit2/tests/config/read.c \
  ../libgit2/tests/config/rename.c \
  ../libgit2/tests/config/snapshot.c \
  ../libgit2/tests/config/stress.c \
  ../libgit2/tests/config/validkeyname.c \
  ../libgit2/tests/config/write.c \
  ../libgit2/tests/core/bitvec.c \
  ../libgit2/tests/core/buffer.c \
  ../libgit2/tests/core/copy.c \
  ../libgit2/tests/core/dirent.c \
  ../libgit2/tests/core/env.c \
  ../libgit2/tests/core/errors.c \
  ../libgit2/tests/core/features.c \
  ../libgit2/tests/core/filebuf.c \
  ../libgit2/tests/core/hex.c \
  ../libgit2/tests/core/iconv.c \
  ../libgit2/tests/core/init.c \
  ../libgit2/tests/core/link.c \
  ../libgit2/tests/core/mkdir.c \
  ../libgit2/tests/core/oid.c \
  ../libgit2/tests/core/oidmap.c \
  ../libgit2/tests/core/opts.c \
  ../libgit2/tests/core/path.c \
  ../libgit2/tests/core/pool.c \
  ../libgit2/tests/core/posix.c \
  ../libgit2/tests/core/pqueue.c \
  ../libgit2/tests/core/rmdir.c \
  ../libgit2/tests/core/sortedcache.c \
  ../libgit2/tests/core/stat.c \
  ../libgit2/tests/core/string.c \
  ../libgit2/tests/core/strmap.c \
  ../libgit2/tests/core/strtol.c \
  ../libgit2/tests/core/vector.c \
  ../libgit2/tests/core/zstream.c \
  ../libgit2/tests/date/date.c \
  ../libgit2/tests/date/rfc2822.c \
  ../libgit2/tests/describe/describe.c \
  ../libgit2/tests/describe/describe_helpers.c \
  ../libgit2/tests/describe/t6120.c \
  ../libgit2/tests/diff/binary.c \
  ../libgit2/tests/diff/blob.c \
  ../libgit2/tests/diff/diff_helpers.c \
  ../libgit2/tests/diff/diffiter.c \
  ../libgit2/tests/diff/drivers.c \
  ../libgit2/tests/diff/format_email.c \
  ../libgit2/tests/diff/index_diff.c \
  ../libgit2/tests/diff/iterator.c \
  ../libgit2/tests/diff/notify.c \
  ../libgit2/tests/diff/patch.c \
  ../libgit2/tests/diff/pathspec.c \
  ../libgit2/tests/diff/rename_diff.c \
  ../libgit2/tests/diff/stats.c \
  ../libgit2/tests/diff/submodules.c \
  ../libgit2/tests/diff/tree_diff.c \
  ../libgit2/tests/diff/workdir_diff.c \
  ../libgit2/tests/fetchhead/nonetwork_fetch.c \
  ../libgit2/tests/filter/blob_filter.c \
  ../libgit2/tests/filter/crlf_filter.c \
  ../libgit2/tests/filter/custom.c \
  ../libgit2/tests/filter/ident.c \
  ../libgit2/tests/graph/descendant_of.c \
  ../libgit2/tests/index/addall.c \
  ../libgit2/tests/index/cache.c \
  ../libgit2/tests/index/collision.c \
  ../libgit2/tests/index/conflicts.c \
  ../libgit2/tests/index/crlf_index.c \
  ../libgit2/tests/index/filemodes.c \
  ../libgit2/tests/index/inmemory.c \
  ../libgit2/tests/index/names.c \
  ../libgit2/tests/index/read_tree.c \
  ../libgit2/tests/index/rename_index.c \
  ../libgit2/tests/index/reuc.c \
  ../libgit2/tests/index/stage.c \
  ../libgit2/tests/index/tests.c \
  ../libgit2/tests/merge/files.c \
  ../libgit2/tests/merge/merge_helpers.c \
  ../libgit2/tests/merge/trees/automerge.c \
  ../libgit2/tests/merge/trees/commits.c \
  ../libgit2/tests/merge/trees/modeconflict.c \
  ../libgit2/tests/merge/trees/renames.c \
  ../libgit2/tests/merge/trees/treediff.c \
  ../libgit2/tests/merge/trees/trivial.c \
  ../libgit2/tests/merge/workdir/analysis.c \
  ../libgit2/tests/merge/workdir/dirty.c \
  ../libgit2/tests/merge/workdir/renames_workdir.c \
  ../libgit2/tests/merge/workdir/setup.c \
  ../libgit2/tests/merge/workdir/simple_workdir.c \
  ../libgit2/tests/merge/workdir/submodules_workdir.c \
  ../libgit2/tests/merge/workdir/trivial_workdir.c \
  ../libgit2/tests/network/cred.c \
  ../libgit2/tests/network/fetchlocal.c \
  ../libgit2/tests/network/matchhost.c \
  ../libgit2/tests/network/refspecs.c \
  ../libgit2/tests/network/remote/createthenload.c \
  ../libgit2/tests/network/remote/defaultbranch.c \
  ../libgit2/tests/network/remote/delete.c \
  ../libgit2/tests/network/remote/isvalidname_remote.c \
  ../libgit2/tests/network/remote/local_remote.c \
  ../libgit2/tests/network/remote/remotes.c \
  ../libgit2/tests/network/remote/rename_remote.c \
  ../libgit2/tests/network/urlparse.c \
  ../libgit2/tests/notes/notes.c \
  ../libgit2/tests/notes/notesref.c \
  ../libgit2/tests/object/blob/filter.c \
  ../libgit2/tests/object/blob/fromchunks.c \
  ../libgit2/tests/object/blob/write_blob.c \
  ../libgit2/tests/object/cache_object.c \
  ../libgit2/tests/object/commit/commitstagedfile.c \
  ../libgit2/tests/object/lookupbypath.c \
  ../libgit2/tests/object/lookup_object.c \
  ../libgit2/tests/object/message.c \
  ../libgit2/tests/object/peel.c \
  ../libgit2/tests/object/raw/chars.c \
  ../libgit2/tests/object/raw/compare.c \
  ../libgit2/tests/object/raw/convert.c \
  ../libgit2/tests/object/raw/fromstr.c \
  ../libgit2/tests/object/raw/hash.c \
  ../libgit2/tests/object/raw/short.c \
  ../libgit2/tests/object/raw/size.c \
  ../libgit2/tests/object/raw/type2string.c \
  ../libgit2/tests/object/raw/write_raw.c \
  ../libgit2/tests/object/shortid.c \
  ../libgit2/tests/object/tag/list.c \
  ../libgit2/tests/object/tag/peel_tag.c \
  ../libgit2/tests/object/tag/read_tag.c \
  ../libgit2/tests/object/tag/write_tag.c \
  ../libgit2/tests/object/tree/attributes.c \
  ../libgit2/tests/object/tree/duplicateentries.c \
  ../libgit2/tests/object/tree/frompath.c \
  ../libgit2/tests/object/tree/read_object_tree.c \
  ../libgit2/tests/object/tree/walk.c \
  ../libgit2/tests/object/tree/write_tree.c \
  ../libgit2/tests/odb/alternates.c \
  ../libgit2/tests/odb/backend/nobackend.c \
  ../libgit2/tests/odb/backend/nonrefreshing.c \
  ../libgit2/tests/odb/emptyobjects.c \
  ../libgit2/tests/odb/foreach.c \
  ../libgit2/tests/odb/loose.c \
  ../libgit2/tests/odb/mixed.c \
  ../libgit2/tests/odb/packed.c \
  ../libgit2/tests/odb/packed_one.c \
  ../libgit2/tests/odb/sorting.c \
  ../libgit2/tests/odb/streamwrite.c \
  ../libgit2/tests/online/clone.c \
  ../libgit2/tests/online/fetch.c \
  ../libgit2/tests/online/fetchhead.c \
  ../libgit2/tests/online/push.c \
  ../libgit2/tests/online/push_util.c \
  ../libgit2/tests/pack/indexer.c \
  ../libgit2/tests/pack/packbuilder.c \
  ../libgit2/tests/pack/sharing.c \
  ../libgit2/tests/path/core.c \
  ../libgit2/tests/path/win32.c \
  ../libgit2/tests/rebase/abort.c \
  ../libgit2/tests/rebase/iterator_rebase.c \
  ../libgit2/tests/rebase/merge.c \
  ../libgit2/tests/rebase/setup_rebase.c \
  ../libgit2/tests/refs/branches/create_branches.c \
  ../libgit2/tests/refs/branches/delete_branches.c \
  ../libgit2/tests/refs/branches/ishead.c \
  ../libgit2/tests/refs/branches/iterator_branches.c \
  ../libgit2/tests/refs/branches/lookup_branches.c \
  ../libgit2/tests/refs/branches/move.c \
  ../libgit2/tests/refs/branches/name.c \
  ../libgit2/tests/refs/branches/remote.c \
  ../libgit2/tests/refs/branches/upstream.c \
  ../libgit2/tests/refs/branches/upstreamname.c \
  ../libgit2/tests/refs/crashes.c \
  ../libgit2/tests/refs/create.c \
  ../libgit2/tests/refs/createwithlog.c \
  ../libgit2/tests/refs/delete_refs.c \
  ../libgit2/tests/refs/foreachglob.c \
  ../libgit2/tests/refs/isvalidname.c \
  ../libgit2/tests/refs/iterator_refs.c \
  ../libgit2/tests/refs/listall.c \
  ../libgit2/tests/refs/list_refs.c \
  ../libgit2/tests/refs/lookup_refs.c \
  ../libgit2/tests/refs/normalize.c \
  ../libgit2/tests/refs/overwrite.c \
  ../libgit2/tests/refs/pack.c \
  ../libgit2/tests/refs/peel_refs.c \
  ../libgit2/tests/refs/races.c \
  ../libgit2/tests/refs/read_refs.c \
  ../libgit2/tests/refs/ref_helpers.c \
  ../libgit2/tests/refs/reflog/drop.c \
  ../libgit2/tests/refs/reflog/reflog.c \
  ../libgit2/tests/refs/rename_refs.c \
  ../libgit2/tests/refs/revparse.c \
  ../libgit2/tests/refs/settargetwithlog.c \
  ../libgit2/tests/refs/setter.c \
  ../libgit2/tests/refs/shorthand.c \
  ../libgit2/tests/refs/transactions.c \
  ../libgit2/tests/refs/unicode.c \
  ../libgit2/tests/refs/update.c \
  ../libgit2/tests/repo/config.c \
  ../libgit2/tests/repo/discover.c \
  ../libgit2/tests/repo/getters_repo.c \
  ../libgit2/tests/repo/hashfile.c \
  ../libgit2/tests/repo/head_repo.c \
  ../libgit2/tests/repo/headtree.c \
  ../libgit2/tests/repo/init_repo.c \
  ../libgit2/tests/repo/iterator_repo.c \
  ../libgit2/tests/repo/message_repo.c \
  ../libgit2/tests/repo/open.c \
  ../libgit2/tests/repo/pathspec_repo.c \
  ../libgit2/tests/repo/repo_helpers.c \
  ../libgit2/tests/repo/setters.c \
  ../libgit2/tests/repo/shallow.c \
  ../libgit2/tests/repo/state.c \
  ../libgit2/tests/reset/default.c \
  ../libgit2/tests/reset/hard.c \
  ../libgit2/tests/reset/mixed_reset.c \
  ../libgit2/tests/reset/reset_helpers.c \
  ../libgit2/tests/reset/soft.c \
  ../libgit2/tests/revert/bare_revert.c \
  ../libgit2/tests/revert/workdir_revert.c \
  ../libgit2/tests/revwalk/basic_revwalk.c \
  ../libgit2/tests/revwalk/hidecb.c \
  ../libgit2/tests/revwalk/mergebase.c \
  ../libgit2/tests/revwalk/signatureparsing.c \
  ../libgit2/tests/revwalk/simplify.c \
  ../libgit2/tests/stash/drop_stash.c \
  ../libgit2/tests/stash/foreach_stash.c \
  ../libgit2/tests/stash/save.c \
  ../libgit2/tests/stash/stash_helpers.c \
  ../libgit2/tests/stash/submodules_stash.c \
  ../libgit2/tests/status/ignore_status.c \
  ../libgit2/tests/status/renames_status.c \
  ../libgit2/tests/status/single.c \
  ../libgit2/tests/status/status_helpers.c \
  ../libgit2/tests/status/submodules_status.c \
  ../libgit2/tests/status/worktree.c \
  ../libgit2/tests/status/worktree_init.c \
  ../libgit2/tests/stress/diff.c \
  ../libgit2/tests/structinit/structinit.c \
  ../libgit2/tests/submodule/add_submodule.c \
  ../libgit2/tests/submodule/init_submodule.c \
  ../libgit2/tests/submodule/lookup_submodule.c \
  ../libgit2/tests/submodule/modify.c \
  ../libgit2/tests/submodule/nosubs.c \
  ../libgit2/tests/submodule/repository_init.c \
  ../libgit2/tests/submodule/status.c \
  ../libgit2/tests/submodule/submodule_helpers.c \
  ../libgit2/tests/submodule/update_submodule.c \
  ../libgit2/tests/threads/basic_threads.c \
  ../libgit2/tests/threads/diff_threads.c \
  ../libgit2/tests/threads/iterator_threads.c \
  ../libgit2/tests/threads/refdb.c \
  ../libgit2/tests/threads/thread_helpers.c \
  ../libgit2/tests/trace/trace.c \
  ../libgit2/tests/transport/register.c \
  ../libgit2/tests/clar.c \
  ../libgit2/tests/clar_libgit2.c \

OTHER_FILES += \
  ../libgit2/tests/clar.suite \

# tell includes.pri which libs we need
DEPENDENCY_LIBRARIES = libgit2
include(../qmake/includes.pri)

win32 {
    # we need the windows socket library
    LIBS += -lws2_32
}
