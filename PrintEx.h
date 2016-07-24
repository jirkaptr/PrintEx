/********************************************************************************
        Copyright 2016 Christopher Andrews.
        https://github.com/Chris--A/PrintEx

        Released using: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007

        You should have received a copy of the licence with the software
        package. You can also view a copy of the full licence here:
        https://github.com/Chris--A/PrintEx/blob/master/LICENSE

        The only exception to the licence applies when a piece of software
        used within PrintEx, and uses a less restrictive licence or is
        public domain. However, these items will be marked accordingly
        with a link or reference of its origins.

        The exception mentioned in the above paragraph only applies to the
        particular lines of code that may be licensed differently, and does
        not remove the GNU GPLv3 restrictions from the remainder of the
        source which contains these items, or other source files used in
        conjunction with them.

********************************************************************************/

#define PRINTEX_VERSION        10200

	#include "MemoryPrinter.h"
	#include "StreamExtension.h"
	
	#include "utility/BufferedPrinter.h"
	#include "utility/DualPrinter.h"
	#include "utility/Base64Encoder.h"
	#include "utility/URIEncoder.h"
	#include "utility/CRCStream.h"
	#include "utility/RxTxCounter.h"
	#include "utility/NullStream.h"
	#include "utility/PrintAdapter.h"

#ifdef ISCPP11
    template<
        typename D,
        typename T,
        typename = typename enable_if<is_base_of<Print,D>::value>::type,
        typename = typename enable_if<!is_base_of<PrintExtension,D>::value>::type,
        typename = typename enable_if<!is_base_of<StreamExtension,D>::value>::type
    >
        D &operator<< ( D &print, const T &data ){
            PrintEx printer = print;
            return printer << data, print;
    }

    template<
        typename D,
        typename T,
        typename = typename enable_if<is_base_of<Stream,D>::value>::type,
        typename = typename enable_if<!is_base_of<StreamExtension,D>::value>::type
    >
        D &operator>> ( D &stream, T &data ){
            StreamEx streamer = stream;
            return streamer >> data, stream;
    }
#endif
