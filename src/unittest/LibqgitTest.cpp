////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////

#include "AutoTest.h"
#include "qgit2/qgitglobal.h"

class TestLibqgit : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
        void canBeInitialized();
        void refusesShutdownWithoutInit();
        void countsInitializations();
};

void TestLibqgit::canBeInitialized()
{
    QVERIFY( LibQGit2::initLibQGit2() );
    QVERIFY( LibQGit2::shutdownLibQGit2() );
}

void TestLibqgit::refusesShutdownWithoutInit()
{
    QVERIFY( ! LibQGit2::shutdownLibQGit2() );
}

void TestLibqgit::countsInitializations()
{
    // first init is o.k.
    QVERIFY( LibQGit2::initLibQGit2() );
    // second init return false - already initialized
    QVERIFY( ! LibQGit2::initLibQGit2() );
    // first shutdown returns false - not yet down
    QVERIFY( ! LibQGit2::shutdownLibQGit2() );
    // second shutdown returns true - down
    QVERIFY( LibQGit2::shutdownLibQGit2() );
    // third shutdown returns false - not initialized
    QVERIFY( ! LibQGit2::shutdownLibQGit2() );
}

AUTO_TEST_SUITE(TestLibqgit);

#include "LibqgitTest.moc"
