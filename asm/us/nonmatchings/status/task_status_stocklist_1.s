.syntax unified
	.align 2, 0
	.global task_status_stocklist_1
	.thumb
	.thumb_func
	.type task_status_stocklist_1, %function
task_status_stocklist_1: @ 080D8190
	adds r2, r0, #0x0
	ldr r0, _080D81C0 @ =0x000004C6
	adds r1, r2, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x18
	bls _080D81BA
	movs r3, #0x00
	movs r0, #0x99
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldrb r0, [r2, #0x00]
	cmp r0, #0x00
	bne _080D81B4
	movs r3, #0x01
_080D81B4:
	strb r3, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r1, #0x00]
_080D81BA:
	movs r0, #0x01
	bx lr
	.byte 0x00, 0x00
_080D81C0: .4byte 0x000004C6
.syntax divided
