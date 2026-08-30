.syntax unified
	.align 2, 0
	.global func_080DED64
	.thumb
	.thumb_func
	.type func_080DED64, %function
func_080DED64: @ 080DED64
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _080DED80 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080DED88
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x02
	ldr r1, _080DED84 @ =0x0984C868
	b _080DED90
	.byte 0x00, 0x00
_080DED80: .4byte 0x02039BB0
_080DED84: .4byte 0x0984C868
_080DED88:
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x02
	ldr r1, _080DED94 @ =0x0984CBD0
_080DED90:
	adds r0, r0, r1
	bx lr
_080DED94: .4byte 0x0984CBD0
.syntax divided
