# qmake project file to build the static library libgit2

QT -= gui
TARGET = git2
TEMPLATE = lib
CONFIG += staticlib

# note: paths relative to _PRO_FILE_PWD_ which is the profile path of
# the subprojects in src/*
INCLUDEPATH += \
  include \
  src \
  deps/zlib \
# $$DESTDIR

# Currently qmake (version 3.0) does not remove a library
# target if the destination directory is not the build directory,
# so we try to add this. Unfortunately it may be non-platform-portable
# as we need to guess the real filename.
# See target 'distclean' in build/app-lib/Makefile
QMAKE_DISTCLEAN += $${DESTDIR}/$${QMAKE_PREFIX_STATICLIB}$${TARGET}.$${QMAKE_EXTENSION_STATICLIB}

win32-g++ {
  INCLUDEPATH += \
    deps/regex \

  # Unfortunately, QtCreator parses these entries even on non-Window
  # systems - so the files are shown in the project tree, although
  # they will not be included into the generated library.

  HEADERS += \
    ./deps/regex/config.h \
    ./deps/regex/regex.h \
    ./deps/regex/regex_internal.h \

  SOURCES += \
    ./deps/regex/regcomp.c \
    ./deps/regex/regex.c \
    ./deps/regex/regexec.c \
    ./deps/regex/regex_internal.c \

}

HEADERS += \
  ./deps/http-parser/http_parser.h \
  ./deps/winhttp/urlmon.h \
  ./deps/winhttp/winhttp.h \
  ./deps/zlib/crc32.h \
  ./deps/zlib/deflate.h \
  ./deps/zlib/inffast.h \
  ./deps/zlib/inffixed.h \
  ./deps/zlib/inflate.h \
  ./deps/zlib/inftrees.h \
  ./deps/zlib/trees.h \
  ./deps/zlib/zconf.h \
  ./deps/zlib/zlib.h \
  ./deps/zlib/zutil.h \
#
  ./include/git2/annotated_commit.h \
  ./include/git2/attr.h \
  ./include/git2/blame.h \
  ./include/git2/blob.h \
  ./include/git2/branch.h \
  ./include/git2/buffer.h \
  ./include/git2/checkout.h \
  ./include/git2/cherrypick.h \
  ./include/git2/clone.h \
  ./include/git2/commit.h \
  ./include/git2/common.h \
  ./include/git2/config.h \
  ./include/git2/cred_helpers.h \
  ./include/git2/describe.h \
  ./include/git2/diff.h \
  ./include/git2/errors.h \
  ./include/git2/filter.h \
  ./include/git2/global.h \
  ./include/git2/graph.h \
  ./include/git2.h \
  ./include/git2/ignore.h \
  ./include/git2/indexer.h \
  ./include/git2/index.h \
  ./include/git2/inttypes.h \
  ./include/git2/merge.h \
  ./include/git2/message.h \
  ./include/git2/net.h \
  ./include/git2/notes.h \
  ./include/git2/object.h \
  ./include/git2/odb_backend.h \
  ./include/git2/odb.h \
  ./include/git2/oidarray.h \
  ./include/git2/oid.h \
  ./include/git2/pack.h \
  ./include/git2/patch.h \
  ./include/git2/pathspec.h \
  ./include/git2/rebase.h \
  ./include/git2/refdb.h \
  ./include/git2/reflog.h \
  ./include/git2/refs.h \
  ./include/git2/refspec.h \
  ./include/git2/remote.h \
  ./include/git2/repository.h \
  ./include/git2/reset.h \
  ./include/git2/revert.h \
  ./include/git2/revparse.h \
  ./include/git2/revwalk.h \
  ./include/git2/signature.h \
  ./include/git2/stash.h \
  ./include/git2/status.h \
  ./include/git2/stdint.h \
  ./include/git2/strarray.h \
  ./include/git2/submodule.h \
  ./include/git2/sys/commit.h \
  ./include/git2/sys/config.h \
  ./include/git2/sys/diff.h \
  ./include/git2/sys/filter.h \
  ./include/git2/sys/hashsig.h \
  ./include/git2/sys/index.h \
  ./include/git2/sys/mempack.h \
  ./include/git2/sys/odb_backend.h \
  ./include/git2/sys/openssl.h \
  ./include/git2/sys/refdb_backend.h \
  ./include/git2/sys/reflog.h \
  ./include/git2/sys/refs.h \
  ./include/git2/sys/repository.h \
  ./include/git2/sys/stream.h \
  ./include/git2/sys/transport.h \
  ./include/git2/tag.h \
  ./include/git2/trace.h \
  ./include/git2/transaction.h \
  ./include/git2/transport.h \
  ./include/git2/tree.h \
  ./include/git2/types.h \
  ./include/git2/version.h \
