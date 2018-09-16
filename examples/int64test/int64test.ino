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
