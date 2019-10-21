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

#ifndef UTF_MAPPER_H
#define UTF_MAPPER_H

#include "language.h"

#if ENABLED(DOGLCD)
  #define HARDWARE_CHAR_OUT u8g.print
#else
  #define HARDWARE_CHAR_OUT lcd.write
#endif

#if DISABLED(SIMULATE_ROMFONT) && ENABLED(DOGLCD)
  #if ENABLED(DISPLAY_CHARSET_ISO10646_1)     \
   || ENABLED(DISPLAY_CHARSET_ISO10646_5)     \
   || ENABLED(DISPLAY_CHARSET_ISO10646_KANA)  \
   || ENABLED(DISPLAY_CHARSET_ISO10646_GREEK) \
   || ENABLED(DISPLAY_CHARSET_ISO10646_TR)
    #define MAPPER_ONE_TO_ONE
  #endif
#else // SIMULATE_ROMFONT || !DOGLCD
  #if DISPLAY_CHARSET_HD44780 == JAPANESE
    #if ENABLED(MAPPER_C2C3)
      const PROGMEM uint8_t utf_recode[] =
           { // 0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f          This is fair for symbols
               0x20,0x3F,0xEC,0xED,0x3F,0x5C,0x7C,0x3F,0x22,0x63,0x61,0x7F,0x3F,0x3F,0x52,0xB0,  // c2a
             //' '        鍨�    鎷�         棰�     l         "    c    a    鑺�              R
               0xDF,0x3F,0x32,0x33,0x27,0xE4,0xF1,0xA5,0x2C,0x31,0xDF,0x7E,0x3F,0x3F,0x3F,0x3F,  // c2b but relatively bad for letters.
             // 鎺�         2    3    `    N    p    .    ,    1    鎺�    绂�
               0x3F,0x3F,0x3F,0x3F,0xE1,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,  // c38
             //                     鐩�
               0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0xEF,0x78,0x3F,0x3F,0x3F,0x3F,0xF5,0x3F,0x3F,0xE2,  // c39 missing characters display as '?'
             //                               鏋�    x                        鐪�              鑴�
               0x3F,0x3F,0x3F,0x3F,0xE1,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,  // c3a
             //                     鐩�
               0x3F,0xEE,0x3F,0x3F,0x3F,0x3F,0xEF,0xFD,0x3F,0x3F,0x3F,0x3F,0xF5,0x3F,0x3F,0x3F   // c3b
             //      n                        鏋�    姊�                        鐪�
           };
    #elif ENABLED(MAPPER_E382E383)
      const PROGMEM uint8_t utf_recode[] =
           { // 0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f
               0x3D,0xB1,0xB1,0xA8,0xB2,0xA9,0xB3,0xAA,0xB4,0xAB,0xB5,0xB6,0xB6,0xB7,0xB7,0xB8,  // e382a Please test and correct
             // =    閵堬拷    閵堬拷    閵堬拷    閵堬拷    閵堬拷    閵堬拷    閵堬拷    閵堬拷    閵堬拷    閵堬拷   閵堬拷    閵堬拷    閵堬拷   閵堬拷    閵堬拷
               0xB8,0xB9,0xB9,0xBA,0xBA,0xBB,0xBB,0xBC,0xBC,0xBD,0xBD,0xBE,0xBE,0xBF,0xBF,0xC0,  // e382b
             // 閵堬拷    閵堬拷    閵堬拷   閵堬拷    閵堬拷    閵堬拷    閵堬拷    閵堬拷    閵堬拷   閵堬拷    閵堬拷    閵堬拷    閵堬拷    閵堬拷   閵堬拷    閵堬拷
               0xC0,0xC1,0xC1,0xC2,0xC2,0xC2,0xC3,0xC3,0xC4,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,  // e3838
             // 閵堬拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷   閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷   閵夛拷    閵夛拷
               0xCA,0xCA,0xCB,0xCB,0xCB,0xCC,0xCC,0xCC,0xCD,0xCD,0xCD,0xCE,0xCE,0xCE,0xCF,0xD0,  // e3839
             // 閵夛拷    閵夛拷    閵夛拷   閵夛拷    閵夛拷     閵夛拷    閵夛拷   閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷   閵夛拷    閵夛拷
               0xD1,0xD2,0xD3,0xD4,0xD4,0xD5,0xD5,0xAE,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDC,  // e383a
             // 閵夛拷    閵夛拷    閵夛拷    閵夛拷   閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷   閵夛拷    閵夛拷
               0xEC,0xA7,0xA6,0xDD,0xCC,0x3F,0x3F,0x3F,0x3F,0x3F,0xA6,0xA5,0xB0,0xA4,0xA4,0x3F   // e383b
             // 閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷    ?    ?   ?    ?    ?    閵夛拷    閵夛拷    閵夛拷    閵夛拷    閵夛拷   ?
           };
    #elif ENABLED(MAPPER_D0D1)
      #error "Cyrillic on a JAPANESE display makes no sense. There are no matching symbols."
    #endif

  #elif DISPLAY_CHARSET_HD44780 == WESTERN
    #if ENABLED(MAPPER_C2C3)
      const PROGMEM uint8_t utf_recode[] =
           { // 0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f   This is relative complete.
               0x20,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0x22,0xA9,0xAA,0xAB,0x3F,0x3F,0xAE,0x3F,  // c2a鑱介殕鍨勬嫝闄囨ゼ濞勬悅绡撴紡闄嬭姦鍗㈤搴愮倝
             //' '   闅�    鍨�    鎷�    闄�    妤�    濞�    鎼�    "    婕�    闄�    鑺�    ?    ?    搴�    ?
               0xB0,0xB1,0xB2,0xB3,0x27,0xB5,0xB6,0xB7,0x2C,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF,  // c2b 鎺冲崵铏忛瞾楹撶闇茶矾璧傞箍娼炵褰曢檰鎴┐
             // 鎺�    鍗�    椴�    铏�    ?    纰�    闇�    璺�    ,    楣�    娼�    绂�    褰�    闄�    鎴�    椹�
               0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,  // c38 鑴岃剷鑴欒剾鑴滆劃鑴熻劆鑴¤劉鑴ｈ劋鑴ヨ劍鑴�
             // 鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�
               0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF,  // c39 鑴ㄨ劑鑴劖鑴劙鑴宠劥鑴佃劮鑴硅労鑴昏劶鑴�
             // 鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�    鑴�
               0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF,  // c3a 鑴胯癌鑼洸姘撳繖鑾界尗鑼呴敋姣涚煕閾嗗嵂鑼�
             // 鑴�    璋�    鑺�    鑼�    鐩�    姘�    蹇�    鑾�    鐚�    鑼�    閿�    姣�    鐭�    閾�    鍗�    鑼�
               0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF   // c3b 鍐掑附璐镐箞鐜灇姊呴叾闇夌叅娌＄湁濯掗晛姣�
             // 鍐�    甯�    璨�    璐�    涔�    鐜�    鏋�    姊�    閰�    闇�    鐓�    娌�    鐪�    濯�    闀�    姣�
           };
    #elif ENABLED(MAPPER_D0D1)
      #define MAPPER_D0D1_MOD
      const PROGMEM uint8_t utf_recode[] =
           {//0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f
               0x41,0x80,0x42,0x92,0x81,0x45,0x82,0x83,0x84,0x85,0x4B,0x86,0x4D,0x48,0x4F,0x87,  // d0a
             // A    琚�    B    琚�    琚�    E    琚�    琚�    琚�    琚�    K    琚�    M    H    O    琚�
               0x50,0x43,0x54,0x88,0xD8,0x58,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x62,0x8F,0xAC,0xAD,  // d0b
             // P    C    T    鏍�    鑲�    X    鏁�    瑜�    妤�    浜�    姝�    铦�    b    鍗�    鎸�    鎼�
               0x61,0x36,0x42,0x92,0x81,0x65,0x82,0xB3,0x84,0x85,0x6B,0x86,0x4D,0x48,0x6F,0x87,  // d18
             // a    6    B    琚�    琚�    e    琚�    椴�    琚�    琚�    k    琚�    M    H    o    琚�
               0x70,0x63,0x54,0x79,0xD8,0x78,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x62,0x8F,0xAC,0xAD   // d19
             // p    c    T    y    鑲�    x    鏁�    瑜�    妤�    浜�    姝�    铦�    b    鍗�    鎸�    鎼�
            };
    #elif ENABLED(MAPPER_E382E383)
      #error "Katakana on a WESTERN display makes no sense. There are no matching symbols."
    #endif

  #elif DISPLAY_CHARSET_HD44780 == CYRILLIC
    #if ENABLED(MAPPER_D0D1)
      #define MAPPER_D0D1_MOD
      // it is a Russian alphabet translation
      // except 0401 --> 0xA2 = 琛�, 0451 --> 0xB5 = 瑜�
      const PROGMEM uint8_t utf_recode[] =
               { 0x41,0xA0,0x42,0xA1,0xE0,0x45,0xA3,0xA4,   // unicode U+0400 to U+047f
               // A   琚�->琛�  B    琚�    琚�    E    琚�    琚�      // 0  琛� 琛� 琚� 琚� 琚� 琚� 琚� 琚�
                 0xA5,0xA6,0x4B,0xA7,0x4D,0x48,0x4F,0xA8,   //    琚� 琚� 琚� 琚� 琚� 琚� 琚� 琚�
               // 琚�    琚�    K    琚�    M    H    O    琚�      // 1  琚� 琚� 琚� 琚� 琚� 琚� 琚� 琚�
                 0x50,0x43,0x54,0xA9,0xAA,0x58,0xE1,0xAB,   //    琚� 琚� 琚� 琚� 琚� 琚� 琚� 琚�
               // P    C    T    鏍�    鑲�    X    鏁�    瑜�      // 2  琚� 灏� 瀛� 鏍� 鑲� 鍟� 琚� 鏁�
                 0xAC,0xE2,0xAD,0xAE,0x62,0xAF,0xB0,0xB1,   //    妤� 浜� 姝� 铦� 闉� 鍗� 鎸� 鎼�
               // 妤�    浜�    姝�    铦�    b    鍗�    鎸�    鎼�      // 3  閭� 鏂� 鑳� 璋� 鍐� 姊� 鍗� 锜�
                 0x61,0xB2,0xB3,0xB4,0xE3,0x65,0xB6,0xB7,   //    鎳� 娉� 娉� 璋� 灞� 钖� 鑺� 閿�
               // a   鏂�->瑜�  鑳�    璋�    鍐�    e    鍗�    锜�      // 4  瑜� 瑜� 瑜� 瑜� 瑜� 瑜� 瑜� 瑜�
                 0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0x6F,0xBE,   //    瑜� 瑜� 瑜� 瑜� 瑜� 瑜� 瑜� 瑜�
               // 鎳�    娉�    娉�    璋�    灞�    钖�    o    閿�      // 5  瑜� 瑜� 瑜� 瑜� 瑜� 瑜� 瑜� 瑜�
                 0x70,0x63,0xBF,0x79,0xE4,0x78,0xE5,0xC0,   //    瑜� 瑜� 瑜� 瑜� 瑜� 瑜� 瑜� 瑜�
               // p    c    瑜�    y    瑜�    x    瑜�    瑜�      // 6  瑜� 閫� 鐧� 鐪� 缁� 闈� 钖� 瀛�
                 0xC1,0xE6,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7    //    琛� 闆� 琛� 鍕� 鐔� 寰� 鏃� 璇�
               // 瑜�    瑜�    瑜�    瑜�    瑜�    瑜�    瑜�      瑜�      // 7  瀵� 椹� 宸� 娈� 姹� 璁� 璁� 閫�
             };                                             //    楦� 鍘� 鎶� 楦� 楦� 鍛� 涓� 鑺�
    #elif ENABLED(MAPPER_C2C3)
      #error "Western languages on a CYRILLIC display makes no sense. There are no matching symbols."
    #elif ENABLED(MAPPER_E382E383)
      #error "Katakana on a CYRILLIC display makes no sense. There are no matching symbols."
    #endif
  #else
    #error "Something went wrong in the setting of DISPLAY_CHARSET_HD44780"
  #endif // DISPLAY_CHARSET_HD44780