#
  ./script/user_nodefs.h \
#
  ./src/annotated_commit.h \
  ./src/array.h \
  ./src/attrcache.h \
  ./src/attr_file.h \
  ./src/attr.h \
  ./src/bitvec.h \
  ./src/blame_git.h \
  ./src/blame.h \
  ./src/blob.h \
  ./src/branch.h \
  ./src/buffer.h \
  ./src/buf_text.h \
  ./src/cache.h \
  ./src/cc-compat.h \
  ./src/checkout.h \
  ./src/clone.h \
  ./src/commit.h \
  ./src/commit_list.h \
  ./src/common.h \
  ./src/config_file.h \
  ./src/config.h \
  ./src/curl_stream.h \
  ./src/delta-apply.h \
  ./src/delta.h \
  ./src/diff_driver.h \
  ./src/diff_file.h \
  ./src/diff.h \
  ./src/diff_patch.h \
  ./src/diff_xdiff.h \
  ./src/fetch.h \
  ./src/fetchhead.h \
  ./src/filebuf.h \
  ./src/fileops.h \
  ./src/filter.h \
  ./src/fnmatch.h \
  ./src/global.h \
  ./src/hash.h \
  ./src/hash/hash_common_crypto.h \
  ./src/hash/hash_generic.h \
  ./src/hash/hash_openssl.h \
  ./src/hash/hash_win32.h \
  ./src/idxmap.h \
  ./src/ignore.h \
  ./src/index.h \
  ./src/integer.h \
  ./src/iterator.h \
  ./src/khash.h \
  ./src/map.h \
  ./src/merge.h \
  ./src/message.h \
  ./src/mwindow.h \
  ./src/netops.h \
  ./src/notes.h \
  ./src/object.h \
  ./src/odb.h \
  ./src/offmap.h \
  ./src/oidarray.h \
  ./src/oid.h \
  ./src/oidmap.h \
  ./src/openssl_stream.h \
  ./src/pack.h \
  ./src/pack-objects.h \
  ./src/path.h \
  ./src/pathspec.h \
  ./src/pool.h \
  ./src/posix.h \
  ./src/pqueue.h \
  ./src/push.h \
  ./src/refdb_fs.h \
  ./src/refdb.h \
  ./src/reflog.h \
  ./src/refs.h \
  ./src/refspec.h \
  ./src/remote.h \
  ./src/repository.h \
  ./src/repo_template.h \
  ./src/revwalk.h \
  ./src/sha1_lookup.h \
  ./src/signature.h \
  ./src/socket_stream.h \
  ./src/sortedcache.h \
  ./src/status.h \
  ./src/stransport_stream.h \
  ./src/stream.h \
  ./src/strmap.h \
  ./src/strnlen.h \
  ./src/submodule.h \
  ./src/sysdir.h \
  ./src/tag.h \
  ./src/thread-utils.h \
  ./src/tls_stream.h \
  ./src/trace.h \
  ./src/transaction.h \
  ./src/transports/auth.h \
  ./src/transports/auth_negotiate.h \
  ./src/transports/cred.h \
  ./src/transports/smart.h \
  ./src/tree-cache.h \
  ./src/tree.h \
  ./src/unix/posix.h \
  ./src/userdiff.h \
  ./src/util.h \
  ./src/vector.h \
  ./src/win32/dir.h \
  ./src/win32/error.h \
  ./src/win32/findfile.h \
  ./src/win32/mingw-compat.h \
  ./src/win32/msvc-compat.h \
  ./src/win32/path_w32.h \
  ./src/win32/posix.h \
  ./src/win32/precompiled.h \
  ./src/win32/pthread.h \
  ./src/win32/reparse.h \
  ./src/win32/utf-conv.h \
  ./src/win32/version.h \
  ./src/win32/w32_buffer.h \
  ./src/win32/w32_crtdbg_stacktrace.h \
  ./src/win32/w32_stack.h \
  ./src/win32/w32_util.h \
  ./src/win32/win32-compat.h \
  ./src/xdiff/xdiff.h \
  ./src/xdiff/xdiffi.h \
  ./src/xdiff/xemit.h \
  ./src/xdiff/xinclude.h \
  ./src/xdiff/xmacros.h \
  ./src/xdiff/xprepare.h \
  ./src/xdiff/xtypes.h \
  ./src/xdiff/xutils.h \
  ./src/zstream.h \


