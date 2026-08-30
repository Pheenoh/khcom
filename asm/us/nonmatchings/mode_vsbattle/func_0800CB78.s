.syntax unified
	.align 2, 0
	.global func_0800CB78
	.thumb
	.thumb_func
	.type func_0800CB78, %function
func_0800CB78: @ 0800CB78
	push {r4, r5, lr}
	mov r12, r0
	movs r2, #0xB4
	lsls r2, r2, #0x01
	add r2, r12
	adds r0, #0xE8
	ldr r1, [r0, #0x00]
	negs r1, r1
	lsls r0, r1, #0x01
	adds r0, r0, r1
	str r0, [r2, #0x00]
	movs r5, #0xA2
	lsls r5, r5, #0x01
	add r5, r12
	ldr r4, _0800CBD8 @ =0x08121400
	mov r2, r12
	adds r2, #0xEC
	ldrb r0, [r2, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x01
	mov r3, r12
	adds r3, #0xE4
	ldr r1, [r3, #0x00]
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r5, #0x00]
	movs r5, #0xA4
	lsls r5, r5, #0x01
	add r5, r12
	ldrb r0, [r2, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	lsls r0, r0, #0x01
	ldr r1, [r3, #0x00]
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r5, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800CBD8: .4byte 0x08121400
.syntax divided
