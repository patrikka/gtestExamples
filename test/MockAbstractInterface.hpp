#include "gmock/gmock.h"
#include "AbstractInterface.hpp"

class MockAbstractInterface : public AbstractInterface
{
	public:
		MOCK_METHOD ( void, constVoidMethod, (), ( const, override ) );
		MOCK_METHOD ( int, constIntMethod, ( int ), ( const, override ) );
		MOCK_METHOD ( int, intMethod, ( int ), ( override ) );
		MOCK_METHOD ( ( std::pair< int, bool > ), stlMethod, ( ( std::pair< int, bool > ) ), ( override ) );
		MOCK_METHOD ( void, voidMethodWhichThrows, (), ( override ) );
		MOCK_METHOD ( int, overloadedMethod, ( int ), ( override ) );
		MOCK_METHOD ( int, overloadedMethod, ( float ), ( override ) );
		MOCK_METHOD ( const std::string &, constStringRefMethod, ( const std::string & ), ( override ) );
		MOCK_METHOD ( char *, charPointerMethod, ( char * ), ( override ) );
};
