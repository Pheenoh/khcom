.syntax unified
	.align 2, 0
	.global task_hum_robe_1
	.thumb
	.thumb_func
	.type task_hum_robe_1, %function
task_hum_robe_1: @ 08059D00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r7, r0, #0x0
	movs r0, #0x40
	adds r0, r0, r7
	mov r8, r0
	adds r0, r7, #0x0
	bl _0800E434
	adds r1, r0, #0x0
	cmp r1, #0x01
	bne _08059D24
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r7, r2
	strh r1, [r0, #0x00]
_08059D24:
	ldr r0, _08059D60 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x16
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08059D68
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r4, r7, r0
	ldrh r0, [r4, #0x00]
	cmp r0, #0x01
	bne _08059D92
	ldr r0, _08059D64 @ =0x0813FDD4
	adds r1, r7, #0x0
	adds r1, #0x14
	ldr r2, [r7, #0x04]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	movs r0, #0x00
	strh r0, [r4, #0x00]
	b _08059D92
	.byte 0x00, 0x00
_08059D60: .4byte 0x02039B84
_08059D64: .4byte 0x0813FDD4
_08059D68:
	adds r4, r7, #0x0
	adds r4, #0x14
	adds r0, r4, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08059D92
	ldr r0, _08059DC0 @ =0x0813FDD4
	ldr r1, [r7, #0x04]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x00
	movs r3, #0x01
	bl func_08019068
	movs r2, #0xC4
	lsls r2, r2, #0x01
	adds r1, r7, r2
	movs r0, #0x01
	strh r0, [r1, #0x00]
_08059D92:
	adds r0, r7, #0x0
	movs r1, #0x01
	bl func_0800F368
	mov r0, r8
	ldr r4, [r0, #0x04]
	ldr r5, [r0, #0x08]
	ldr r6, [r0, #0x0C]
	adds r0, r7, #0x0
	bl func_0800E5F0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, r8
	str r4, [r1, #0x04]
	str r5, [r1, #0x08]
	str r6, [r1, #0x0C]
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08059DC0: .4byte 0x0813FDD4
.syntax divided
