.syntax unified
	.align 2, 0
	.global task_roomcreate_3
	.thumb
	.thumb_func
	.type task_roomcreate_3, %function
task_roomcreate_3: @ 0803F6E0
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _0803F700 @ =0x0203DB10
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r1, #0xFF
	bl func_08120EF8
	adds r4, #0x2C
	adds r0, r4, #0x0
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803F700: .4byte 0x0203DB10
.syntax divided
