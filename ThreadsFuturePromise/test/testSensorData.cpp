// unit test for the sensor object

#include "gtest/gtest.h"
#include "SensorData.h"


class SensorDataTest : public ::testing::Test 
{
    protected:
        // an interface to the test object
        std::unique_ptr<SensorData> _pSensorDataTestObj = nullptr;

    // setup for each test
    void SetUp() override 
    {
        _pSensorDataTestObj = std::make_unique<SensorData>();
    }

    // tear down after each test
    void TearDown() override 
    {
        _pSensorDataTestObj.release();
    }

};

 
TEST_F(SensorDataTest, testSensorDataTestinitValue)
{
    EXPECT_EQ(0, _pSensorDataTestObj->sensorValue);
}
