#ifndef PLUGIN4A_GLOBAL_H
#define PLUGIN4A_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef PLUGIN4A_LIB
# define PLUGIN4A_EXPORT Q_DECL_EXPORT
#else
# define PLUGIN4A_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGIN4A_GLOBAL_H
