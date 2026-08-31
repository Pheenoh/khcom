.syntax unified
	.align 2, 0
	.global func_08031BC4
	.thumb
	.thumb_func
	.type func_08031BC4, %function
func_08031BC4: @ 08031BC4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl GetKeysHeld
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08031BE4
	bl GetKeysHeld
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08031BE4
	movs r0, #0xAD
	b _08031D6C
_08031BE4:
	bl GetKeysHeld
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08031C00
	bl GetKeysHeld
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08031C00
	movs r0, #0xD3
	b _08031D6C
_08031C00:
	bl GetKeysHeld
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08031C1C
	bl GetKeysHeld
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08031C1C
	movs r0, #0x2D
	b _08031D6C
_08031C1C:
	bl GetKeysHeld
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08031C38
	bl GetKeysHeld
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08031C38
	movs r0, #0x53
	b _08031D6C
_08031C38:
	bl GetKeysHeld
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08031C56
	movs r0, #0x20
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031C56
	movs r0, #0xAD
	b _08031D6C
_08031C56:
	bl GetKeysHeld
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08031C74
	movs r0, #0x10
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031C74
	movs r0, #0x53
	b _08031D6C
_08031C74:
	bl GetKeysHeld
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08031C92
	movs r0, #0x20
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031C92
	movs r0, #0xD3
	b _08031D6C
_08031C92:
	bl GetKeysHeld
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08031CB0
	movs r0, #0x10
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031CB0
	movs r0, #0x2D
	b _08031D6C
_08031CB0:
	bl GetKeysHeld
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08031CCE
	movs r0, #0x40
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031CCE
	movs r0, #0xD3
	b _08031D6C
_08031CCE:
	bl GetKeysHeld
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08031CEC
	movs r0, #0x80
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031CEC
	movs r0, #0xAD
	b _08031D6C
_08031CEC:
	bl GetKeysHeld
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08031D0A
	movs r0, #0x40
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031D0A
	movs r0, #0x2D
	b _08031D6C
_08031D0A:
	bl GetKeysHeld
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08031D28
	movs r0, #0x80
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031D28
	movs r0, #0x53
	b _08031D6C
_08031D28:
	bl GetKeysHeld
	movs r2, #0x80
	adds r1, r2, #0x0
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r5, #0x00
	beq _08031D3E
	strb r2, [r4, #0x14]
	b _08031D6E
_08031D3E:
	bl GetKeysHeld
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08031D4E
	strb r5, [r4, #0x14]
	b _08031D6E
_08031D4E:
	bl GetKeysHeld
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08031D5E
	movs r0, #0xC0
	b _08031D6C
_08031D5E:
	bl GetKeysHeld
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08031D6E
	movs r0, #0x40
_08031D6C:
	strb r0, [r4, #0x14]
_08031D6E:
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
