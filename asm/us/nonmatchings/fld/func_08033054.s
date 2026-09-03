.syntax unified
	.align 2, 0
	.global func_08033054
	.thumb
	.thumb_func
	.type func_08033054, %function
func_08033054: @ 08033054
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r4, r1, #0x0
	ldr r0, _080330CC @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r5, r0, #0x0
	adds r5, #0x18
	bl GetKeysPressed
	movs r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	bne _0803309E
	bl GetKeysPressed
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	bne _0803309E
	ldrb r0, [r5, #0x14]
	cmp r0, #0xD3
	bne _0803308C
	bl GetKeysPressed
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	bne _0803309E
_0803308C:
	ldrb r0, [r5, #0x14]
	cmp r0, #0x2D
	bne _080330D4
	bl GetKeysPressed
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _080330D4
_0803309E:
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
	ldr r0, _080330CC @ =0x02039BA0
	ldr r0, [r0, #0x00]
	str r2, [r0, #0x68]
	ldr r1, _080330D0 @ =0x080324DD
	adds r0, r4, #0x0
	bl SetTaskUpdate
	movs r0, #0x01
	b _0803314A
_080330CC: .4byte 0x02039BA0
_080330D0: .4byte 0x080324DD
_080330D4:
	bl GetKeysHeld
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	bne _08033104
	ldrb r0, [r5, #0x14]
	cmp r0, #0xD3
	bne _080330F2
	bl GetKeysHeld
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	bne _08033104
_080330F2:
	ldrb r0, [r5, #0x14]
	cmp r0, #0x2D
	bne _08033148
	bl GetKeysHeld
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08033148
_08033104:
	adds r0, r6, #0x0
	adds r0, #0x98
	movs r4, #0x00
	strh r4, [r0, #0x00]
	adds r1, r6, #0x0
	adds r1, #0x94
	movs r0, #0x0A
	str r0, [r1, #0x00]
	ldr r0, _0803313C @ =0x00000133
	str r0, [r5, #0x10]
	adds r1, #0x0C
	ldr r0, _08033140 @ =0xFFFFFA40
	str r0, [r1, #0x00]
	adds r2, r6, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	movs r0, #0x04
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r0, #0x8E
	bl m4aSongNumStart
	ldr r0, _08033144 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	str r4, [r0, #0x68]
	movs r0, #0x01
	b _0803314A
	.byte 0x00, 0x00
_0803313C: .4byte 0x00000133
_08033140: .4byte 0xFFFFFA40
_08033144: .4byte 0x02039BA0
_08033148:
	movs r0, #0x00
_0803314A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
