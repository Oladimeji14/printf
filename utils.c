#include "main.h"
/**
* is_printable - printable.
* @c: Character
*
* Return: Output
*/
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);
return (0);
}
/**
* append_hexa_code - hexadecimal
* @buffer: Array
* @i: Index
* @ascii_code: ASSCI CODE.
* Return: output
*/
int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
/* The hexa format code is always 2 digits long */
if (ascii_code < 0)
ascii_code *= -1;
buffer[i++] = '\\';
buffer[i++] = 'x';
buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];
return (0);
}
/**
* is_digit -is a digit
* @c: Char
*
* Return: Output
*/
int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);
return (0);
}
/**
* convert_size_number -  specified size
* @num: Number
* @size: Number
*
* Return: num
*/
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}
/**
* convert_size_unsgnd - specified size
* @num: Number
* @size: Number
*
* Return: nothing
*/
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}

