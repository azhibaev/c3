item *it;
item *next;
it = p->pf;
while (it)
{
	next = it->next;
	item_free(it);
	it = next;
}

