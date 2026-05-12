# CMake generated Testfile for 
# Source directory: /home/researcher/ur5_test/src/robotiq_hande_driver/robotiq_hande_driver
# Build directory: /home/researcher/ur5_test/build/robotiq_hande_driver
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_load_hw_interface "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/researcher/ur5_test/build/robotiq_hande_driver/test_results/robotiq_hande_driver/test_load_hw_interface.gtest.xml" "--package-name" "robotiq_hande_driver" "--output-file" "/home/researcher/ur5_test/build/robotiq_hande_driver/ament_cmake_gmock/test_load_hw_interface.txt" "--command" "/home/researcher/ur5_test/build/robotiq_hande_driver/test_load_hw_interface" "--gtest_output=xml:/home/researcher/ur5_test/build/robotiq_hande_driver/test_results/robotiq_hande_driver/test_load_hw_interface.gtest.xml")
set_tests_properties(test_load_hw_interface PROPERTIES  LABELS "gmock" REQUIRED_FILES "/home/researcher/ur5_test/build/robotiq_hande_driver/test_load_hw_interface" TIMEOUT "60" WORKING_DIRECTORY "/home/researcher/ur5_test/build/robotiq_hande_driver" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_gmock/cmake/ament_add_gmock_test.cmake;98;ament_add_test;/opt/ros/jazzy/share/ament_cmake_gmock/cmake/ament_add_gmock.cmake;90;ament_add_gmock_test;/home/researcher/ur5_test/src/robotiq_hande_driver/robotiq_hande_driver/CMakeLists.txt;66;ament_add_gmock;/home/researcher/ur5_test/src/robotiq_hande_driver/robotiq_hande_driver/CMakeLists.txt;0;")
subdirs("gmock")
subdirs("gtest")
