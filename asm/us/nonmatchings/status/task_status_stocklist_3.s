.syntax unified
	.align 2, 0
	.global task_status_stocklist_3
	.thumb
	.thumb_func
	.type task_status_stocklist_3, %function
task_status_stocklist_3: @ 080D8288
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	movs r0, #0x92
	lsls r0, r0, #0x03
	adds r4, r6, r0
	movs r5, #0x07
_080D8294:
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080D829E
	bl func_080028C0
_080D829E:
	adds r4, #0x04
	subs r5, #0x01
	cmp r5, #0x00
	bge _080D8294
	movs r1, #0x96
	lsls r1, r1, #0x03
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r1, _080D82D0 @ =0x000004B4
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r1, #0x97
	lsls r1, r1, #0x03
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D82D0: .4byte 0x000004B4
.syntax divided
