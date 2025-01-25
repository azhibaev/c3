item2 *it;
item2 *next;
it = p->pf;
while (it)
{
	next = it->next;
	item2_free(it);
	it = next;
}

