#ifndef ABSTRACTINTERFACE_HPP
#define ABSTRACTINTERFACE_HPP

#include <stdio.h>
#include <string>

/**
 * An abstract interface made for googlemock examples.
 */

class AbstractInterface
{
	public:
		virtual ~AbstractInterface () {}

		virtual void constVoidMethod () const = 0;

		virtual int constIntMethod ( int param ) const = 0;

		virtual int intMethod ( int param ) = 0;

		virtual std::pair< int, bool > stlMethod ( std::pair< int, bool > param ) = 0;

		virtual void voidMethodWhichThrows () = 0;

		virtual int overloadedMethod ( int param ) = 0;

		virtual int overloadedMethod ( float param ) = 0;

		virtual const std::string &constStringRefMethod ( const std::string &param ) = 0;

		virtual char *charPointerMethod ( char *param ) = 0;
};
#endif
