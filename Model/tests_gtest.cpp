#include <gtest/gtest.h>
#include <gmock/gmock.h>
//#include "lib/ModelInterface/model_interface_tests.cpp"
//#include "lib/GraphInterface/graph_interface_tests.cpp"
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}