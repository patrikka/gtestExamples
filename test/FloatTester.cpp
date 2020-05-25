#include "gtest/gtest.h"

class FloatTester : public ::testing::Test
{
	public:
		FloatTester () {};

	protected:
		virtual void SetUp () {}
		virtual void TearDown () {}
};

// https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#floating-point-comparison
TEST_F ( FloatTester, compareFloatsSuccessfully )
{
	float x = 1.0 / 10.0;
	float y = x * 10.0;
	// ASSERT_EQ ( y, 1.0 ); // This might fail!
	EXPECT_FLOAT_EQ ( y, 1.0 ); // Floats are almost equal
	ASSERT_FLOAT_EQ ( y, 1.0 ); // Floats are almost equal
	ASSERT_NEAR ( y, 1.0, 0.0000001 ); // Floats are equal within 0.0000001.
}
