.syntax unified
	.align 2, 0
	.global task_poo_ti_board_1
	.thumb
	.thumb_func
	.type task_poo_ti_board_1, %function
task_poo_ti_board_1: @ 080CF794
	push {lr}
	adds r1, r0, #0x0
	ldr r0, [r1, #0x04]
	cmp r0, #0x00
	beq _080CF7B4
	adds r0, r1, #0x0
	adds r0, #0x1C
	movs r1, #0x09
	bl func_08012660
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CF7B4
	ldr r1, _080CF7BC @ =0x0203C3F0
	movs r0, #0x05
	str r0, [r1, #0x00]
_080CF7B4:
	movs r0, #0x01
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080CF7BC: .4byte 0x0203C3F0
.syntax divided
