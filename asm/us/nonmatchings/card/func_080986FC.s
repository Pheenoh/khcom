.syntax unified
	.align 2, 0
	.global func_080986FC
	.thumb
	.thumb_func
	.type func_080986FC, %function
func_080986FC: @ 080986FC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x00
	beq _08098754
	movs r0, #0x80
	lsls r0, r0, #0x01
	bl func_080038C8
	adds r5, r0, #0x0
	ldr r0, _08098748 @ =0x09EF1198
	ldr r1, [r0, #0x04]
	ldr r2, _0809874C @ =0x0950C478
	adds r0, r5, #0x0
	bl func_080038E4
	lsls r1, r4, #0x07
	ldr r0, [r5, #0x00]
	adds r0, r0, r1
	ldrh r1, [r5, #0x06]
	adds r1, #0x04
	lsls r1, r1, #0x05
	ldr r4, _08098750 @ =0x06010000
	adds r1, r1, r4
	movs r2, #0x80
	bl RequestDma3Copy
	ldr r0, [r5, #0x00]
	movs r1, #0xA0
	lsls r1, r1, #0x03
	adds r0, r0, r1
	ldrh r1, [r5, #0x06]
	lsls r1, r1, #0x05
	adds r1, r1, r4
	movs r2, #0x80
	bl RequestDma3Copy
	b _08098768
_08098748: .4byte 0x09EF1198
_0809874C: .4byte 0x0950C478
_08098750: .4byte 0x06010000
_08098754:
	movs r0, #0x80
	bl func_080038C8
	adds r5, r0, #0x0
	ldr r0, _08098770 @ =0x09EF1198
	ldr r1, [r0, #0x00]
	ldr r2, _08098774 @ =0x0950C478
	adds r0, r5, #0x0
	bl func_080038E4
_08098768:
	adds r0, r5, #0x0
	pop {r4, r5}
	pop {r1}
	bx r1
_08098770: .4byte 0x09EF1198
_08098774: .4byte 0x0950C478
.syntax divided
