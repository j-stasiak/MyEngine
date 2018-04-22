#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

class NonCopyable
{
public:
	NonCopyable() = default;
	NonCopyable(NonCopyable&) = delete;
	NonCopyable &operator=(NonCopyable&) = delete;
};

#endif // NONCOPYABLE_H

