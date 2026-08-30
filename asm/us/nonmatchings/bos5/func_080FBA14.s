.syntax unified
	.align 2, 0
	.global func_080FBA14
	.thumb
	.thumb_func
	.type func_080FBA14, %function
func_080FBA14: @ 080FBA14
	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0xD2
	lsls r2, r2, #0x01
	adds r3, r0, r2
	movs r4, #0x00
	strh r1, [r3, #0x00]
	ldr r2, _080FBA48 @ =0x09992E24
	lsls r1, r1, #0x10
	asrs r1, r1, #0x0D
	adds r1, r1, r2
	ldr r2, [r1, #0x00]
	str r2, [r3, #0x04]
	ldrh r1, [r1, #0x04]
	strh r1, [r3, #0x08]
	strh r4, [r3, #0x0A]
	ldrh r1, [r2, #0x02]
	strh r1, [r3, #0x0C]
	ldrh r1, [r2, #0x00]
	bl func_080FB930
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080FBA48: .4byte 0x09992E24
.syntax divided
