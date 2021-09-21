/* Definitions of target machine for GNU compiler, for the pdp-11
   Copyright (C) 2000-2021 Free Software Foundation, Inc.
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

#ifndef __LIBRE8_PROTOS_H__
#define __LIBRE8_PROTOS_H__

extern void libre8_print_operand(FILE *, rtx, int);
extern void libre8_print_operand_address(FILE *, machine_mode, rtx);

extern enum reg_class libre8_regno_reg_class (int);
extern bool libre8_function_value_regno_p(const unsigned int);
extern rtx  libre8_function_value (const_tree, const_tree, bool);
extern bool libre8_function_value_regno_p(const unsigned int);
extern rtx  libre8_function_arg(CUMULATIVE_ARGS, machine_mode, const_tree, bool);
extern void libre8_function_arg_advance(CUMULATIVE_ARGS, machine_mode, const_tree, bool);


extern bool libre8_dummy_insn_cond(machine_mode);
extern enum reg_class libre8_regno_to_class(int);
extern int libre8_valid_regno_for_base_p(int);
extern int libre8_valid_regno_for_index_p(int);

extern HOST_WIDE_INT libre8_initial_elimination_offset(int, int);
extern void libre8_init_cumulative_args (CUMULATIVE_ARGS*, tree, rtx, tree, int);

extern bool libre8_lra_p(void);

extern int libre8_valid_regno_for_index_p(int);
extern int libre8_valid_regno_for_base_p(int);

extern bool libre8_legitimate_address_p(machine_mode, rtx, bool);
extern bool libre8_must_pass_in_stack(machine_mode,const_tree);

extern void libre8_init_libfuncs();
extern rtx libre8_libcall_value(machine_mode, const_rtx);

extern void libre8_globalize_label(FILE *, const char *);

#endif /* __LIBRE8_PROTOS_H__ */
