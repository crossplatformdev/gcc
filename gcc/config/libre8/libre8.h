/* Definitions of target machine for GNU compiler, for the pdp-11
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

#undef TARGET_ASM_GLOBALIZE_LABEL
#define TARGET_ASM_GLOBALIZE_LABEL libre8_globalize_label

#undef NUM_OPTAB_PATTERNS
#define NUM_OPTAB_PATTERNS  1

#define UNITS_PER_WORD 4
#define MAX_BITS_PER_WORD 32
#define BITS_BIG_ENDIAN 0
#define BYTES_BIG_ENDIAN 0
#define WORDS_BIG_ENDIAN 0
#define STRICT_ALIGNMENT 0
#define PARM_BOUNDARY 24
#define POINTER_BOUNDARY 24
#define FUNCTION_BOUNDARY 24
#define STRUCTURE_SIZE_BOUNDARY 8
#define BIGGEST_ALIGNMENT 32

#define FUNCTION_MODE SImode
#define Pmode SImode

/* how many ints are requird to hold X number of bytes */
#define LIBRE8_NUM_INTS(X) (((X) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)

/* how many registers are required to hold a value in the given mode */
#define LIBRE8_NUM_REGS(MODE) LIBRE8_NUM_INTS(GET_MODE_SIZE(MODE))

/* 1 if N is a possible register number for function argument passing.
   - not used on pdp */

#define FUNCTION_ARG_REGNO_P(N) 1


/**********************************************************************
 Target registers file

 r0 accumulator
 r0 function return value
 r1-r3 function jump value. return. call arguments.
 rsp stack pointer d
 eip instruction pointer

**********************************************************************/

enum  reg_class {
	NO_REGS,
	SP_REGS,
	FP_REGS,
	ASM_REGS,
	GP_REGS,
	ALL_REGS,
	LIM_REG_CLASSES
};

/* names of register classes */
#define REG_CLASS_NAMES \
{			\
	"NO_REGS",	\
	"SP_REGS",	\
	"FP_REGS",	\
	"ASM_REGS",	\
	"GP_REGS",	\
	"ALL_REGS"	\
}

/* register names */
#define REGISTER_NAMES \
{				\
	"r0", "r1", "r2", "r3", \
	"rsp",			\
	"eip",			\
	"ra",			\
	"pc"			\
}

/* register class content */
#define REG_CLASS_CONTENTS {{0x000000},{0xffffff}}

/* list of registers not available for allocation */
#define FIXED_REGISTERS { 0, 0, 0, 0, 1, 1, 1, 1 }

/* list of registers potentially clobbered by callee's */
#define CALL_USED_REGISTERS {1,1,1,1,1,1,1,1}

/* suggest a register allocation order */
#define REG_ALLOC_ORDER { 0, 1, 2, 3 }

#define N_REG_CLASSES 7
#define GENERAL_REGS reg_class::GP_REGS

#define REGNO_REG_CLASS(REGNO) libre8_regno_to_class(REGNO)
#define REGNO_OK_FOR_BASE_P(REGNO) libre8_valid_regno_for_base_p(REGNO)
#define REGNO_OK_FOR_INDEX_P(REGNO) libre8_valid_regno_for_index_p(REGNO)

#define BASE_REG_CLASS reg_class::GP_REGS
#define INDEX_REG_CLASS reg_class::GP_REGS

#define LAST_ARG_REGNUM 4
#define FIRST_ASM_REGNUM 8;
#define LAST_ASM_REGNUM 8;
#define FIRST_CALLEE_SAVED_REGNUM 1
#define LAST_CALLEE_SAVED_REGNUM 3
#define STACK_POINTER_REGNUM 4
#define FRAME_POINTER_REGNUM 5
#define RET_VALUE_REGNUM 0
#define RET_ADDRESS_REGNUM 5
#define FIRST_PSEUDO_REGISTER 4
#define MAX_REGS_PER_ADDRESS 3
#define ARG_POINTER_REGNUM FRAME_POINTER_REGNUM
#define NUM_ARG_REGISTERS LAST_ARG_REGNUM

#define ELIMINABLE_REGS {{ FRAME_POINTER_REGNUM }}
#define INITIAL_ELIMINATION_OFFSET(FROM,TO,OFFSET) \
	(OFFSET) = libre8_initial_elimination_offset((FROM), (TO))

/* memory, stack, function args */
#define MOVE_MAX 4
#define SLOW_BYTE_ACCESS 0
#define PUSH_ARGS 0
#define ACCUMULATE_OUTGOING_ARGS 1
#define STACK_BOUNDARY 24
#define STACK_GROWS_BACKWARD 0
#define FRAME_GROWS_DOWNWARD 0
#define STACK_POINTER_OFFSET -8
#define EXIT_IGNORE_STACK 1
#define MAX_ARGS_IN_REGISTERS 1

/* cumulative argument info */
typedef struct
{
	int num_reg_args;
	int num_args;
} libre8_cumulative_arg_info;

#define CUMULATIVE_ARGS libre8_cumulative_arg_info

/* init cumulative args */
#define INIT_CUMULATIVE_ARGS(CUM,FNTYPE,LIBNAME,FNDECL,N_NAMED_ARGS) \
  libre8_init_cumulative_args (&(CUM), FNTYPE, LIBNAME, FNDECL, N_NAMED_ARGS)
#define FIRST_PARM_OFFSET(FNDECL) 0


/*****************************************************************************
 Misc.
*****************************************************************************/

#define DEFAULT_SIGNED_CHAR 0

/* for nested functions only */
#define TRAMPOLINE_SIZE 64
#define TRAMPOLINE_ALIGNMENT 32

/* treat case labels as integers */
#define CASE_VECTOR_MODE SImode

/* no profiler support yet */
#define FUNCTION_PROFILER(FILE,LABELNO) do { } while(0);

/* target cpu built-ins */
#define TARGET_CPU_CPP_BUILTINS()  		\
do{						\
	builtin_assert("cpu=libre8");		\
	builtin_assert("machine=libre8");	\
	builtin_define("__libre8__");		\
	builtin_define("__LIBRE8__");		\
	builtin_define("__LIBRE8_SOFT_FLOAT__");\
} while (0);					\


/*Asembler */

/* how to output alignment directives */
#define ASM_OUTPUT_ALIGN(STREAM,LOG) \
do { 									\
	if(LOG!=0) fprintf(STREAM,"\t.align\t%d\n", 1 << (LOG)); 	\
}while (0);								\

/* how to output labels */
#define  ASM_OUTPUT_LABEL(FILE,NAME) 					\
do{									\
	assemble_name (FILE, NAME);					\
	fputs(":\n", FILE);						\
}while(0);								\

/* not entirely sure about the following directives since missing in my docs. Thus, guessing here */
#define ASM_APP_ON "#APP\n"
#define ASM_APP_OFF "#NO_APP\n"

#define TEXT_SECTION_ASM_OP "\t.code"
#define DATA_SECTION_ASM_OP "\t.data"

// #define READONLY_DATA_SECTION_ASM_OP "\t.rodata";
// #define BSS_SECTION_ASM_OP "\t.bss"

// #undef GLOBAL_ASM_OP
// #define GLONAL_ASM_OP "\t.global\t"

// #undef GLOBAL_ASM_OP
// #define GLOBAL_ASM_OP "\t.global"

// #undef GLOBAL_ASM_ALIGNED_SI_OP
// #define GLOBAL_ASMALIGNED_SO_OP "\t.word"

/*   */





