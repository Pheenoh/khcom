.syntax unified
	.align 2, 0
	.global mode_debug_2
	.thumb
	.thumb_func
	.type mode_debug_2, %function
mode_debug_2: @ 0800B2E4
	push {r4, lr}
	bl func_080609A0
	ldr r4, _0800B308 @ =0x02034898
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x04]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x08]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	bl func_080009C4
	pop {r4}
	pop {r0}
	bx r0
_0800B308: .4byte 0x02034898
.syntax divided
