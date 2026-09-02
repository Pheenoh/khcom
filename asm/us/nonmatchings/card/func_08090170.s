.syntax unified
	.align 2, 0
	.global func_08090170
	.thumb
	.thumb_func
	.type func_08090170, %function
func_08090170: @ 08090170
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x48
	ldrh r1, [r5, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080901AC
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x08]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x0C]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x10]
	bl ReleaseObjTiles
	ldrh r1, [r5, #0x00]
	ldr r0, _080901B4 @ =0x0000FFFE
	ands r0, r1
	movs r1, #0x00
	strh r0, [r5, #0x00]
	str r1, [r4, #0x08]
	str r1, [r4, #0x0C]
	str r1, [r4, #0x10]
	str r1, [r4, #0x04]
_080901AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080901B4: .4byte 0x0000FFFE
.syntax divided
