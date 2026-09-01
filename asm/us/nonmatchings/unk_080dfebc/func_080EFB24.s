.syntax unified
	.align 2, 0
	.global func_080EFB24
	.thumb
	.thumb_func
	.type func_080EFB24, %function
func_080EFB24: @ 080EFB24
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	lsls r1, r1, #0x18
	cmp r1, #0x00
	beq _080EFB54
	adds r2, r3, #0x0
	adds r2, #0xD4
	ldr r0, _080EFB4C @ =0x02039BA0
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x18]
	str r0, [r2, #0x00]
	adds r2, #0x04
	ldr r0, [r1, #0x1C]
	str r0, [r2, #0x00]
	adds r2, #0x04
	ldr r0, [r1, #0x20]
	ldr r1, _080EFB50 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r2, #0x00]
	b _080EFBFC
_080EFB4C: .4byte 0x02039BA0
_080EFB50: .4byte 0xFFFFF000
_080EFB54:
	adds r6, r3, #0x0
	adds r6, #0xD4
	ldr r0, _080EFBA0 @ =0x02039BA0
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x18]
	str r0, [r6, #0x00]
	adds r5, r3, #0x0
	adds r5, #0xD8
	ldr r0, [r1, #0x1C]
	str r0, [r5, #0x00]
	adds r4, r3, #0x0
	adds r4, #0xDC
	ldr r0, [r1, #0x20]
	str r0, [r4, #0x00]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080EFBA4
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x41
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	movs r1, #0x80
	lsls r1, r1, #0x06
	adds r0, r0, r1
	ldr r1, [r6, #0x00]
	subs r1, r1, r0
	b _080EFBC0
	.byte 0x00, 0x00
_080EFBA0: .4byte 0x02039BA0
_080EFBA4:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x41
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	movs r1, #0x80
	lsls r1, r1, #0x06
	adds r0, r0, r1
	ldr r1, [r6, #0x00]
	adds r1, r1, r0
_080EFBC0:
	str r1, [r6, #0x00]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x79
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _080EFC04 @ =0xFFFFC400
	adds r0, r0, r1
	ldr r1, [r5, #0x00]
	adds r1, r1, r0
	str r1, [r5, #0x00]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x31
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	movs r1, #0x80
	lsls r1, r1, #0x05
	adds r0, r0, r1
	ldr r1, [r4, #0x00]
	subs r1, r1, r0
	str r1, [r4, #0x00]
_080EFBFC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080EFC04: .4byte 0xFFFFC400
.syntax divided
