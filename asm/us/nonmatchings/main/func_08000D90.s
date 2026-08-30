.syntax unified
	.align 2, 0
	.global func_08000D90
	.thumb
	.thumb_func
	.type func_08000D90, %function
func_08000D90: @ 08000D90
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r5, [r4, #0x08]
	adds r1, #0x08
	adds r2, #0x0C
	bl func_08000B6C
	ldrh r1, [r4, #0x0C]
	ldr r0, _08000DB0 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r4, #0x0C]
	cmp r5, #0x00
	bne _08000DB4
	movs r0, #0x00
	b _08000DB6
_08000DB0: .4byte 0x0000FFFE
_08000DB4:
	ldr r0, [r5, #0x00]
_08000DB6:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
