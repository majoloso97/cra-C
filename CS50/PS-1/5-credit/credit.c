#include <cs50.h>
#include <stdio.h>

long nth_power_of_10(int power);
int get_digit_in_nth_position(long number, int position);
int get_first_2_digits_value_from_position(long number, int start_position);
int is_checksum_valid(long number);
int is_amex(long number);
int is_mastercard(long number);
int is_visa(long number);

int main(void) {
  long card_number = 0;
  while (card_number <= 0) {
    card_number = get_long("Number: ");
  }
  if (is_checksum_valid(card_number)) {
    if (is_amex(card_number)) {
      printf("AMEX\n");
    } else if (is_mastercard(card_number)) {
      printf("MASTERCARD\n");
    } else if (is_visa(card_number)) {
      printf("VISA\n");
    } else {
      printf("INVALID\n");
    }
  } else {
    printf("INVALID\n");
  }
}

int is_checksum_valid(long number) {
  int to_position = 16;
  int sum_odd_positions = 0;
  int sum_even_positions = 0;
  for (int position = 1; position <= to_position; position++) {
    int current_digit = get_digit_in_nth_position(number, position);
    if (position % 2 == 0) {
      int digit_times_2 = 0;
      digit_times_2 = current_digit * 2;
      if (digit_times_2 >= 10) {
        for (int i = 1; i <= 2; i++) {
          current_digit = get_digit_in_nth_position(digit_times_2, i);
          sum_even_positions += current_digit;
        }
      } else {
        sum_even_positions += digit_times_2;
      }
    } else {
      sum_odd_positions += current_digit;
    }
  }
  int total = sum_even_positions + sum_odd_positions;
  if (total % 10 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int is_amex(long number) {
  int starts_with = get_first_2_digits_value_from_position(number, 15);
  if (starts_with == 34 || starts_with == 37) {
    return 1;
  }
  return 0;
}

int is_mastercard(long number) {
  int starts_with = get_first_2_digits_value_from_position(number, 16);
  if (starts_with >= 51 && starts_with <= 55) {
    return 1;
  }
  return 0;
}

int is_visa(long number) {
  int starts_with_16_digits = get_digit_in_nth_position(number, 16);
  int starts_with_13_digits = get_digit_in_nth_position(number, 13);
  if (starts_with_16_digits == 4 || starts_with_13_digits == 4) {
    return 1;
  }
  return 0;
}

int get_first_2_digits_value_from_position(long number, int position) {
  int nth_digit = get_digit_in_nth_position(number, position);
  int nth_digit_minus_one = get_digit_in_nth_position(number, position - 1);
  return (nth_digit * 10) + nth_digit_minus_one;
}

int get_digit_in_nth_position(long number, int position) {
  // Returns the digit in the nth position of a number.
  // E.g. get_digit_in_nth_position(256, 2) returns 5, which is position 2 of
  // 256
  int digit = 0;
  long nth_position_minus_1 = nth_power_of_10(position - 1);
  long nth_position = nth_power_of_10(position);
  digit = (number % nth_position - number % nth_position_minus_1) /
          nth_position_minus_1;
  return digit;
}

long nth_power_of_10(int power) {
  // Returns the equivalent to 10^n based on the provided power
  long result = 1;
  if (power == 0) {
    return result;
  }
  int base = 10;
  int i = 1;
  while (i <= power) {
    result *= base;
    i++;
  }
  return result;
}
