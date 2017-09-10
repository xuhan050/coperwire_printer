/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MACROS_H
#define MACROS_H

// Macros to make a string from a macro
#define STRINGIFY_(n) #n
#define STRINGIFY(n) STRINGIFY_(n)              // Just like str(n) in python

// Macros for bit masks
#define TEST(n,b) (((n)&_BV(b))!=0)             // test if the 'b' bit of 'n' is 1. 1=true
#define SBI(n,b) (n |= _BV(b))                  // set '1' into 'b' bit of 'n'
#define CBI(n,b) (n &= ~_BV(b))                 // set '0' into 'b' bit of 'n'
#define SET_BIT(n,b,value) (n) ^= ((-value)^(n)) & (_BV(b))         // set 'value = 0 or 1' into 'b' bit of 'n'

// Macros for maths shortcuts
#define RADIANS(d) ((d)*M_PI/180.0)             // convert degree to radians
#define DEGREES(r) ((r)*180.0/M_PI)             // convert radians to degree

// Macros to contrain values
#define NOLESS(v,n) do{ if (v < n) v = n; }while(0)     // make v no less than n
#define NOMORE(v,n) do{ if (v > n) v = n; }while(0)     // make v no more than n

// Macros to support option testing
#define _CAT(a, ...) a ## __VA_ARGS__                 // connect 'a' + '...' directly
#define SWITCH_ENABLED_false 0
#define SWITCH_ENABLED_true  1
#define SWITCH_ENABLED_0     0
#define SWITCH_ENABLED_1     1
#define SWITCH_ENABLED_      1
#define ENABLED(b) _CAT(SWITCH_ENABLED_, b)           // Connect 'SWITCH_ENABLED_' with 'b'(b can be 'true' 'false' '0' '1'), Then find value in former #define
#define DISABLED(b) (!_CAT(SWITCH_ENABLED_, b))       // Reverse the value find in former #define

#define COUNT(a) (sizeof(a)/sizeof(*a))              // count the size of array 'a'

#endif //__MACROS_H
