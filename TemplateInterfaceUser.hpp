#ifndef TEMPLATEINTERFACEUSER_HPP
#define TEMPLATEINTERFACEUSER_HPP

#include "TemplateInterface.hpp"

class TemplateInterfaceUser
{
	public:

		TemplateInterfaceUser ( TemplateInterface< float > *iface );

		~TemplateInterfaceUser ();

		int useIntMethodWithTemplateParameter ( float param );

	private:

		TemplateInterface< float > *templateInterface = NULL;

};

#endif
