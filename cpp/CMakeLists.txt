cmake_minimum_required (VERSION 3.11.1)

project (DailyCodingProblem)

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()
option(DATE "Date to compile and run tests from ('all' to compile all)")

LIST(APPEND SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/maintest.cpp")
IF(DATE STREQUAL "all")
    SUBDIRLIST(DIRS_YEAR "${CMAKE_CURRENT_SOURCE_DIR}")
    FOREACH(DIR_YEAR ${DIRS_YEAR})
        IF (${DIR_YEAR} STREQUAL "build")
            CONTINUE()
        ENDIF()
        SUBDIRLIST(DIRS_MONTH "${CMAKE_CURRENT_SOURCE_DIR}/${DIR_YEAR}")
        FOREACH(DIR_MONTH ${DIRS_MONTH})
            SUBDIRLIST(DIRS_DAY "${CMAKE_CURRENT_SOURCE_DIR}/${DIR_YEAR}/${DIR_MONTH}")
            FOREACH(DIR_DAY ${DIRS_DAY})
                LIST(APPEND SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/${DIR_YEAR}/${DIR_MONTH}/${DIR_DAY}/test.cpp")
            ENDFOREACH()
        ENDFOREACH()
    ENDFOREACH()
ELSEIF (DATE)
    message("${CMAKE_CURRENT_SOURCE_DIR}/${DATE}/test.cpp")
    LIST(APPEND SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/${DATE}/test.cpp")
ELSE()
    string(TIMESTAMP TODAY "%Y/%m/%d")
    LIST(APPEND SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/${TODAY}/test.cpp")
ENDIF()

add_executable(DailyCodingProblem ${SOURCE_FILES})