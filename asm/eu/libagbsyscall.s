.include "gba_constants.inc"

	.syntax unified
	.text
	.align 2, 0

	.global BgAffineSet
	.thumb
	.thumb_func
	.type BgAffineSet, %function
BgAffineSet:
	swi #14
	bx lr
	.size BgAffineSet, . - BgAffineSet

	.global CpuFastSet
	.thumb
	.thumb_func
	.type CpuFastSet, %function
CpuFastSet:
	swi #12
	bx lr
	.size CpuFastSet, . - CpuFastSet

	.global CpuSet
	.thumb
	.thumb_func
	.type CpuSet, %function
CpuSet:
	swi #11
	bx lr
	.size CpuSet, . - CpuSet

	swi #18
	bx lr
	.global LZ77UnCompWram
	.thumb
	.thumb_func
	.type LZ77UnCompWram, %function
LZ77UnCompWram:
	swi #17
	bx lr
	.size LZ77UnCompWram, . - LZ77UnCompWram

	.global RegisterRamReset
	.thumb
	.thumb_func
	.type RegisterRamReset, %function
RegisterRamReset:
	swi #1
	bx lr
	.size RegisterRamReset, . - RegisterRamReset

	.global SoftReset
	.thumb
	.thumb_func
	.type SoftReset, %function
SoftReset:
	ldr r3, sSoftResetRegIme
	movs r2, #0
	strb r2, [r3, #0]
	ldr r1, sSoftResetStack
	mov sp, r1
	swi #1
	swi #0
	.align 2, 0
sSoftResetRegIme:
	.word REG_BASE + OFFSET_REG_IME
sSoftResetStack:
	.word IWRAM_END - 0x100
	.size SoftReset, . - SoftReset

	.global Sqrt
	.thumb
	.thumb_func
	.type Sqrt, %function
Sqrt:
	swi #8
	bx lr
	.size Sqrt, . - Sqrt

	.global VBlankIntrWait
	.thumb
	.thumb_func
	.type VBlankIntrWait, %function
VBlankIntrWait:
	movs r2, #0
	swi #5
	bx lr
	.align 2, 0
	.size VBlankIntrWait, . - VBlankIntrWait