#endif // SIMULATE_ROMFONT

#define PRINTABLE(C) (((C) & 0xC0u) != 0x80u)

#if ENABLED(MAPPER_C2C3)

  char charset_mapper(const char c) {
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_c2 = false;
    uint8_t d = c;
    if (d >= 0x80u) { // UTF-8 handling
      if (d >= 0xC0u && !seen_c2) {
        utf_hi_char = d - 0xC2u;
        seen_c2 = true;
        return 0;
      }
      else if (seen_c2) {
        d &= 0x3Fu;
        #ifndef MAPPER_ONE_TO_ONE
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x20));
        #else
          HARDWARE_CHAR_OUT((char)(0x80u + (utf_hi_char << 6) + d)) ;
        #endif
      }
      else {
        HARDWARE_CHAR_OUT('?');
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_c2 = false;
    return 1;
  }

#elif ENABLED(MAPPER_C2C3_TR)

  // the C2C3-mapper extended for the 6 altered symbols from C4 and C5 range.

  char charset_mapper(const char c) {
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_c2 = false,
                seen_c4 = false,
                seen_c5 = false;
    uint8_t d = c;
    if (d >= 0x80u) { // UTF-8 handling
           if (d == 0xC4u) { seen_c4 = true; return 0; }
      else if (d == 0xC5u) { seen_c5 = true; return 0; }
      else if (d >= 0xC0u && !seen_c2) {
        utf_hi_char = d - 0xC2u;
        seen_c2 = true;
        return 0;
      }
      else if (seen_c4) {
        switch(d) {
          case 0x9Eu: d = 0xD0u; break;
          case 0x9Fu: d = 0xF0u; break;
          case 0xB0u: d = 0xDDu; break;
          case 0xB1u: d = 0xFDu; break;
          default: d = '?';
        }
        HARDWARE_CHAR_OUT((char)d) ;
      }
      else if (seen_c5) {
        switch(d) {
          case 0x9Eu: d = 0xDEu; break;
          case 0x9Fu: d = 0xFEu; break;
          default: d = '?';
        }
        HARDWARE_CHAR_OUT((char)d) ;
      }
      else if (seen_c2) {
        d &= 0x3Fu;
        #ifndef MAPPER_ONE_TO_ONE
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x20));
        #else
          HARDWARE_CHAR_OUT((char)(0x80u + (utf_hi_char << 6) + d)) ;
        #endif
      }
      else {
        HARDWARE_CHAR_OUT('?');
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_c2 = seen_c4 = seen_c5 = false;
    return 1;
  }

