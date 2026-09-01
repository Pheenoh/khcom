.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
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
.syntax divided
