.syntax unified
	.align 2, 0
	.global func_0800EEBC
	.thumb
	.thumb_func
	.type func_0800EEBC, %function
func_0800EEBC: @ 0800EEBC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r2, r0, #0x0
	adds r5, r1, #0x0
	cmp r5, #0x00
	bne _0800EECE
	b _0800EFD8
_0800EECE:
	ldrh r1, [r5, #0x34]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _0800EEDA
	b _0800EFD8
_0800EEDA:
	adds r4, r2, #0x0
	adds r4, #0x40
	ldr r0, [r5, #0x2C]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800EF08
	ldr r0, _0800EF04 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	adds r1, r2, #0x0
	b _0800EF26
	.byte 0x00, 0x00
_0800EF04: .4byte 0x02039B84
_0800EF08:
	ldr r0, _0800EF20 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _0800EF24
	adds r1, r2, #0x0
	movs r0, #0x01
	orrs r7, r0
	b _0800EF26
	.byte 0x00, 0x00
_0800EF20: .4byte 0x02039B84
_0800EF24:
	negs r1, r2
_0800EF26:
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _0800EF36
	cmp r1, r2
	bne _0800EF36
	movs r0, #0x00
	b _0800EF48
_0800EF36:
	cmp r2, #0xFF
	bgt _0800EF40
	movs r0, #0x00
	movs r3, #0x00
	b _0800EF44
_0800EF40:
	movs r0, #0x00
	movs r3, #0x01
_0800EF44:
	bl AllocObjAffine
_0800EF48:
	mov r8, r0
	ldrh r1, [r5, #0x34]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _0800EF70
	ldr r2, [r5, #0x2C]
	asrs r1, r2, #0x08
	lsls r1, r1, #0x02
	ldr r3, _0800EF6C @ =0xFFFFEFFC
	adds r0, r3, #0x0
	subs r0, r0, r1
	movs r1, #0x03
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r3, r2, #0x0
	b _0800EFA8
_0800EF6C: .4byte 0xFFFFEFFC
_0800EF70:
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0800EF90
	ldr r0, [r4, #0x08]
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r4, _0800EF8C @ =0xFFFFEFFC
	adds r1, r4, #0x0
	subs r1, r1, r0
	movs r0, #0x03
	orrs r1, r0
	subs r1, #0x01
	b _0800EFA2
_0800EF8C: .4byte 0xFFFFEFFC
_0800EF90:
	ldr r0, [r4, #0x08]
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r2, _0800EFE4 @ =0xFFFFEFFC
	adds r1, r2, #0x0
	subs r1, r1, r0
	movs r0, #0x03
	orrs r1, r0
	adds r1, #0x01
_0800EFA2:
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r3, [r5, #0x2C]
_0800EFA8:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x28]
	ldr r0, [r5, #0x30]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r3, #0x00
	ldsh r0, [r0, r3]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r5, #0x38]
	ldr r3, [r5, #0x04]
	ldr r4, [r5, #0x0C]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	str r7, [sp, #0x008]
	str r6, [sp, #0x00C]
	bl DrawSprite
_0800EFD8:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800EFE4: .4byte 0xFFFFEFFC
.syntax divided
