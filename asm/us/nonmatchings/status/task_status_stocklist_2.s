.syntax unified
	.align 2, 0
	.global task_status_stocklist_2
	.thumb
	.thumb_func
	.type task_status_stocklist_2, %function
task_status_stocklist_2: @ 080D81C4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	movs r1, #0x24
	movs r6, #0x00
	movs r7, #0x00
_080D81D0:
	movs r2, #0x92
	lsls r2, r2, #0x03
	adds r0, r4, r2
	adds r0, r0, r7
	ldr r0, [r0, #0x00]
	lsls r5, r1, #0x10
	cmp r0, #0x00
	beq _080D8268
	movs r3, #0x99
	lsls r3, r3, #0x03
	adds r0, r4, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D8238
	bl func_080D78A8
	adds r0, r0, r6
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl func_080D855C
	bl func_0800FD20
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D8238
	asrs r1, r5, #0x10
	ldr r2, _080D8280 @ =0x000004BC
	adds r0, r4, r2
	ldr r2, [r0, #0x00]
	ldr r3, _080D8284 @ =0x000004B4
	adds r0, r4, r3
	ldr r0, [r0, #0x00]
	mov r12, r0
	adds r3, #0x04
	adds r0, r4, r3
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	adds r0, r6, #0x0
	adds r0, #0x0D
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	movs r0, #0x00
	mov r3, r12
	bl DrawSprite
_080D8238:
	asrs r1, r5, #0x10
	movs r2, #0x92
	lsls r2, r2, #0x03
	adds r0, r4, r2
	adds r0, r0, r7
	ldr r3, [r0, #0x00]
	adds r2, #0x20
	adds r0, r4, r2
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	adds r0, r6, #0x0
	adds r0, #0x15
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	movs r0, #0x01
	movs r2, #0x00
	bl DrawSprite
_080D8268:
	movs r3, #0xC0
	lsls r3, r3, #0x0C
	adds r0, r5, r3
	lsrs r1, r0, #0x10
	adds r7, #0x04
	adds r6, #0x01
	cmp r6, #0x07
	ble _080D81D0
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D8280: .4byte 0x000004BC
_080D8284: .4byte 0x000004B4
.syntax divided
