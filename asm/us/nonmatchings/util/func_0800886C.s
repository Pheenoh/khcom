.syntax unified
	.align 2, 0
	.global func_0800886C
	.thumb
	.thumb_func
	.type func_0800886C, %function
func_0800886C: @ 0800886C
	push {lr}
	ldr r0, _08008880 @ =0x0203407C
	ldr r0, [r0, #0x00]
	bl func_0800833C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08008880: .4byte 0x0203407C
.syntax divided
