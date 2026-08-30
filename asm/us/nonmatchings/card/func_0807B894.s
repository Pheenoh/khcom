.syntax unified
	.align 2, 0
	.global func_0807B894
	.thumb
	.thumb_func
	.type func_0807B894, %function
func_0807B894: @ 0807B894
	push {r4, lr}
	mov r12, r0
	ldr r1, [r0, #0x44]
	movs r3, #0x00
	adds r0, #0xA8
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r3, r0
	bge _0807B90A
	ldr r4, _0807B8D4 @ =0x08F70AB0
	adds r2, r1, #0x0
_0807B8AA:
	ldr r1, [r2, #0x00]
	ldr r0, _0807B8D8 @ =0x0000FFFF
	cmp r1, r0
	beq _0807B8FA
	subs r0, #0x01
	cmp r1, r0
	beq _0807B8FA
	ldr r0, _0807B8DC @ =0x00000FFF
	ands r1, r0
	movs r0, #0x34
	muls r0, r1
	adds r0, r0, r4
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0807B8E0
	ldrb r0, [r2, #0x0A]
	cmp r0, #0x00
	bne _0807B8FA
	b _0807B8F8
	.byte 0x00, 0x00
_0807B8D4: .4byte 0x08F70AB0
_0807B8D8: .4byte 0x0000FFFF
_0807B8DC: .4byte 0x00000FFF
_0807B8E0:
	cmp r0, #0x02
	beq _0807B8FA
	ldrb r0, [r2, #0x0A]
	cmp r0, #0x01
	beq _0807B8F6
	ldrb r0, [r2, #0x07]
	cmp r0, #0x01
	beq _0807B8F6
	ldrb r0, [r2, #0x08]
	cmp r0, #0x01
	bne _0807B8FA
_0807B8F6:
	movs r0, #0x01
_0807B8F8:
	strb r0, [r2, #0x06]
_0807B8FA:
	adds r2, #0x0C
	adds r3, #0x01
	mov r0, r12
	adds r0, #0xA8
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r3, r0
	blt _0807B8AA
_0807B90A:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
