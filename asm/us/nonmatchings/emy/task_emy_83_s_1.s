.syntax unified
	.align 2, 0
	.global task_emy_83_s_1
	.thumb
	.thumb_func
	.type task_emy_83_s_1, %function
task_emy_83_s_1: @ 0803EBCC
	push {r4, r5, r6, lr}
	add sp, #-0x00C
	adds r4, r0, #0x0
	ldr r0, _0803EC44 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x40
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803EC4C
	ldr r1, [r4, #0x08]
	ldr r0, [r4, #0x18]
	adds r6, r1, r0
	str r6, [r4, #0x08]
	ldr r1, [r4, #0x0C]
	ldr r0, [r4, #0x1C]
	adds r5, r1, r0
	str r5, [r4, #0x0C]
	movs r1, #0x22
	ldsh r0, [r4, r1]
	movs r1, #0x03
	bl func_0811D684
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r4, #0x20]
	cmp r0, r1
	bne _0803EC28
	ldr r3, [r4, #0x10]
	movs r0, #0x02
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0xE1
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	bl func_08011F78
	cmp r0, #0x00
	beq _0803EC28
	ldr r0, _0803EC48 @ =0x00000241
	bl func_0811FE70
_0803EC28:
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0x14]
	adds r1, r1, r0
	str r1, [r4, #0x10]
	adds r0, #0x14
	str r0, [r4, #0x14]
	cmp r1, #0x00
	bge _0803EC4C
	ldrh r0, [r4, #0x22]
	adds r0, #0x01
	strh r0, [r4, #0x22]
	movs r0, #0x01
	b _0803EC4E
	.byte 0x00, 0x00
_0803EC44: .4byte 0x02039B84
_0803EC48: .4byte 0x00000241
_0803EC4C:
	movs r0, #0x00
_0803EC4E:
	add sp, #0x00C
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
