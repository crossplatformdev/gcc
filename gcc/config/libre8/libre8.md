;;- Machine description for the libre8 for GNU C compiler
;; Copyright (C) 1994-2021 Free Software Foundation, Inc.
;; Contributed by Michael K. Gschwind (mike@vlsivie.tuwien.ac.at).

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.

;; GCC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

(define_insn "add"
	[
	(
	      set (match_operand:SI 0 "register_operand" "=r")
                  (
			plus:SI (match_operand:SI 1 "address_operand" "r")
		                (match_operand:SI 2 "address_operand" "r")
              
		  )
	)
	]
        "libre8_dummy_insn_cond(SImode)"
	"%0 = %1 + %2;"
)



	
(define_insn "nop"
	[(const_int 0)]
	""
	"nop"
)

