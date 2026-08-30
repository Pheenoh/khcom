.syntax unified
	.align 2, 0
	.global func_0811FD40
	.thumb
	.thumb_func
	.type func_0811FD40, %function
func_0811FD40: @ 0811FD40
	push {r4, r5, r6, r7, lr}
	mov r12, r0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r7, r2, #0x18
	cmp r6, #0xB2
	bls _0811FD54
	movs r6, #0xB2
	movs r7, #0xFF
	lsls r7, r7, #0x18
_0811FD54:
	ldr r3, _0811FD9C @ =0x09D6D3D8
	adds r0, r6, r3
	ldrb r5, [r0, #0x00]
	ldr r4, _0811FDA0 @ =0x09D6D48C
	movs r2, #0x0F
	adds r0, r5, #0x0
	ands r0, r2
	lsls r0, r0, #0x02
	adds r0, r0, r4
	lsrs r1, r5, #0x04
	ldr r5, [r0, #0x00]
	lsrs r5, r1
	adds r0, r6, #0x1
	adds r0, r0, r3
	ldrb r1, [r0, #0x00]
	adds r0, r1, #0x0
	ands r0, r2
	lsls r0, r0, #0x02
	adds r0, r0, r4
	lsrs r1, r1, #0x04
	ldr r0, [r0, #0x00]
	lsrs r0, r1
	mov r1, r12
	ldr r4, [r1, #0x04]
	subs r0, r0, r5
	adds r1, r7, #0x0
	bl _0811F140
	adds r1, r0, #0x0
	adds r1, r5, r1
	adds r0, r4, #0x0
	bl _0811F140
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_0811FD9C: .4byte 0x09D6D3D8
_0811FDA0: .4byte 0x09D6D48C
	.byte 0x70, 0x47, 0x00, 0x00
.syntax divided
