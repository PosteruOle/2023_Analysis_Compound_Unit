#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class compound_unit_test : public QObject
{
    Q_OBJECT

public:
    compound_unit_test();
    ~compound_unit_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

compound_unit_test::compound_unit_test()
{

}

compound_unit_test::~compound_unit_test()
{

}

void compound_unit_test::initTestCase()
{

}

void compound_unit_test::cleanupTestCase()
{

}

void compound_unit_test::test_case1()
{

}

QTEST_MAIN(compound_unit_test)

#include "tst_compound_unit_test.moc"
