cmake_minimum_required(VERSION 3.4)
project(Library)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/model/Client.cpp
        src/model/Item.cpp
        src/model/Rent.cpp
        src/model/ClientType.cpp
        src/model/Movie.cpp
        src/model/Music.cpp
        src/model/Comics.cpp include/model/Membership.h include/model/DiamondMembership.h include/model/NoMembership.h src/model/Membership.cpp src/model/NoMembership.cpp src/model/DiamondMembership.cpp include/managers/ClientManager.h include/repositories/ClientRepository.h src/repositories/ClientRepository.cpp
        src/model/Comics.cpp
        src/model/Membership.cpp
        src/model/NoMembership.cpp
        src/model/DiamondMembership.cpp
        src/repositories/ClientRepository.cpp
        src/repositories/RentRepository.cpp
        src/repositories/ItemRepository.cpp
        src/repositories/StorageContainer.cpp
        include/exceptions/LogicException.h include/exceptions/ParameterException.h include/menu/TerminalMenu.h src/menu/TerminalMenu.cpp
        src/repositories/Repository.cpp
        src/managers/ClientManager.cpp
        src/managers/RentManager.cpp
        src/managers/ItemManager.cpp)

add_library(Library ${SOURCE_FILES})

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Unit Tests section

# Check if generating Visual Studio 14 2015 project
if(MSVC)
    if(NOT BOOST_ROOT)
        set(BOOST_ROOT "C:/local/boost_1_60_0")
    endif()
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib32-msvc-14.0")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)

    if(NOT EXISTS ${Boost_LIBRARY_DIR})
        message(WARNING "Boost library requires manual installation in Windows")
        message("1) Browse: https://sourceforge.net/projects/boost/files/boost-binaries/1.60.0/")
        message("2) Download: boost_1_60_0-msvc-14.0-32.exe")
        message("3) Install into default directory: C:\\local")
        message("")
        message(FATAL_ERROR "Boost libraries not found at ${Boost_LIBRARY_DIR}")
    endif()

    find_package(Boost COMPONENTS unit_test_framework REQUIRED)

    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})

else()
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()

set(SOURCE_TEST_FILES
        test/master.cpp
        test/ClientTest.cpp
        test/ItemTest.cpp
        test/RentTest.cpp
        test/ClientRepositoryTest.cpp
        test/RentRepositoryTest.cpp
        test/ItemRepositoryTest.cpp
        src/model/Client.cpp
        src/model/Item.cpp
        src/model/Rent.cpp
        src/model/ClientType.cpp
        src/model/Movie.cpp
        src/model/Music.cpp
        src/model/Comics.cpp include/model/Membership.h include/model/DiamondMembership.h include/model/NoMembership.h src/model/Membership.cpp src/model/NoMembership.cpp src/model/DiamondMembership.cpp include/managers/ClientManager.h include/repositories/ClientRepository.h src/repositories/ClientRepository.cpp
        src/model/Comics.cpp
        src/model/Membership.cpp
        src/model/NoMembership.cpp
        src/model/DiamondMembership.cpp
        src/repositories/ClientRepository.cpp
        src/repositories/RentRepository.cpp
        src/repositories/ItemRepository.cpp
        src/repositories/StorageContainer.cpp
        include/exceptions/LogicException.h include/exceptions/ParameterException.h include/menu/TerminalMenu.h src/menu/TerminalMenu.cpp
        src/repositories/Repository.cpp
        src/managers/ClientManager.cpp
        src/managers/RentManager.cpp
        src/managers/ItemManager.cpp
        test/ClientManagerTest.cpp test/RentManagerTest.cpp test/ItemManagerTest.cpp)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

add_executable (Test ${SOURCE_TEST_FILES})

target_link_libraries (Test
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()
add_test(LibraryTest Test)
