/*
 * File:   testcase2.cpp
 * Author: along
 *
 * Created on 2012-5-7, 21:53:23
 */

#include "testcase2.h"
#include "CodeRunner.h"


CPPUNIT_TEST_SUITE_REGISTRATION(testcase2);

testcase2::testcase2() {
}

testcase2::~testcase2() {
}

void testcase2::setUp() {
}

void testcase2::tearDown() {
}

void testcase2::testCompile() {

    int status;
    CodePizza pizza;
    pizza.lanuage = "CPP";
    pizza.code = "#include <stdio.h> \n int main() {printf(\"hello CPP\"); return 0;}";

    CodeRunner codeRunner("/tmp");
    status = codeRunner.compile(pizza);
    CPPUNIT_ASSERT(status == 0);

    pizza.lanuage = "C";
    pizza.code = "#include <stdio.h> \n int main() {printf(\"hello C\"); return 0;}";
    status = codeRunner.compile(pizza);
    CPPUNIT_ASSERT(status == 0);

}

void testcase2::testRun() {

    CodePizza pizza;
    RunResult _return;
    CodeRunner codeRunner("/tmp");

    pizza.lanuage = "CPP";
    pizza.code = "#include <stdio.h> \n int main() {printf(\"hello CPP\"); return 0;}";
    codeRunner.run(_return, pizza, 0);
    CPPUNIT_ASSERT(_return.stdout == "hello CPP");
    CPPUNIT_ASSERT(_return.ret == 0);


    pizza.lanuage = "CPP";
    pizza.code = "#include <stdio.h> \n int main() {printf(\"hello CPP 11\"); return 1;}";
    codeRunner.run(_return, pizza, 0);
    CPPUNIT_ASSERT(_return.stdout == "hello CPP 11");
    CPPUNIT_ASSERT(_return.ret != 0);

}

