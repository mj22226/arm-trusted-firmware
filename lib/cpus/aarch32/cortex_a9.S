/*
 * Copyright (c) 2016-2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch.h>
#include <asm_macros.S>
#include <assert_macros.S>
#include <cortex_a9.h>
#include <cpu_macros.S>

	.macro assert_cache_enabled
#if ENABLE_ASSERTIONS
		ldcopr	r0, SCTLR
		tst	r0, #SCTLR_C_BIT
		ASM_ASSERT(eq)
#endif
	.endm

func cortex_a9_disable_smp
	ldcopr	r0, ACTLR
	bic	r0, #CORTEX_A9_ACTLR_SMP_BIT
	stcopr	r0, ACTLR
	isb
	dsb	sy
	bx	lr
endfunc cortex_a9_disable_smp

func cortex_a9_enable_smp
	ldcopr	r0, ACTLR
	orr	r0, #CORTEX_A9_ACTLR_SMP_BIT
	stcopr	r0, ACTLR
	isb
	bx	lr
endfunc cortex_a9_enable_smp

func check_errata_794073
#if ERRATA_A9_794073
	mov	r0, #ERRATA_APPLIES
#else
	mov	r0, #ERRATA_MISSING
#endif
	bx	lr
endfunc check_errata_794073

add_erratum_entry cortex_a9, ERRATUM(794073), ERRATA_A9_794073

func check_errata_cve_2017_5715
#if WORKAROUND_CVE_2017_5715
	mov	r0, #ERRATA_APPLIES
#else
	mov	r0, #ERRATA_MISSING
#endif
	bx	lr
endfunc check_errata_cve_2017_5715

add_erratum_entry cortex_a9, CVE(2017, 5715), WORKAROUND_CVE_2017_5715

func cortex_a9_reset_func
#if IMAGE_BL32 && WORKAROUND_CVE_2017_5715
	ldr	r0, =wa_cve_2017_5715_bpiall_vbar
	stcopr	r0, VBAR
	stcopr	r0, MVBAR
	/* isb will be applied in the course of the reset func */
#endif
	b	cortex_a9_enable_smp
endfunc cortex_a9_reset_func

func cortex_a9_core_pwr_dwn
	push	{r12, lr}

	assert_cache_enabled

	/* Flush L1 cache */
	mov	r0, #DC_OP_CISW
	bl	dcsw_op_level1

	/* Exit cluster coherency */
	pop	{r12, lr}
	b	cortex_a9_disable_smp
endfunc cortex_a9_core_pwr_dwn

func cortex_a9_cluster_pwr_dwn
	push	{r12, lr}

	assert_cache_enabled

	/* Flush L1 caches */
	mov	r0, #DC_OP_CISW
	bl	dcsw_op_level1

	bl	plat_disable_acp

	/* Exit cluster coherency */
	pop	{r12, lr}
	b	cortex_a9_disable_smp
endfunc cortex_a9_cluster_pwr_dwn

declare_cpu_ops cortex_a9, CORTEX_A9_MIDR, \
	cortex_a9_reset_func, \
	cortex_a9_core_pwr_dwn, \
	cortex_a9_cluster_pwr_dwn
