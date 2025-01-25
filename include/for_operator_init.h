p->start = i_start;
p->end = i_end;
p->step = i_step;
p->i = p->start;
p->is_start = 1;
p->p = NULL;
if (p->start < p->end &&
		p->step > 0)
{
	p->is_up = 1;
}
else if (p->start > p->end &&
		p->step < 0)
{
	p->is_down = 1;
}

