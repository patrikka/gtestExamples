#ifndef TEMPLATEINTERFACE_HPP
#define TEMPLATEINTERFACE_HPP

#include <stdio.h>
#include <string>

template < typename Elem >
class TemplateInterface
{
	public:
		virtual ~TemplateInterface () {}

		virtual int intMethodWithTemplateParameter ( Elem param ) = 0;
};
#endif
