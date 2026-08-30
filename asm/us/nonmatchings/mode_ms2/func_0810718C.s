.syntax unified
	.align 2, 0
	.global func_0810718C
	.thumb
	.thumb_func
	.type func_0810718C, %function
func_0810718C: @ 0810718C
	push {lr}
	bl func_0810714C
	ldr r2, _081071A8 @ =0x02035E28
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x03
	subs r1, r1, r0
	lsls r1, r1, #0x02
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_081071A8: .4byte 0x02035E28
.syntax divided
