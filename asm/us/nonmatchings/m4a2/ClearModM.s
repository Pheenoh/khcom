.syntax unified
	.align 2, 0
	.global ClearModM
	.thumb
	.thumb_func
	.type ClearModM, %function
ClearModM: @ 08120200
	push {lr}
	ldr r1, _08120210 @ =0x0203D88C
	ldr r1, [r1, #0x00]
	bl _call_via_r1
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08120210: .4byte 0x0203D88C
.syntax divided
