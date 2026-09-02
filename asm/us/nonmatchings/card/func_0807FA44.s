.syntax unified
	.align 2, 0
	.global func_0807FA44
	.thumb
	.thumb_func
	.type func_0807FA44, %function
func_0807FA44: @ 0807FA44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r12, r0
	movs r2, #0x00
	mov r3, r12
	adds r3, #0xB9
	ldr r5, _0807FACC @ =0x02034AAC
	ldr r7, _0807FAD0 @ =0x02039DD4
	ldr r0, _0807FAD4 @ =0x02039B84
	mov r8, r0
	ldrb r0, [r3, #0x00]
	cmp r2, r0
	bcs _0807FA80
	mov r4, r12
	adds r4, #0x28
	movs r6, #0x21
	negs r6, r6
_0807FA68:
	lsls r0, r2, #0x02
	adds r0, r4, r0
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x78]
	ands r0, r6
	str r0, [r1, #0x78]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldrb r0, [r3, #0x00]
	cmp r2, r0
	bcc _0807FA68
_0807FA80:
	ldr r2, [r5, #0x00]
	cmp r2, #0x00
	beq _0807FA90
	ldr r0, [r2, #0x78]
	movs r1, #0x21
	negs r1, r1
	ands r0, r1
	str r0, [r2, #0x78]
_0807FA90:
	ldr r4, [r7, #0x00]
	adds r1, r4, #0x0
	adds r1, #0xCC
	movs r6, #0x00
	movs r0, #0x00
	strh r0, [r1, #0x00]
	mov r0, r8
	ldr r5, [r0, #0x00]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x6C]
	movs r2, #0x20
	movs r3, #0x00
	orrs r0, r2
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
	adds r4, #0xEA
	strb r6, [r4, #0x00]
	ldr r0, [r7, #0x00]
	adds r0, #0xE4
	strb r6, [r0, #0x00]
	mov r1, r12
	adds r1, #0xC9
	movs r0, #0x01
	strb r0, [r1, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0807FACC: .4byte 0x02034AAC
_0807FAD0: .4byte 0x02039DD4
_0807FAD4: .4byte 0x02039B84
.syntax divided
