.syntax unified
	.align 2, 0
	.global task_poo_ti_board_3
	.thumb
	.thumb_func
	.type task_poo_ti_board_3, %function
task_poo_ti_board_3: @ 080CF874
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CF890
	bl func_08002C10
	adds r0, r4, #0x0
	adds r0, #0x1C
	bl func_08012304
_080CF890:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
