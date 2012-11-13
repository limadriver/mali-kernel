/*
 * Copyright (C) 2010 ARM Limited. All rights reserved.
 * 
 * This program is free software and is provided to you under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation, and any use by you of this program is subject to the terms of such GNU licence.
 * 
 * A copy of the licence is included with the program, and can also be obtained from Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __ARCH_CONFIG_H__
#define __ARCH_CONFIG_H__

/* Note: IRQ auto detection (setting irq to -1) only works if the IRQ is not shared with any other hardware resource */

static _mali_osk_resource_t arch_configuration [] =
{
	{
		.type = MALIGP2,
		.description = "MALI GP2",
		.base = 0xc0002000,
		.irq = -1,
		.mmu_id = 1
	},
#if USING_MMU
	{
		.type = MMU,
		.base = 0xc0003000,
		.irq = -1, /*105*/
		.description = "Mali MMU",
		.mmu_id = 1
	},
#endif /* USING_MMU */
	{
		.type = FPGA_FRAMEWORK,
		.base = 0xC000A000,
		.description = "FPGA Framework"
	},
	{
		.type = MALI200,
		.base = 0xc0000000,
		.irq = -1/*106*/,
		.description = "Mali 200 (GX525)",
		.mmu_id = 1
	},

#if ! ONLY_ZBT
#if USING_OS_MEMORY
	{
		.type = OS_MEMORY,
		.description = "OS Memory",
		.cpu_usage_adjust = -0x50000000,
		.alloc_order = 10, /* Lowest preference for this memory */
		.base = 0x78000000, /* aim to use map=120M@1920M */
		.size = 0x04000000, /* 64MB, to avoid OOM-killer */
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_READABLE | _MALI_PP_WRITEABLE |_MALI_GP_READABLE | _MALI_GP_WRITEABLE
	},
	{
		.type = MEMORY,
		.description = "Mali SDRAM remapped to baseboard",
		.cpu_usage_adjust = -0x50000000,
		.alloc_order = 0, /* Highest preference for this memory */
#if MALI_USE_UNIFIED_MEMORY_PROVIDER != 0
		.base = 0xD2000000, /* Reserving 32MB for UMP devicedriver */
		.size = 0x0E000000, /* 224 MB */
#else
		.base = 0xD0000000,
		.size = 0x10000000, /* 256 MB */
#endif /* MALI_USE_UNIFIED_MEMORY_PROVIDER != 0 */
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_READABLE | _MALI_PP_WRITEABLE |_MALI_GP_READABLE | _MALI_GP_WRITEABLE
	},

#else /* USING_OS_MEMORY */
	{
		.type = MEMORY,
		.description = "Mali SDRAM remapped to baseboard",
		.cpu_usage_adjust = -0x50000000,
		.alloc_order = 0, /* Highest preference for this memory */
#if MALI_USE_UNIFIED_MEMORY_PROVIDER != 0
		.base = 0xCA000000, /* Reserving 32MB for UMP devicedriver */
		.size = 0x16000000,
#else
		.base = 0xC8000000,
		.size = 0x18000000,
#endif /* MALI_USE_UNIFIED_MEMORY_PROVIDER != 0 */
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_READABLE | _MALI_PP_WRITEABLE |_MALI_GP_READABLE | _MALI_GP_WRITEABLE
	},
#endif /** USING_OS_MEMORY */
#endif /* ! ONLY_ZBT */

#if USING_ZBT
	{
		.type = MEMORY,
		.description = "Mali ZBT",
		.alloc_order = 5, /* Medium preference for this memory */
		.base = 0xe0600000,
		.size = 0x01a00000,
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_READABLE | _MALI_PP_WRITEABLE |_MALI_GP_READABLE | _MALI_GP_WRITEABLE
	},
#endif /* USING_ZBT */
	{
		.type = MEM_VALIDATION,
		.description = "Framebuffer",
		.base = 0xe0000000,
		.size = 0x00600000,
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_WRITEABLE | _MALI_PP_READABLE
	},

};

#endif /* __ARCH_CONFIG_H__ */
