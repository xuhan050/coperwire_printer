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

// 100k Honeywell 135-104LAF-J01
// R0 = 100000 Ohm
// T0 = 25 鎺矯
// Beta = 3974
// R1 = 0 Ohm
// R2 = 4700 Ohm
const short temptable_71[][2] PROGMEM = {
  {   35 * OVERSAMPLENR, 300 },
  {   51 * OVERSAMPLENR, 270 },
  {   54 * OVERSAMPLENR, 265 },
  {   58 * OVERSAMPLENR, 260 },
  {   59 * OVERSAMPLENR, 258 },
  {   61 * OVERSAMPLENR, 256 },
  {   63 * OVERSAMPLENR, 254 },
  {   64 * OVERSAMPLENR, 252 },
  {   66 * OVERSAMPLENR, 250 },
  {   67 * OVERSAMPLENR, 249 },
  {   68 * OVERSAMPLENR, 248 },
  {   69 * OVERSAMPLENR, 247 },
  {   70 * OVERSAMPLENR, 246 },
  {   71 * OVERSAMPLENR, 245 },
  {   72 * OVERSAMPLENR, 244 },
  {   73 * OVERSAMPLENR, 243 },
  {   74 * OVERSAMPLENR, 242 },
  {   75 * OVERSAMPLENR, 241 },
  {   76 * OVERSAMPLENR, 240 },
  {   77 * OVERSAMPLENR, 239 },
  {   78 * OVERSAMPLENR, 238 },
  {   79 * OVERSAMPLENR, 237 },
  {   80 * OVERSAMPLENR, 236 },
  {   81 * OVERSAMPLENR, 235 },
  {   82 * OVERSAMPLENR, 234 },
  {   84 * OVERSAMPLENR, 233 },
  {   85 * OVERSAMPLENR, 232 },
  {   86 * OVERSAMPLENR, 231 },
  {   87 * OVERSAMPLENR, 230 },
  {   89 * OVERSAMPLENR, 229 },
  {   90 * OVERSAMPLENR, 228 },
  {   91 * OVERSAMPLENR, 227 },
  {   92 * OVERSAMPLENR, 226 },
  {   94 * OVERSAMPLENR, 225 },
  {   95 * OVERSAMPLENR, 224 },
  {   97 * OVERSAMPLENR, 223 },
  {   98 * OVERSAMPLENR, 222 },
  {   99 * OVERSAMPLENR, 221 },
  {  101 * OVERSAMPLENR, 220 },
  {  102 * OVERSAMPLENR, 219 },
  {  104 * OVERSAMPLENR, 218 },
  {  106 * OVERSAMPLENR, 217 },
  {  107 * OVERSAMPLENR, 216 },
  {  109 * OVERSAMPLENR, 215 },
  {  110 * OVERSAMPLENR, 214 },
  {  112 * OVERSAMPLENR, 213 },
  {  114 * OVERSAMPLENR, 212 },
  {  115 * OVERSAMPLENR, 211 },
  {  117 * OVERSAMPLENR, 210 },
  {  119 * OVERSAMPLENR, 209 },
  {  121 * OVERSAMPLENR, 208 },
  {  123 * OVERSAMPLENR, 207 },
  {  125 * OVERSAMPLENR, 206 },
  {  126 * OVERSAMPLENR, 205 },
  {  128 * OVERSAMPLENR, 204 },
  {  130 * OVERSAMPLENR, 203 },
  {  132 * OVERSAMPLENR, 202 },
  {  134 * OVERSAMPLENR, 201 },
  {  136 * OVERSAMPLENR, 200 },
  {  139 * OVERSAMPLENR, 199 },
  {  141 * OVERSAMPLENR, 198 },
  {  143 * OVERSAMPLENR, 197 },
  {  145 * OVERSAMPLENR, 196 },
  {  147 * OVERSAMPLENR, 195 },
  {  150 * OVERSAMPLENR, 194 },
  {  152 * OVERSAMPLENR, 193 },
  {  154 * OVERSAMPLENR, 192 },
  {  157 * OVERSAMPLENR, 191 },
  {  159 * OVERSAMPLENR, 190 },
  {  162 * OVERSAMPLENR, 189 },
  {  164 * OVERSAMPLENR, 188 },
  {  167 * OVERSAMPLENR, 187 },
  {  170 * OVERSAMPLENR, 186 },
  {  172 * OVERSAMPLENR, 185 },
  {  175 * OVERSAMPLENR, 184 },
  {  178 * OVERSAMPLENR, 183 },
  {  181 * OVERSAMPLENR, 182 },
  {  184 * OVERSAMPLENR, 181 },
  {  187 * OVERSAMPLENR, 180 },
  {  190 * OVERSAMPLENR, 179 },
  {  193 * OVERSAMPLENR, 178 },
  {  196 * OVERSAMPLENR, 177 },
  {  199 * OVERSAMPLENR, 176 },
  {  202 * OVERSAMPLENR, 175 },
  {  205 * OVERSAMPLENR, 174 },
  {  208 * OVERSAMPLENR, 173 },
  {  212 * OVERSAMPLENR, 172 },
  {  215 * OVERSAMPLENR, 171 },
  {  219 * OVERSAMPLENR, 170 },
  {  237 * OVERSAMPLENR, 165 },
  {  256 * OVERSAMPLENR, 160 },
  {  300 * OVERSAMPLENR, 150 },
  {  351 * OVERSAMPLENR, 140 },
  {  470 * OVERSAMPLENR, 120 },
  {  504 * OVERSAMPLENR, 115 },
  {  538 * OVERSAMPLENR, 110 },
  {  552 * OVERSAMPLENR, 108 },
  {  566 * OVERSAMPLENR, 106 },
  {  580 * OVERSAMPLENR, 104 },
  {  594 * OVERSAMPLENR, 102 },
  {  608 * OVERSAMPLENR, 100 },
  {  622 * OVERSAMPLENR,  98 },
  {  636 * OVERSAMPLENR,  96 },
  {  650 * OVERSAMPLENR,  94 },
  {  664 * OVERSAMPLENR,  92 },
  {  678 * OVERSAMPLENR,  90 },
  {  712 * OVERSAMPLENR,  85 },
  {  745 * OVERSAMPLENR,  80 },
  {  758 * OVERSAMPLENR,  78 },
  {  770 * OVERSAMPLENR,  76 },
  {  783 * OVERSAMPLENR,  74 },
  {  795 * OVERSAMPLENR,  72 },
  {  806 * OVERSAMPLENR,  70 },
  {  818 * OVERSAMPLENR,  68 },
  {  829 * OVERSAMPLENR,  66 },
  {  840 * OVERSAMPLENR,  64 },
  {  850 * OVERSAMPLENR,  62 },
  {  860 * OVERSAMPLENR,  60 },
  {  870 * OVERSAMPLENR,  58 },
  {  879 * OVERSAMPLENR,  56 },
  {  888 * OVERSAMPLENR,  54 },
  {  897 * OVERSAMPLENR,  52 },
  {  905 * OVERSAMPLENR,  50 },
  {  924 * OVERSAMPLENR,  45 },
  {  940 * OVERSAMPLENR,  40 },
  {  955 * OVERSAMPLENR,  35 },
  {  967 * OVERSAMPLENR,  30 },
  {  970 * OVERSAMPLENR,  29 },
  {  972 * OVERSAMPLENR,  28 },
  {  974 * OVERSAMPLENR,  27 },
  {  976 * OVERSAMPLENR,  26 },
  {  978 * OVERSAMPLENR,  25 },
  {  980 * OVERSAMPLENR,  24 },
  {  982 * OVERSAMPLENR,  23 },
  {  984 * OVERSAMPLENR,  22 },
  {  985 * OVERSAMPLENR,  21 },
  {  987 * OVERSAMPLENR,  20 },
  {  995 * OVERSAMPLENR,  15 },
  { 1001 * OVERSAMPLENR,  10 },
  { 1006 * OVERSAMPLENR,   5 },
  { 1010 * OVERSAMPLENR,   0 }
};
