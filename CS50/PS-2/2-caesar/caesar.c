#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_key_numeric(string key);
void rotate(string plaintext, int key);

int main(int argc, string argv[]) {
  if (argc != 2 || is_key_numeric(argv[1]) == 0) {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  int key = atoi(argv[1]);
  printf("Using key: %i\n", key);
  string plaintext = get_string("plaintext: ");
  rotate(plaintext, key);
}

int is_key_numeric(string key) {
  for (int i = 0, n = strlen(key); i < n; i++) {
    if (!isdigit(key[i])) {
      return 0;
    }
  }
  return 1;
}

void rotate(string plaintext, int key) {
  printf("ciphertext: ");
  char base_char;
  char rotated_char;
  int rotation;
  for (int i = 0, n = strlen(plaintext); i < n; i++) {
    char c = plaintext[i];
    // printf("Current char: %c\n", c);
    if (c >= 'a' && c <= 'z') {
      base_char = c - 'a';
      rotation = (base_char + key) % 26;
      // printf("%c", rotation);
      rotated_char = 'a' + rotation;
    } else if (c >= 'A' && c <= 'Z') {
      base_char = c - 'A';
      rotation = (base_char + key) % 26;
      rotated_char = 'A' + rotation;
    } else {
      rotated_char = c;
    }
    printf("%c", rotated_char);
  }
  printf("\n");
}
