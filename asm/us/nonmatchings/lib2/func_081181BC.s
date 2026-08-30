.syntax unified
	.align 2, 0
	.global func_081181BC
	.thumb
	.thumb_func
	.type func_081181BC, %function
func_081181BC: @ 081181BC
	push {r7, lr}
	add sp, #-0x010
	mov r7, sp
	str r0, [r7, #0x00]
	str r1, [r7, #0x04]
	str r2, [r7, #0x08]
	str r3, [r7, #0x0C]
	ldr r1, [r7, #0x04]
	ldr r2, [r7, #0x08]
	ldr r3, [r7, #0x0C]
	ldr r0, [r7, #0x00]
	bl func_08118578
	ldr r1, [r7, #0x04]
	ldr r2, [r7, #0x08]
	ldr r3, [r7, #0x0C]
	ldr r0, [r7, #0x00]
	bl func_0811D4B4
	add sp, #0x010
	pop {r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
