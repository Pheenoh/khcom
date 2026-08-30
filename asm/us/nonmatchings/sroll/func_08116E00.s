.syntax unified
	.align 2, 0
	.global func_08116E00
	.thumb
	.thumb_func
	.type func_08116E00, %function
func_08116E00: @ 08116E00
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r4, r1, #0x0
	adds r5, r2, #0x0
	bl func_08116CEC
	ldr r1, _08116E30 @ =0x02036028
	str r4, [r1, #0x10]
	str r4, [r1, #0x14]
	str r4, [r1, #0x18]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r5
	cmp r0, #0x00
	beq _08116E38
	ldr r0, _08116E34 @ =0x08116DD1
	str r0, [r1, #0x04]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r0, r5
	cmp r0, #0x00
	bne _08116E4A
	adds r0, r4, #0x4
	b _08116E48
_08116E30: .4byte 0x02036028
_08116E34: .4byte 0x08116DD1
_08116E38:
	ldr r0, _08116E58 @ =0x08116DE9
	str r0, [r1, #0x04]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r0, r5
	cmp r0, #0x00
	bne _08116E4A
	adds r0, r4, #0x2
_08116E48:
	str r0, [r1, #0x18]
_08116E4A:
	ldr r0, _08116E5C @ =0x02036028
	str r6, [r0, #0x08]
	str r5, [r0, #0x1C]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08116E58: .4byte 0x08116DE9
_08116E5C: .4byte 0x02036028
.syntax divided
