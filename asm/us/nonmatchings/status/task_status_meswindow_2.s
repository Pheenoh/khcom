.syntax unified
	.align 2, 0
	.global task_status_meswindow_2
	.thumb
	.thumb_func
	.type task_status_meswindow_2, %function
task_status_meswindow_2: @ 080D89D0
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x1C]
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D89E4
	movs r0, #0x00
	bl func_0800501C
	b _080D89F0
_080D89E4:
	movs r0, #0x00
	bl func_08004FC8
	adds r0, r4, #0x0
	bl TaskPoolDraw
_080D89F0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
