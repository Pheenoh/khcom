.syntax unified
	.align 2, 0
	.global func_080E2BF8
	.thumb
	.thumb_func
	.type func_080E2BF8, %function
func_080E2BF8: @ 080E2BF8
	push {lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _080E2C24 @ =0x02034F20
	ldr r2, [r0, #0x00]
	ldr r0, _080E2C28 @ =0x02034F28
	ldrh r1, [r2, #0x02]
	ldrh r0, [r0, #0x00]
	cmp r1, r0
	beq _080E2C16
	adds r1, r0, #0x0
_080E2C0E:
	adds r2, #0x18
	ldrh r0, [r2, #0x02]
	cmp r0, r1
	bne _080E2C0E
_080E2C16:
	adds r0, r2, #0x0
	adds r1, r3, #0x0
	bl func_080E2668
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E2C24: .4byte 0x02034F20
_080E2C28: .4byte 0x02034F28
.syntax divided
