#ifndef BINARY_CONST_H
#define BINARY_CONST_H

// C99 compilant version of 0b
// https://stackoverflow.com/questions/15114140/
#define B(x) S_to_binary_(#x)

static inline unsigned long long S_to_binary_(const char *s)
{
    unsigned long long i = 0;
    while (*s)
    {
        i <<= 1;
        i += *s++ - '0';
    }
    return i;
}

#endif