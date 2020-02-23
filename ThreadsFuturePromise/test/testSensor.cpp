// unit test for the sensor object

#include "gtest/gtest.h"
#include "Sensor.h"


class SensorTest : public ::testing::Test 
{
    protected:
        // an interface to the test object
        std::unique_ptr<ISensor> _pSensorTestObj = nullptr;

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


TEST_F(SensorTest, testRunSensor)
{
    std::future<SensorData> sensorData;

    EXPECT_NO_THROW(_pSensorTestObj->start());
    EXPECT_NO_THROW(sensorData = _pSensorTestObj->run());

    EXPECT_TRUE(true == sensorData.valid());

    int value = sensorData.get().sensorValue;
    EXPECT_EQ(1, value);
}


TEST_F(SensorTest, testRunNotStartedSensor)
{
    std::future<SensorData> sensorData;
    int value = 0;

    EXPECT_NO_THROW(sensorData = _pSensorTestObj->run());

    EXPECT_TRUE(true == sensorData.valid());
    EXPECT_EQ(0, value);
}
