#ifndef PERSISTENCE_GLOBAL_H
#define PERSISTENCE_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef PERSISTENCE_LIB
# define PERSISTENCE_EXPORT Q_DECL_EXPORT
#else
# define PERSISTENCE_EXPORT Q_DECL_IMPORT
#endif

#endif // PERSISTENCE_GLOBAL_H
