#include <Arduino.h>
#include <ASCON.h>

#define STRING_SIZE 1048576 // 1MB
#define MAX_TAG_SIZE 32

// Pointers for plaintext, ciphertext, and decrypted text in PSRAM
unsigned char *plaintext;
unsigned char *ciphertext;
unsigned char *decrypted;

static unsigned char const key[17] = "IOT_LWC_ASCON---";
static unsigned char nonce[17] = "IOT_LWC_ASCON---";

uint32_t successful_encryptions = 0;
uint32_t successful_decryptions = 0;
uint32_t num_glitches = 0;
// print a byte in binary format.
void print_binary(unsigned char value) {
  for (int i = 7; i >= 0; i--) {
    Serial.print((value & (1 << i)) ? '1' : '0');
  }
}

void setup() {
  Serial.begin(115200);

  // Initialize PSRAM
  if (!psramInit()) {
    Serial.println("PSRAM initialization failed.");
    while (1);
  }

  // Allocate memory in PSRAM for plaintext, ciphertext, and decrypted text
  plaintext = (unsigned char *)ps_malloc(STRING_SIZE);
  ciphertext = (unsigned char *)ps_malloc(STRING_SIZE + MAX_TAG_SIZE);
  decrypted = (unsigned char *)ps_malloc(STRING_SIZE);

  if (plaintext == nullptr || ciphertext == nullptr || decrypted == nullptr) {
    Serial.println("PSRAM allocation failed.");
    while (1);
  }

  // Fill plaintext with dummy data
  for (size_t i = 0; i < STRING_SIZE; i++) {
    plaintext[i] = 'A' + (i % 26);
  }
}

void loop() {
  size_t clen;
  size_t plen;

  long start = micros(); 
  // Encrypt the plaintext
  ascon128_aead_encrypt(ciphertext, &clen, plaintext, STRING_SIZE, nullptr, 0, nonce, key);
  long end = micros();
  long time_enc = end - start;
  successful_encryptions++;
  
  start = micros();
  // Decrypt the ciphertext
  ascon128_aead_decrypt(decrypted, &plen, ciphertext, clen, nullptr, 0, nonce, key);
  end = micros();
  long time_dec = end - start;
  // Compare the decrypted text to the original plaintext
  bool glitch_found = false;
  for (size_t i = 0; i < STRING_SIZE; i++) {
    if (plaintext[i] != decrypted[i]) {
      glitch_found = true;
      size_t start_idx = (i >= 10) ? i - 10 : 0;
      size_t end_idx = (i + 10 < STRING_SIZE) ? i + 10 : STRING_SIZE - 1;

      Serial.print("Glitch found at index: ");
      Serial.println(i);

      Serial.print("Plaintext around glitch: ");
      for (size_t j = start_idx; j <= end_idx; j++) {
        Serial.print((char)plaintext[j]);
      }
      Serial.println();

      Serial.print("Decrypted around glitch: ");
      for (size_t j = start_idx; j <= end_idx; j++) {
        Serial.print((char)decrypted[j]);
      }
      Serial.println();

      Serial.print("Binary values at glitched position - Plaintext: ");
      print_binary(plaintext[i]);
      Serial.print("\tDecrypted: ");
      print_binary(decrypted[i]);
      Serial.println();

      break;
    }
  }

  if (glitch_found) {
    num_glitches++;
  } else {
    successful_decryptions++;
  }
  Serial.print("Encryption done in ");
  Serial.println(time_enc);
  Serial.print("Decryption done in ");
  Serial.println(time_dec);
  // Display the results
  Serial.print("Successful encryptions: ");
  Serial.print(successful_encryptions);
  Serial.print("\tSuccessful decryptions: ");
  Serial.print(successful_decryptions);
  Serial.print("\tGlitches: ");
  Serial.println(num_glitches);

  // delay(1000); // Wait for 5 seconds before trying again
}
