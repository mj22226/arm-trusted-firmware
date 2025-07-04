/*
 * Copyright (c) 2019, Xilinx, Inc. All rights reserved.
 * Copyright (c) 2022-2025, Advanced Micro Devices, Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Versal PM nodes enums and defines */

#ifndef PM_NODE_H
#define PM_NODE_H

/*********************************************************************
 * Macro definitions
 ********************************************************************/

#define NODE_CLASS_SHIFT	26U
#define NODE_SUBCLASS_SHIFT	20U
#define NODE_TYPE_SHIFT		14U
#define NODE_INDEX_SHIFT	0U
#define NODE_CLASS_MASK_BITS    GENMASK_32(5, 0)
#define NODE_SUBCLASS_MASK_BITS GENMASK_32(5, 0)
#define NODE_TYPE_MASK_BITS     GENMASK_32(5, 0)
#define NODE_INDEX_MASK_BITS    GENMASK_32(13, 0)
#define NODE_CLASS_MASK         (NODE_CLASS_MASK_BITS << NODE_CLASS_SHIFT)

#define NODEID(CLASS, SUBCLASS, TYPE, INDEX)	\
	     ((((CLASS) & NODE_CLASS_MASK_BITS) << NODE_CLASS_SHIFT) | \
	     (((SUBCLASS) & NODE_SUBCLASS_MASK_BITS) << NODE_SUBCLASS_SHIFT) | \
	     (((TYPE) & NODE_TYPE_MASK_BITS) << NODE_TYPE_SHIFT) | \
	     (((INDEX) & NODE_INDEX_MASK_BITS) << NODE_INDEX_SHIFT))

#define NODECLASS(ID)           (((ID) & NODE_CLASS_MASK) >> NODE_CLASS_SHIFT)

/*********************************************************************
 * Enum definitions
 ********************************************************************/

/* Node class types */
enum pm_node_class {
	XPM_NODECLASS_MIN,

	XPM_NODECLASS_POWER,
	XPM_NODECLASS_CLOCK,
	XPM_NODECLASS_RESET,
	XPM_NODECLASS_MEMIC,
	XPM_NODECLASS_STMIC,
	XPM_NODECLASS_DEVICE,

	XPM_NODECLASS_MAX
};

enum pm_device_node_subclass {
	/* Device types */
	XPM_NODESUBCL_DEV_CORE = 1,
	XPM_NODESUBCL_DEV_PERIPH,
	XPM_NODESUBCL_DEV_MEM,
	XPM_NODESUBCL_DEV_SOC,
	XPM_NODESUBCL_DEV_MEM_CTRLR,
	XPM_NODESUBCL_DEV_PHY,
};

enum pm_device_node_type {
	/* Device types */
	XPM_NODETYPE_DEV_CORE_PMC = 1,
	XPM_NODETYPE_DEV_CORE_PSM,
	XPM_NODETYPE_DEV_CORE_APU,
	XPM_NODETYPE_DEV_CORE_RPU,
	XPM_NODETYPE_DEV_OCM,
	XPM_NODETYPE_DEV_TCM,
	XPM_NODETYPE_DEV_L2CACHE,
	XPM_NODETYPE_DEV_DDR,
	XPM_NODETYPE_DEV_PERIPH,
	XPM_NODETYPE_DEV_SOC,
	XPM_NODETYPE_DEV_GT,
};

/* Device node Indexes */
enum pm_device_node_idx {
	/* Device nodes */
	XPM_NODEIDX_DEV_MIN = 0x0,

	/* Processor devices */
	XPM_NODEIDX_DEV_PMC_PROC = 0x1,
	XPM_NODEIDX_DEV_PSM_PROC = 0x2,
	XPM_NODEIDX_DEV_ACPU_0 = 0x3,
	XPM_NODEIDX_DEV_ACPU_1 = 0x4,
	XPM_NODEIDX_DEV_RPU0_0 = 0x5,
	XPM_NODEIDX_DEV_RPU0_1 = 0x6,

	/* Memory devices */
	XPM_NODEIDX_DEV_OCM_0 = 0x7,
	XPM_NODEIDX_DEV_OCM_1 = 0x8,
	XPM_NODEIDX_DEV_OCM_2 = 0x9,
	XPM_NODEIDX_DEV_OCM_3 = 0xA,
	XPM_NODEIDX_DEV_TCM_0_A = 0xB,
	XPM_NODEIDX_DEV_TCM_0_B = 0xC,
	XPM_NODEIDX_DEV_TCM_1_A = 0xD,
	XPM_NODEIDX_DEV_TCM_1_B = 0xE,
	XPM_NODEIDX_DEV_L2_BANK_0 = 0xF,
	XPM_NODEIDX_DEV_DDR_0 = 0x10,
	XPM_NODEIDX_DEV_DDR_1 = 0x11,
	XPM_NODEIDX_DEV_DDR_2 = 0x12,
	XPM_NODEIDX_DEV_DDR_3 = 0x13,
	XPM_NODEIDX_DEV_DDR_4 = 0x14,
	XPM_NODEIDX_DEV_DDR_5 = 0x15,
	XPM_NODEIDX_DEV_DDR_6 = 0x16,
	XPM_NODEIDX_DEV_DDR_7 = 0x17,

