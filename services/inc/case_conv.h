/*
 * Copyright (c) 2018 Particle Industries, Inc.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cctype>

namespace particle {

inline char* toUpperCase(char* str, size_t n) {
    char* s = str;
    char* const s2 = str + n;
    while (s != s2) {
        *s = std::toupper(*s);
        ++s;
    }
    return str;
}

inline char* toLowerCase(char* str, size_t n) {
    char* s = str;
    char* const s2 = str + n;
    while (s != s2) {
        *s = std::tolower(*s);
        ++s;
    }
    return str;
}

} // particle