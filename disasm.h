/* disasm.h -*- C++ -*-
 * Copyright © 2009 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1.  Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Inc. ("Apple") nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * @APPLE_LICENSE_HEADER_END@
 */


#ifndef _DISASM_H_
#define _DISASM_H_

#include <mach/machine.h> /* for cpu_subtype_t */
#ifndef bool
# include <stdbool.h>
#endif /* !bool */
#include <stdint.h> /* for uint64_t */
#include <mach-o/nlist.h> /* for 'struct nlist' and 'struct nlist_64' */
#include <mach-o/loader.h> /* for 'struct load_command' */
#include <mach-o/reloc.h> /* for 'struct relocation_info' */

#ifndef _ENUM_BYTESEX_DEFINED
# define _ENUM_BYTESEX_DEFINED 1
enum byte_sex
{
  UNKNOWN_BYTE_SEX,
  BIG_ENDIAN_BYTE_SEX,
  LITTLE_ENDIAN_BYTE_SEX
};
#endif /* !_ENUM_BYTESEX_DEFINED */

#ifndef _STRUCT_SYMBOL_DEFINED
# define _STRUCT_SYMBOL_DEFINED 1
struct symbol
{
  char *name;
  char *indr_name;
  uint64_t n_value;
  int is_thumb;
};
#endif /* !_STRUCT_SYMBOL_DEFINED */

#ifdef __cplusplus
# ifndef EXTERN_C
#  define EXTERN_C extern "C"
# endif /* !EXTERN_C */
#else
# ifndef EXTERN_C
#  define EXTERN_C /* (nothing) */
# endif /* !EXTERN_C */
#endif /* __cplusplus */
EXTERN_C int sym_compare(struct symbol *sym1, struct symbol *sym2);
EXTERN_C int rel_compare(struct relocation_info *rel1,
                         struct relocation_info *rel2);

#if !defined(verbose) && !defined(_VERBOSE_DECLARED) && 0
# define _VERBOSE_DECLARED 1
const bool verbose = true;
#endif /* !verbose && !_VERBOSE_DECLARED && 0 */

EXTERN_C const char * guess_symbol(const uint64_t value,
                                   const struct symbol *sorted_symbols,
                                   const uint32_t nsorted_symbols,
                                   const bool verbose);

const char * guess_indirect_symbol(const uint64_t value, /* the value of this symbol (in) */
                      const uint32_t ncmds,
                      const uint32_t sizeofcmds,
                      const struct load_command *load_commands,
                      const enum byte_sex load_commands_byte_sex,
                      const uint32_t *indirect_symbols,
                      const uint32_t nindirect_symbols,
                      const struct nlist *symbols,
                      const struct nlist_64 *symbols64,
                      const uint32_t nsymbols,
                      const char *strings,
                      const uint32_t strings_size);

EXTERN_C uint32_t i386_disassemble(char *sect, uint32_t left,
                                   uint64_t addr, uint64_t sect_addr,
                                   enum byte_sex object_byte_sex,
                                   struct relocation_info *sorted_relocs,
                                   uint32_t nsorted_relocs,
                                   struct nlist *symbols,
                                   struct nlist_64 *symbols64,
                                   uint32_t nsymbols,
                                   struct symbol *sorted_symbols,
                                   uint32_t nsorted_symbols, char *strings,
                                   uint32_t strings_size,
                                   uint32_t *indirect_symbols,
                                   uint32_t nindirect_symbols,
                                   cpu_type_t cputype,
                                   struct load_command *load_commands,
                                   uint32_t ncmds, uint32_t sizeofcmds,
                                   bool verbose, bool llvm_mc);

/* try to prevent types from conflicting: */
#ifdef _ARM_DISASM_H
# ifndef ENUM_BOOL
#  define ENUM_BOOL enum bool
# endif /* !ENUM_BOOL */
#else
# ifndef ENUM_BOOL
#  define ENUM_BOOL bool
# endif /* !ENUM_BOOL */
#endif /* _ARM_DISASM_H */

#ifndef _ENUM_BOOL_IN_THUMB_DEFINED
# define _ENUM_BOOL_IN_THUMB_DEFINED 1
extern ENUM_BOOL in_thumb;
#endif /* !_ENUM_BOOL_IN_THUMB_DEFINED */

EXTERN_C uint32_t arm_disassemble(char *sect, uint32_t left, uint32_t addr,
                                  uint32_t sect_addr,
                                  enum byte_sex object_byte_sex,
                                  struct relocation_info *sorted_relocs,
                                  uint32_t nsorted_relocs,
                                  struct nlist *symbols,
                                  uint32_t nsymbols,
                                  struct symbol *sorted_symbols,
                                  uint32_t nsorted_symbols, char *strings,
                                  uint32_t strings_size,
                                  uint32_t *indirect_symbols,
                                  uint32_t nindirect_symbols,
                                  struct load_command *load_commands,
                                  uint32_t ncmds, uint32_t sizeofcmds,
                                  cpu_subtype_t cpu_subtype, bool verbose);

#endif /* !_DISASM_H_ */

/* EOF */
