/* stuff/symbol.h */

#ifndef _STUFF_SYMBOL_H_
#define _STUFF_SYMBOL_H_

#include <stdint.h>

#ifndef _STRUCT_SYMBOL_DEFINED
# define _STRUCT_SYMBOL_DEFINED 1
struct symbol {
    char *name;
    char *indr_name;
    uint64_t n_value;
    int is_thumb;
};
#endif /* !_STRUCT_SYMBOL_DEFINED */

#endif /* _STUFF_SYMBOL_H_ */

/* EOF */
