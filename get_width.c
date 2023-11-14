#include "main.h"
/**
* get_width - a function that calculate the width to be printed.
* @format: Formatted string of the argument
* @i: input of argument to be printed
* @list: list
*
* Return: wdth
*/
int get_width(const char *format, int *i, va_list list)
{
int qadri;
int lateef = 0;
for (qadri = *i + 1; format[qadri] != '\0'; qadri++)
{
if (is_digit(format[qadri]))
{
lateef *= 10;
lateef += format[qadri] - '0';
}
else if (format[qadri] == '*')
{
qadri++;
lateef = va_arg(list, int);
break;
}
else
break;
}
*i = qadri - 1;
return (lateef);
}
