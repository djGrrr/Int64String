/**
 *  This file is available under the terms of the MIT License, see the LICENSE file for full details
 */

#ifndef INT64STRING_H
# define INT64STRING_H

# if defined(ARDUINO) && ARDUINO >= 100
#  include "Arduino.h"
# else
#  include "WString.h"
# endif

# define base16char(i) ("0123456789ABCDEF"[i])

String int64String(uint64_t value, uint8_t base = DEC, bool prefix = false, bool sign = false);
String int64String(int64_t value, uint8_t base = DEC, bool prefix = false);

#endif // INT64STRING_H
