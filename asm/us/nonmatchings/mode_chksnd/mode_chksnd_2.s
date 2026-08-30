.syntax unified
	.align 2, 0
	.global mode_chksnd_2
	.thumb
	.thumb_func
	.type mode_chksnd_2, %function
mode_chksnd_2: @ 0800BB18
	push {lr}
	bl func_0811FFA4
	ldr r0, _0800BB28 @ =0x020348A0
	bl func_08000F0C
	pop {r0}
	bx r0
_0800BB28: .4byte 0x020348A0
.syntax divided
