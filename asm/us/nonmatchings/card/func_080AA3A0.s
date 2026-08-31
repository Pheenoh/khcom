.syntax unified
	.align 2, 0
	.global func_080AA3A0
	.thumb
	.thumb_func
	.type func_080AA3A0, %function
func_080AA3A0: @ 080AA3A0
	push {r4, r5, lr}
	adds r5, r0, #0x0
	movs r0, #0x34
	adds r4, r1, #0x0
	muls r4, r0
	ldr r0, _080AA3D0 @ =0x08F70AB0
	adds r4, r4, r0
	ldr r0, [r4, #0x0C]
	adds r1, r5, #0x0
	adds r1, #0xE8
	bl func_08065B6C
	ldr r2, _080AA3D4 @ =0x00000705
	adds r1, r5, r2
	strb r0, [r1, #0x00]
	adds r4, #0x2A
	ldrb r0, [r4, #0x00]
	cmp r0, #0x01
	beq _080AA3F4
	cmp r0, #0x01
	bgt _080AA3D8
	cmp r0, #0x00
	beq _080AA3E2
	b _080AA43E
_080AA3D0: .4byte 0x08F70AB0
_080AA3D4: .4byte 0x00000705
_080AA3D8:
	cmp r0, #0x02
	beq _080AA3FC
	cmp r0, #0x03
	beq _080AA424
	b _080AA43E
_080AA3E2:
	ldr r0, _080AA3EC @ =0x09614458
	ldr r3, _080AA3F0 @ =0x000004BC
	adds r1, r5, r3
	b _080AA402
	.byte 0x00, 0x00
_080AA3EC: .4byte 0x09614458
_080AA3F0: .4byte 0x000004BC
_080AA3F4:
	ldr r0, _080AA3F8 @ =0x09614478
	b _080AA3FE
_080AA3F8: .4byte 0x09614478
_080AA3FC:
	ldr r0, _080AA418 @ =0x09614498
_080AA3FE:
	ldr r2, _080AA41C @ =0x000004BC
	adds r1, r5, r2
_080AA402:
	ldr r2, [r1, #0x00]
	ldrh r1, [r2, #0x06]
	lsls r1, r1, #0x05
	ldr r3, _080AA420 @ =0x05000200
	adds r1, r1, r3
	ldrh r2, [r2, #0x08]
	lsls r2, r2, #0x15
	lsrs r2, r2, #0x10
	bl LoadPalette
	b _080AA43E
_080AA418: .4byte 0x09614498
_080AA41C: .4byte 0x000004BC
_080AA420: .4byte 0x05000200
_080AA424:
	ldr r0, _080AA444 @ =0x096144B8
	ldr r2, _080AA448 @ =0x000004BC
	adds r1, r5, r2
	ldr r2, [r1, #0x00]
	ldrh r1, [r2, #0x06]
	lsls r1, r1, #0x05
	ldr r3, _080AA44C @ =0x05000200
	adds r1, r1, r3
	ldrh r2, [r2, #0x08]
	lsls r2, r2, #0x15
	lsrs r2, r2, #0x10
	bl LoadPalette
_080AA43E:
	pop {r4, r5}
	pop {r0}
	bx r0
_080AA444: .4byte 0x096144B8
_080AA448: .4byte 0x000004BC
_080AA44C: .4byte 0x05000200
.syntax divided
