#ifndef AUTOTEST_H
#define AUTOTEST_H

// This file was originally taken from the following URLs and slightly modified:
// http://qtcreator.blogspot.com/2009/10/running-multiple-unit-tests.html
// http://qtcreator.blogspot.com/2010/04/sample-multiple-unit-test-project.html

#include <QTest>
#include <QList>
#include <QString>
#include <QSharedPointer>
#include <QtDebug>

namespace AutoTest
{
  typedef QList<QObject*> TestList;

  inline TestList& testList()
  {
    static TestList list;
    return list;
  }

  inline bool findObject(QObject* object)
  {
    TestList& list = testList();
    if (list.contains(object))
    {
      return true;
    }
    foreach (QObject* test, list)
    {
      if (test->objectName() == object->objectName())
      {
        return true;
      }
    }
    return false;
  }

  inline void addTest(QObject* object)
  {
    TestList& list = testList();
    if (!findObject(object))
    {
      list.append(object);
    }
  }

  inline int run(int argc, char *argv[])
  {
    const int ERROR = -1;
    int ret = 0;
    int failed = 0;
    int passed = 0;

    foreach (QObject* test, testList())
    {
      if( QTest::qExec(test, argc, argv) == 0 )
      {
        ++passed;
      }
      else
      {
        ++failed;
        ret = ERROR;
      }
    }

    qDebug() << "Overall result:" << ((ret==0)?"PASS,":"FAIL,")
             << passed << "suites passed," << failed << "suites failed";

    return ret;
  }
}

template <class T>
class Test
{
  public:
    QSharedPointer<T> child;

    Test(const QString& name) : child(new T)
    {
      child->setObjectName(name);
      AutoTest::addTest(child.data());
    }
};

#define AUTO_TEST_SUITE(className) static Test<className> t(#className)

#define TEST_MAIN \
  int main(int argc, char *argv[]) \
  { \
    return AutoTest::run(argc, argv); \
  }

// Add some overloaded qCompare() functions, see qtestcase.h for the
// default ones. Otherwise only the general qCompare template will be
// used which just prints "Compared values are not the same" in case of
// unequality; we want to see the values too!
#include <string>
#include <sstream>
namespace QTest {
    inline
    bool qCompare(std::string const & actual, char const * expected,
                  char const * actualExpression, char const * expectedExpression,
                  char const * file, int line)
    {
        return qCompare(actual.c_str(), expected,
                        actualExpression, expectedExpression, file, line);
    }

    inline
    bool qCompare(std::string const & actual, std::string const & expected,
                  char const * actualExpression, char const * expectedExpression,
                  char const * file, int line)
    {
        return qCompare(actual.c_str(), expected.c_str(),
                        actualExpression, expectedExpression, file, line);
    }

    // For ostringstreams, we just want to compare the underlying
    // strings and see any difference.
    inline
    bool qCompare(std::ostringstream const & actual, std::ostringstream const & expected,
                  char const * actualExpression, char const * expectedExpression,
                  char const * file, int line)
    {
        return qCompare(actual.str(), expected.str(),
                        actualExpression, expectedExpression, file, line);
    }

    inline
    bool qCompare(std::ostringstream const & actual, std::string const & expected,
                  char const * actualExpression, char const * expectedExpression,
                  char const * file, int line)
    {
        return qCompare(actual.str(), expected,
                        actualExpression, expectedExpression, file, line);
    }

    inline
    bool qCompare(std::ostringstream const & actual, char const * expected,
                  char const * actualExpression, char const * expectedExpression,
                  char const * file, int line)
    {
        return qCompare(actual.str().c_str(), expected,
                        actualExpression, expectedExpression, file, line);
    }
}

#endif // AUTOTEST_H
