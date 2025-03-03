#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(BLL_LIB)
#  define BLL_EXPORT Q_DECL_EXPORT
# else
#  define BLL_EXPORT Q_DECL_IMPORT
# endif
#else
# define BLL_EXPORT
#endif
