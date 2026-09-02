.syntax unified
	.align 2, 0
	.global func_0807B98C
	.thumb
	.thumb_func
	.type func_0807B98C, %function
func_0807B98C: @ 0807B98C
	push {r4, r5, lr}
	mov r12, r0
	ldr r1, [r0, #0x44]
	movs r3, #0x00
	adds r0, #0xA8
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r3, r0
	bge _0807B9D8
	ldr r5, _0807B9E0 @ =0x08F70AB0
	movs r4, #0x00
	adds r2, r1, #0x0
_0807B9A4:
	ldr r1, [r2, #0x00]
	ldr r0, _0807B9E4 @ =0x0000FFFF
	cmp r1, r0
	beq _0807B9C8
	subs r0, #0x01
	cmp r1, r0
	beq _0807B9C8
	ldr r0, _0807B9E8 @ =0x00000FFF
	ands r1, r0
	movs r0, #0x34
	muls r0, r1
	adds r0, r0, r5
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	beq _0807B9C8
	strb r4, [r2, #0x06]
	strb r4, [r2, #0x0A]
_0807B9C8:
	adds r2, #0x0C
	adds r3, #0x01
	mov r0, r12
	adds r0, #0xA8
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r3, r0
	blt _0807B9A4
_0807B9D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0807B9E0: .4byte 0x08F70AB0
_0807B9E4: .4byte 0x0000FFFF
_0807B9E8: .4byte 0x00000FFF
.syntax divided
