###############################################################################
### UNIT TEST FRAMWEWORK
###############################################################################

# Keep test files in a separate source directory called unit_test
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} unit_test/*.cpp)

# Run through each source
foreach(testSrc ${TEST_SRCS})
        # Extract the filename without an extension (NAME_WE)
        get_filename_component(testName ${testSrc} NAME_WE)

        # Add compile target
        add_executable(${testName} ${testSrc})

        # Link to Boost libraries AND your targets and dependencies
        target_link_libraries(${testName} ${Boost_LIBRARIES})

        target_include_directories(${testName} PRIVATE ${Boost_INCLUDE_DIRS})

        # Specifies include directories to use when compiling the target
        target_include_directories(
          ${testName} PRIVATE
          $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)
          
        #Finally add it to test execution. Notice the WORKING_DIRECTORY and COMMAND
        add_test(NAME ${testName}
                 WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
               COMMAND ${PROJECT_BINARY_DIR}/tests/${testName} )

endforeach(testSrc)