SOURCES += \
# ./src/annotated_commit.c \
  ./src/attr.c \
  ./src/attrcache.c \
  ./src/attr_file.c \
# ./src/blame.c \
# ./src/blame_git.c \
# ./src/blob.c \
# ./src/branch.c \
# ./src/buffer.c \
# ./src/buf_text.c \
# ./src/cache.c \
# ./src/checkout.c \
# ./src/cherrypick.c \
# ./src/clone.c \
# ./src/commit.c \
# ./src/commit_list.c \
# ./src/config.c \
# ./src/config_cache.c \
# ./src/config_file.c \
# ./src/crlf.c \
# ./src/curl_stream.c \
# ./src/date.c \
# ./src/delta-apply.c \
# ./src/delta.c \
# ./src/describe.c \
# ./src/diff.c \
# ./src/diff_driver.c \
# ./src/diff_file.c \
# ./src/diff_patch.c \
# ./src/diff_print.c \
# ./src/diff_stats.c \
# ./src/diff_tform.c \
# ./src/diff_xdiff.c \
# ./src/errors.c \
# ./src/fetch.c \
# ./src/fetchhead.c \
# ./src/filebuf.c \
# ./src/fileops.c \
# ./src/filter.c \
# ./src/fnmatch.c \
# ./src/global.c \
# ./src/graph.c \
# ./src/hash.c \
# ./src/hashsig.c \
# ./src/ident.c \
# ./src/ignore.c \
# ./src/index.c \
# ./src/indexer.c \
# ./src/iterator.c \
# ./src/merge.c \
# ./src/merge_file.c \
# ./src/message.c \
# ./src/mwindow.c \
# ./src/netops.c \
# ./src/notes.c \
# ./src/object_api.c \
# ./src/object.c \
# ./src/odb.c \
# ./src/odb_loose.c \
# ./src/odb_mempack.c \
# ./src/odb_pack.c \
# ./src/oidarray.c \
# ./src/oid.c \
# ./src/openssl_stream.c \
# ./src/pack.c \
# ./src/pack-objects.c \
# ./src/path.c \
# ./src/pathspec.c \
# ./src/pool.c \
# ./src/posix.c \
# ./src/pqueue.c \
# ./src/push.c \
# ./src/rebase.c \
# ./src/refdb.c \
# ./src/refdb_fs.c \
# ./src/reflog.c \
# ./src/refs.c \
# ./src/refspec.c \
# ./src/remote.c \
# ./src/repository.c \
# ./src/reset.c \
# ./src/revert.c \
# ./src/revparse.c \
# ./src/revwalk.c \
# ./src/settings.c \
# ./src/sha1_lookup.c \
# ./src/signature.c \
# ./src/socket_stream.c \
# ./src/sortedcache.c \
# ./src/stash.c \
# ./src/status.c \
# ./src/stransport_stream.c \
# ./src/strmap.c \
# ./src/submodule.c \
# ./src/sysdir.c \
# ./src/tag.c \
# ./src/thread-utils.c \
# ./src/tls_stream.c \
# ./src/trace.c \
# ./src/transaction.c \
# ./src/transport.c \
# ./src/tree.c \
# ./src/tree-cache.c \
# ./src/tsort.c \
# ./src/util.c \
# ./src/vector.c \
# ./src/zstream.c \

# ./src/unix/map.c \
# ./src/unix/realpath.c \

# ./src/hash/hash_generic.c \
# ./src/hash/hash_win32.c \

# ./src/transports/auth.c \
# ./src/transports/auth_negotiate.c \
# ./src/transports/cred.c \
# ./src/transports/cred_helpers.c \
# ./src/transports/git.c \
# ./src/transports/http.c \
# ./src/transports/local.c \
# ./src/transports/smart.c \
# ./src/transports/smart_pkt.c \
# ./src/transports/smart_protocol.c \
# ./src/transports/ssh.c \
# ./src/transports/winhttp.c \