#elif ENABLED(MAPPER_CECF)

  char charset_mapper(const char c) {
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_ce = false;
    uint8_t d = c;
    if (d >= 0x80) { // UTF-8 handling
      if (d >= 0xC0 && !seen_ce) {
        utf_hi_char = d - 0xCE;
        seen_ce = true;
        return 0;
      }
      else if (seen_ce) {
        d &= 0x3F;
        #ifndef MAPPER_ONE_TO_ONE
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x20));
        #else
          HARDWARE_CHAR_OUT((char)(0x80 + (utf_hi_char << 6) + d)) ;
        #endif
      }
      else {
        HARDWARE_CHAR_OUT('?');
      }
    }
    else {
      HARDWARE_CHAR_OUT((char)c);
    }
    seen_ce = false;
    return 1;
  }

#elif ENABLED(MAPPER_CECF)

  char charset_mapper(const char c) {
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_ce = false;
    uint8_t d = c;
    if (d >= 0x80) { // UTF-8 handling
      if (d >= 0xC0 && !seen_ce) {
        utf_hi_char = d - 0xCE;
        seen_ce = true;
        return 0;
      }
      else if (seen_ce) {
        d &= 0x3F;
        #ifndef MAPPER_ONE_TO_ONE
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x20));
        #else
          HARDWARE_CHAR_OUT((char)(0x80 + (utf_hi_char << 6) + d)) ;
        #endif
      }
      else {
        HARDWARE_CHAR_OUT('?');
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_ce = false;
    return 1;
  }

