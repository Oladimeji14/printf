#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
* _printf - Printf function.
* @format: format.
* Return: Output.
*/
int _printf(const char *format, ...)
{
int qad, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (qad = 0; format && format[qad] != '\0'; qad++)
{
if (format[qad] != '%')
{
buffer[buff_ind++] = format[qad];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
/* write(1, &format[qad], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &qad);
width = get_width(format, &qad, list);
precision = get_precision(format, &qad, list);
size = get_size(format, &qad);
++qad;
printed = handle_print(format, &qad, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}
/**
* print_buffer - Printing the buffer if it exist
* @buffer: Array of chars
* @buff_ind: Index buffer
*/
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}
