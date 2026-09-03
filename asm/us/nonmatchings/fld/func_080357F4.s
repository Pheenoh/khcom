.syntax unified
	.align 2, 0
	.global func_080357F4
	.thumb
	.thumb_func
	.type func_080357F4, %function
func_080357F4: @ 080357F4
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r4, r1, #0x0
	ldr r0, _0803586C @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r5, r0, #0x0
	adds r5, #0x18
	bl GetKeysPressed
	movs r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	bne _0803583E
	bl GetKeysPressed
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	bne _0803583E
	ldrb r0, [r5, #0x14]
	cmp r0, #0xD3
	bne _0803582C
	bl GetKeysPressed
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	bne _0803583E
_0803582C:
	ldrb r0, [r5, #0x14]
	cmp r0, #0x2D
	bne _08035874
	bl GetKeysPressed
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08035874
_0803583E:
	adds r0, r6, #0x0
	adds r0, #0x98
	movs r2, #0x00
	strh r2, [r0, #0x00]
	adds r1, r6, #0x0
	adds r1, #0x94
	movs r0, #0x04
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	adds r0, #0xA0
	str r2, [r0, #0x00]
	ldrb r0, [r5, #0x14]
	adds r0, #0x80
	strb r0, [r5, #0x14]
	ldr r0, _0803586C @ =0x02039BA0
	ldr r0, [r0, #0x00]
	str r2, [r0, #0x68]
	ldr r1, _08035870 @ =0x08034C89
	adds r0, r4, #0x0
	bl SetTaskUpdate
	movs r0, #0x01
	b _080358EA
_0803586C: .4byte 0x02039BA0
_08035870: .4byte 0x08034C89
_08035874:
	bl GetKeysHeld
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	bne _080358A4
	ldrb r0, [r5, #0x14]
	cmp r0, #0xD3
	bne _08035892
	bl GetKeysHeld
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	bne _080358A4
_08035892:
	ldrb r0, [r5, #0x14]
	cmp r0, #0x2D
	bne _080358E8
	bl GetKeysHeld
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080358E8
_080358A4:
	adds r0, r6, #0x0
	adds r0, #0x98
	movs r4, #0x00
	strh r4, [r0, #0x00]
	adds r1, r6, #0x0
	adds r1, #0x94
	movs r0, #0x0A
	str r0, [r1, #0x00]
	ldr r0, _080358DC @ =0x00000133
	str r0, [r5, #0x10]
	adds r1, #0x0C
	ldr r0, _080358E0 @ =0xFFFFFA40
	str r0, [r1, #0x00]
	adds r2, r6, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	movs r0, #0x04
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r0, #0x8E
	bl m4aSongNumStart
	ldr r0, _080358E4 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	str r4, [r0, #0x68]
	movs r0, #0x01
	b _080358EA
	.byte 0x00, 0x00
_080358DC: .4byte 0x00000133
_080358E0: .4byte 0xFFFFFA40
_080358E4: .4byte 0x02039BA0
_080358E8:
	movs r0, #0x00
_080358EA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
