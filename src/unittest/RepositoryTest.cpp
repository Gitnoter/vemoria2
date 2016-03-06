////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////

#include "AutoTest.h"

class TestRepository : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
        void canBeCreated();
};

void TestRepository::canBeCreated()
{
    QWARN("missing test");
}

AUTO_TEST_SUITE(TestRepository);

#include "RepositoryTest.moc"
