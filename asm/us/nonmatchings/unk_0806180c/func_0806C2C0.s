.syntax unified
	.align 2, 0
	.global func_0806C2C0
	.thumb
	.thumb_func
	.type func_0806C2C0, %function
func_0806C2C0: @ 0806C2C0
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r6, #0x00
	cmp r6, r7
	bcs _0806C340
_0806C2CE:
	ldr r0, _0806C310 @ =0x02034A88
	ldr r1, [r0, #0x00]
	lsls r0, r6, #0x01
	adds r0, r0, r6
	lsls r0, r0, #0x03
	adds r3, r0, r1
	ldrb r0, [r3, #0x15]
	cmp r0, #0x01
	bne _0806C336
	ldr r0, [r3, #0x00]
	ldr r1, [r3, #0x04]
	ldr r5, [r3, #0x08]
	cmp r5, #0x00
	beq _0806C336
	ldrb r4, [r3, #0x14]
	cmp r4, #0x00
	bne _0806C318
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _0806C314 @ =0x09EEB204
	ldr r2, [r2, #0x00]
	ldr r3, [r3, #0x0C]
	str r3, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	adds r3, r5, #0x0
	bl DrawSprite
	b _0806C336
	.byte 0x00, 0x00
_0806C310: .4byte 0x02034A88
_0806C314: .4byte 0x09EEB204
_0806C318:
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _0806C348 @ =0x09EEB204
	ldr r2, [r2, #0x00]
	ldr r3, [r3, #0x10]
	str r3, [sp, #0x000]
	movs r3, #0x00
	str r3, [sp, #0x004]
	str r3, [sp, #0x008]
	str r3, [sp, #0x00C]
	adds r3, r5, #0x0
	bl DrawSprite
_0806C336:
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, r7
	bcc _0806C2CE
_0806C340:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0806C348: .4byte 0x09EEB204
.syntax divided
