.syntax unified
	.align 2, 0
	.global func_0804FA70
	.thumb
	.thumb_func
	.type func_0804FA70, %function
func_0804FA70: @ 0804FA70
	push {r4, r5, lr}
	mov r12, r0
	adds r3, r1, #0x0
	mov r1, r12
	adds r1, #0x40
	ldr r0, [r1, #0x04]
	str r0, [r3, #0x00]
	ldr r0, [r1, #0x08]
	str r0, [r3, #0x04]
	ldr r0, [r1, #0x0C]
	str r0, [r3, #0x08]
	ldr r0, [r1, #0x34]
	ldr r1, [r1, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0804FA9E
	ldrh r1, [r3, #0x0C]
	movs r0, #0x01
	orrs r0, r1
	b _0804FAA4
_0804FA9E:
	ldrh r1, [r3, #0x0C]
	ldr r0, _0804FACC @ =0x0000FFFE
	ands r0, r1
_0804FAA4:
	strh r0, [r3, #0x0C]
	adds r1, r3, #0x0
	adds r1, #0x10
	mov r0, r12
	adds r0, #0x14
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	mov r1, r12
	ldr r0, [r1, #0x04]
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x28]
	ldr r0, _0804FAD0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x24]
	str r0, [r3, #0x2C]
	pop {r4, r5}
	pop {r0}
	bx r0
_0804FACC: .4byte 0x0000FFFE
_0804FAD0: .4byte 0x02039B84
.syntax divided