	/* LPD Peripheral devices */
	XPM_NODEIDX_DEV_USB_0 = 0x18,
	XPM_NODEIDX_DEV_GEM_0 = 0x19,
	XPM_NODEIDX_DEV_GEM_1 = 0x1A,
	XPM_NODEIDX_DEV_SPI_0 = 0x1B,
	XPM_NODEIDX_DEV_SPI_1 = 0x1C,
	XPM_NODEIDX_DEV_I2C_0 = 0x1D,
	XPM_NODEIDX_DEV_I2C_1 = 0x1E,
	XPM_NODEIDX_DEV_CAN_FD_0 = 0x1F,
	XPM_NODEIDX_DEV_CAN_FD_1 = 0x20,
	XPM_NODEIDX_DEV_UART_0 = 0x21,
	XPM_NODEIDX_DEV_UART_1 = 0x22,
	XPM_NODEIDX_DEV_GPIO = 0x23,
	XPM_NODEIDX_DEV_TTC_0 = 0x24,
	XPM_NODEIDX_DEV_TTC_1 = 0x25,
	XPM_NODEIDX_DEV_TTC_2 = 0x26,
	XPM_NODEIDX_DEV_TTC_3 = 0x27,
	XPM_NODEIDX_DEV_SWDT_LPD = 0x28,
	XPM_NODEIDX_DEV_I2C_2 = 0x117,
	XPM_NODEIDX_DEV_I2C_3 = 0x118,
	XPM_NODEIDX_DEV_I2C_4 = 0x119,
	XPM_NODEIDX_DEV_I2C_5 = 0x11A,
	XPM_NODEIDX_DEV_I2C_6 = 0x11B,
	XPM_NODEIDX_DEV_I2C_7 = 0x11C,
	XPM_NODEIDX_DEV_CAN_FD_2 = 0x11D,
	XPM_NODEIDX_DEV_CAN_FD_3 = 0x11E,
	XPM_NODEIDX_DEV_TTC_4 = 0x11F,
	XPM_NODEIDX_DEV_TTC_5 = 0x120,
	XPM_NODEIDX_DEV_TTC_6 = 0x121,
	XPM_NODEIDX_DEV_TTC_7 = 0x122,

	/* FPD Peripheral devices */
	XPM_NODEIDX_DEV_SWDT_FPD = 0x29,

	/* PMC Peripheral devices */
	XPM_NODEIDX_DEV_OSPI = 0x2A,
	XPM_NODEIDX_DEV_QSPI = 0x2B,
	XPM_NODEIDX_DEV_GPIO_PMC = 0x2C,
	XPM_NODEIDX_DEV_I2C_PMC = 0x2D,
	XPM_NODEIDX_DEV_SDIO_0 = 0x2E,
	XPM_NODEIDX_DEV_SDIO_1 = 0x2F,

	XPM_NODEIDX_DEV_PL_0 = 0x30,
	XPM_NODEIDX_DEV_PL_1 = 0x31,
	XPM_NODEIDX_DEV_PL_2 = 0x32,
	XPM_NODEIDX_DEV_PL_3 = 0x33,
	XPM_NODEIDX_DEV_RTC = 0x34,
	XPM_NODEIDX_DEV_ADMA_0 = 0x35,
	XPM_NODEIDX_DEV_ADMA_1 = 0x36,
	XPM_NODEIDX_DEV_ADMA_2 = 0x37,
	XPM_NODEIDX_DEV_ADMA_3 = 0x38,
	XPM_NODEIDX_DEV_ADMA_4 = 0x39,
	XPM_NODEIDX_DEV_ADMA_5 = 0x3A,
	XPM_NODEIDX_DEV_ADMA_6 = 0x3B,
	XPM_NODEIDX_DEV_ADMA_7 = 0x3C,
	XPM_NODEIDX_DEV_IPI_0 = 0x3D,
	XPM_NODEIDX_DEV_IPI_1 = 0x3E,
	XPM_NODEIDX_DEV_IPI_2 = 0x3F,
	XPM_NODEIDX_DEV_IPI_3 = 0x40,
	XPM_NODEIDX_DEV_IPI_4 = 0x41,
	XPM_NODEIDX_DEV_IPI_5 = 0x42,
	XPM_NODEIDX_DEV_IPI_6 = 0x43,

	/* Entire SoC */
	XPM_NODEIDX_DEV_SOC = 0x44,

	/* DDR memory controllers */
	XPM_NODEIDX_DEV_DDRMC_0 = 0x45,
	XPM_NODEIDX_DEV_DDRMC_1 = 0x46,
	XPM_NODEIDX_DEV_DDRMC_2 = 0x47,
	XPM_NODEIDX_DEV_DDRMC_3 = 0x48,

