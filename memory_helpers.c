#include "main.h"
/**
 * mem_cpy - copy memory
 * @dest: destination
 * @src: source
 * @n: size of memory to be copied
 * Return: memory of destination
 */
void *mem_cpy(void *dest, void *src, size_t n)
{
	char *cdest = (char *)(dest);
	const char *csrc = (const char *)(src);
	size_t i = 0;

	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
/**
 * realloc_cust - Custom realloc
 * @ptr: old malloc pointer
 * @size: new size
 * Return: new ptr
 */
void *realloc_cust(void *ptr, size_t size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	mem_cpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
/**
 * str_dup -  duplicate a string
 * @s: string
 * Return: duplicate of s
 */
char *str_dup(char *s)
{
	size_t len = str_len(s) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}
	mem_cpy(new_str, s, len);

	return (new_str);
}
/**
 * str_cat - strcat()
 * @dest: destination string
 * @src: source string
 * Return: concatenated string
 */
char *str_cat(char *dest, const char *src)
{
	char *p = dest;
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		p[i] = src[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
/**
 * str_chr - implementation of strchr
 * @str:The string to search.
 * @character:The character to find.
 * Return: pointer to the str
 */
char *str_chr(const char *str, int character)
{
    /*Loop through the str until char is found*/
	while (*str)
	{
		if (*str == character)
		{
			return ((char *)str);/*Return the address of the char*/
		}
		str++;
	}
	return (NULL);
}
