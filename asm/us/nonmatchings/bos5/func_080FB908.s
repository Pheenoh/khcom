.syntax unified
	.align 2, 0
	.global func_080FB908
	.thumb
	.thumb_func
	.type func_080FB908, %function
func_080FB908: @ 080FB908
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080FB92C @ =0x09992108
	movs r0, #0x4C
	adds r2, r1, #0x0
	muls r2, r0
	adds r0, r3, #0x4
	adds r0, r2, r0
	ldr r1, [r0, #0x00]
	adds r2, r2, r3
	ldrh r2, [r2, #0x08]
	movs r0, #0x01
	bl func_080050B8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080FB92C: .4byte 0x09992108
.syntax divided
