if (!size)
{
	size = CHARS_DEFAULT_BUFFER_SIZE;
}
p->buf = malloc(size * sizeof(char));
if (p->buf)
{
	p->size = size;
	p->is_init = 1;
	p->is_alloc = 1;
}
else
{
	p->is_alloc = 0;
}
p->factor = CHARS_DEFAULT_GROWTH_FACTOR;
is_init = 1;

