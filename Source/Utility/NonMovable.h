#ifndef NONMOVABLE_H
#define NONMOVABLE_H

class NonMovable
{
public:
	NonMovable() = default;
	NonMovable(NonMovable&&) = delete;
	NonMovable &operator=(NonMovable&&) = delete;
};

#endif // NONMOVABLE_H

