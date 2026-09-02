.syntax unified
	.align 2, 0
	.global func_080A5C60
	.thumb
	.thumb_func
	.type func_080A5C60, %function
func_080A5C60: @ 080A5C60
	push {r4, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x34
	muls r0, r1
	ldr r1, _080A5C90 @ =0x08F70AB0
	adds r0, r0, r1
	ldr r1, _080A5C94 @ =0x09EE8F48
	ldrh r0, [r0, #0x1C]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r2, #0xF0
	lsls r2, r2, #0x01
	adds r1, r4, r2
	bl func_08065B6C
	ldr r1, _080A5C98 @ =0x000004FE
	adds r4, r4, r1
	strb r0, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_080A5C90: .4byte 0x08F70AB0
_080A5C94: .4byte 0x09EE8F48
_080A5C98: .4byte 0x000004FE
.syntax divided
