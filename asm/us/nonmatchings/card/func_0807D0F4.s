.syntax unified
	.align 2, 0
	.global func_0807D0F4
	.thumb
	.thumb_func
	.type func_0807D0F4, %function
func_0807D0F4: @ 0807D0F4
	push {r4, lr}
	mov r12, r0
	mov r3, r12
	adds r3, #0x80
	ldr r0, [r3, #0x00]
	mov r1, r12
	ldr r2, [r1, #0x7C]
	subs r0, r0, r2
	movs r1, #0xFE
	lsls r1, r1, #0x07
	cmp r0, r1
	ble _0807D116
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r2, r1
	mov r2, r12
	str r0, [r2, #0x7C]
_0807D116:
	ldr r3, [r3, #0x00]
	mov r0, r12
	ldr r2, [r0, #0x7C]
	subs r0, r3, r2
	cmp r0, #0xFF
	bgt _0807D132
	ldr r1, _0807D18C @ =0xFFFF0000
	adds r4, r2, r1
	subs r1, r3, r4
	subs r0, r2, r3
	cmp r1, r0
	bge _0807D132
	mov r2, r12
	str r4, [r2, #0x7C]
_0807D132:
	mov r0, r12
	adds r0, #0x80
	ldr r0, [r0, #0x00]
	mov r3, r12
	ldr r1, [r3, #0x7C]
	subs r0, r0, r1
	asrs r0, r0, #0x02
	adds r1, r1, r0
	str r1, [r3, #0x7C]
	ldr r4, _0807D190 @ =0x08121400
	asrs r1, r1, #0x08
	movs r0, #0xFF
	ands r1, r0
	lsls r0, r1, #0x01
	adds r0, r0, r4
	movs r3, #0x00
	ldsh r2, [r0, r3]
	mov r3, r12
	adds r3, #0x84
	ldr r0, [r3, #0x00]
	asrs r0, r0, #0x08
	muls r0, r2
	mov r2, r12
	adds r2, #0x8C
	ldr r2, [r2, #0x00]
	adds r0, r0, r2
	mov r2, r12
	str r0, [r2, #0x4C]
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r4
	movs r0, #0x00
	ldsh r1, [r1, r0]
	negs r1, r1
	ldr r0, [r3, #0x00]
	asrs r0, r0, #0x08
	muls r0, r1
	mov r1, r12
	adds r1, #0x90
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x50]
	pop {r4}
	pop {r0}
	bx r0
_0807D18C: .4byte 0xFFFF0000
_0807D190: .4byte 0x08121400
.syntax divided
