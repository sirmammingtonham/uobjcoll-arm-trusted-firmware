/*
 * Copyright (c) 2013-2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <uberspark/uobjcoll/platform/st/stm32mp1/main/include/arch/arch.h>
#include <uberspark/uobjcoll/platform/st/stm32mp1/main/include/arch/arch_helpers.h>
#include <uberspark/uobjcoll/platform/st/stm32mp1/main/bl2/bl2_private.h>

/*******************************************************************************
 * Place holder function to perform any S-EL1 specific architectural setup. At
 * the moment there is nothing to do.
 ******************************************************************************/
void bl2_arch_setup(void)
{
	/* Give access to FP/SIMD registers */
	write_cpacr(CPACR_EL1_FPEN(CPACR_EL1_FP_TRAP_NONE));
}
