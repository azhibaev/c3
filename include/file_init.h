if (file_name)
{
	chars_read_pchar(p->file_name, file_name, strlen(file_name), CHARS_FLAG_RESET);
	if (FILE_FLAG_READ & flags)
	{
		p->f = fopen(file_name, "r");
		if (p->f)
		{
			p->is_read = 1;
			is_init = 1;
			chars_init(p->s, 32);
			//chars_init(p->s, 4 KB);
		}
	}
	else if (FILE_FLAG_WRITE & flags)
	{
		p->f = fopen(file_name, "w");
		if (p->f)
		{
			p->is_write = 1;
			is_init = 1;
			chars_init(p->s, 4 KB);
		}
	}
}

