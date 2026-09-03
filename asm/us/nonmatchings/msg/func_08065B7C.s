.syntax unified
	.align 2, 0
	.global func_08065B7C
	.thumb
	.thumb_func
	.type func_08065B7C, %function
func_08065B7C: @ 08065B7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	movs r7, #0x00
	ldr r0, _08065BAC @ =0x02034A90
	strb r7, [r0, #0x00]
	ldrh r1, [r6, #0x00]
	mov r8, r0
	cmp r1, #0x00
	bne _08065B96
	b _08065CF6
_08065B96:
	movs r4, #0x00
	cmp r1, #0x0A
	bne _08065BB0
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _08065BA8
	bl ReleaseObjTiles
	str r4, [r5, #0x00]
_08065BA8:
	strb r4, [r5, #0x05]
	b _08065CE2
_08065BAC: .4byte 0x02034A90
_08065BB0:
	adds r0, r1, #0x0
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xDF
	bhi _08065BC0
	ldrh r4, [r6, #0x00]
	b _08065CA2
_08065BC0:
	ldrh r1, [r6, #0x00]
	movs r0, #0x99
	lsls r0, r0, #0x06
	cmp r1, r0
	beq _08065C94
	cmp r1, r0
	bgt _08065C1C
	ldr r0, _08065BEC @ =0x00002192
	cmp r1, r0
	beq _08065C74
	cmp r1, r0
	bgt _08065BF4
	subs r0, #0x02
	cmp r1, r0
	beq _08065C70
	cmp r1, r0
	bgt _08065C68
	ldr r0, _08065BF0 @ =0x0000203B
	cmp r1, r0
	beq _08065C88
	b _08065CA0
	.byte 0x00, 0x00
_08065BEC: .4byte 0x00002192
_08065BF0: .4byte 0x0000203B
_08065BF4:
	ldr r0, _08065C08 @ =0x000025A0
	cmp r1, r0
	beq _08065C9C
	cmp r1, r0
	bgt _08065C10
	ldr r0, _08065C0C @ =0x00002193
	cmp r1, r0
	beq _08065C6C
	b _08065CA0
	.byte 0x00, 0x00
_08065C08: .4byte 0x000025A0
_08065C0C: .4byte 0x00002193
_08065C10:
	ldr r0, _08065C18 @ =0x00002605
	cmp r1, r0
	beq _08065C98
	b _08065CA0
_08065C18: .4byte 0x00002605
_08065C1C:
	ldr r0, _08065C38 @ =0x0000300D
	cmp r1, r0
	beq _08065C7C
	cmp r1, r0
	bgt _08065C4C
	ldr r0, _08065C3C @ =0x0000266A
	cmp r1, r0
	beq _08065C8C
	cmp r1, r0
	bgt _08065C40
	subs r0, #0x28
	cmp r1, r0
	beq _08065C90
	b _08065CA0
_08065C38: .4byte 0x0000300D
_08065C3C: .4byte 0x0000266A
_08065C40:
	ldr r0, _08065C48 @ =0x0000300C
	cmp r1, r0
	beq _08065C78
	b _08065CA0
_08065C48: .4byte 0x0000300C
_08065C4C:
	ldr r0, _08065C64 @ =0x0000300F
	cmp r1, r0
	beq _08065C84
	cmp r1, r0
	blt _08065C80
	movs r0, #0xE0
	lsls r0, r0, #0x08
	cmp r1, r0
	bne _08065CA0
	movs r4, #0x19
	b _08065CA2
	.byte 0x00, 0x00
_08065C64: .4byte 0x0000300F
_08065C68:
	movs r4, #0x0A
	b _08065CA2
_08065C6C:
	movs r4, #0x0B
	b _08065CA2
_08065C70:
	movs r4, #0x0C
	b _08065CA2
_08065C74:
	movs r4, #0x0D
	b _08065CA2
_08065C78:
	movs r4, #0x01
	b _08065CA2
_08065C7C:
	movs r4, #0x02
	b _08065CA2
_08065C80:
	movs r4, #0x03
	b _08065CA2
_08065C84:
	movs r4, #0x04
	b _08065CA2
_08065C88:
	movs r4, #0x06
	b _08065CA2
_08065C8C:
	movs r4, #0x12
	b _08065CA2
_08065C90:
	movs r4, #0x08
	b _08065CA2
_08065C94:
	movs r4, #0x09
	b _08065CA2
_08065C98:
	movs r4, #0x15
	b _08065CA2
_08065C9C:
	movs r4, #0x11
	b _08065CA2
_08065CA0:
	movs r4, #0x00
_08065CA2:
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _08065CB0
	bl ReleaseObjTiles
	movs r0, #0x00
	str r0, [r5, #0x00]
_08065CB0:
	cmp r4, #0x20
	beq _08065CC4
	ldr r0, _08065CC0 @ =0x08F7D438
	lsls r1, r4, #0x01
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	b _08065CC6
	.byte 0x00, 0x00
_08065CC0: .4byte 0x08F7D438
_08065CC4:
	movs r0, #0xFF
_08065CC6:
	strb r0, [r5, #0x05]
	ldr r1, _08065D04 @ =0x09EEC134
	lsls r0, r4, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r4, [r0, #0x06]
	lsls r0, r4, #0x05
	ldr r1, _08065D08 @ =0x090CBFB2
	adds r0, r0, r1
	movs r1, #0x80
	bl LoadObjTiles
	str r0, [r5, #0x00]
	strb r7, [r5, #0x04]
_08065CE2:
	ldr r1, _08065D0C @ =0x02034A90
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	adds r5, #0x08
	adds r6, #0x02
	ldrh r1, [r6, #0x00]
	cmp r1, #0x00
	beq _08065CF6
	b _08065B96
_08065CF6:
	mov r1, r8
	ldrb r0, [r1, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08065D04: .4byte 0x09EEC134
_08065D08: .4byte 0x090CBFB2
_08065D0C: .4byte 0x02034A90
.syntax divided
