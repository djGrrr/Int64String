## Usage

Usage of this function is very simple:  
Parameters are:  
**value** either _int64_t_ (_long long_) or _uint64_t_ (_unsigned long long_): Value to be converted  
**base** _uint8_t_ (unsigned char): the "base" for the converted number, either BIN (2), OCT (8), DEC (10), or HEX (16), optional defaults to DEC (10)  
**prefix** _bool_: Add a prefix onto converted number. "B" for BIN, "0" for OCT, or "0x" for HEX, optional, defaults to false  

Rerurns a String

```cpp
// Signed function
String int64String(int64_t value, uint8_t base = DEC, bool prefix = false);
// Unsigned function
String int64String(uint64_t value, uint8_t base = DEC, bool prefix = false);
```

An example sketch:
```cpp
#include <Int64String.h>

// LL and ULL suffixes are needed for the compiler to parse the numbers correctly
int64_t MIN_INT64 = -9223372036854775808LL;
int64_t MAX_INT64 = 9223372036854775807LL;
uint64_t MAX_UINT64 = 18446744073709551615ULL;
uint64_t UINT64 = 4527492349271ULL;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println(int64String(MIN_INT64));
  Serial.println(int64String(MAX_UINT64));
  Serial.println(int64String(UINT64));
  Serial.println(int64String(UINT64, BIN));
  Serial.println(int64String(MAX_INT64, OCT, true));
  Serial.println(int64String(UINT64, HEX));
  Serial.println(int64String(MAX_UINT64, HEX, true));
  Serial.println(int64String(0LL));
  Serial.println(int64String(0ULL, BIN, true));
}

void loop() {

}
```

Will output the following on the Serial Monitor:  
```text
-9223372036854775808
18446744073709551615
4527492349271
1000001111000100011100100101011110101010111
0777777777777777777777
41E2392BD57
0xFFFFFFFFFFFFFFFF
0
B0
```