# ./src/win32/dir.c \
# ./src/win32/error.c \
# ./src/win32/findfile.c \
# ./src/win32/map.c \
# ./src/win32/path_w32.c \
# ./src/win32/posix_w32.c \
# ./src/win32/precompiled.c \
# ./src/win32/pthread.c \
# ./src/win32/utf-conv.c \
# ./src/win32/w32_buffer.c \
# ./src/win32/w32_crtdbg_stacktrace.c \
# ./src/win32/w32_stack.c \
# ./src/win32/w32_util.c \

# ./src/xdiff/xdiffi.c \
# ./src/xdiff/xemit.c \
# ./src/xdiff/xhistogram.c \
# ./src/xdiff/xmerge.c \
# ./src/xdiff/xpatience.c \
# ./src/xdiff/xprepare.c \
# ./src/xdiff/xutils.c \

# ./deps/zlib/adler32.c \
# ./deps/zlib/crc32.c \
# ./deps/zlib/deflate.c \
# ./deps/zlib/infback.c \
# ./deps/zlib/inffast.c \
# ./deps/zlib/inflate.c \
# ./deps/zlib/inftrees.c \
# ./deps/zlib/trees.c \
# ./deps/zlib/zutil.c \

# ./deps/http-parser/http_parser.c \

OTHER_FILES += \
  ./examples/common.h \
  ./examples/network/common.h \
  \
  ./examples/add.c \
  ./examples/blame.c \
  ./examples/cat-file.c \
  ./examples/common.c \
  ./examples/describe.c \
  ./examples/diff.c \
  ./examples/for-each-ref.c \
  ./examples/general.c \
  ./examples/init.c \
  ./examples/log.c \
  ./examples/network/clone.c \
  ./examples/network/common.c \
  ./examples/network/fetch.c \
  ./examples/network/git2.c \
  ./examples/network/index-pack.c \
  ./examples/network/ls-remote.c \
  ./examples/remote.c \
  ./examples/rev-list.c \
  ./examples/rev-parse.c \
  ./examples/showindex.c \
  ./examples/status.c \
  ./examples/tag.c \
  \
  ./tests/attr/attr_expect.h \
  ./tests/blame/blame_helpers.h \
  ./tests/checkout/checkout_helpers.h \
  ./tests/clar/fixtures.h \
  ./tests/clar/fs.h \
  ./tests/clar.h \
  ./tests/clar_libgit2.h \
  ./tests/clar_libgit2_timer.h \
  ./tests/clar_libgit2_trace.h \
  ./tests/clar/print.h \
  ./tests/clar/sandbox.h \
  ./tests/config/config_helpers.h \
  ./tests/describe/describe_helpers.h \
  ./tests/diff/diff_helpers.h \
  ./tests/fetchhead/fetchhead_data.h \
  ./tests/filter/crlf.h \
  ./tests/filter/custom_helpers.h \
  ./tests/merge/conflict_data.h \
  ./tests/merge/merge_helpers.h \
  ./tests/object/raw/data.h \
  ./tests/odb/loose_data.h \
  ./tests/odb/pack_data.h \
  ./tests/odb/pack_data_one.h \
  ./tests/online/push_util.h \
  ./tests/perf/helper__perf__do_merge.h \
  ./tests/perf/helper__perf__timer.h \
  ./tests/refs/ref_helpers.h \
  ./tests/repo/repo_helpers.h \
  ./tests/reset/reset_helpers.h \
  ./tests/stash/stash_helpers.h \
  ./tests/status/status_data.h \
  ./tests/status/status_helpers.h \
  ./tests/submodule/submodule_helpers.h \
  ./tests/threads/thread_helpers.h \
  \
  ./tests/attr/file.c \
  ./tests/attr/flags.c \
  ./tests/attr/ignore.c \
  ./tests/attr/lookup.c \
  ./tests/attr/repo.c \
  ./tests/blame/blame_helpers.c \
  ./tests/blame/buffer.c \
  ./tests/blame/getters.c \
  ./tests/blame/harder.c \
  ./tests/blame/simple.c \
  ./tests/buf/basic.c \
  ./tests/buf/oom.c \
  ./tests/buf/splice.c \
  ./tests/checkout/binaryunicode.c \
  ./tests/checkout/checkout_helpers.c \
  ./tests/checkout/conflict.c \
  ./tests/checkout/crlf.c \
  ./tests/checkout/head.c \
  ./tests/checkout/icase.c \
  ./tests/checkout/index.c \
  ./tests/checkout/nasty.c \
  ./tests/checkout/tree.c \
  ./tests/checkout/typechange.c \
  ./tests/cherrypick/bare.c \
  ./tests/cherrypick/workdir.c \
  ./tests/clar.c \
  ./tests/clar_libgit2.c \
  ./tests/clar_libgit2_timer.c \
  ./tests/clar_libgit2_trace.c \
  ./tests/clone/empty.c \
  ./tests/clone/local.c \
  ./tests/clone/nonetwork.c \
  ./tests/clone/transport.c \
  ./tests/commit/commit.c \
  ./tests/commit/parent.c \
  ./tests/commit/parse.c \
  ./tests/commit/signature.c \
  ./tests/commit/write.c \
  ./tests/config/add.c \
  ./tests/config/backend.c \
  ./tests/config/config_helpers.c \
  ./tests/config/configlevel.c \
  ./tests/config/global.c \
  ./tests/config/include.c \
  ./tests/config/multivar.c \
  ./tests/config/new.c \
  ./tests/config/read.c \
  ./tests/config/rename.c \
  ./tests/config/snapshot.c \
  ./tests/config/stress.c \
  ./tests/config/validkeyname.c \
  ./tests/config/write.c \
  ./tests/core/bitvec.c \
  ./tests/core/buffer.c \
  ./tests/core/copy.c \
  ./tests/core/dirent.c \
  ./tests/core/env.c \
  ./tests/core/errors.c \
  ./tests/core/features.c \
  ./tests/core/filebuf.c \
  ./tests/core/ftruncate.c \
  ./tests/core/futils.c \
  ./tests/core/hex.c \
  ./tests/core/iconv.c \
  ./tests/core/init.c \
  ./tests/core/link.c \
  ./tests/core/mkdir.c \
  ./tests/core/oid.c \
  ./tests/core/oidmap.c \
  ./tests/core/opts.c \
  ./tests/core/path.c \
  ./tests/core/pool.c \
  ./tests/core/posix.c \
  ./tests/core/pqueue.c \
  ./tests/core/rmdir.c \
  ./tests/core/sortedcache.c \
  ./tests/core/stat.c \
  ./tests/core/stream.c \
  ./tests/core/string.c \
  ./tests/core/strmap.c \
  ./tests/core/strtol.c \
  ./tests/core/structinit.c \
  ./tests/core/useragent.c \
  ./tests/core/vector.c \
  ./tests/core/zstream.c \
  ./tests/date/date.c \
  ./tests/date/rfc2822.c \
  ./tests/describe/describe.c \
  ./tests/describe/describe_helpers.c \
  ./tests/describe/t6120.c \
  ./tests/diff/binary.c \
  ./tests/diff/blob.c \
  ./tests/diff/diff_helpers.c \
  ./tests/diff/diffiter.c \
  ./tests/diff/drivers.c \
  ./tests/diff/format_email.c \
  ./tests/diff/index.c \
  ./tests/diff/iterator.c \
  ./tests/diff/notify.c \
  ./tests/diff/patch.c \
  ./tests/diff/pathspec.c \
  ./tests/diff/rename.c \
  ./tests/diff/stats.c \
  ./tests/diff/submodules.c \
  ./tests/diff/tree.c \
  ./tests/diff/workdir.c \
  ./tests/fetchhead/nonetwork.c \
  ./tests/filter/blob.c \
  ./tests/filter/crlf.c \
  ./tests/filter/custom.c \
  ./tests/filter/custom_helpers.c \
  ./tests/filter/file.c \
  ./tests/filter/ident.c \
  ./tests/filter/query.c \
  ./tests/filter/stream.c \
  ./tests/filter/wildcard.c \
  ./tests/graph/descendant_of.c \
  ./tests/index/addall.c \
  ./tests/index/add.c \
  ./tests/index/bypath.c \
  ./tests/index/cache.c \
  ./tests/index/collision.c \
  ./tests/index/conflicts.c \
  ./tests/index/crlf.c \
  ./tests/index/filemodes.c \
  ./tests/index/inmemory.c \
  ./tests/index/names.c \
  ./tests/index/nsec.c \
  ./tests/index/racy.c \
  ./tests/index/read_index.c \
  ./tests/index/read_tree.c \
  ./tests/index/rename.c \
  ./tests/index/reuc.c \
  ./tests/index/stage.c \
  ./tests/index/tests.c \
  ./tests/main.c \
  ./tests/merge/files.c \
  ./tests/merge/merge_helpers.c \
  ./tests/merge/trees/automerge.c \
  ./tests/merge/trees/commits.c \
  ./tests/merge/trees/modeconflict.c \
  ./tests/merge/trees/recursive.c \
  ./tests/merge/trees/renames.c \
  ./tests/merge/trees/treediff.c \
  ./tests/merge/trees/trivial.c \
  ./tests/merge/trees/whitespace.c \
  ./tests/merge/workdir/analysis.c \
  ./tests/merge/workdir/dirty.c \
  ./tests/merge/workdir/recursive.c \
  ./tests/merge/workdir/renames.c \
  ./tests/merge/workdir/setup.c \
  ./tests/merge/workdir/simple.c \
  ./tests/merge/workdir/submodules.c \
  ./tests/merge/workdir/trivial.c \
  ./tests/network/cred.c \
  ./tests/network/fetchlocal.c \
  ./tests/network/matchhost.c \
  ./tests/network/refspecs.c \
  ./tests/network/remote/createthenload.c \
  ./tests/network/remote/defaultbranch.c \
  ./tests/network/remote/delete.c \
  ./tests/network/remote/isvalidname.c \
  ./tests/network/remote/local.c \
  ./tests/network/remote/push.c \
  ./tests/network/remote/remotes.c \
  ./tests/network/remote/rename.c \
  ./tests/network/urlparse.c \
  ./tests/notes/notes.c \
  ./tests/notes/notesref.c \
  ./tests/object/blob/filter.c \
  ./tests/object/blob/fromchunks.c \
  ./tests/object/blob/write.c \
  ./tests/object/cache.c \
  ./tests/object/commit/commitstagedfile.c \
  ./tests/object/lookupbypath.c \
  ./tests/object/lookup.c \
  ./tests/object/message.c \
  ./tests/object/peel.c \
  ./tests/object/raw/chars.c \
  ./tests/object/raw/compare.c \
  ./tests/object/raw/convert.c \
  ./tests/object/raw/fromstr.c \
  ./tests/object/raw/hash.c \
  ./tests/object/raw/short.c \
  ./tests/object/raw/size.c \
  ./tests/object/raw/type2string.c \
  ./tests/object/raw/write.c \
  ./tests/object/shortid.c \
  ./tests/object/tag/list.c \
  ./tests/object/tag/peel.c \
  ./tests/object/tag/read.c \
  ./tests/object/tag/write.c \
  ./tests/object/tree/attributes.c \
  ./tests/object/tree/duplicateentries.c \
  ./tests/object/tree/frompath.c \
  ./tests/object/tree/read.c \
  ./tests/object/tree/walk.c \
  ./tests/object/tree/write.c \
  ./tests/odb/alternates.c \
  ./tests/odb/backend/nobackend.c \
  ./tests/odb/backend/nonrefreshing.c \
  ./tests/odb/emptyobjects.c \
  ./tests/odb/foreach.c \
  ./tests/odb/loose.c \
  ./tests/odb/mixed.c \
  ./tests/odb/packed.c \
  ./tests/odb/packed_one.c \
  ./tests/odb/sorting.c \
  ./tests/odb/streamwrite.c \
  ./tests/online/badssl.c \
  ./tests/online/clone.c \
  ./tests/online/fetch.c \
  ./tests/online/fetchhead.c \
  ./tests/online/push.c \
  ./tests/online/push_util.c \
  ./tests/online/remotes.c \
  ./tests/pack/indexer.c \
  ./tests/pack/packbuilder.c \
  ./tests/pack/sharing.c \
  ./tests/path/core.c \
  ./tests/path/win32.c \
  ./tests/perf/helper__perf__do_merge.c \
  ./tests/perf/helper__perf__timer.c \
  ./tests/perf/merge.c \
  ./tests/rebase/abort.c \
  ./tests/rebase/inmemory.c \
  ./tests/rebase/iterator.c \
  ./tests/rebase/merge.c \
  ./tests/rebase/setup.c \
  ./tests/refs/branches/create.c \
  ./tests/refs/branches/delete.c \
  ./tests/refs/branches/ishead.c \
  ./tests/refs/branches/iterator.c \
  ./tests/refs/branches/lookup.c \
  ./tests/refs/branches/move.c \
  ./tests/refs/branches/name.c \
  ./tests/refs/branches/remote.c \
  ./tests/refs/branches/upstream.c \
  ./tests/refs/branches/upstreamname.c \
  ./tests/refs/crashes.c \
  ./tests/refs/create.c \
  ./tests/refs/createwithlog.c \
  ./tests/refs/delete.c \
  ./tests/refs/foreachglob.c \
  ./tests/refs/isvalidname.c \
  ./tests/refs/iterator.c \
  ./tests/refs/listall.c \
  ./tests/refs/list.c \
  ./tests/refs/lookup.c \
  ./tests/refs/normalize.c \
  ./tests/refs/overwrite.c \
  ./tests/refs/pack.c \
  ./tests/refs/peel.c \
  ./tests/refs/races.c \
  ./tests/refs/read.c \
  ./tests/refs/ref_helpers.c \
  ./tests/refs/reflog/drop.c \
  ./tests/refs/reflog/reflog.c \
  ./tests/refs/rename.c \
  ./tests/refs/revparse.c \
  ./tests/refs/settargetwithlog.c \
  ./tests/refs/setter.c \
  ./tests/refs/shorthand.c \
  ./tests/refs/transactions.c \
  ./tests/refs/unicode.c \
  ./tests/refs/update.c \
  ./tests/remote/insteadof.c \
  ./tests/repo/config.c \
  ./tests/repo/discover.c \
  ./tests/repo/getters.c \
  ./tests/repo/hashfile.c \
  ./tests/repo/head.c \
  ./tests/repo/headtree.c \
  ./tests/repo/init.c \
  ./tests/repo/iterator.c \
  ./tests/repo/message.c \
  ./tests/repo/new.c \
  ./tests/repo/open.c \
  ./tests/repo/pathspec.c \
  ./tests/repo/repo_helpers.c \
  ./tests/repo/reservedname.c \
  ./tests/repo/setters.c \
  ./tests/repo/shallow.c \
  ./tests/repo/state.c \
  ./tests/reset/default.c \
  ./tests/reset/hard.c \
  ./tests/reset/mixed.c \
  ./tests/reset/reset_helpers.c \
  ./tests/reset/soft.c \
  ./tests/revert/bare.c \
  ./tests/revert/workdir.c \
  ./tests/revwalk/basic.c \
  ./tests/revwalk/hidecb.c \
  ./tests/revwalk/mergebase.c \
  ./tests/revwalk/signatureparsing.c \
  ./tests/revwalk/simplify.c \
  ./tests/stash/apply.c \
  ./tests/stash/drop.c \
  ./tests/stash/foreach.c \
  ./tests/stash/save.c \
  ./tests/stash/stash_helpers.c \
  ./tests/stash/submodules.c \
  ./tests/status/ignore.c \
  ./tests/status/renames.c \
  ./tests/status/single.c \
  ./tests/status/status_helpers.c \
  ./tests/status/submodules.c \
  ./tests/status/worktree.c \
  ./tests/status/worktree_init.c \
  ./tests/stress/diff.c \
  ./tests/submodule/add.c \
  ./tests/submodule/init.c \
  ./tests/submodule/lookup.c \
  ./tests/submodule/modify.c \
  ./tests/submodule/nosubs.c \
  ./tests/submodule/repository_init.c \
  ./tests/submodule/status.c \
  ./tests/submodule/submodule_helpers.c \
  ./tests/submodule/update.c \
  ./tests/threads/basic.c \
  ./tests/threads/diff.c \
  ./tests/threads/iterator.c \
  ./tests/threads/refdb.c \
  ./tests/threads/thread_helpers.c \
  ./tests/trace/trace.c \
  ./tests/trace/windows/stacktrace.c \
  ./tests/transport/register.c \
  ./tests/win32/forbidden.c \
  ./tests/win32/longpath.c \

