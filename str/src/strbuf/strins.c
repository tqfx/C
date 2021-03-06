#include <string.h>
#include "strbuf.h"

#undef strins

int strins(char *_str, size_t _bufsz, size_t _index, const char *_substr)
{
    size_t nstr = strnlen(_str, _bufsz);

    if (nstr < _index || nstr >= _bufsz)
        return 0;

    size_t nsub = strlen(_substr);

    for (size_t j = nstr; j + 1 > _index; j--)
    {
        if (j + nsub > _bufsz - 1)
            continue;
        else if (j + nsub == _bufsz - 1)
            _str[_bufsz - 1] = '\0';
        else
            _str[j + nsub] = _str[j];
    }

    for (size_t j = 0; _index + j < _bufsz && j < nsub; j++)
    {
        _str[_index + j] = _substr[j];
        if (_index + j == _bufsz - 1)
            _str[_bufsz - 1] = '\0';
    }

    return 1;
}
