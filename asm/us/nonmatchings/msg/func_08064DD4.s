.syntax unified
	.align 2, 0
	.global func_08064DD4
	.thumb
	.thumb_func
	.type func_08064DD4, %function
func_08064DD4: @ 08064DD4
	push {r4, r5, lr}
	adds r3, r0, #0x0
	movs r4, #0x00
	ldrh r0, [r3, #0x00]
	cmp r0, #0x00
	bne _08064DE2
	b _08064EE8
_08064DE2:
	ldr r5, _08064DFC @ =0x08F7D438
_08064DE4:
	movs r1, #0x00
	cmp r0, #0x0A
	bne _08064DEC
	b _08064EDE
_08064DEC:
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xDF
	bhi _08064E00
	ldrh r1, [r3, #0x00]
	b _08064ECE
	.byte 0x00, 0x00
_08064DFC: .4byte 0x08F7D438
_08064E00:
	ldrh r2, [r3, #0x00]
	movs r0, #0x99
	lsls r0, r0, #0x06
	cmp r2, r0
	beq _08064EC8
	cmp r2, r0
	bgt _08064E50
	ldr r0, _08064E28 @ =0x00002191
	cmp r2, r0
	beq _08064E9C
	cmp r2, r0
	bgt _08064E34
	ldr r0, _08064E2C @ =0x0000203B
	cmp r2, r0
	beq _08064EBC
	ldr r0, _08064E30 @ =0x00002190
	cmp r2, r0
	beq _08064EA4
	b _08064ECE
	.byte 0x00, 0x00
_08064E28: .4byte 0x00002191
_08064E2C: .4byte 0x0000203B
_08064E30: .4byte 0x00002190
_08064E34:
	ldr r0, _08064E48 @ =0x00002193
	cmp r2, r0
	beq _08064EA0
	cmp r2, r0
	blt _08064EA8
	ldr r0, _08064E4C @ =0x00002605
	cmp r2, r0
	beq _08064ECC
	b _08064ECE
	.byte 0x00, 0x00
_08064E48: .4byte 0x00002193
_08064E4C: .4byte 0x00002605
_08064E50:
	ldr r0, _08064E6C @ =0x0000300D
	cmp r2, r0
	beq _08064EB0
	cmp r2, r0
	bgt _08064E80
	ldr r0, _08064E70 @ =0x0000266A
	cmp r2, r0
	beq _08064EC0
	cmp r2, r0
	bgt _08064E74
	subs r0, #0x28
	cmp r2, r0
	beq _08064EC4
	b _08064ECE
_08064E6C: .4byte 0x0000300D
_08064E70: .4byte 0x0000266A
_08064E74:
	ldr r0, _08064E7C @ =0x0000300C
	cmp r2, r0
	beq _08064EAC
	b _08064ECE
_08064E7C: .4byte 0x0000300C
_08064E80:
	ldr r0, _08064E98 @ =0x0000300F
	cmp r2, r0
	beq _08064EB8
	cmp r2, r0
	blt _08064EB4
	movs r0, #0xE0
	lsls r0, r0, #0x08
	cmp r2, r0
	bne _08064ECE
	movs r1, #0x19
	b _08064ECE
	.byte 0x00, 0x00
_08064E98: .4byte 0x0000300F
_08064E9C:
	movs r1, #0x0A
	b _08064ECE
_08064EA0:
	movs r1, #0x0B
	b _08064ECE
_08064EA4:
	movs r1, #0x0C
	b _08064ECE
_08064EA8:
	movs r1, #0x0D
	b _08064ECE
_08064EAC:
	movs r1, #0x01
	b _08064ECE
_08064EB0:
	movs r1, #0x02
	b _08064ECE
_08064EB4:
	movs r1, #0x03
	b _08064ECE
_08064EB8:
	movs r1, #0x04
	b _08064ECE
_08064EBC:
	movs r1, #0x06
	b _08064ECE
_08064EC0:
	movs r1, #0x12
	b _08064ECE
_08064EC4:
	movs r1, #0x08
	b _08064ECE
_08064EC8:
	movs r1, #0x09
	b _08064ECE
_08064ECC:
	movs r1, #0x15
_08064ECE:
	lsls r1, r1, #0x01
	adds r1, r1, r5
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r1, #0x00]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08064EDE:
	adds r3, #0x02
	ldrh r0, [r3, #0x00]
	cmp r0, #0x00
	beq _08064EE8
	b _08064DE4
_08064EE8:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
