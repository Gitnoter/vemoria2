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

AUTO_TEST_SUITE(TestLibqgit);

#include "LibqgitTest.moc"
