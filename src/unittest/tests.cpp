#include "../version.h"
#include <QString>
#include <QtTest>

class vemoria_test : public QObject
{
    Q_OBJECT

public:
    vemoria_test();

private Q_SLOTS:
    void initTestCase();
};

vemoria_test::vemoria_test()
{
}

void vemoria_test::initTestCase()
{
      qDebug()<<"Version: "<<VERSION;
      QVERIFY2(true,"gut");
}

QTEST_APPLESS_MAIN(vemoria_test)

#include "tests.moc"
