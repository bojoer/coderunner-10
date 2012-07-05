/*
 * File:   testcase2.h
 * Author: along
 *
 * Created on 2012-5-7, 21:53:22
 */

#ifndef TESTCASE2_H
#define	TESTCASE2_H

#include <cppunit/extensions/HelperMacros.h>

class testcase2 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(testcase2);

    CPPUNIT_TEST(testCompile);
    CPPUNIT_TEST(testRun);

    CPPUNIT_TEST_SUITE_END();

public:
    testcase2();
    virtual ~testcase2();
    void setUp();
    void tearDown();

private:
    void testCompile();
    void testRun();

};

#endif	/* TESTCASE2_H */

