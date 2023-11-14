#include "main.h"
/**
* print_unsigned - a function that Prints a unsigned number
* @size: size of the specifier
* @width:the width  Buffer array to handle print
* @flags: calculate active flags
* @buffer: the buffer
* @precision: Precision specification
* @types: argument list
* Return: No of character  printed
*/
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int q = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[q--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[q--] = (num % 10) + '0';
num /= 10;
}

q++;

return (write_unsgnd(0, q, buffer, flags, width, precision, size));
}
/**
* print_octal - a function that Prints an octal notation
* @size: size of the specifier
* @width:the width  Buffer array to handle print
* @flags: calculate active flags
* @buffer: the buffer
* @precision: Precision specification
* @types: argument list
* Return: No of character  printed
*/
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{

int l = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[l--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[l--] = (num % 8) + '0';
num /= 8;
}

if (flags & F_HASH && init_num != 0)
buffer[l--] = '0';

l++;

return (write_unsgnd(0, l, buffer, flags, width, precision, size));
}
/**
* print_hexadecimal - a function that Prints an hexadecimal notation
* @size: size of the specifier
* @width:the width  Buffer array to handle print
* @flags: calculate active flags
* @buffer: the buffer
* @precision: Precision specification
* @types: argument list
* Return: No of character  printed
*/
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}
/**
* print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/**
* print_hexadecimal - Prints a hexadecimal number in lower
* size: specifier
* @width: width Lista of arguments
* @map_to: Array of values to map the number to
* @buffer: Buffer array to handle print
* @flags:  Calculates active flaggs
* @flag_ch: Calculates active flags
* @types: argument list
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int q = BUFF_SIZE - 2;

unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[q--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[q--] = map_to[num % 16];
num /= 16;
}

if (flags & F_HASH && init_num != 0)
{
buffer[q--] = flag_ch;
buffer[q--] = '0';
}

q++;

return (write_unsgnd(0, q, buffer, flags, width, precision, size));
}
