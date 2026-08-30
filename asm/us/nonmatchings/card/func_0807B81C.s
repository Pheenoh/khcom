.syntax unified
	.align 2, 0
	.global func_0807B81C
	.thumb
	.thumb_func
	.type func_0807B81C, %function
func_0807B81C: @ 0807B81C
	push {r4, lr}
	mov r12, r0
	ldr r1, [r0, #0x44]
	movs r3, #0x00
	adds r0, #0xA8
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r3, r0
	bge _0807B88E
	ldr r4, _0807B858 @ =0x08F70AB0
	adds r2, r1, #0x0
_0807B832:
	ldr r1, [r2, #0x00]
	ldr r0, _0807B85C @ =0x0000FFFF
	cmp r1, r0
	beq _0807B87E
	subs r0, #0x01
	cmp r1, r0
	beq _0807B87E
	ldr r0, _0807B860 @ =0x00000FFF
	ands r1, r0
	movs r0, #0x34
	muls r0, r1
	adds r0, r0, r4
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0807B864
	strb r0, [r2, #0x06]
	strb r0, [r2, #0x0A]
	b _0807B87E
_0807B858: .4byte 0x08F70AB0
_0807B85C: .4byte 0x0000FFFF
_0807B860: .4byte 0x00000FFF
_0807B864:
	cmp r0, #0x02
	beq _0807B87E
	ldrb r0, [r2, #0x08]
	cmp r0, #0x01
	beq _0807B87A
	ldrb r0, [r2, #0x0A]
	cmp r0, #0x01
	beq _0807B87A
	ldrb r0, [r2, #0x07]
	cmp r0, #0x01
	bne _0807B87E
_0807B87A:
	movs r0, #0x01
	strb r0, [r2, #0x06]
_0807B87E:
	adds r2, #0x0C
	adds r3, #0x01
	mov r0, r12
	adds r0, #0xA8
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r3, r0
	blt _0807B832
_0807B88E:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
