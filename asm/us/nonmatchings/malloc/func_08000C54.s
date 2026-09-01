.syntax unified
	.align 2, 0
	.global func_08000C54
	.thumb
	.thumb_func
	.type func_08000C54, %function
func_08000C54: @ 08000C54
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	ldr r6, [r5, #0x08]
	adds r1, #0x08
	adds r2, r4, #0x0
	adds r2, #0x0C
	bl func_08000B6C
	adds r2, r4, #0x4
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_08000B08
	ldrh r1, [r5, #0x0C]
	ldr r0, _08000C80 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r5, #0x0C]
	cmp r6, #0x00
	bne _08000C84
	movs r0, #0x00
	b _08000C86
_08000C80: .4byte 0x0000FFFE
_08000C84:
	ldr r0, [r6, #0x00]
_08000C86:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
