#get the name of the library
get_filename_component(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
message(status " LIB_NAME: ${LIB_NAME}")

#add related env path
#message(status "PCAP_INCLUDE_DIR: ${PCAP_INCLUDE_DIR} ") 
#message(status "PCAP_LIBRARIES: ${PCAP_LIBRARIES} ") 
#INCLUDE_DIRECTORIES(${PCAP_INCLUDE_DIR})
#INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
#INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})

INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/include
					${PROJECT_SOURCE_DIR}/include/${LIB_NAME}
					)


#add related file to the workstation
file(GLOB_RECURSE LIBRARY_HEADERS 
					../../include/${LIB_NAME}/*.h 
					../../include/${LIB_NAME}/*.hpp
#					${PROJECT_SOURSE_DIR}/*.h
#					${PROJECT_SOURSE_DIR}/*.hpp
					)
					
source_group("Include" FILES ${LIBRARY_HEADERS})

aux_source_directory(. LIBRARY_SRCS)

#ADD_LIBRARY(LOAMAlign LOAMAlign.cpp FeatureCloud.cpp common.cpp)
#TARGET_LINK_LIBRARIES(LOAMAlign 
#						${PCL_LIBRARIES})

ADD_LIBRARY(${LIB_NAME}  
			${LIBRARY_SRCS} 
			${LIBRARY_HEADERS}
			#${PCAP_LIBRARIES}
						)

