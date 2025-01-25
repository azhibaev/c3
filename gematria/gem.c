#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int i_arg = 0;
	int s = 0;
	int s2 = 0;
	int s3 = 0;
	int s4 = 0;
	int i_arg_0 = 1;
	char *buf = NULL;
	int buf_size = 0;
	int i = 0;
	unsigned char c = 0;
	int is_option_v = 0;
	int is_option_n = 0;
	int is_option = 0;

	/* Options */
	for (i_arg = i_arg_0; i_arg < argc; i_arg++)
	{
		buf = argv[i_arg];
		if (buf)
		{
			buf_size = strlen(buf);
			if (buf_size > 0)
			{
				c = (unsigned char)tolower(buf[0]);
				if (c == '-')
				{
					for (i = 1; i < buf_size; i++)
					{
						c = (unsigned char)tolower(buf[i]);
						if (c == 'v')
						{
							is_option_v = 1;
							is_option++;
						}
						else if (c == 'h')
						{
							printf("Usage: %s [options] word ...\n",
									argv[0]);
							is_option++;
						}
						else if (c == 'n')
						{
							is_option_n = 1;
							is_option++;
						}
						else
						{
							break;
						}
					}
					if (is_option)
					{
							i_arg_0++;
							is_option = 0;
					}
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}

	for (i_arg = i_arg_0; i_arg < argc; i_arg++)
	{
		buf = argv[i_arg];
		if (buf)
		{
			buf_size = strlen(buf);
			for (i = 0; i < buf_size; i++)
			{
				c = (unsigned char)tolower(buf[i]);
				if (c >= 'a' && c <= 'z')
					s += c - 'a' + 1;
				else if (c >= '0' && c <= '9')
					s += c - '0';
			}
			for (i = 0; i < buf_size; i++)
			{
				c = (unsigned char)tolower(buf[i]);
				if (c >= 'a' && c <= 'z')
					s2 += (c - 'a') % 9 + 1;
				else if (c >= '0' && c <= '9')
					s2 += c - '0';
			}
			for (i = 0; i < buf_size; i++)
			{
				c = (unsigned char)tolower(buf[i]);
				if (c >= 'a' && c <= 'z')
					s3 += 'z' - c + 1;
				else if (c >= '0' && c <= '9')
					s3 += c - '0';
			}
			for (i = 0; i < buf_size; i++)
			{
				c = (unsigned char)tolower(buf[i]);
				if (c >= 'a' && c <= 'z')
					s4 += ('z' - c) % 9 + 1;
				else if (c >= '0' && c <= '9')
					s4 += c - '0';
			}
			printf("%s ", buf);

			/* Option v */
			if (is_option_v)
			{
				for (i = 0; i < buf_size; i++)
				{
					c = (unsigned char)tolower(buf[i]);
					if (c >= 'a' && c <= 'z')
						printf("%d", (c - 'a') % 9 + 1);
					else if (c >= '0' && c <= '9')
						printf("%d", c - '0');
				}
				printf(" ");
				for (i = 0; i < buf_size; i++)
				{
					c = (unsigned char)tolower(buf[i]);
					if (c >= 'a' && c <= 'z')
						printf("%d", ('z' - c) % 9 + 1);
					else if (c >= '0' && c <= '9')
						printf("%d", c - '0');
				}
				printf(" ");
			}
		}
	}
	if (s)
	{
		printf("= %d ", s);
		printf("%d ", s2);
		printf("| %d ", s3);
		printf("%d\n", s4);
	}
	else if (!is_option_n)
	{
		printf("\n");
	}

	return 0;
}
