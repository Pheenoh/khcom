.syntax unified
	.align 2, 0
	.global func_08093838
	.thumb
	.thumb_func
	.type func_08093838, %function
func_08093838: @ 08093838
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r0, #0x14
	bl ListPoolFirst
	adds r4, r0, #0x0
	movs r6, #0x80
	lsls r6, r6, #0x01
	movs r1, #0x00
	movs r2, #0xF6
	lsls r2, r2, #0x01
	adds r0, r5, r2
	str r1, [r0, #0x00]
	cmp r4, #0x00
	beq _08093894
_08093856:
	ldr r1, [r4, #0x4C]
	ldr r0, _080938A4 @ =0xFFFF9C00
	cmp r1, r0
	beq _08093886
	asrs r1, r1, #0x08
	movs r2, #0x96
	lsls r2, r2, #0x02
	adds r0, r5, r2
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	subs r1, r1, r0
	adds r0, r1, #0x0
	muls r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r6, r0
	ble _08093886
	adds r6, r0, #0x0
	movs r1, #0xF6
	lsls r1, r1, #0x01
	adds r0, r5, r1
	str r4, [r0, #0x00]
_08093886:
	adds r0, r4, #0x0
	adds r0, #0x38
	bl ListPoolNext
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _08093856
_08093894:
	movs r2, #0xF6
	lsls r2, r2, #0x01
	adds r3, r5, r2
	ldr r2, [r3, #0x00]
	cmp r2, #0x00
	bne _080938A8
	movs r0, #0x00
	b _080938C6
_080938A4: .4byte 0xFFFF9C00
_080938A8:
	adds r2, #0x6C
	ldrh r1, [r2, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x01
	adds r0, r4, #0x0
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r0, [r3, #0x00]
	movs r2, #0x96
	lsls r2, r2, #0x02
	adds r1, r5, r2
	ldr r0, [r0, #0x4C]
	ldr r1, [r1, #0x00]
	subs r0, r0, r1
	asrs r0, r0, #0x08
_080938C6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
