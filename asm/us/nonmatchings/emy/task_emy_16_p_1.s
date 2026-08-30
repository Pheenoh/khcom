.syntax unified
	.align 2, 0
	.global task_emy_16_p_1
	.thumb
	.thumb_func
	.type task_emy_16_p_1, %function
task_emy_16_p_1: @ 08039200
	push {r4, lr}
	add sp, #-0x00C
	adds r4, r0, #0x0
	ldr r0, _0803922C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x40
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08039274
	adds r0, r4, #0x0
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08039234
	ldr r0, [r4, #0x20]
	ldr r1, _08039230 @ =0xFFFFFC00
	b _0803923A
	.byte 0x00, 0x00
_0803922C: .4byte 0x02039B84
_08039230: .4byte 0xFFFFFC00
_08039234:
	ldr r0, [r4, #0x20]
	movs r1, #0x80
	lsls r1, r1, #0x03
_0803923A:
	adds r0, r0, r1
	str r0, [r4, #0x20]
	ldr r1, [r4, #0x20]
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x28]
	movs r0, #0x04
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0xB7
	bl func_08011F78
	cmp r0, #0x00
	beq _0803925E
	movs r0, #0x99
	lsls r0, r0, #0x02
	bl func_0811FE70
_0803925E:
	adds r0, r4, #0x0
	adds r0, #0x20
	adds r1, r4, #0x0
	adds r1, #0x24
	movs r2, #0x10
	movs r3, #0x00
	bl func_0801A8A4
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _08039278
_08039274:
	movs r0, #0x00
	b _08039298
_08039278:
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #0x30]
	adds r1, r1, r0
	str r1, [r4, #0x28]
	adds r0, #0x2E
	str r0, [r4, #0x30]
	cmp r1, #0x00
	blt _0803928E
	ldr r0, _080392A0 @ =0xFFFFFC00
	str r0, [r4, #0x30]
	str r2, [r4, #0x28]
_0803928E:
	adds r0, r4, #0x0
	adds r0, #0x08
	bl func_08005A64
	movs r0, #0x01
_08039298:
	add sp, #0x00C
	pop {r4}
	pop {r1}
	bx r1
_080392A0: .4byte 0xFFFFFC00
.syntax divided
