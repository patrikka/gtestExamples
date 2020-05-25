#include "gmock/gmock.h"
#include "TemplateInterface.hpp"

template < typename Elem >
class MockTemplateInterface : public TemplateInterface< Elem >
{
	public:
		MOCK_METHOD ( int, intMethodWithTemplateParameter, ( Elem param ), ( override ) );
};
