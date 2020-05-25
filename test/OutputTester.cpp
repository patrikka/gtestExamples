#include "gtest/gtest.h"

class OutputTester : public ::testing::Test
{
	public:
		OutputTester () {};

	protected:
		std::string testString = "TestString";
		virtual void SetUp () {}
		virtual void TearDown () {}
};

TEST_F ( OutputTester, testStdCoutOutput )
{
	testing::internal::CaptureStdout ();
	std::cout << testString;
	std::string output = testing::internal::GetCapturedStdout ();
	ASSERT_EQ ( output, testString );
}

TEST_F ( OutputTester, testMultipleStdCoutOutput )
{
	testing::internal::CaptureStdout ();
	std::cout << testString << std::endl;
	std::cout << testString << "2";
	std::string output = testing::internal::GetCapturedStdout ();
	ASSERT_EQ ( output, testString + "\n" + testString + "2" );
}

TEST_F ( OutputTester, testStdErrByCerrOutput )
{
	testing::internal::CaptureStderr ();
	std::cerr << testString;
	std::string output = testing::internal::GetCapturedStderr ();
	ASSERT_EQ ( output, testString );
}
