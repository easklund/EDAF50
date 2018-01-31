#include "coding.h"

/* For any character c, encode(c) is a character different from c */
unsigned char encode(unsigned char c)
{
  return c + 5;
}
/* For any character c, decode(encode(c)) == c */
unsigned char decode(unsigned char c)
{
  return c - 5;
}
