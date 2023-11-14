#include "main.h"
/**
* get_flags - function to print an active flags.
* @format: the Formatted string to print the argument
* @i: Input parameter
* Return: flag
*/
int get_flags(const char *format, int *i)
{
/* - + 0 # ' ' */
/* 1 2 4 8  16 */
int lat, curr_i;
int flags = 0;

const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
for (lat = 0; FLAGS_CH[lat] != '\0'; lat++)
if (format[curr_i] == FLAGS_CH[lat])
{
flags |= FLAGS_ARR[lat];
break;
}
if (FLAGS_CH[lat] == 0)
break;
}
*i = curr_i - 1;
return (flags);
}
