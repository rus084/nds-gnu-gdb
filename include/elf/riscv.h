/* RISC-V ELF support for BFD.
   Copyright (C) 2011-2019 Free Software Foundation, Inc.

   Contributed by Andrew Waterman (andrew@sifive.com).
   Based on MIPS ELF support for BFD, by Ian Lance Taylor.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING3. If not,
   see <http://www.gnu.org/licenses/>.  */

/* This file holds definitions specific to the RISCV ELF ABI.  Note
   that most of this is not actually implemented by BFD.  */

#ifndef _ELF_RISCV_H
#define _ELF_RISCV_H

#include "elf/reloc-macros.h"
#include "libiberty.h"

/* Relocation types.  */
START_RELOC_NUMBERS (elf_riscv_reloc_type)
  /* Relocation types used by the dynamic linker.  */
  RELOC_NUMBER (R_RISCV_NONE, 0)
  RELOC_NUMBER (R_RISCV_32, 1)
  RELOC_NUMBER (R_RISCV_64, 2)
  RELOC_NUMBER (R_RISCV_RELATIVE, 3)
  RELOC_NUMBER (R_RISCV_COPY, 4)
  RELOC_NUMBER (R_RISCV_JUMP_SLOT, 5)
  RELOC_NUMBER (R_RISCV_TLS_DTPMOD32, 6)
  RELOC_NUMBER (R_RISCV_TLS_DTPMOD64, 7)
  RELOC_NUMBER (R_RISCV_TLS_DTPREL32, 8)
  RELOC_NUMBER (R_RISCV_TLS_DTPREL64, 9)
  RELOC_NUMBER (R_RISCV_TLS_TPREL32, 10)
  RELOC_NUMBER (R_RISCV_TLS_TPREL64, 11)

  /* Relocation types not used by the dynamic linker.  */
  RELOC_NUMBER (R_RISCV_BRANCH, 16)
  RELOC_NUMBER (R_RISCV_JAL, 17)
  RELOC_NUMBER (R_RISCV_CALL, 18)
  RELOC_NUMBER (R_RISCV_CALL_PLT, 19)
  RELOC_NUMBER (R_RISCV_GOT_HI20, 20)
  RELOC_NUMBER (R_RISCV_TLS_GOT_HI20, 21)
  RELOC_NUMBER (R_RISCV_TLS_GD_HI20, 22)
  RELOC_NUMBER (R_RISCV_PCREL_HI20, 23)
  RELOC_NUMBER (R_RISCV_PCREL_LO12_I, 24)
  RELOC_NUMBER (R_RISCV_PCREL_LO12_S, 25)
  RELOC_NUMBER (R_RISCV_HI20, 26)
  RELOC_NUMBER (R_RISCV_LO12_I, 27)
  RELOC_NUMBER (R_RISCV_LO12_S, 28)
  RELOC_NUMBER (R_RISCV_TPREL_HI20, 29)
  RELOC_NUMBER (R_RISCV_TPREL_LO12_I, 30)
  RELOC_NUMBER (R_RISCV_TPREL_LO12_S, 31)
  RELOC_NUMBER (R_RISCV_TPREL_ADD, 32)
  RELOC_NUMBER (R_RISCV_ADD8, 33)
  RELOC_NUMBER (R_RISCV_ADD16, 34)
  RELOC_NUMBER (R_RISCV_ADD32, 35)
  RELOC_NUMBER (R_RISCV_ADD64, 36)
  RELOC_NUMBER (R_RISCV_SUB8, 37)
  RELOC_NUMBER (R_RISCV_SUB16, 38)
  RELOC_NUMBER (R_RISCV_SUB32, 39)
  RELOC_NUMBER (R_RISCV_SUB64, 40)
  RELOC_NUMBER (R_RISCV_GNU_VTINHERIT, 41)
  RELOC_NUMBER (R_RISCV_GNU_VTENTRY, 42)
  RELOC_NUMBER (R_RISCV_ALIGN, 43)
  RELOC_NUMBER (R_RISCV_RVC_BRANCH, 44)
  RELOC_NUMBER (R_RISCV_RVC_JUMP, 45)
  RELOC_NUMBER (R_RISCV_RVC_LUI, 46)
  RELOC_NUMBER (R_RISCV_GPREL_I, 47)
  RELOC_NUMBER (R_RISCV_GPREL_S, 48)
  RELOC_NUMBER (R_RISCV_TPREL_I, 49)
  RELOC_NUMBER (R_RISCV_TPREL_S, 50)
  RELOC_NUMBER (R_RISCV_RELAX, 51)
  RELOC_NUMBER (R_RISCV_SUB6, 52)
  RELOC_NUMBER (R_RISCV_SET6, 53)
  RELOC_NUMBER (R_RISCV_SET8, 54)
  RELOC_NUMBER (R_RISCV_SET16, 55)
  RELOC_NUMBER (R_RISCV_SET32, 56)
  RELOC_NUMBER (R_RISCV_32_PCREL, 57)

  /* Relocations for NDS V5.  */
  RELOC_NUMBER (R_RISCV_NDS_MISC, 230)
  RELOC_NUMBER (R_RISCV_EXECIT_ITE, 231)
  RELOC_NUMBER (R_RISCV_ICT_HI20, 232)
  RELOC_NUMBER (R_RISCV_ICT_LO12_I, 233)
  RELOC_NUMBER (R_RISCV_PCREL_ICT_HI20, 234)
  RELOC_NUMBER (R_RISCV_CALL_ICT, 235)
  RELOC_NUMBER (R_RISCV_ICT_64, 236)
  RELOC_NUMBER (R_RISCV_NO_RVC_REGION_BEGIN, 237)
  RELOC_NUMBER (R_RISCV_NO_RVC_REGION_END, 238)
  RELOC_NUMBER (R_RISCV_DELETE, 239)
  RELOC_NUMBER (R_RISCV_ALIGN_BTB, 240)
  RELOC_NUMBER (R_RISCV_10_PCREL, 241)
  RELOC_NUMBER (R_RISCV_DATA, 242)
  RELOC_NUMBER (R_RISCV_LALO_HI20, 243)
  RELOC_NUMBER (R_RISCV_LALO_LO12_I, 244)
  RELOC_NUMBER (R_RISCV_RELAX_ENTRY, 245)
  RELOC_NUMBER (R_RISCV_LGP18S0, 246)
  RELOC_NUMBER (R_RISCV_LGP17S1, 247)
  RELOC_NUMBER (R_RISCV_LGP17S2, 248)
  RELOC_NUMBER (R_RISCV_LGP17S3, 249)
  RELOC_NUMBER (R_RISCV_SGP18S0, 250)
  RELOC_NUMBER (R_RISCV_SGP17S1, 251)
  RELOC_NUMBER (R_RISCV_SGP17S2, 252)
  RELOC_NUMBER (R_RISCV_SGP17S3, 253)
  RELOC_NUMBER (R_RISCV_RELAX_REGION_BEGIN, 254)
  RELOC_NUMBER (R_RISCV_RELAX_REGION_END, 255)
