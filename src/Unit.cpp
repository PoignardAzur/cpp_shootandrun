Unit::Unit (int t, int m, int l, int r, int f)
{
	team = t;
	max_move = m;
	max_life = l;
	range = r;
	firepower = f;
}

sf_Vector2sz Unit::get_pos ()
{
	return(pos);
}

int Unit::get_team ()
{
	return(team);
}

int Unit::get_move ()
{
	return(move);
}

int Unit::get_life ()
{
	return(life);
}

int Unit::get_range()
{
	return(range);
}

int Unit::get_firepower ()
{
	return(firepower);
}

int Unit::get_max_life()
{
	return(max_life);
}

int Unit::get_max_move()
{
	return(max_move);
}

int Unit::get_animLength()
{
	return(m_animLength);
}

bool Unit::isDead()
{
	return(!life);
}

bool Unit::isInTransition()
{
	return(m_animeLength)
}

void Unit::move()
{
	m_animeLength = 15;
}

void Unit::attack()
{
	m_animeLength = 15;
}

void Unit::takeDamage()
{
	m_animeLength = 15;
}

void Unit::update()
{
	if (isInTransition)
		--m_animLength;
}
