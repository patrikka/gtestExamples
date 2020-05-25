#ifndef ABSTRACTINTERFACEUSER_HPP
#define ABSTRACTINTERFACEUSER_HPP

#include "AbstractInterface.hpp"

class AbstractInterfaceUser
{
	public:

		AbstractInterfaceUser ( AbstractInterface *iface );

		~AbstractInterfaceUser ();

		int useConstVoidMethod () const;

		int useConstIntMethod ( int param ) const;

		int useIntMethod ( int param );

		std::pair< int, bool > useStlMethod ( std::pair< int, bool > param );

		int useVoidMethodWhichThrows ();

		int useOverloadedMethod ( int param );

		int useOverloadedMethod ( float param );

		const std::string &useConstStringRefMethod ( const std::string &str );

		char *useCharPointerMethod ( char *param );

	private:

		AbstractInterface *abstractInterface = NULL;

};

#endif
