#include "main.h"
#include <stdarg.h>
/**
* print_pointer - a function that Prints a pointer
* @size: size of the specifie
* @width:the width  Buffer array to handle print
* @flags: calculate active flags
* @buffer: the buffer
* @precision: Precision specification
* @types: argument list
* Return: No of character  printed
*/
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char lateef = 0, qadri = ' ';
int ind = BUFF_SIZE - 2, length = 2, qadri_start = 1; /* length=2, for '0x' */
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);

UNUSED(width);
UNUSED(size);

if (addrs == NULL)
return (write(1, "(nil)", 5));

buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);

num_addrs = (unsigned long)addrs;

while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}

if ((flags & F_ZERO) && !(flags & F_MINUS))
qadri = '0';
if (flags & F_PLUS)
lateef = '+', length++;
else if (flags & F_SPACE)
{
	lateef = ' '; length++;
}
ind++;

/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
return (write_pointer(buffer, ind, length,
width, flags, qadri, lateef, qadri_start));
}
/**
* print_non_printable- a function that Prints a nom printable xters
* @size: size of the specifie
* @width:the width  Buffer array to handle print
* @flags: calculate active flags
* @buffer: the buffer
* @precision: Precision specification
* @types: argument list
* Return: No of character  printed
*/
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int q = 0, l = 0;
char *str = va_arg(types, char *);

UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
return (write(1, "(null)", 6));

while (str[q] != '\0')
{
if (is_printable(str[q]))
buffer[q + l] = str[q];
else
l += append_hexa_code(str[q], buffer, q + l);

q++;
}

buffer[q + l] = '\0';

return (write(1, buffer, q + l));
}
/**
* print_reverse - a function that Prints a reverse string
* @size: size of the specifier
* @width:the width  Buffer array to handle print
* @flags: calculate active flags
* @buffer: the buffer
* @precision: Precision specification
* @types: argument list
* Return: No of character  printed
*/
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str;
int q, count = 0;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);

str = va_arg(types, char *);

if (str == NULL)
{
UNUSED(precision);

str = ")Null(";
}
for (q = 0; str[q]; q++)
;

for (q = q - 1; q >= 0; q--)
{
char z = str[q];

write(1, &z, 1);
count++;
}
return (count);
}
/**
* print_rot13string - a function that Prints a reverse string
* @size: size of the specifier
* @width:the width  Buffer array to handle print
* @flags: calculate active flags
* @buffer: the buffer
* @precision: Precision specification
* @types: argument list
* Return: No of character  printed
*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char q;
char *str;
unsigned int l, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
str = "(AHYY)";
for (l = 0; str[l]; l++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[l])
{
q = out[j];
write(1, &q, 1);
count++;
break;
}
}
if (!in[j])
{
q = str[l];
write(1, &q, 1);
count++;
}
}
return (count);
}

