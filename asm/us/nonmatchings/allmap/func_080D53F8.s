.syntax unified
	.align 2, 0
	.global func_080D53F8
	.thumb
	.thumb_func
	.type func_080D53F8, %function
func_080D53F8: @ 080D53F8
	push {r4, r5, r6, r7, lr}
	ldr r2, _080D548C @ =0x0203C4B4
	ldr r0, [r2, #0x00]
	adds r0, #0xBA
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D5490 @ =0x0203C53C
	movs r3, #0x00
	ldsh r1, [r1, r3]
	subs r0, r0, r1
	lsls r6, r0, #0x09
	movs r5, #0x00
	adds r7, r2, #0x0
_080D5416:
	ldr r0, [r7, #0x00]
	lsls r4, r5, #0x02
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D545A
	ldr r0, [r7, #0x00]
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x04]
	adds r2, r3, #0x0
	adds r2, #0x94
	adds r0, r3, #0x0
	adds r0, #0x8E
	movs r4, #0x00
	ldsh r1, [r0, r4]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D5490 @ =0x0203C53C
	movs r4, #0x00
	ldsh r1, [r1, r4]
	subs r0, r0, r1
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x90
	subs r0, r0, r6
	str r0, [r1, #0x00]
_080D545A:
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x1F
	bls _080D5416
	ldr r4, _080D548C @ =0x0203C4B4
	ldr r0, [r4, #0x00]
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D5484
	ldr r0, [r4, #0x00]
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x04]
	ldr r0, [r1, #0x2C]
	subs r0, r0, r6
	str r0, [r1, #0x28]
_080D5484:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D548C: .4byte 0x0203C4B4
_080D5490: .4byte 0x0203C53C
.syntax divided
