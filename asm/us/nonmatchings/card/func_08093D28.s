.syntax unified
	.align 2, 0
	.global func_08093D28
	.thumb
	.thumb_func
	.type func_08093D28, %function
func_08093D28: @ 08093D28
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0x0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r12, r0
	movs r2, #0x00
	ldr r0, _08093D74 @ =0x0000029E
	adds r3, r6, r0
	ldr r4, _08093D78 @ =0x09619098
_08093D3A:
	adds r1, r3, r2
	adds r0, r2, #0x0
	adds r0, #0x20
	adds r0, r0, r4
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x15
	bls _08093D3A
	movs r2, #0x16
	movs r4, #0x02
	movs r1, #0xF6
	lsls r1, r1, #0x01
	adds r7, r6, r1
	ldr r0, _08093D74 @ =0x0000029E
	adds r3, r6, r0
	ldr r5, _08093D78 @ =0x09619098
_08093D60:
	ldr r0, [r7, #0x00]
	ldr r0, [r0, #0x18]
	ldrb r0, [r0, #0x1E]
	cmp r0, #0x02
	beq _08093D8E
	cmp r0, #0x02
	bgt _08093D7C
	cmp r0, #0x01
	beq _08093D86
	b _08093DAA
_08093D74: .4byte 0x0000029E
_08093D78: .4byte 0x09619098
_08093D7C:
	cmp r0, #0x03
	beq _08093D96
	cmp r0, #0x04
	beq _08093D9E
	b _08093DAA
_08093D86:
	adds r0, r3, r2
	adds r1, r4, #0x0
	adds r1, #0x60
	b _08093DA4
_08093D8E:
	adds r0, r3, r2
	adds r1, r4, #0x0
	adds r1, #0x40
	b _08093DA4
_08093D96:
	adds r0, r3, r2
	adds r1, r4, #0x0
	adds r1, #0xA0
	b _08093DA4
_08093D9E:
	adds r0, r3, r2
	adds r1, r4, #0x0
	adds r1, #0x80
_08093DA4:
	adds r1, r1, r5
	ldrb r1, [r1, #0x00]
	strb r1, [r0, #0x00]
_08093DAA:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r2, #0x19
	bls _08093D60
	movs r2, #0x1A
	ldr r1, _08093E24 @ =0x0000029E
	adds r3, r6, r1
	ldr r4, _08093E28 @ =0x09618C58
_08093DC2:
	adds r1, r3, r2
	adds r0, r2, r4
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x1F
	bls _08093DC2
	mov r2, r12
	movs r4, #0x02
	adds r0, r2, #0x0
	adds r0, #0x0A
	cmp r2, r0
	bge _08093E10
	ldr r0, _08093E24 @ =0x0000029E
	adds r3, r6, r0
	ldr r5, _08093E2C @ =0x0203A8C0
_08093DE6:
	adds r0, r2, r5
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08093DFC
	adds r1, r3, r4
	movs r0, #0xFF
	strb r0, [r1, #0x00]
	adds r0, r4, #0x1
	adds r0, r3, r0
	movs r1, #0x7F
	strb r1, [r0, #0x00]
_08093DFC:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r4, #0x2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r0, r12
	adds r0, #0x0A
	cmp r2, r0
	blt _08093DE6
_08093E10:
	ldr r1, _08093E24 @ =0x0000029E
	adds r0, r6, r1
	ldr r1, _08093E30 @ =0x05000180
	movs r2, #0x20
	bl func_08005BE8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08093E24: .4byte 0x0000029E
_08093E28: .4byte 0x09618C58
_08093E2C: .4byte 0x0203A8C0
_08093E30: .4byte 0x05000180
.syntax divided
