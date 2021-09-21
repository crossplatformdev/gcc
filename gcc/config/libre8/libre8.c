/* Subroutines for gcc2 for pdp11.
   Copyright (C) 1994-2021 Free Software Foundation, Inc.
   Contributed by Michael K. Gschwind (mike@vlsivie.tuwien.ac.at).

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "target.h"
#include "rtl.h"
#include "tree.h"
#include "stringpool.h"
#include "attribs.h"
#include "df.h"
#include "memmodel.h"
#include "tm_p.h"
#include "insn-config.h"
#include "insn-attr.h"
#include "regs.h"
#include "emit-rtl.h"
#include "recog.h"
#include "conditions.h"
#include "output.h"
#include "stor-layout.h"
#include "varasm.h"
#include "calls.h"
#include "expr.h"
#include "builtins.h"
#include "dbxout.h"
#include "explow.h"
#include "expmed.h"

/* This file should be included last.  */
#include "target-def.h"


//static bool libre8_lra_p(void);
//static rtx  libre8_libcall_value(machine_mode, const_rtx);

//static bool libre8_legitimate_address_p(machine_mode, rtx, bool);
//static bool libre8_must_pass_in_stack(machine_mode, const_tree);

//static void libre8_init_libfuncs();
//static void libre8_globalize_label(FILE *, const char *);

//static void libre8_print_operand(FILE *, rtx, int);
//static void libre8_print_operand_address(FILE *, machine_mode, rtx);

//int libre8_valid_regno_for_index_p(int regno);
//int libre8_valid_regno_for_base_p(int regno);


//static rtx  libre8_function_value (const_tree, const_tree, bool);
//static bool libre8_function_value_regno_p(const unsigned int);
//static rtx  libre8_function_arg(cumulative_args_t, machine_mode, const_tree, bool);
//static void libre8_function_arg_advance(cumulative_args_t, machine_mode, const_tree, bool);

//void libre8_init_cumulative_args(CUMULATIVE_ARGS, tree, rtx, tree, int);

rtx libre8_function_value(const_tree ret_type, const_tree fn_type, bool)
{
	return NULL_RTX;
}

bool libre8_function_value_regno_p(const unsigned int regno)
{
	return (RET_VALUE_REGNUM == regno);
}

bool libre8_function_arg_regno_p(const unsigned int regno)
{
	return (RET_VALUE_REGNUM == regno);
}

rtx libre8_function_arg(cumulative_args_t ca, machine_mode mode, const_tree type, bool named)
{
	return NULL_RTX;
}

void libre8_function_arg_advance(cumulative_args_t ca, machine_mode mode, const_tree, bool named)
{
	return;
}

void libre8_print_operand(FILE *file, rtx op, int letter)
{
	return;
}

void libre8_print_operand_address(FILE *file, machine_mode mode, rtx addr)
{
	return;
}

void libre8_init_cumulative_args (CUMULATIVE_ARGS *cum, tree fntype, rtx libname,
                          tree fndecl ATTRIBUTE_UNUSED, int num_names)
{
  return;
}


int libre8_function_arg_regno_p(int r)
{
	return 0;
}

struct GTY(()) 
{
	int reg_val;
	int reg_num;
} machine_function;

struct gcc_target targetm = TARGET_INITIALIZER;

bool libre8_lra_p(void)
{
	return false;
}

rtx libre8_libcall_value(machine_mode mode, const_rtx fun)
{
	return NULL_RTX;
}


bool libre8_legitimate_address_p(machine_mode mode, rtx x, bool strict)
{
	return true;
}

rtx libre8_legitimate_address (rtx x, rtx old_x,
                                   machine_mode mode, addr_space_t as)
{
	return NULL_RTX;
}


void libre8_init_libfuncs(void)
{
	return;
}

bool libre8_must_pass_in_stack(machine_mode mode, const_tree type)
{
	return false;
}

int libre8_valid_regno_for_base_p(int regno)
{
	return 1;
}

int libre8_valid_regno_for_index_p(int regno)
{
	return libre8_valid_regno_for_base_p(regno);
}

enum reg_class libre8_regno_to_class(int regno)
{
	return reg_class::GP_REGS;
}

HOST_WIDE_INT libre8_initial_elimination_offset(int from, int to)
{
	return 0;
}

bool libre8_dummy_insn_cond(machine_mode mode)
{
	return true;
}

void libre8_globalize_label (FILE *stream, const char *name)
{
  fputs (".global ", stream);
  assemble_name (stream, name);
  fputc (';',stream);
  fputc ('\n',stream);
}



#undef  TARGET_FUNCTION_VALUE
#define TARGET_FUNCTION_VALUE libre8_function_value

#undef TARGET_FUNCTION_VALUE_REGNO_P
#define TARGET_FUNCTION_VALUE_REGNO_P libre8_function_value_regno_p

#undef TARGET_FUNCTION_ARG_REGNO_P
#define TARGET_FUNCTION_ARG_REGNO_P libre8_function_arg_regno_p

#undef TARGET_FUNCTION_ARG
#define TARGET_FUNCTION_ARG libre8_function_arg

#undef TARGET_FUNCTION_ARG_ADVANCE
#define TARGET_FUNCTION_ARG_ADVANCE libre8_function_arg_advance

#undef TARGET_PRINT_OPERAND
#define TARGET_PRINT_OPERAND libre8_print_operand

#undef TARGET_PRINT_OPERAND_ADDRESS
#define TARGET_PRINT_OPERAND_ADDRESS libre8_print_operand_address


#undef TARGET_INIT_CUMULATIVE_ARGS
#define TARGET_INIT_CUMULATIVE_ARGS libre8_init_cumulative_args


#undef TARGET_LRA_P
#define TARGET_LRA_P libre8_lra_p

#undef TARGET_LEGITIMATE_ADDRESS
#define TARGET_LEGITIMATE_ADDRESS libre8_legitimate_address

#undef TARGET_LEGITIMATE_ADDRESS_P
#define TARGET_LEGITIMATE_ADDRESS_P libre8_legitimate_address_p

#undef TARGET_INIT_LIBFUNCS
#define TARGET_INIT_LIBFUNCS libre8_init_libfuncs

#undef TARGET_LIBCALL_VALUE
#define TARGET_LIBCALL_VALUE libre8_libcall_value

#undef TARGET_MUST_PASS_IN_STACK
#define TARGET_MUST_PASS_IN_STACK libre8_must_pass_in_stack



// #include "gt-libre8.h"

