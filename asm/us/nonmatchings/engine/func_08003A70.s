.syntax unified
	.align 2, 0
	.global func_08003A70
	.thumb
	.thumb_func
	.type func_08003A70, %function
func_08003A70: @ 08003A70
	push {lr}
	adds r2, r0, #0x0
	adds r3, r1, #0x0
	ldr r0, [r2, #0x20]
	cmp r0, #0x02
	bne _08003A90
	ldrh r1, [r2, #0x06]
	lsls r1, r1, #0x05
	ldr r0, _08003A94 @ =0x05000200
	adds r1, r1, r0
	ldrh r2, [r2, #0x08]
	lsls r2, r2, #0x15
	lsrs r2, r2, #0x10
	adds r0, r3, #0x0
	bl LoadPalette
_08003A90:
	pop {r0}
	bx r0
_08003A94: .4byte 0x05000200
.syntax divided
