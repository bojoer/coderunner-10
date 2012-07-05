#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/gen-cpp/CodeRunner_types.o \
	${OBJECTDIR}/gen-cpp/CodeRunner.o \
	${OBJECTDIR}/gen-cpp/CodeRunner_constants.o \
	${OBJECTDIR}/CodeRunner.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lthrift -lcppunit

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f1

${TESTDIR}/TestFiles/f1: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/gen-cpp/CodeRunner_types.o: gen-cpp/CodeRunner_types.cpp 
	${MKDIR} -p ${OBJECTDIR}/gen-cpp
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/gen-cpp/CodeRunner_types.o gen-cpp/CodeRunner_types.cpp

${OBJECTDIR}/gen-cpp/CodeRunner.o: gen-cpp/CodeRunner.cpp 
	${MKDIR} -p ${OBJECTDIR}/gen-cpp
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/gen-cpp/CodeRunner.o gen-cpp/CodeRunner.cpp

${OBJECTDIR}/gen-cpp/CodeRunner_constants.o: gen-cpp/CodeRunner_constants.cpp 
	${MKDIR} -p ${OBJECTDIR}/gen-cpp
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/gen-cpp/CodeRunner_constants.o gen-cpp/CodeRunner_constants.cpp

${OBJECTDIR}/CodeRunner.o: CodeRunner.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/CodeRunner.o CodeRunner.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/testcase2.o ${TESTDIR}/tests/testrunner2.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} -lcppunit 


${TESTDIR}/tests/testcase2.o: tests/testcase2.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/thrift -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/testcase2.o tests/testcase2.cpp


${TESTDIR}/tests/testrunner2.o: tests/testrunner2.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/thrift -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/testrunner2.o tests/testrunner2.cpp


${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include/thrift -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/gen-cpp/CodeRunner_types_nomain.o: ${OBJECTDIR}/gen-cpp/CodeRunner_types.o gen-cpp/CodeRunner_types.cpp 
	${MKDIR} -p ${OBJECTDIR}/gen-cpp
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gen-cpp/CodeRunner_types.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include/thrift -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/gen-cpp/CodeRunner_types_nomain.o gen-cpp/CodeRunner_types.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gen-cpp/CodeRunner_types.o ${OBJECTDIR}/gen-cpp/CodeRunner_types_nomain.o;\
	fi

${OBJECTDIR}/gen-cpp/CodeRunner_nomain.o: ${OBJECTDIR}/gen-cpp/CodeRunner.o gen-cpp/CodeRunner.cpp 
	${MKDIR} -p ${OBJECTDIR}/gen-cpp
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gen-cpp/CodeRunner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include/thrift -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/gen-cpp/CodeRunner_nomain.o gen-cpp/CodeRunner.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gen-cpp/CodeRunner.o ${OBJECTDIR}/gen-cpp/CodeRunner_nomain.o;\
	fi

${OBJECTDIR}/gen-cpp/CodeRunner_constants_nomain.o: ${OBJECTDIR}/gen-cpp/CodeRunner_constants.o gen-cpp/CodeRunner_constants.cpp 
	${MKDIR} -p ${OBJECTDIR}/gen-cpp
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gen-cpp/CodeRunner_constants.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include/thrift -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/gen-cpp/CodeRunner_constants_nomain.o gen-cpp/CodeRunner_constants.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/gen-cpp/CodeRunner_constants.o ${OBJECTDIR}/gen-cpp/CodeRunner_constants_nomain.o;\
	fi

${OBJECTDIR}/CodeRunner_nomain.o: ${OBJECTDIR}/CodeRunner.o CodeRunner.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/CodeRunner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include/thrift -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/CodeRunner_nomain.o CodeRunner.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/CodeRunner.o ${OBJECTDIR}/CodeRunner_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f1

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
