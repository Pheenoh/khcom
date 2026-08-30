.syntax unified
	.align 2, 0
	.global func_080F800C
	.thumb
	.thumb_func
	.type func_080F800C, %function
func_080F800C: @ 080F800C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	movs r0, #0xD4
	lsls r0, r0, #0x01
	muls r0, r7
	adds r0, #0x20
	adds r5, r6, r0
	ldr r0, [r6, #0x18]
	cmp r0, #0x00
	bne _080F802E
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	b _080F8038
_080F802E:
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
_080F8038:
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
	lsls r4, r7, #0x10
	asrs r4, r4, #0x10
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_080F7F70
	movs r2, #0xA0
	lsls r2, r2, #0x01
	adds r1, r5, r2
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_080F7F94
	movs r3, #0xA2
	lsls r3, r3, #0x01
	adds r1, r5, r3
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_080F7FAC
	movs r2, #0x92
	lsls r2, r2, #0x01
	adds r1, r5, r2
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_080F7FC8
	movs r3, #0x94
	lsls r3, r3, #0x01
	adds r1, r5, r3
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_080F7FE4
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r1, r5, r2
	str r0, [r1, #0x00]
	ldr r1, _080F80BC @ =0x09991F54
	lsls r0, r7, #0x03
	adds r0, r0, r7
	lsls r0, r0, #0x02
	adds r1, r0, r1
	ldrh r2, [r1, #0x10]
	ldr r0, [r6, #0x18]
	cmp r0, #0x00
	beq _080F80A4
	negs r2, r2
_080F80A4:
	movs r3, #0xAF
	lsls r3, r3, #0x01
	adds r0, r5, r3
	strh r2, [r0, #0x00]
	ldrh r1, [r1, #0x12]
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strh r1, [r0, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080F80BC: .4byte 0x09991F54
.syntax divided