#elif ENABLED(MAPPER_D0D1_MOD)

  char charset_mapper(const char c) {
    // it is a Russian alphabet translation
    // except 0401 --> 0xA2 = 琛�, 0451 --> 0xB5 = 瑜�
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_d5 = false;
    uint8_t d = c;
    if (d >= 0x80) { // UTF-8 handling
      if (d >= 0xD0 && !seen_d5) {
        utf_hi_char = d - 0xD0;
        seen_d5 = true;
        return 0;
      }
      else if (seen_d5) {
        d &= 0x3F;
        if (!utf_hi_char && d == 1) {
          HARDWARE_CHAR_OUT((char) 0xA2); // 琛�
        }
        else if (utf_hi_char == 1 && d == 0x11) {
          HARDWARE_CHAR_OUT((char)0xB5); // 瑜�
        }
        else {
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x10));
        }
      }
      else {
        HARDWARE_CHAR_OUT('?');
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_d5 = false;
    return 1;
  }

#elif ENABLED(MAPPER_D0D1)

  char charset_mapper(const char c) {
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_d5 = false;
    uint8_t d = c;
    if (d >= 0x80u) { // UTF-8 handling
      if (d >= 0xD0u && !seen_d5) {
        utf_hi_char = d - 0xD0u;
        seen_d5 = true;
        return 0;
      }
      else if (seen_d5) {
        d &= 0x3Fu;
        #ifndef MAPPER_ONE_TO_ONE
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x20));
        #else
          HARDWARE_CHAR_OUT((char)(0xA0u + (utf_hi_char << 6) + d)) ;
        #endif
      }
      else {
        HARDWARE_CHAR_OUT('?');
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_d5 = false;
    return 1;
  }

