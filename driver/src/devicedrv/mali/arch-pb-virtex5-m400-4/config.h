/*
 * Copyright (C) 2010-2011 ARM Limited. All rights reserved.
 * 
 * This program is free software and is provided to you under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation, and any use by you of this program is subject to the terms of such GNU licence.
 * 
 * A copy of the licence is included with the program, and can also be obtained from Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __ARCH_CONFIG_H__
#define __ARCH_CONFIG_H__

/* Configuration for the EB platform with ZBT memory enabled */

static _mali_osk_resource_t arch_configuration [] =
{
	{
		.type = MALI400GP,
		.description = "Mali-400 GP",
		.base = 0xC0000000,
		.irq = -1,
		.mmu_id = 1
	},
	{
		.type = MALI400PP,
		.base = 0xc0008000,
		.irq = -1,
		.description = "Mali-400 PP 0",
		.mmu_id = 2
	},
	{
		.type = MALI400PP,
		.base = 0xc000A000,
		.irq = -1,
		.description = "Mali-400 PP 1",
		.mmu_id = 3
	},
	{
		.type = MALI400PP,
		.base = 0xc000C000,
		.irq = -1,
		.description = "Mali-400 PP 2",
		.mmu_id = 4
	},
	{
		.type = MALI400PP,
		.base = 0xc000E000,
		.irq = -1,
		.description = "Mali-400 PP 3",
		.mmu_id = 5
	},
#if USING_MMU
	{
		.type = MMU,
		.base = 0xC0003000,
		.irq = 102,
		.description = "Mali-400 MMU for GP",
		.mmu_id = 1
	},
	{
		.type = MMU,
		.base = 0xC0004000,
		.irq = 102,
		.description = "Mali-400 MMU for PP 0",
		.mmu_id = 2
	},
	{
		.type = MMU,
		.base = 0xC0005000,
		.irq = 102,
		.description = "Mali-400 MMU for PP 1",
		.mmu_id = 3
	},
	{
		.type = MMU,
		.base = 0xC0006000,
		.irq = 102,
		.description = "Mali-400 MMU for PP 2",
		.mmu_id = 4
	},
	{
		.type = MMU,
		.base = 0xC0007000,
		.irq = 102,
		.description = "Mali-400 MMU for PP 3",
		.mmu_id = 5
	},
#endif
#if ! ONLY_ZBT
	{
		.type = MEMORY,
		.description = "Mali SDRAM remapped to baseboard",
		.cpu_usage_adjust = -0x50000000,
		.alloc_order = 0, /* Highest preference for this memory */
#if MALI_USE_UNIFIED_MEMORY_PROVIDER != 0
		.base = 0xD2000000, /* Reserving 32MB for UMP devicedriver */
		.size = 0x08000000,
#else
		.base = 0xD0000000,
		.size = 0x10000000,
#endif /* MALI_USE_UNIFIED_MEMORY_PROVIDER != 0 */
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_READABLE | _MALI_PP_WRITEABLE |_MALI_GP_READABLE | _MALI_GP_WRITEABLE
	},
#endif
#if USING_ZBT
	{
		.type = MEMORY,
		.description = "Mali ZBT",
		.alloc_order = 5, /* Medium preference for this memory */
		.base = 0xe1000000,
		.size = 0x01000000,
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_READABLE | _MALI_PP_WRITEABLE |_MALI_GP_READABLE | _MALI_GP_WRITEABLE
	},
#endif
	{
		.type = MEM_VALIDATION,
		.description = "Framebuffer",
		.base = 0xe0000000,
		.size = 0x01000000,
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_WRITEABLE | _MALI_PP_READABLE
	},
	{
		.type = MALI400L2,
		.base = 0xC0001000,
		.description = "Mali-400 L2 cache"
	},
};

#endif /* __ARCH_CONFIG_H__ */
