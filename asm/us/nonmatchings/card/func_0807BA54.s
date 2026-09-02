.syntax unified
	.align 2, 0
	.global func_0807BA54
	.thumb
	.thumb_func
	.type func_0807BA54, %function
func_0807BA54: @ 0807BA54
	push {r4, lr}
	ldr r0, _0807BA8C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	ldr r4, _0807BA90 @ =0x02039B84
	cmp r0, #0x00
	beq _0807BAD4
	ldr r3, [r4, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	bne _0807BA94
	movs r0, #0xE4
	lsls r0, r0, #0x01
	adds r1, r3, r0
	movs r2, #0xE5
	lsls r2, r2, #0x01
	adds r0, r3, r2
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _0807BAAC
_0807BA8C: .4byte 0x02039BB0
_0807BA90: .4byte 0x02039B84
_0807BA94:
	movs r0, #0xE5
	lsls r0, r0, #0x01
	adds r2, r3, r0
	movs r0, #0x00
	ldsb r0, [r2, r0]
	cmp r0, #0x00
	bge _0807BAB2
	movs r0, #0xE4
	lsls r0, r0, #0x01
	adds r1, r3, r0
	movs r0, #0x00
	ldsb r0, [r2, r0]
_0807BAAC:
	ldrh r2, [r1, #0x00]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
_0807BAB2:
	ldr r0, [r4, #0x00]
	movs r2, #0xE4
	lsls r2, r2, #0x01
	adds r1, r0, r2
	movs r2, #0x00
	ldsh r0, [r1, r2]
	ldr r2, _0807BAC8 @ =0x000003E7
	cmp r0, r2
	ble _0807BACC
	strh r2, [r1, #0x00]
	b _0807BAD4
_0807BAC8: .4byte 0x000003E7
_0807BACC:
	cmp r0, #0x00
	bge _0807BAD4
	movs r0, #0x00
	strh r0, [r1, #0x00]
_0807BAD4:
	ldr r1, [r4, #0x00]
	movs r2, #0xE4
	lsls r2, r2, #0x01
	adds r0, r1, r2
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x1D
	ble _0807BAFA
	ldr r0, [r1, #0x68]
	ldr r1, [r1, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	bne _0807BAFA
	movs r0, #0x01
	b _0807BAFC
_0807BAFA:
	movs r0, #0x00
_0807BAFC:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
