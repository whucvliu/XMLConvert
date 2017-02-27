#Find the package of all related libraries
#add the reference of the pcap library
set(LINK_LIBS "")
set(INCLUDE_DIRS "")
set(LIB_PATH "")


#Add the reference of the PCL libraries
#set(OpenCV_DIR "G:/lib/opencv2413/opencv/build")
#find_package(OpenCV REQUIRED)
#if(NOT ${OPENCV_FOUND})
#	message(FATAL_ERROR "Please Set the OpenCV_DIR")
#endif()
#LIST(APPEND INCLUDE_DIRS "${OpenCV_INCLUDE_DIRS}")
#LIST(APPEND LINK_LIBS "${OpenCV_LIBS}")

#message(status " OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS} ")
#message(status " OpenCV_LIBS: ${OpenCV_LIBS} ")
#message(status " OpenCV_LIB_DIR: ${OpenCV_LIB_DIR} ")


set(gflags_DIR "G:/lib/gflags/gflags_VS2013")
FIND_PACKAGE(gflags REQUIRED)
if( NOT ${GFLAGS_FOUND} )
	message(FATAL_ERROR "Please Set the gflags_DIR")
endif()
LIST(APPEND INCLUDE_DIRS "${GFLAGS_INCLUDE_DIR}")
LIST(APPEND LINK_LIBS "${GFLAGS_LIBRARIES}")


#SET( EIGEN3_INCLUDE_DIR "G:/lib/Eigen/eigen/include")
#if(EIGEN3_INCLUDE_DIR)
#	message(status "EIGEN3_INCLUDE_DIR: ${EIGEN3_INCLUDE_DIR} ")
#	LIST(APPEND INCLUDE_DIRS "${EIGEN3_INCLUDE_DIR}")
#	message(status "INCLUDE_DIRS: ${INCLUDE_DIRS} ")
#else()
#	message(FATAL_ERROR "Please Set the value of EIGEN3_INCLUDE_DIR")
#endif()

set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
set(Boost_NO_BOOST_CMAKE		ON)
find_package(Boost REQUIRED COMPONENTS filesystem system)
if(NOT　Boost_FOUND)
	message(FATAL_ERROR "Please set the BOOST_ROOT")	
endif()
LIST(APPEND INCLUDE_DIRS "${Boost_INCLUDE_DIRS}")
LIST(APPEND LIB_PATH "${Boost_LIBRARY_DIRS}")
LIST(APPEND LINK_LIBS "${Boost_LIBRARIES}")

#Recursively Add the env path of the sub-dictionaries
FILE(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
SET(DIRLIST "")
FOREACH(child ${children})
	if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
		LIST(APPEND DIRLIST ${child})
		ADD_SUBDIRECTORY( ${CMAKE_CURRENT_SOURCE_DIR}/${child} )
		INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/include/${child})
	endif()
ENDFOREACH()
aux_source_directory(. DIR_SRCS)

#Add related env path
#message(status "INCLUDE_DIRS: ${INCLUDE_DIRS} ")
INCLUDE_DIRECTORIES(${INCLUDE_DIRS})
INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/include
					 ${PROJECT_SOURCE_DIR}/include/TinyXML
					)
LINK_LIBRARIES(${LIB_PATH})

set(PROJECT_HEADERS ${PROJECT_SOURCE_DIR}/include/common.h
					${PROJECT_SOURCE_DIR}/include/ConvertProcess.h)
source_group("Include" FILES ${PROJECT_HEADERS})


ADD_EXECUTABLE( ${PROJECT_NAME}  ${DIR_SRCS} ${PROJECT_HEADERS})
TARGET_LINK_LIBRARIES( ${PROJECT_NAME}
	${LINK_LIBS}
	${DIRLIST}
)


