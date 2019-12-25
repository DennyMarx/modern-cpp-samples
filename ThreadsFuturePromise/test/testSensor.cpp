// unit test for the sensor object

#include "gtest/gtest.h"
#include "Sensor.h"


class SensorTest : public ::testing::Test 
{
    protected:
        // the test object
        std::unique_ptr<Sensor> _pSensorTestObj = nullptr;

    // setup for each test
    void SetUp() override 
    {
        _pSensorTestObj = std::make_unique<Sensor>();
    }

    // tear down after each test
    void TearDown() override 
    {
        _pSensorTestObj.release();
    }

};

 
TEST_F(SensorTest, testStartSensor)
{
    EXPECT_NO_THROW(_pSensorTestObj->start());
}
