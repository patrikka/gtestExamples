#include "gtest/gtest.h"

class DoubleTester : public ::testing::Test
{
	public:
		DoubleTester () {};

	protected:
		virtual void SetUp () {}
		virtual void TearDown () {}
};

// https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#doubleing-point-comparison
TEST_F ( DoubleTester, compareDoublesSuccessfully )
{
	double x = 1.0 / 10.0;
	double y = x * 10.0;
	// ASSERT_EQ ( y, 1.0 ); // This might fail!
	EXPECT_DOUBLE_EQ ( y, 1.0 ); // Doubles are almost equal
	ASSERT_DOUBLE_EQ ( y, 1.0 ); // Doubles are almost equal
	ASSERT_NEAR ( y, 1.0, 0.0000001 ); // Doubles are equal within 0.0000001.
}
