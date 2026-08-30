.syntax unified
	.align 2, 0
	.global func_0807B910
	.thumb
	.thumb_func
	.type func_0807B910, %function
func_0807B910: @ 0807B910
	push {r4, r5, lr}
	mov r12, r0
	ldr r1, [r0, #0x44]
	movs r3, #0x00
	adds r0, #0xA8
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r3, r0
	bge _0807B986
	ldr r5, _0807B950 @ =0x08F70AB0
	adds r2, r1, #0x0
	movs r4, #0x00
_0807B928:
	ldr r1, [r2, #0x00]
	ldr r0, _0807B954 @ =0x0000FFFF
	cmp r1, r0
	beq _0807B976
	subs r0, #0x01
	cmp r1, r0
	beq _0807B976
	ldr r0, _0807B958 @ =0x00000FFF
	ands r1, r0
	movs r0, #0x34
	muls r0, r1
	adds r0, r0, r5
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0807B95C
	strb r4, [r2, #0x06]
	strb r4, [r2, #0x0A]
	b _0807B976
	.byte 0x00, 0x00
_0807B950: .4byte 0x08F70AB0
_0807B954: .4byte 0x0000FFFF
_0807B958: .4byte 0x00000FFF
_0807B95C:
	cmp r0, #0x02
	beq _0807B976
	ldrb r0, [r2, #0x08]
	cmp r0, #0x01
	beq _0807B972
	ldrb r0, [r2, #0x0A]
	cmp r0, #0x01
	beq _0807B972
	ldrb r0, [r2, #0x07]
	cmp r0, #0x01
	bne _0807B976
_0807B972:
	movs r0, #0x01
	strb r0, [r2, #0x06]
_0807B976:
	adds r2, #0x0C
	adds r3, #0x01
	mov r0, r12
	adds r0, #0xA8
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r3, r0
	blt _0807B928
_0807B986:
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
