p->base = INT_ARRAY_DEFAULT_BASE;
if (!size)
{
	size = 1 KB;
}
p->size = size;
if (p->a)
{
	free(p->a);
}
p->a = malloc(p->size * sizeof(int));
if (p->a)
{
	memset(p->a, 0, p->size * sizeof(int));
}

