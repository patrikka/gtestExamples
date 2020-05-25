#include "gtest/gtest.h"
#include "TemplateInterfaceUser.hpp"
#include "MockTemplateInterface.hpp"

using ::testing::Return;

class TemplateInterfaceUserTester : public ::testing::Test
{
	public:
		TemplateInterfaceUserTester () {};

	protected:
		TemplateInterfaceUser *tiu;
		MockTemplateInterface< float> *mockTemplateInterface;

		virtual void SetUp ()
		{
			mockTemplateInterface = new MockTemplateInterface< float > ();
			tiu = new TemplateInterfaceUser ( mockTemplateInterface );
		}

		virtual void TearDown ()
		{
			delete mockTemplateInterface;
			delete tiu;
		}
};

TEST_F ( TemplateInterfaceUserTester, useIntMethodWithTemplateParameter_returnsParamAsInt )
{
	float param = 100.0f;
	EXPECT_CALL ( *mockTemplateInterface, intMethodWithTemplateParameter ( param ) )
	.WillOnce ( Return ( 666 ) );

	ASSERT_EQ ( tiu->useIntMethodWithTemplateParameter ( param ), 666 );
}
