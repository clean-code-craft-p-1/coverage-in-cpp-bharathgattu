
#include "typewise-alert.h"

#include "gtest/gtest.h"

TEST(TypewiseAlert, InferBreachAsPerLimits) {
  ASSERT_TRUE(inferBreach(12.0, 20.0, 30.0) == TOO_LOW);
  ASSERT_TRUE(inferBreach(40.0, 20.0, 30.0) == TOO_HIGH);
  ASSERT_FALSE(inferBreach(15.0, 30.0, 20.0) == NORMAL);
  ASSERT_FALSE(inferBreach(15.0, 20.0, 20.0) == NORMAL);
}

TEST(TypewiseAlert, classifyTemperatureBreach) {
	ASSERT_TRUE(classifyTemperatureBreach(CoolingType::PASSIVE_COOLING, 40) == TOO_HIGH);
	ASSERT_TRUE(classifyTemperatureBreach(CoolingType::PASSIVE_COOLING, 20) == NORMAL);
	ASSERT_FALSE(classifyTemperatureBreach(CoolingType::PASSIVE_COOLING, -1) == NORMAL);

	ASSERT_TRUE(classifyTemperatureBreach(CoolingType::HI_ACTIVE_COOLING, 50) == TOO_HIGH);
	ASSERT_TRUE(classifyTemperatureBreach(CoolingType::HI_ACTIVE_COOLING, 20) == NORMAL);
	ASSERT_FALSE(classifyTemperatureBreach(CoolingType::HI_ACTIVE_COOLING, -1) == NORMAL);

	ASSERT_TRUE(classifyTemperatureBreach(CoolingType::MED_ACTIVE_COOLING, 50) == TOO_HIGH);
	ASSERT_TRUE(classifyTemperatureBreach(CoolingType::MED_ACTIVE_COOLING, 20) == NORMAL);
	ASSERT_FALSE(classifyTemperatureBreach(CoolingType::MED_ACTIVE_COOLING, -1) == NORMAL);
}
TEST(TypewiseAlert, checkAndAlert) {

}