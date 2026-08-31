.syntax unified
	.align 2, 0
	.global func_0804F9C8
	.thumb
	.thumb_func
	.type func_0804F9C8, %function
func_0804F9C8: @ 0804F9C8
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	ldr r5, _0804FA1C @ =0x02039B84
	ldr r0, [r5, #0x00]
	ldr r6, [r0, #0x7C]
	adds r0, r4, #0x0
	adds r0, #0x40
	mov r1, sp
	movs r2, #0x00
	movs r3, #0x00
	bl func_0801C700
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_0800F368
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r0, r4, #0x0
	adds r1, r3, #0x0
	adds r2, r3, #0x0
	bl func_0800F504
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0804FA66
	ldr r0, [r5, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x08
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0804FA20
	subs r1, #0x80
	adds r0, r4, #0x0
	bl func_0804F8F0
	b _0804FA62
_0804FA1C: .4byte 0x02039B84
_0804FA20:
	bl GetRandom
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0804FA58
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0804FA44
	ldr r1, [sp, #0x000]
	movs r0, #0xA0
	lsls r0, r0, #0x06
	b _0804FA48
_0804FA44:
	ldr r1, [sp, #0x000]
	ldr r0, _0804FA54 @ =0xFFFFD800
_0804FA48:
	adds r1, r1, r0
	adds r0, r4, #0x0
	movs r2, #0x30
	bl func_0804F9A0
	b _0804FA62
_0804FA54: .4byte 0xFFFFD800
_0804FA58:
	movs r1, #0x80
	negs r1, r1
	adds r0, r4, #0x0
	bl func_0804F8F0
_0804FA62:
	movs r0, #0x01
	b _0804FA68
_0804FA66:
	movs r0, #0x00
_0804FA68:
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
