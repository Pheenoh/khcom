.syntax unified
	.align 2, 0
	.global func_0807AE78
	.thumb
	.thumb_func
	.type func_0807AE78, %function
func_0807AE78: @ 0807AE78
	push {r4, r5, r6, lr}
	mov r12, r0
	movs r3, #0x00
	mov r4, r12
	adds r4, #0xA8
_0807AE82:
	lsls r0, r3, #0x02
	mov r1, r12
	adds r1, #0x44
	adds r1, r1, r0
	ldr r1, [r1, #0x00]
	movs r2, #0x00
	movs r5, #0x00
	ldsh r0, [r4, r5]
	adds r3, #0x01
	cmp r2, r0
	bge _0807AEB6
	movs r5, #0x00
_0807AE9A:
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x02
	adds r0, r0, r1
	strb r5, [r0, #0x07]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r0, r2, #0x01
	adds r0, r4, r0
	movs r6, #0x00
	ldsh r0, [r0, r6]
	cmp r2, r0
	blt _0807AE9A
_0807AEB6:
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x03
	bls _0807AE82
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
