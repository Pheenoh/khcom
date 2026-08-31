.syntax unified
	.align 2, 0
	.global func_080E5FB4
	.thumb
	.thumb_func
	.type func_080E5FB4, %function
func_080E5FB4: @ 080E5FB4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x08
	adds r0, #0xC8
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsrs r0, r1, #0x1F
	adds r1, r1, r0
	asrs r1, r1, #0x01
	adds r0, r4, #0x0
	adds r0, #0xCA
	movs r3, #0x00
	ldsh r2, [r0, r3]
	lsrs r0, r2, #0x1F
	adds r2, r2, r0
	asrs r2, r2, #0x01
	adds r0, r5, #0x0
	bl func_080E02E0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080E602A
	ldr r0, _080E6014 @ =0x0203C7AC
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x00]
	movs r1, #0x80
	orrs r0, r1
	movs r1, #0x04
	orrs r0, r1
	str r0, [r2, #0x00]
	adds r0, r4, #0x0
	adds r0, #0xE4
	ldr r1, _080E6018 @ =0x09EF6EC4
	adds r2, r5, #0x0
	bl TaskCreate
	ldr r0, _080E601C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080E6020
	movs r0, #0xE4
	bl m4aSongNumStart
	b _080E6026
	.byte 0x00, 0x00
_080E6014: .4byte 0x0203C7AC
_080E6018: .4byte 0x09EF6EC4
_080E601C: .4byte 0x02039BB0
_080E6020:
	movs r0, #0x75
	bl m4aSongNumStart
_080E6026:
	movs r0, #0x01
	b _080E602C
_080E602A:
	movs r0, #0x00
_080E602C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
