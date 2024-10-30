if (p->p)
{
	free(p->p);
	p->p = NULL;
}
if (p->pa)
{
	free(p->pa);
	p->pa = NULL;
}

