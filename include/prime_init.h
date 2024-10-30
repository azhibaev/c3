if (!n)
{
	n = 1000;
}
if (!m)
{
	m = 1000000;
}
p->n = n;
p->m = m;
p->p = malloc(n + 1);
memset(p->p, 0, sizeof(unsigned char) * (n + 1));
p->pa = malloc(sizeof(unsigned int) * (m + 1));
memset(p->pa, 0, sizeof(unsigned int) * (m + 1));

