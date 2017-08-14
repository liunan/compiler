#ifndef PLUGIN4L_GLOBAL_H
#define PLUGIN4L_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef PLUGIN4L_LIB
# define PLUGIN4L_EXPORT Q_DECL_EXPORT
#else
# define PLUGIN4L_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGIN4L_GLOBAL_H
