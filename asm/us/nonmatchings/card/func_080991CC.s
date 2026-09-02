.syntax unified
	.align 2, 0
	.global func_080991CC
	.thumb
	.thumb_func
	.type func_080991CC, %function
func_080991CC: @ 080991CC
	push {r4, r5, lr}
	add sp, #-0x010
	ldr r5, [sp, #0x01C]
	movs r4, #0x01
	strb r4, [r3, #0x00]
	str r1, [sp, #0x000]
	str r2, [sp, #0x004]
	str r3, [sp, #0x008]
	mov r2, sp
	ldrb r1, [r1, #0x00]
	strb r1, [r2, #0x0C]
	mov r1, sp
	strb r5, [r1, #0x0D]
	ldr r1, _080991F4 @ =0x09EE76F0
	bl TaskCreate
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
_080991F4: .4byte 0x09EE76F0
.syntax divided
