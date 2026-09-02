.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global RealClearChain
	.thumb
	.thumb_func
	.type RealClearChain, %function
RealClearChain:
	ldr r3, [r0, 0x2C]
	cmp r3, 0
	beq RealClearChain_4
	ldr r1, [r0, 0x34]
	ldr r2, [r0, 0x30]
	cmp r2, 0
	beq RealClearChain_1
	str r1, [r2, 0x34]
	b RealClearChain_2
RealClearChain_1:
	str r1, [r3, 0x20]
RealClearChain_2:
	cmp r1, 0
	beq RealClearChain_3
	str r2, [r1, 0x30]
RealClearChain_3:
	movs r1, 0
	str r1, [r0, 0x2C]
RealClearChain_4:
	bx lr
.syntax divided
