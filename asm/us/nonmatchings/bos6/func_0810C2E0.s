.syntax unified
	.align 2, 0
	.global func_0810C2E0
	.thumb
	.thumb_func
	.type func_0810C2E0, %function
func_0810C2E0: @ 0810C2E0
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0xE4
	bl func_0801BCD4
	adds r4, #0x70
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
