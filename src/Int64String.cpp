/**
 *  This file is available under the terms of the MIT License, see the LICENSE file for full details
 */

#include "Int64String.h"

// Unsigned integer function, it does the bulk of the work, returns a String
String int64String(uint64_t value, uint8_t base = DEC, bool prefix = false, bool sign = false) {
  // Binary?
  bool is_bin = base == BIN;
  // Octal?
  bool is_oct = base == OCT;
  // Hexadecimal?
  bool is_hex = base == HEX;

  // default to decimal
  if (!is_bin && !is_oct && !is_hex)
    base = DEC;

  // Decimal?
  bool is_dec = base == DEC;

  char buffer[66] = {0};
  uint8_t i = 64;
  if (value == 0)
    buffer[i--] = '0';
  else {
    for (; value && i; --i, value /= base)
      buffer[i] = "0123456789ABCDEF"[value % base];
  }

  // Signed numbers only make sense for decimal numbers
  if (is_dec && sign)
    buffer[i--] = '-';
  else if (prefix) {
    if (is_hex) {
      // 0x prefix
      buffer[i--] = 'x';
      buffer[i--] = '0';
    }
    else if (is_oct)
      buffer[i--] = '0';
    else if (is_bin)
      buffer[i--] = 'B';
  }

  // return String starting at i + 1
  return String(&buffer[i + 1]);
}

// Signed integer function, returns a String
String int64String(int64_t value, uint8_t base = DEC, bool prefix = false) {
  // Signed numbers only make sense for decimal numbers
  bool sign = base == DEC && value < 0;
  // if signed, make it positive
  uint64_t uvalue = sign ? -value : value;

  // call the unsigned function to format the number
  return int64String(uvalue, base, prefix, sign);
}
