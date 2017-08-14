#ifndef PLUGIN4PT_GLOBAL_H
#define PLUGIN4PT_GLOBAL_H

#include <qglobal.h>

#ifdef PLUGIN4PT_LIB
# define PLUGIN4PT_EXPORT Q_DECL_EXPORT
#else
# define PLUGIN4PT_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGIN4PT_GLOBAL_H
