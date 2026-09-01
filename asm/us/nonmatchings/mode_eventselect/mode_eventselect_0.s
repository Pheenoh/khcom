.syntax unified
	.align 2, 0
	.global mode_eventselect_0
	.thumb
	.thumb_func
	.type mode_eventselect_0, %function
mode_eventselect_0: @ 080750D4
	push {lr}
	bl func_08004DB0
	bl func_08085FB0
	bl func_08085C3C
	bl func_08093BB4
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1E
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x00
	bl EnableBg
	movs r1, #0x80
	lsls r1, r1, #0x08
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0805FA8C
	ldr r1, _08075118 @ =0x08F70990
	movs r0, #0x00
	movs r2, #0x20
	movs r3, #0x00
	bl func_0805FA60
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08075118: .4byte 0x08F70990
.syntax divided
