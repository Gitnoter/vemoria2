////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////

#include "Repository.h"
#include "Repository.h"  // verify include protection
#include "qgit2.h"
#include "AutoTest.h"

class TestRepository : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
        void isInitiallyFalse();
        void operatorBoolIsInitiallyFalse();
        void initializesLibqgit();
        void shutsDownLibqgit();
};

void TestRepository::isInitiallyFalse()
{
    Repository repo;

    QVERIFY( ! repo.isOk() );
}

void TestRepository::operatorBoolIsInitiallyFalse()
{
    Repository repo;

    QVERIFY( ! repo ) ;
}

void TestRepository::initializesLibqgit()
{
    // Verify LibQGit2 is uninitialized by
    // initializing once and trying to shutdown
    // two times
    QVERIFY( LibQGit2::initLibQGit2() );
    QVERIFY( LibQGit2::shutdownLibQGit2() );
    QVERIFY( ! LibQGit2::shutdownLibQGit2() );

    Repository repo;
    (void) repo;        // avoid warning "unused variable"

    QVERIFY( LibQGit2::shutdownLibQGit2() );
}

void TestRepository::shutsDownLibqgit()
{
    // Verify LibQGit2 is uninitialized by
    // initializing once and trying to shutdown
    // two times
    QVERIFY( LibQGit2::initLibQGit2() );
    QVERIFY( LibQGit2::shutdownLibQGit2() );
    QVERIFY( ! LibQGit2::shutdownLibQGit2() );

    Repository repo;
    (void) repo;        // avoid warning "unused variable"

    // Shutdown is possible once, but not two times
    QVERIFY( LibQGit2::shutdownLibQGit2() );
    QVERIFY( ! LibQGit2::shutdownLibQGit2() );
}

AUTO_TEST_SUITE(TestRepository);
#include "RepositoryTest.moc"