END_RELOC_NUMBERS (R_RISCV_max)

/* Processor specific flags for the ELF header e_flags field.  */

/* File may contain compressed instructions.  */
#define EF_RISCV_RVC 0x0001

/* Which floating-point ABI a file uses.  */
#define EF_RISCV_FLOAT_ABI 0x0006

/* File uses the soft-float ABI.  */
#define EF_RISCV_FLOAT_ABI_SOFT 0x0000

/* File uses the single-float ABI.  */
#define EF_RISCV_FLOAT_ABI_SINGLE 0x0002

/* File uses the double-float ABI.  */
#define EF_RISCV_FLOAT_ABI_DOUBLE 0x0004

/* File uses the quad-float ABI.  */
#define EF_RISCV_FLOAT_ABI_QUAD 0x0006

/* File uses the 32E base integer instruction.  */
#define EF_RISCV_RVE 0x0008

/* The name of the global pointer symbol.  */
#define RISCV_GP_SYMBOL "__global_pointer$"

/* Additional section types.  */
#define SHT_RISCV_ATTRIBUTES   0x70000003  /* Section holds attributes.  */

/* Object attributes.  */

#define TAG_VALUE_BEGIN_V5     0x8000

enum
{
  /* 0-3 are generic.  */
  Tag_RISCV_stack_align = 4,
  Tag_RISCV_arch = 5,
  Tag_RISCV_unaligned_access = 6,
  Tag_RISCV_priv_spec = 8,
  Tag_RISCV_priv_spec_minor = 10,
  Tag_RISCV_priv_spec_revision = 12,
  /* Andes backward compatible */
  Tag_RISCV_strict_align = Tag_RISCV_unaligned_access,
  Tag_RISCV_ict_version = 0 + TAG_VALUE_BEGIN_V5,
  Tag_RISCV_ict_model = 1 + TAG_VALUE_BEGIN_V5,
};

/* Processor specific program header types */
#define PT_RISCV_ATTRIBUTES 0x70000000 /* .riscv.attributes section */

/* Additional section types.  */
#define SHT_RISCV_ATTRIBUTES   0x70000003  /* Section holds attributes.  */

/* Object attributes.  */

#define NUM_KNOWN_OBJ_ATTRIBUTES_V5     0x2
enum andes_old_attributes
{
  /* 0-3 are generic.  */
  Tag_arch = 4,
  Tag_priv_spec,
  Tag_priv_spec_minor,
  Tag_priv_spec_revision,
  Tag_strict_align,
  Tag_stack_align,
  Tag_shfit = 0x100,
  /* For NDS v5.  */
  Tag_ict_version = TAG_VALUE_BEGIN_V5,
  Tag_ict_model
};

#endif /* _ELF_RISCV_H */
