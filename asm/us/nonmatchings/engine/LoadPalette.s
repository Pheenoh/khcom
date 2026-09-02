.syntax unified
	.align 2, 0
	.global LoadPalette
	.thumb
	.thumb_func
	.type LoadPalette, %function
LoadPalette: @ 08005BE8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
	ldr r0, _08005C58 @ =0x03007568
	ldr r0, [r0, #0x00]
	mov r8, r0
	lsrs r7, r2, #0x15
	movs r0, #0xFB
	lsls r0, r0, #0x18
	adds r1, r5, r0
	cmp r1, #0x00
	bge _08005C0C
	ldr r2, _08005C5C @ =0xFB00001F
	adds r1, r5, r2
_08005C0C:
	asrs r4, r1, #0x05
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	adds r2, r3, #0x0
	bl LoadPaletteWithEffect
	adds r6, r0, #0x0
	cmp r7, #0x00
	beq _08005C4E
	movs r0, #0x01
	mov r12, r0
	movs r0, #0x2C
	adds r1, r4, #0x0
	muls r1, r0
	mov r0, r8
	adds r0, #0x29
	adds r4, r1, r0
	adds r3, r5, #0x0
	mov r2, r8
	adds r0, r1, r2
	adds r1, r6, #0x0
	adds r2, r7, #0x0
_08005C38:
	str r1, [r0, #0x00]
	str r3, [r0, #0x04]
	mov r5, r12
	strb r5, [r4, #0x00]
	adds r4, #0x2C
	adds r3, #0x20
	adds r0, #0x2C
	adds r1, #0x20
	subs r2, #0x01
	cmp r2, #0x00
	bne _08005C38
_08005C4E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08005C58: .4byte 0x03007568
_08005C5C: .4byte 0xFB00001F
.syntax divided