	/* GT devices */
	XPM_NODEIDX_DEV_GT_0 = 0x49,
	XPM_NODEIDX_DEV_GT_1 = 0x4A,
	XPM_NODEIDX_DEV_GT_2 = 0x4B,
	XPM_NODEIDX_DEV_GT_3 = 0x4C,
	XPM_NODEIDX_DEV_GT_4 = 0x4D,
	XPM_NODEIDX_DEV_GT_5 = 0x4E,
	XPM_NODEIDX_DEV_GT_6 = 0x4F,
	XPM_NODEIDX_DEV_GT_7 = 0x50,
	XPM_NODEIDX_DEV_GT_8 = 0x51,
	XPM_NODEIDX_DEV_GT_9 = 0x52,
	XPM_NODEIDX_DEV_GT_10 = 0x53,

#if defined(PLAT_versal_net)
	XPM_NODEIDX_DEV_ACPU_0_0 = 0xAF,
	XPM_NODEIDX_DEV_ACPU_0_1 = 0xB0,
	XPM_NODEIDX_DEV_ACPU_0_2 = 0xB1,
	XPM_NODEIDX_DEV_ACPU_0_3 = 0xB2,
	XPM_NODEIDX_DEV_ACPU_1_0 = 0xB3,
	XPM_NODEIDX_DEV_ACPU_1_1 = 0xB4,
	XPM_NODEIDX_DEV_ACPU_1_2 = 0xB5,
	XPM_NODEIDX_DEV_ACPU_1_3 = 0xB6,
	XPM_NODEIDX_DEV_ACPU_2_0 = 0xB7,
	XPM_NODEIDX_DEV_ACPU_2_1 = 0xB8,
	XPM_NODEIDX_DEV_ACPU_2_2 = 0xB9,
	XPM_NODEIDX_DEV_ACPU_2_3 = 0xBA,
	XPM_NODEIDX_DEV_ACPU_3_0 = 0xBB,
	XPM_NODEIDX_DEV_ACPU_3_1 = 0xBC,
	XPM_NODEIDX_DEV_ACPU_3_2 = 0xBD,
	XPM_NODEIDX_DEV_ACPU_3_3 = 0xBE,
	XPM_NODEIDX_DEV_RPU_A_0 = 0xBF,
	XPM_NODEIDX_DEV_RPU_A_1 = 0xC0,
	XPM_NODEIDX_DEV_RPU_B_0 = 0xC1,
	XPM_NODEIDX_DEV_RPU_B_1 = 0xC2,
	XPM_NODEIDX_DEV_OCM_0_0 = 0xC3,
	XPM_NODEIDX_DEV_OCM_0_1 = 0xC4,
	XPM_NODEIDX_DEV_OCM_0_2 = 0xC5,
	XPM_NODEIDX_DEV_OCM_0_3 = 0xC6,
	XPM_NODEIDX_DEV_OCM_1_0 = 0xC7,
	XPM_NODEIDX_DEV_OCM_1_1 = 0xC8,
	XPM_NODEIDX_DEV_OCM_1_2 = 0xC9,
	XPM_NODEIDX_DEV_OCM_1_3 = 0xCA,
	XPM_NODEIDX_DEV_TCM_A_0A = 0xCB,
	XPM_NODEIDX_DEV_TCM_A_0B = 0xCC,
	XPM_NODEIDX_DEV_TCM_A_0C = 0xCD,
	XPM_NODEIDX_DEV_TCM_A_1A = 0xCE,
	XPM_NODEIDX_DEV_TCM_A_1B = 0xCF,
	XPM_NODEIDX_DEV_TCM_A_1C = 0xD0,
	XPM_NODEIDX_DEV_TCM_B_0A = 0xD1,
	XPM_NODEIDX_DEV_TCM_B_0B = 0xD2,
	XPM_NODEIDX_DEV_TCM_B_0C = 0xD3,
	XPM_NODEIDX_DEV_TCM_B_1A = 0xD4,
	XPM_NODEIDX_DEV_TCM_B_1B = 0xD5,
	XPM_NODEIDX_DEV_TCM_B_1C = 0xD6,
	XPM_NODEIDX_DEV_USB_1 = 0xD7,
	XPM_NODEIDX_DEV_PMC_WWDT = 0xD8,
	XPM_NODEIDX_DEV_LPD_SWDT_0 = 0xD9,
	XPM_NODEIDX_DEV_LPD_SWDT_1 = 0xDA,
	XPM_NODEIDX_DEV_FPD_SWDT_0 = 0xDB,
	XPM_NODEIDX_DEV_FPD_SWDT_1 = 0xDC,
	XPM_NODEIDX_DEV_FPD_SWDT_2 = 0xDD,
	XPM_NODEIDX_DEV_FPD_SWDT_3 = 0xDE,
#endif

#if defined(PLAT_versal2)
	XPM_NODEIDX_DEV_USB_1 = 0xD7,
#endif

	XPM_NODEIDX_DEV_MAX,
};

#endif /* PM_NODE_H */
