#pragma once

#ifndef NDEBUG
#include <QDebug>

#define StrDebug(x)                                                                                \
    (qDebug().nospace() << "[" << __FILE__ << ":" << __LINE__ << ", " << __FUNCTION__ << "()] " x)
#else
#define StrDebug(x)
#endif
