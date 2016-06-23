#ifndef ROMAN_H
#define ROMAN_H

char * add_roman(char *augend, char *addend);

char * subtract_roman(char *minuend, char *subtrahend);

int get_arabic_value(char *roman_numerals);

int get_char_arabic_value(char roman_numeral);

char * get_roman_value(int arabic);

#endif /* ROMAN_H */
