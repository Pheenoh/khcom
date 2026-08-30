.syntax unified
	.align 2, 0
	.global task_poo_mapanime_0
	.thumb
	.thumb_func
	.type task_poo_mapanime_0, %function
task_poo_mapanime_0: @ 080CD13C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _080CD158 @ =0x096FD3E8
	bl func_080DDDDC
	adds r4, #0x0C
	ldr r1, _080CD15C @ =0x096FD400
	adds r0, r4, #0x0
	bl func_080DDDDC
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CD158: .4byte 0x096FD3E8
_080CD15C: .4byte 0x096FD400
.syntax divided
