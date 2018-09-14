/**
 *  This file is available under the terms of the MIT License, see the LICENSE file for full details
 */

#include "StringInt64.h"

// Unsigned integer functions
// This function does the bulk of the work
String int64toString(uint64_t value, uint8_t base, bool sign, bool prefix) {
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

  return String(&buf[i+1]);
}

String int64toString(uint64_t value, uint8_t base, bool prefix) {
  return int64toString(value, base, false, prefix);
}

String int64toString(uint64_t value, uint8_t base) {
  return int64toString(value, base, false, false);
}

String int64toString(uint64_t value) {
  return int64toString(value, DEC, false, false);
}


// Signed integer functions
String int64toString(int64_t value, uint8_t base, bool prefix) {
  if(value == 0)
    return String("0");

  // Signed numbers only make sense for decimal numbers
  bool sign = base == DEC && value < 0;
  uint64_t uvalue;
  if (sign)
    uvalue = -value;
  else
    uvalue = value;

  return int64toString(uvalue, base, sign, prefix);
}

String int64toString(int64_t value, uint8_t base) {
  return int64toString(value, base, false);
}

String int64toString(int64_t value) {
  return int64toString(value, DEC, false);
}
