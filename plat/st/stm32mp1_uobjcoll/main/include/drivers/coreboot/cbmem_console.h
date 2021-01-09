/*
 * Copyright (c) 2017, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CBMEM_CONSOLE_H
#define CBMEM_CONSOLE_H

#include <uberspark/uobjcoll/platform/st/stm32mp1/main/include/drivers/console.h>

#define CONSOLE_T_CBMC_SIZE	CONSOLE_T_DRVDATA

#ifndef __ASSEMBLER__

typedef struct {
	console_t console;
	uint32_t size;
} console_cbmc_t;

int console_cbmc_register(uintptr_t base, console_cbmc_t *console);

#endif /* __ASSEMBLER__ */

#endif /* CBMEM_CONSOLE_H */
