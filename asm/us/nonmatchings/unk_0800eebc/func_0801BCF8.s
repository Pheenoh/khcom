.syntax unified
	.align 2, 0
	.global func_0801BCF8
	.thumb
	.thumb_func
	.type func_0801BCF8, %function
func_0801BCF8: @ 0801BCF8
	push {r4, r5, r6, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	ldr r2, _0801BD4C @ =0x00007202
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0801BDC6
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	adds r1, #0xB2
	ldrh r2, [r1, #0x00]
	ldr r6, _0801BD50 @ =0x02039B84
	ldr r1, [r6, #0x00]
	adds r1, #0xEE
	ldrb r1, [r1, #0x00]
	muls r1, r2
	bl func_0811D684
	cmp r0, #0x00
	bne _0801BDC6
	add r2, sp, #0x004
	adds r0, r4, #0x0
	mov r1, sp
	movs r3, #0x00
	bl func_0801C700
	adds r0, r4, #0x0
	adds r0, #0xD0
	movs r2, #0x00
	ldsh r1, [r0, r2]
	adds r5, r0, #0x0
	cmp r1, #0x00
	bne _0801BD54
	ldr r0, [r6, #0x00]
	b _0801BDC2
_0801BD4C: .4byte 0x00007202
_0801BD50: .4byte 0x02039B84
_0801BD54:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0801BD74
	adds r0, r4, #0x0
	adds r0, #0xCE
	movs r6, #0x00
	ldsh r0, [r0, r6]
	lsls r0, r0, #0x08
	ldr r1, [r4, #0x04]
	subs r1, r1, r0
	b _0801BD82
_0801BD74:
	adds r0, r4, #0x0
	adds r0, #0xCE
	movs r6, #0x00
	ldsh r0, [r0, r6]
	lsls r0, r0, #0x08
	ldr r1, [r4, #0x04]
	adds r1, r1, r0
_0801BD82:
	movs r2, #0x00
	ldsh r0, [r5, r2]
	subs r0, #0x04
	lsls r0, r0, #0x08
	subs r3, r1, r0
	adds r0, r4, #0x0
	adds r0, #0xD2
	movs r6, #0x00
	ldsh r1, [r0, r6]
	lsls r2, r1, #0x08
	ldr r0, [r4, #0x08]
	subs r2, r0, r2
	movs r6, #0x00
	ldsh r0, [r5, r6]
	adds r0, #0x04
	lsls r0, r0, #0x09
	adds r0, r3, r0
	adds r1, #0x04
	lsls r1, r1, #0x09
	adds r5, r2, r1
	ldr r1, [sp, #0x000]
	cmp r3, r1
	bgt _0801BDC6
	cmp r0, r1
	blt _0801BDC6
	ldr r0, [sp, #0x004]
	cmp r2, r0
	bgt _0801BDC6
	cmp r5, r0
	blt _0801BDC6
	ldr r0, _0801BDD0 @ =0x02039B84
	ldr r0, [r0, #0x00]
_0801BDC2:
	adds r0, #0xAC
	str r4, [r0, #0x00]
_0801BDC6:
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801BDD0: .4byte 0x02039B84
.syntax divided
