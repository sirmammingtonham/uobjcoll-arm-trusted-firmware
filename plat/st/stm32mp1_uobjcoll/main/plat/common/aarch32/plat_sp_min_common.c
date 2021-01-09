/*
 * Copyright (c) 2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <uberspark/uobjcoll/platform/st/stm32mp1/main/include/drivers/console.h>
#include <uberspark/uobjcoll/platform/st/stm32mp1/main/include/plat/common/platform.h>
#include <uberspark/uobjcoll/platform/st/stm32mp1/main/include/platform_sp_min.h>

/*
 * The following platform setup functions are weakly defined. They
 * provide typical implementations that may be re-used by multiple
 * platforms but may also be overridden by a platform if required.
 */
#pragma weak sp_min_plat_runtime_setup

void sp_min_plat_runtime_setup(void)
{
	/*
	 * Finish the use of console driver in SP_MIN so that any runtime logs
	 * from SP_MIN will be suppressed.
	 */
	console_switch_state(CONSOLE_FLAG_RUNTIME);
}
