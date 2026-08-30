.syntax unified
	.align 2, 0
	.global task_status_tab_1
	.thumb
	.thumb_func
	.type task_status_tab_1, %function
task_status_tab_1: @ 080D7C24
	ldr r2, _080D7C40 @ =0x09EF6920
	ldr r1, [r0, #0x18]
	ldr r1, [r1, #0x00]
	lsls r1, r1, #0x02
	adds r2, r1, r2
	ldr r2, [r2, #0x00]
	str r2, [r0, #0x10]
	ldr r2, _080D7C44 @ =0x09EF6934
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x14]
	movs r0, #0x01
	bx lr
	.byte 0x00, 0x00
_080D7C40: .4byte 0x09EF6920
_080D7C44: .4byte 0x09EF6934
.syntax divided
