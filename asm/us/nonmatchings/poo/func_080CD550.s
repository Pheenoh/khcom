.syntax unified
	.align 2, 0
	.global func_080CD550
	.thumb
	.thumb_func
	.type func_080CD550, %function
func_080CD550: @ 080CD550
	push {r4, r5, r6, r7, lr}
	add sp, #-0x02C
	mov r12, r2
	lsls r1, r1, #0x10
	mov r4, sp
	ldr r2, _080CD584 @ =0x096FD43C
	ldm r2!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	ldm r2!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	add r2, sp, #0x018
	mov r4, r12
	str r4, [sp, #0x018]
	str r3, [r2, #0x04]
	lsrs r1, r1, #0x0E
	add r1, sp
	ldr r1, [r1, #0x00]
	str r1, [r2, #0x10]
	ldr r1, _080CD588 @ =0x09EF4A00
	bl TaskCreate
	add sp, #0x02C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CD584: .4byte 0x096FD43C
_080CD588: .4byte 0x09EF4A00
.syntax divided
