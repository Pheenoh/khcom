.syntax unified
	.align 2, 0
	.global func_0800AB8C
	.thumb
	.thumb_func
	.type func_0800AB8C, %function
func_0800AB8C: @ 0800AB8C
	push {lr}
	add sp, #-0x00C
	ldr r0, _0800ABCC @ =0x09ECEB50
	ldr r0, [r0, #0x00]
	movs r2, #0x02
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	ldr r1, _0800ABD0 @ =0x08126630
	adds r1, r0, r1
	ldr r0, [r1, #0x08]
	cmp r0, #0xB9
	bne _0800ABC6
	movs r0, #0xA8
	lsls r0, r0, #0x09
	str r0, [sp, #0x000]
	movs r0, #0xB0
	lsls r0, r0, #0x09
	str r0, [sp, #0x004]
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r0, _0800ABD4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldr r1, [r1, #0x0C]
	mov r2, sp
	bl TaskCreate
_0800ABC6:
	add sp, #0x00C
	pop {r0}
	bx r0
_0800ABCC: .4byte 0x09ECEB50
_0800ABD0: .4byte 0x08126630
_0800ABD4: .4byte 0x02039B84
.syntax divided
