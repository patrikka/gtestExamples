#include "AbstractInterfaceUser.hpp"

AbstractInterfaceUser::AbstractInterfaceUser ( AbstractInterface *iface ) : abstractInterface ( iface )
{
}

AbstractInterfaceUser::~AbstractInterfaceUser ()
{
}

int AbstractInterfaceUser::useConstVoidMethod () const
{
	abstractInterface->constVoidMethod ();
	return 0;
}

int AbstractInterfaceUser::useConstIntMethod ( int param ) const
{
	return ( abstractInterface->constIntMethod ( param * 2 ) );
}

int AbstractInterfaceUser::useIntMethod ( int param )
{
	return ( abstractInterface->intMethod ( param * 2 ) );
}

std::pair< int, bool > AbstractInterfaceUser::useStlMethod ( std::pair< int, bool > param )
{
	return ( abstractInterface->stlMethod ( param ) );
}

int AbstractInterfaceUser::useVoidMethodWhichThrows ()
{
	try
	{
		abstractInterface->voidMethodWhichThrows ();
	}
	catch ( int i )
	{
		return i;
	}
	return 0;
}

int AbstractInterfaceUser::useOverloadedMethod ( int param )
{
	return ( abstractInterface->overloadedMethod ( param ) );
}

int AbstractInterfaceUser::useOverloadedMethod ( float param )
{
	return ( abstractInterface->overloadedMethod ( param ) );
}

const std::string &AbstractInterfaceUser::useConstStringRefMethod ( const std::string &param )
{
	return ( abstractInterface->constStringRefMethod ( param ) );
}

char *AbstractInterfaceUser::useCharPointerMethod ( char *param )
{
	return ( abstractInterface->charPointerMethod ( param ) );
}
