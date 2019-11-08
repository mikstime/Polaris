#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;



TEST(TestStatic, HelloWorld) {

}

int main(int argc, char** argv) {
//  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