#elif ENABLED(MAPPER_E382E383)

  char charset_mapper(const char c) {
    static uint8_t utf_hi_char; // UTF-8 high part
    static bool seen_e3 = false,
                seen_82_83 = false;
    uint8_t d = c;
    if (d >= 0x80) { // UTF-8 handling
      if (d == 0xE3 && !seen_e3) {
        seen_e3 = true;
        return 0;      // eat 0xE3
      }
      else if (d >= 0x82 && seen_e3 && !seen_82_83) {
        utf_hi_char = d - 0x82;
        seen_82_83 = true;
        return 0;
      }
      else if (seen_e3 && seen_82_83) {
        d &= 0x3F;
        #ifndef MAPPER_ONE_TO_ONE
          HARDWARE_CHAR_OUT((char)pgm_read_byte_near(utf_recode + d + (utf_hi_char << 6) - 0x20));
        #else
          HARDWARE_CHAR_OUT((char)(0x80 + (utf_hi_char << 6) + d)) ;
        #endif
      }
      else {
        HARDWARE_CHAR_OUT((char) '?' );
      }
    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_e3 = false;
    seen_82_83 = false;
    return 1;
  }

#elif ENABLED(MAPPER_C3C4C5_PL)

  /**
   * 鑶� C4 84 = 80
   * 鑶� C4 85 = 81
   * 鑶� C4 86 = 82
   * 鑶� C4 87 = 83
   * 鑷� C4 98 = 84
   * 鑷� C4 99 = 85
   * 鑹� C5 81 = 86
   * 鑹� C5 82 = 87
   * 鑹� C5 83 = 88
   * 鑹� C5 84 = 89
   * 鑴� C3 93 = 8A
   * 璐� C3 B3 = 8B
   * 鑹� C5 9A = 8C
   * 鑹� C5 9B = 8D
   * 娈� C5 B9 = 8E
   * 钘� C5 BA = 8F
   * 鍛� C5 BB = 90
   * 鍋� C5 BC = 91
   */

  char charset_mapper(const char c) {
    static bool seen_c3 = false,
                seen_c4 = false,
                seen_c5 = false;
    uint8_t d = c;
    if (d >= 0x80u) { // UTF-8 handling
           if (d == 0xC4u) { seen_c4 = true; return 0; }
      else if (d == 0xC5u) { seen_c5 = true; return 0; }
      else if (d == 0xC3u) { seen_c3 = true; return 0; }
      else if (seen_c4) {
        switch(d) {
          case 0x84u ... 0x87u: d -= 4; break;  //鑶� - 鑶�
          case 0x98u ... 0x99u: d -= 20; break; //鑷� i 鑷�
          default: d = '?';
        }
        HARDWARE_CHAR_OUT((char)d) ;
      }
      else if (seen_c5) {
        switch(d) {
          case 0x81u ... 0x84u: d += 5; break;  //鑹� - 鑹�
          case 0x9Au ... 0x9Bu: d -= 0x0Eu; break; //鑹� i 鑹�
          case 0xB9u ... 0xBCu: d -= 0x2Bu; break; //娈� - 鍋�
          default: d = '?';
        }
        HARDWARE_CHAR_OUT((char)d) ;
      }
      else if (seen_c3) {
        switch(d) {
          case 0x93u: d = 0x8Au; break; //鑴�
          case 0xB3u: d = 0x8Bu; break; //璐�
          d = '?';
        }
        HARDWARE_CHAR_OUT((char)d) ;
      }

    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_c3 = seen_c4 = seen_c5 = false;
    return 1;
  }

#elif ENABLED(MAPPER_C3C4C5_CZ)

  /**
   * 鑴� C3 81 = 80
   * 鑴� C3 89 = 81
   * 鑴� C3 8D = 82
   * 鑴� C3 93 = 83
   * 鑴� C3 9A = 84
   * 鑴� C3 9D = 85
   * 璋� C3 A1 = 86
   * 鑼� C3 A9 = 87
   * 閾� C3 AD = 88
   * 璐� C3 B3 = 89
   * 鐓� C3 BA = 8A
   * 濯� C3 BD = 8B
   * 鑶� C4 8C = 8C
   * 鑶� C4 8D = 8D
   * 鑶� C4 8E = 8E
   * 鑶� C4 8F = 8F
   * 鑷� C4 9A = 90
   * 鑷� C4 9B = 91
   * 鑹� C5 87 = 92
   * 鑹� C5 88 = 93
   * 鑹� C5 98 = 94
   * 鑹� C5 99 = 95
   * 鑹� C5 A0 = 96
   * 鎷� C5 A1 = 97
   * 鎵� C5 A4 = 98
   * 閽� C5 A5 = 99
   * 濂� C5 AE = 9A
   * 鏆� C5 AF = 9B
   * 娌� C5 BD = 9C
   * 鍟� C5 BE = 9D
   */

  char charset_mapper(const char c) {
    static bool seen_c3 = false,
                seen_c4 = false,
                seen_c5 = false;
    uint8_t d = c;
    if (d >= 0x80u) { // UTF-8 handling
           if (d == 0xC4u) { seen_c4 = true; return 0; }
      else if (d == 0xC5u) { seen_c5 = true; return 0; }
      else if (d == 0xC3u) { seen_c3 = true; return 0; }
      else if (seen_c4) {
        switch(d) {
          case 0x8Cu ... 0x8Fu: break;          // 鑶惰喎鑶歌喒 Mapping 1:1
          case 0x9Au ... 0x9Bu: d -= 10; break; // 鑷嶈噹
          default: d = '?';
        }
        HARDWARE_CHAR_OUT((char)d) ;
      }
      else if (seen_c5) {
        switch(d) {
          case 0x87u ... 0x88u: d += 0x0Bu; break;  // 鑹婅墝
          case 0x98u ... 0x99u: d -= 0x04u; break;  // 鑹犺墶
          case 0xA0u ... 0xA1u: d -= 0x0Au; break;  // 鑹╂嫥
          case 0xA4u ... 0xA5u: d -= 0x0Cu; break;  // 鎵挳
          case 0xAEu ... 0xAFu: d -= 0x14u; break;  // 濂虫殩
          case 0xBDu ... 0xBEu: d -= 0x21u; break;  // 娌ゅ暘
          default: d = '?';
        }
        HARDWARE_CHAR_OUT((char)d) ;
      }
      else if (seen_c3) {
        switch(d) {
          case 0x81u: d = 0x80u; break;  // 鑴�
          case 0x89u: d = 0x81u; break;  // 鑴�
          case 0x8Du: d = 0x82u; break;  // 鑴�
          case 0x93u: d = 0x83u; break;  // 鑴�
          case 0x9Au: d = 0x84u; break;  // 鑴�
          case 0x9Du: d = 0x85u; break;  // 鑴�
          case 0xA1u: d = 0x86u; break;  // 璋�
          case 0xA9u: d = 0x87u; break;  // 鑼�
          case 0xADu: d = 0x88u; break;  // 閾�
          case 0xB3u: d = 0x89u; break;  // 璐�
          case 0xBAu: d = 0x8Au; break;  // 鐓�
          case 0xBDu: d = 0x8Bu; break;  // 濯�
          default: d = '?';
        }
        HARDWARE_CHAR_OUT((char)d) ;
      }

    }
    else {
      HARDWARE_CHAR_OUT((char) c );
    }
    seen_c3 = seen_c4 = seen_c5 = false;
    return 1;
  }

#elif ENABLED(MAPPER_C3C4C5_SK)

  // TBD
  #error "No mapping for Slovak at this time. Use MAPPER_NON."

#else

  #define MAPPER_NON

  #undef PRINTABLE
  #define PRINTABLE(C) true

  char charset_mapper(const char c) {
    HARDWARE_CHAR_OUT(c);
    return 1;
  }

#endif // code mappers

#endif // UTF_MAPPER_H
