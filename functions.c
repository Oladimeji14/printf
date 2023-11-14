#include "main.h"
/**
* print_char - a function that Prints a character
* @size: size of the specifier.
* @width:the width  Buffer array to handle print
* @flags: calculate active flags
* @buffer: the buffer
* @precision: Precision specification
* @types: argument list
* Return: No of character  printed
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char o = va_arg(types, int);
return (handle_write_char(o, buffer, flags, width, precision, size));
}
/**
* print_string - a function that  Prints a string
* @size: size of the specifier.
* @width:the width  Buffer array to handle print
* @flags:  Calculates active flags
* @buffer: the buffer
* @precision: specification of the precision
* @types: argument list
* Return: No of character  printed
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, q;
char *str = va_arg(types, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}

while (str[length] != '\0')
length++;

if (precision >= 0 && precision < length)
length = precision;

if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for (q = width - length; q > 0; q--)
write(1, " ", 1);
return (width);
}
else
{
for (q = width - length; q > 0; q--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}
}

return (write(1, str, length));
}
/**
* print_percent - function that prints  percent
* @size: size of the specifier.
* @width:the width  Buffer array to handle print
* @flags:  Calculates active flags
* @buffer: the buffer
* @precision: specification of the precision
* @types: argument list
* Return: No of character  printed
*/
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/**
* print_int - function that prints integer
* @size: size of the specifier.
* @width:the width  Buffer array to handle print
* @flags:  Calculates active flags
* @buffer: the buffer
* @precision: specification of the precision
* @types: argument list
* Return: No of character  printed
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int q = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;

n = convert_size_number(n, size);

if (n == 0)
buffer[q--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;

if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}

while (num > 0)
{
buffer[q--] = (num % 10) + '0';
num /= 10;
}

q++;

return (write_number(is_negative, q, buffer, flags, width, precision, size));
}
/**
* print_binary - function that prints binary
* @size: size of the specifier
* @width:the width  Buffer array to handle print
* @flags:  Calculates active flags
* @buffer: the buffer
* @precision: specification of the precision
* @types: argument list
* Return: No of character  printed
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int l, q, o, sum;
unsigned int c[32];
int count;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

l = va_arg(types, unsigned int);
q = 2147483648; /* (2 ^ 31) */
c[0] = l / q;
for (o = 1; o < 32; o++)
{
q /= 2;
c[o] = (l / q) % 2;
}
for (o = 0, sum = 0, count = 0; o < 32; o++)
{
sum += c[o];
if (sum || o == 31)
{
char z = '0' + c[o];

write(1, &z, 1);
count++;
}
}
return (count);
}


