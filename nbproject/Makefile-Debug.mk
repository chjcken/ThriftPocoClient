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
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Counter.o \
	${OBJECTDIR}/counter_constants.o \
	${OBJECTDIR}/counter_types.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=`pkg-config --libs thrift` ../../Downloads/poco-1.6.0/lib/Linux/x86_64/libPocoFoundation.so ../../Downloads/poco-1.6.0/lib/Linux/x86_64/libPocoFoundationd.so ../../Downloads/poco-1.6.0/lib/Linux/x86_64/libPocoUtil.so ../../Downloads/poco-1.6.0/lib/Linux/x86_64/libPocoUtild.so  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thirftpococlient

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thirftpococlient: ../../Downloads/poco-1.6.0/lib/Linux/x86_64/libPocoFoundation.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thirftpococlient: ../../Downloads/poco-1.6.0/lib/Linux/x86_64/libPocoFoundationd.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thirftpococlient: ../../Downloads/poco-1.6.0/lib/Linux/x86_64/libPocoUtil.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thirftpococlient: ../../Downloads/poco-1.6.0/lib/Linux/x86_64/libPocoUtild.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thirftpococlient: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thirftpococlient ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Counter.o: Counter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags thrift`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Counter.o Counter.cpp

${OBJECTDIR}/counter_constants.o: counter_constants.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags thrift`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/counter_constants.o counter_constants.cpp

${OBJECTDIR}/counter_types.o: counter_types.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags thrift`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/counter_types.o counter_types.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags thrift`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thirftpococlient

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
