.syntax unified
	.align 2, 0
	.global task_poo_mapbeeborn_3
	.thumb
	.thumb_func
	.type task_poo_mapbeeborn_3, %function
task_poo_mapbeeborn_3: @ 080D260C
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x98
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D2620
	adds r0, r4, #0x0
	adds r0, #0x20
	bl func_08012304
_080D2620:
	adds r0, r4, #0x0
	adds r0, #0x80
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
