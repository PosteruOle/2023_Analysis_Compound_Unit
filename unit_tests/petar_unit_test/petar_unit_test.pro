QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG += c++17
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_compound_unit_test.cpp
            base_unit.hpp
            base_unit_traits.hpp
            compound_unit.hpp
            is_valid.hpp
