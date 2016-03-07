////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////

#include "../version.h"
#include "AutoTest.h"
#include <QString>
#include <QtTest>

class TestVersion : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
        void isNotEmpty();
};

void TestVersion::isNotEmpty()
{
    // Arrange + "Act"
    QString version = VERSION;
    // Assert
    QVERIFY(!version.isEmpty());
    qDebug() << "Version:" << VERSION;
}

AUTO_TEST_SUITE(TestVersion);

#include "VersionTest.moc"
