#include "main.h"

/**
 * str_cmp - compare 2 given strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0 if equaul and otherwise if not equal
 */
int str_cmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (str1[i] - str2[i]);
}
/**
 * strn_cmp - compare 2 strings
 * @s1: string 1
 * @s2: string
 * @n: size
 * Return: 0 if equaul and otherwise if not equal
 */
int strn_cmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * str_len - Get the length of a string
 * @str: string
 * Return: length of string
 */
int str_len(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * strn_cpy - Copy a string with a limit of n
 * @dest: destination
 * @src: source string
 * @size: number of char to be copied
 * Return: sized of char copied
 */
int strn_cpy(char *dest, char *src, int size)
{
	int i = 0;

	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
/**
 * str_cpy - Copy a string
 * @dest: destination
 * @src: source string
 * Return: sized of char copied
 */
int str_cpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
