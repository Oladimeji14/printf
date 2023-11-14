#include "main.h"
/**
* get_size - print the size to cast the argument.
* @format: Formatted string
* @i: insert of arguments
*
* Return: output
*/
int get_size(const char *format, int *i)
{
int qad = *i + 1;
int lat = 0;
if (format[qad] == 'l')
lat = S_LONG;
else if (format[qad] == 'h')
lat = S_SHORT;
if (lat == 0)
*i = qad - 1;
else
*i = qad;
return (lat);
}
