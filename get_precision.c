#include "main.h"
/**
* get_precision -  function  that print the calculated precision
* @format: Formatted string
* @i: inserted the rgument.
* @list: list of arguments.
*
* Return: Nothing
*/
int get_precision(const char *format, int *i, va_list list)
{
int qadri = *i + 1;
int lateef = -1;
if (format[qadri] != '.')
return (lateef);
lateef = 0;
for (qadri += 1; format[qadri] != '\0'; qadri++)
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
