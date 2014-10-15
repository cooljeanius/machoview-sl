/* dyld_bind_info.h */

#ifndef _DYLD_BIND_INFO_H
#define _DYLD_BIND_INFO_H

/*
 * The internal structure for the broken out bind info.
 */
struct dyld_bind_info {
    const char *segname;
    const char *sectname;
    uint64_t address;
    int bind_type;
    uint64_t addend;
    const char *dylibname;
    const char *symbolname;
    enum bool weak_import;
};

/* (prototypes removed because we are not using the source file that
 * implements those functions.) */

#endif /* !_DYLD_BIND_INFO_H */

/* EOF */
