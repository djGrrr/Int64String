/**
 *  This file is available under the terms of the MIT License, see the LICENSE file for full details
 */

#ifndef STRINGINT64_H
# define STRINGINT64_H

# if defined(ARDUINO) && ARDUINO >= 100
#  include "Arduino.h"
# else
#  include "WString.h"
# endif

String int64toString(uint64_t value, uint8_t base, bool sign, bool prefix);
String int64toString(uint64_t value, uint8_t base, bool prefix);
String int64toString(uint64_t value, uint8_t base);
String int64toString(uint64_t value);

String int64toString(int64_t value, uint8_t base, bool prefix);
String int64toString(int64_t value, uint8_t base);
String int64toString(int64_t value);

#endif // STRINGINT64_H
