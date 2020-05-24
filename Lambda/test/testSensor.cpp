// unit test for the sensor object

#include "gtest/gtest.h"



class SensorTest : public ::testing::Test 
{
    // setup for each test
    void SetUp() override 
    {
    }

    // tear down after each test
    void TearDown() override 
    {
    }

};

 
TEST_F(SensorTest, testSensor)
{
    EXPECT_TRUE(true);
}
