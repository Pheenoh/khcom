.syntax unified
	.align 2, 0
	.global func_0800889C
	.thumb
	.thumb_func
	.type func_0800889C, %function
func_0800889C: @ 0800889C
	push {lr}
	ldr r0, _080088B0 @ =0x0203407C
	ldr r0, [r0, #0x00]
	bl func_08008340
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080088B0: .4byte 0x0203407C
.syntax divided
