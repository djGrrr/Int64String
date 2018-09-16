/**
 *  This file is available under the terms of the MIT License, see the LICENSE file for full details
 */

#include "Int64String.h"

// Unsigned integer function, it does the bulk of the work
String Int64String(uint64_t value, uint8_t base = DEC, bool prefix = false, bool sign = false) {
  if (value == 0)
    return String("0");

  bool is_bin = base == BIN;
  bool is_oct = base == OCT;
  bool is_hex = base == HEX;

  // default to decimal
  if (!is_bin && !is_oct && !is_hex)
    base = DEC;

  bool is_dec = base == DEC;

  char buf[66] = {0};
  uint8_t i = 64;
  for (; value && i; --i, value /= base)
    buf[i] = "0123456789ABCDEF"[value % base];

  if (is_dec && sign)
    buf[i--] = '-';
  else if (prefix) {
    if (is_hex) {
      buf[i--] = 'x';
      buf[i--] = '0';
    }
    else if (is_oct)
      buf[i--] = '0';
    else if (is_bin)
      buf[i--] = 'B';
  }

  return String(&buf[i + 1]);
}

// Signed integer function
String Int64String(int64_t value, uint8_t base = DEC, bool prefix = false) {
  if (value == 0)
    return String("0");

  // Signed numbers only make sense for decimal numbers
  bool sign = base == DEC && value < 0;
  // if signed, make it positive
  uint64_t uvalue = sign ? -value : value;

  return Int64String(uvalue, base, prefix, sign);
}
