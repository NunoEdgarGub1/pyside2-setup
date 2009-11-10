/*
 * This file is part of the Shiboken Python Binding Generator project.
 *
 * Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * Contact: PySide team <contact@pyside.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation. Please
 * review the following information to ensure the GNU Lesser General
 * Public License version 2.1 requirements will be met:
 * http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 *
 * As a special exception to the GNU Lesser General Public License
 * version 2.1, the object code form of a "work that uses the Library"
 * may incorporate material from a header file that is part of the
 * Library.  You may distribute such object code under terms of your
 * choice, provided that the incorporated material (i) does not exceed
 * more than 5% of the total size of the Library; and (ii) is limited to
 * numerical parameters, data structure layouts, accessors, macros,
 * inline functions and templates.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef OVERLOADSORT_H
#define OVERLOADSORT_H

#include "libsamplemacros.h"

#include <list>

class LIBSAMPLE_API ImplicitTarget
{
public:
    ImplicitTarget(){}
};

class LIBSAMPLE_API ImplicitBase
{
public:
    ImplicitBase(){}
    ImplicitBase(const ImplicitTarget &b){}
};

class LIBSAMPLE_API SortedOverload
{
public:

    const char *overload(int x) {
        return "int";
    }

    const char *overload(double x) {
        return "double";
    }

    const char *overload(ImplicitBase x) {
        return "ImplicitBase";
    }

    const char *overload(ImplicitTarget x) {
        return "ImplicitTarget";
    }

    const char *overload(const std::list<ImplicitBase> &x) {
        return "list(ImplicitBase)";
    }

    int implicit_overload(const ImplicitBase &x) {
        return 1;
    }
};

#endif // OVERLOADSORT_H

