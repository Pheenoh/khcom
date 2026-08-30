.syntax unified
	.align 2, 0
	.global mode_status_2
	.thumb
	.thumb_func
	.type mode_status_2, %function
mode_status_2: @ 080D7558
	push {lr}
	ldr r0, _080D7564 @ =0x02034EE0
	bl func_08000F0C
	pop {r0}
	bx r0
_080D7564: .4byte 0x02034EE0
	.byte 0x01, 0x49, 0x08, 0x70, 0x70, 0x47, 0x00, 0x00, 0xF8, 0x4E, 0x03, 0x02
.syntax divided
