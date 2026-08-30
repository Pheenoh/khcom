.syntax unified
	.align 2, 0
	.global func_080050DC
	.thumb
	.thumb_func
	.type func_080050DC, %function
func_080050DC: @ 080050DC
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r6, r1, #0x0
	lsls r5, r2, #0x10
	lsrs r5, r5, #0x10
	bl func_08004FC8
	ldr r0, _08005108 @ =0x030074D0
	adds r4, r4, r0
	ldrb r1, [r4, #0x00]
	lsls r1, r1, #0x05
	movs r0, #0xA0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	adds r0, r6, #0x0
	adds r2, r5, #0x0
	bl func_08005BE8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08005108: .4byte 0x030074D0
.syntax divided
