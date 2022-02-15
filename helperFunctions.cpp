#include"helperFunctions.h"

int strLength(const char* src)
{
	int length = {};
	for (length; src[length] != '\0'; length++);
	return length;
}
void deepCopy(char*& dest, const char* src, int start , int end)
{
	if (end == 0 || start >= end)
	{
		if (src)
		{
			int maxSize = {};
			maxSize = strLength(src) - (start - 1);

			dest = new char[maxSize + 1];
			for (int i = 0, j = start - 1; i < maxSize; i++, j++)
			{
				dest[i] = src[j];
			}
			dest[maxSize] = '\0';
		}
		else
		{
			dest = nullptr;
		}
	}
	else
	{
		if (src)
		{
			int maxSize = {};
			maxSize = end - (start - 1);
			dest = new char[maxSize + 1];
			for (int i = 0, j = start - 1; j < end; i++, j++)
			{
				dest[i] = src[j];
			}
			dest[maxSize] = '\0';
		}
		else
		{
		dest = nullptr;
		}
	}
	
}