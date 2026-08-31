.syntax unified
	.align 2, 0
	.global task_hum_vixen_ndl_1
	.thumb
	.thumb_func
	.type task_hum_vixen_ndl_1, %function
task_hum_vixen_ndl_1: @ 08055540
	push {r4, r5, lr}
	add sp, #-0x00C
	adds r5, r0, #0x0
	ldr r0, _08055570 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x40
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0805556A
	adds r4, r5, #0x0
	adds r4, #0x08
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08055574
_0805556A:
	movs r0, #0x00
	b _080555E2
	.byte 0x00, 0x00
_08055570: .4byte 0x02039B84
_08055574:
	adds r0, r4, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x02
	bgt _080555BA
	cmp r0, #0x01
	blt _080555BA
	adds r0, r5, #0x0
	adds r0, #0x2D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080555BA
	ldr r0, _080555EC @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0x07
	ands r0, r1
	adds r1, r5, #0x0
	adds r1, #0x2C
	ldrb r1, [r1, #0x00]
	cmp r0, r1
	bne _080555BA
	movs r0, #0x9D
	lsls r0, r0, #0x01
	ldr r1, [r5, #0x20]
	ldr r2, [r5, #0x24]
	movs r3, #0x04
	str r3, [sp, #0x000]
	str r3, [sp, #0x004]
	movs r3, #0x10
	str r3, [sp, #0x008]
	movs r3, #0x00
	bl func_08011F78
_080555BA:
	ldr r0, _080555F0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r1, [r0, #0x38]
	ldr r0, [r0, #0x34]
	movs r2, #0x80
	lsls r2, r2, #0x06
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080555DA
	adds r1, r5, #0x0
	adds r1, #0x2D
	movs r0, #0x01
	strb r0, [r1, #0x00]
_080555DA:
	adds r0, r4, #0x0
	bl AnimUpdate
	movs r0, #0x01
_080555E2:
	add sp, #0x00C
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080555EC: .4byte 0x03007480
_080555F0: .4byte 0x02039B84
.syntax divided
