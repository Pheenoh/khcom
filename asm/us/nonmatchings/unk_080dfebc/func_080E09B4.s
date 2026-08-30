.syntax unified
	.align 2, 0
	.global func_080E09B4
	.thumb
	.thumb_func
	.type func_080E09B4, %function
func_080E09B4: @ 080E09B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r4, #0x00
	beq _080E0A2C
	lsls r1, r6, #0x02
	ldr r0, _080E09DC @ =0x0984D32C
	adds r3, r1, r0
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	beq _080E09E4
	cmp r0, #0x01
	bne _080E09E4
	ldr r0, _080E09E0 @ =0x02034F34
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x1C]
	b _080E09EA
_080E09DC: .4byte 0x0984D32C
_080E09E0: .4byte 0x02034F34
_080E09E4:
	ldr r0, _080E0A34 @ =0x02034F34
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x18]
_080E09EA:
	movs r0, #0x07
	ands r0, r2
	ldrb r1, [r3, #0x01]
	adds r0, r0, r1
	lsls r0, r0, #0x02
	lsrs r1, r2, #0x03
	ldrb r2, [r3, #0x02]
	adds r1, r1, r2
	lsls r1, r1, #0x06
	adds r1, r0, r1
	ldrh r2, [r4, #0x00]
	movs r0, #0x04
	ands r0, r2
	cmp r0, #0x00
	beq _080E0A12
	ldrb r0, [r3, #0x03]
	lsls r0, r0, #0x02
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_080E0A12:
	movs r0, #0x08
	ands r0, r2
	cmp r0, #0x00
	beq _080E0A24
	ldrb r0, [r3, #0x03]
	lsls r0, r0, #0x03
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_080E0A24:
	strb r6, [r4, #0x04]
	lsls r0, r1, #0x01
	adds r0, r5, r0
	str r0, [r4, #0x18]
_080E0A2C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E0A34: .4byte 0x02034F34
.syntax divided
