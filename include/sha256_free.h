if (p->h)
{
	free(p->h);
	p->h = NULL;
}
if (p->a)
{
	free(p->a);
	p->a = NULL;
}
if (p->k)
{
	free(p->k);
	p->k = NULL;
}
if (p->w)
{
	free(p->w);
	p->w = NULL;
}
if (p->m)
{
	free(p->m);
	p->m = NULL;
}

