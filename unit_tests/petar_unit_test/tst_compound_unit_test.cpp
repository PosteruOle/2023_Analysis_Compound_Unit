#include <QtTest>
#include <QCoreApplication>

#include <is_valid.hpp>
#include <compound_unit.hpp>
#include <base_unit.hpp>
#include <base_unit_traits.hpp>
#include <string>

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

    void testCompoundUnitTemplate();
    void testIsValidTemplate();
    void testMergingCompoundUnits();
    void testCondensingCompoundUnits();
    void testMultiplyingCompoundUnits();
};

//-----------------------------------------------
void compound_unit_test::testCompoundUnitTemplate(){
    using acceleration = unit::compound_unit<unit::meter<1>, unit::second<-1>>;
    using cout_format = unit::to_str_type_t<acceleration>;

    std::string return_value=cout_format::str();
    const char *expected_value="m^1s^-1";

    QCOMPARE(return_value, expected_value);
}

void compound_unit_test::testMergingCompoundUnits(){
    using acceleration = unit::compound_unit<unit::meter<1>, unit::second<-2>>;

    using merged = unit::merge_t<acceleration,
                                 unit::compound_unit<unit::second<3>,
                                                     unit::second<2>>>;
    using merged_cout_format = unit::to_str_type_t<merged>;
    std::string return_value=merged_cout_format::str();

    const char *expected_value="s^2s^3m^1s^-2";

    QCOMPARE(return_value, expected_value);
}

void compound_unit_test::testCondensingCompoundUnits(){
    using acceleration = unit::compound_unit<unit::meter<1>, unit::second<-2>>;
    //using cout_format = unit::to_str_type_t<acceleration>;

    using merged = unit::merge_t<acceleration,
                                 unit::compound_unit<unit::second<3>,
                                                     unit::second<2>>>;
    //using merged_cout_format = unit::to_str_type_t<merged>;


    using condensed = unit::condense_t<merged>;
    using condensed_cout_format = unit::to_str_type_t<condensed>;
    std::string return_value=condensed_cout_format::str();
    const char *expected_value="s^3m^1";
    QCOMPARE(return_value, expected_value);
}

void compound_unit_test::testMultiplyingCompoundUnits(){
    using acceleration = unit::compound_unit<unit::meter<1>, unit::second<-2>>;

    //using merged = unit::merge_t<acceleration,
    //                             unit::compound_unit<unit::second<3>,
    //                                                 unit::second<2>>>;

    using some_unit = unit::compound_unit<unit::second<-1>, unit::meter<4>>;

    using multiplied = unit::multiply_t<acceleration,
                                        some_unit>;
    using multiplied_cout_format = unit::to_str_type_t<multiplied>;

    std::string return_value=multiplied_cout_format::str();
    const char *expected_value="m^5s^-3";
    QCOMPARE(return_value, expected_value);
}

void compound_unit_test::testIsValidTemplate(){

}
//-----------------------------------------------



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
