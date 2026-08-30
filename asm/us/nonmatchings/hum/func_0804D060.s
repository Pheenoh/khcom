.syntax unified
	.align 2, 0
	.global func_0804D060
	.thumb
	.thumb_func
	.type func_0804D060, %function
func_0804D060: @ 0804D060
	push {r4, lr}
	mov r12, r0
	mov r4, r12
	adds r4, #0x40
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0804D086
	movs r2, #0xE4
	lsls r2, r2, #0x01
	add r2, r12
	ldr r1, [r2, #0x00]
	movs r0, #0xC0
	lsls r0, r0, #0x05
	b _0804D090
_0804D086:
	movs r2, #0xE4
	lsls r2, r2, #0x01
	add r2, r12
	ldr r1, [r2, #0x00]
	ldr r0, _0804D0DC @ =0xFFFFE800
_0804D090:
	subs r0, r0, r1
	asrs r0, r0, #0x03
	adds r1, r1, r0
	str r1, [r2, #0x00]
	movs r3, #0xE6
	lsls r3, r3, #0x01
	add r3, r12
	ldr r1, [r3, #0x00]
	ldr r0, _0804D0E0 @ =0xFFFFEE00
	subs r0, r0, r1
	asrs r0, r0, #0x03
	adds r1, r1, r0
	str r1, [r3, #0x00]
	movs r2, #0xD8
	lsls r2, r2, #0x01
	add r2, r12
	movs r1, #0xE4
	lsls r1, r1, #0x01
	add r1, r12
	ldr r0, [r4, #0x04]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	movs r1, #0xDA
	lsls r1, r1, #0x01
	add r1, r12
	ldr r0, [r4, #0x08]
	str r0, [r1, #0x00]
	movs r2, #0xDC
	lsls r2, r2, #0x01
	add r2, r12
	ldr r0, [r4, #0x0C]
	ldr r1, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_0804D0DC: .4byte 0xFFFFE800
_0804D0E0: .4byte 0xFFFFEE00
.syntax divided
