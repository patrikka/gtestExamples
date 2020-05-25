#include "TemplateInterfaceUser.hpp"

TemplateInterfaceUser::TemplateInterfaceUser ( TemplateInterface< float > *iface ) : templateInterface ( iface )
{
}

TemplateInterfaceUser::~TemplateInterfaceUser ()
{
}

int TemplateInterfaceUser::useIntMethodWithTemplateParameter ( float param )
{
	return ( templateInterface->intMethodWithTemplateParameter ( param ) );
}
