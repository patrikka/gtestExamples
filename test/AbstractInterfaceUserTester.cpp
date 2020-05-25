#include "gtest/gtest.h"
#include "AbstractInterfaceUser.hpp"
#include "MockAbstractInterface.hpp"

using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::ByRef;
using ::testing::TypedEq;
using ::testing::Eq;
using ::testing::Pointee;
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;

class AbstractInterfaceUserTester : public ::testing::Test
{
	public:
		AbstractInterfaceUserTester () {};

	protected:
		AbstractInterfaceUser *aiu;
		MockAbstractInterface *mockAbstractInterface;

		// Called once before every test.
		virtual void SetUp ()
		{
			mockAbstractInterface = new MockAbstractInterface ();
			aiu = new AbstractInterfaceUser ( mockAbstractInterface );
		}

		// Called once after every test.
		virtual void TearDown ()
		{
			delete mockAbstractInterface;
			delete aiu;
		}
};

TEST_F ( AbstractInterfaceUserTester, useConstVoidMethod_returnsZero )
{
	EXPECT_CALL ( *mockAbstractInterface, constVoidMethod () )
	.Times ( 1 );

	ASSERT_EQ ( aiu->useConstVoidMethod (), 0 );
}

TEST_F ( AbstractInterfaceUserTester, useConstIntMethod_returnsTripleTheGivenParameter )
{
	int param = 1;
	EXPECT_CALL ( *mockAbstractInterface, constIntMethod ( param * 2 ) )
	.WillOnce ( Return ( param * 3 ) );

	ASSERT_EQ ( aiu->useConstIntMethod ( param ), param * 3 );
}

TEST_F ( AbstractInterfaceUserTester, useIntMethod_returnsTripleTheGivenParameter )
{
	int param = 123;

	EXPECT_CALL ( *mockAbstractInterface, intMethod ( param * 2 ) )
	.WillOnce ( Return ( param * 3 ) );

	ASSERT_EQ ( aiu->useIntMethod ( param ), param * 3 );
}

TEST_F ( AbstractInterfaceUserTester, useStlMethod_returnsStlContainer )
{
	std::pair< int, bool > param ( 666, true );

	EXPECT_CALL ( *mockAbstractInterface, stlMethod ( param ) )
	.WillOnce ( Return ( param ) );

	ASSERT_EQ ( aiu->useStlMethod ( param ), param );
}

TEST_F ( AbstractInterfaceUserTester, useVoidMethodWhichThrows_returnsZeroWhenNoExceptionIsThrown )
{
	EXPECT_CALL ( *mockAbstractInterface, voidMethodWhichThrows () )
	.Times ( 1 );

	ASSERT_EQ ( aiu->useVoidMethodWhichThrows (), 0 );
}

ACTION ( MyThrowAction )
{
	throw 616;
}

TEST_F ( AbstractInterfaceUserTester, useVoidMethodWhichThrows_returnsNumberWhichIsThrown )
{
	EXPECT_CALL ( *mockAbstractInterface, voidMethodWhichThrows () )
	.WillOnce ( MyThrowAction () );

	ASSERT_EQ ( aiu->useVoidMethodWhichThrows (), 616 );
}

TEST_F ( AbstractInterfaceUserTester, useOverloadedMethod_returnsIntParameter )
{
	int param = 10;
	EXPECT_CALL ( *mockAbstractInterface, overloadedMethod ( TypedEq<int>( param ) ) )
	.WillOnce ( Return ( param ) );

	ASSERT_EQ ( aiu->useOverloadedMethod ( param ), param );
}

TEST_F ( AbstractInterfaceUserTester, useOverloadedMethod_returnsFloatParameterAsInt )
{
	float param = 20.0f;
	EXPECT_CALL ( *mockAbstractInterface, overloadedMethod ( TypedEq<float>( param ) ) )
	.WillOnce ( Return ( 20 ) );

	ASSERT_EQ ( aiu->useOverloadedMethod ( param ), 20 );
}

TEST_F ( AbstractInterfaceUserTester, useConstStringRefMethod_returnsReferenceToStringGivenAsParameter )
{
	std::string str ( "test" );
	EXPECT_CALL ( *mockAbstractInterface, constStringRefMethod ( Eq ( ByRef ( str ) ) ) )
	.WillOnce ( ReturnRef ( str ) );

	ASSERT_EQ ( aiu->useConstStringRefMethod ( str ), str );
}

TEST_F ( AbstractInterfaceUserTester, useCharPointerMethod_returnsPointerWhichEqualsThePointerGivenAsParameter )
{
	char *param = NULL;
	EXPECT_CALL ( *mockAbstractInterface, charPointerMethod ( param ) )
	.WillRepeatedly ( Return ( param ) );

	ASSERT_EQ ( aiu->useCharPointerMethod ( param ), param );
}

TEST_F ( AbstractInterfaceUserTester, useCharPointerMethod_characterPointedByParameterIsSecondInArrayAndReturnedByMethod )
{
	char array [] = "World";
	char *param = array;
	param++;
	EXPECT_CALL ( *mockAbstractInterface, charPointerMethod ( Pointee ( 'o' ) ) )
	.WillOnce ( Return ( param ) );

	ASSERT_EQ ( aiu->useCharPointerMethod ( param ), param );
}

TEST_F ( AbstractInterfaceUserTester, useCharPointerMethod_changesValueThroughPointerAndReturnsPointer )
{
	char array [] = "World";
	char *param = array;
	EXPECT_CALL ( *mockAbstractInterface, charPointerMethod ( _ ) )
	.WillOnce ( DoAll ( SetArgPointee< 0 > ( 'X' ), Return ( param ) ) );

	ASSERT_EQ ( aiu->useCharPointerMethod ( param ), param );
	ASSERT_EQ ( *param, 'X' );
}
