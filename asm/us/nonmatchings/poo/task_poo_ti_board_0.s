.syntax unified
	.align 2, 0
	.global task_poo_ti_board_0
	.thumb
	.thumb_func
	.type task_poo_ti_board_0, %function
task_poo_ti_board_0: @ 080CF754
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x0C]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x10]
	movs r5, #0x00
	str r5, [r4, #0x14]
	ldr r0, _080CF78C @ =0x097565FC
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x00]
	str r5, [r4, #0x04]
	ldr r0, _080CF790 @ =0x097565E8
	str r0, [r4, #0x08]
	adds r0, r4, #0x0
	adds r0, #0x1C
	ldr r1, [r4, #0x0C]
	ldr r2, [r4, #0x10]
	ldr r3, [r4, #0x14]
	bl func_08012324
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CF78C: .4byte 0x097565FC
_080CF790: .4byte 0x097565E8
.syntax divided
