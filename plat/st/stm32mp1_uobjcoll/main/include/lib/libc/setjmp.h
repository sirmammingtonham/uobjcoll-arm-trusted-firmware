/*
 * Copyright (c) 2018-2019, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SETJMP_H
#define SETJMP_H

#include <uberspark/uobjcoll/platform/st/stm32mp1/main/include/setjmp_.h>

#ifndef __ASSEMBLER__

#include <uberspark/uobjcoll/platform/st/stm32mp1/main/include/cdefs.h>

int setjmp(jmp_buf env);
__dead2 void longjmp(jmp_buf env, int val);

#endif /* __ASSEMBLER__ */
#endif /* SETJMP_H */
