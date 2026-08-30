.syntax unified
	.align 2, 0
	.global mode_test_2
	.thumb
	.thumb_func
	.type mode_test_2, %function
mode_test_2: @ 0805F1A0
	push {lr}
	ldr r0, _0805F1B8 @ =0x02034A08
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, _0805F1BC @ =0x02034A0C
	ldr r0, [r0, #0x00]
	bl func_08002C10
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805F1B8: .4byte 0x02034A08
_0805F1BC: .4byte 0x02034A0C
.syntax divided
