.syntax unified
	.align 2, 0
	.global func_080A6EB4
	.thumb
	.thumb_func
	.type func_080A6EB4, %function
func_080A6EB4: @ 080A6EB4
	push {r4, r5, lr}
	adds r5, r0, #0x0
	movs r0, #0x34
	adds r4, r1, #0x0
	muls r4, r0
	ldr r0, _080A6EE4 @ =0x08F70AB0
	adds r4, r4, r0
	ldr r0, [r4, #0x0C]
	adds r1, r5, #0x0
	adds r1, #0xF0
	bl func_08065B6C
	ldr r2, _080A6EE8 @ =0x000004FD
	adds r1, r5, r2
	strb r0, [r1, #0x00]
	adds r4, #0x2A
	ldrb r0, [r4, #0x00]
	cmp r0, #0x01
	beq _080A6F04
	cmp r0, #0x01
	bgt _080A6EEC
	cmp r0, #0x00
	beq _080A6EF6
	b _080A6F50
_080A6EE4: .4byte 0x08F70AB0
_080A6EE8: .4byte 0x000004FD
_080A6EEC:
	cmp r0, #0x02
	beq _080A6F0C
	cmp r0, #0x03
	beq _080A6F34
	b _080A6F50
_080A6EF6:
	ldr r0, _080A6F00 @ =0x09614458
	movs r3, #0xF6
	lsls r3, r3, #0x02
	adds r1, r5, r3
	b _080A6F14
_080A6F00: .4byte 0x09614458
_080A6F04:
	ldr r0, _080A6F08 @ =0x09614478
	b _080A6F0E
_080A6F08: .4byte 0x09614478
_080A6F0C:
	ldr r0, _080A6F2C @ =0x09614498
_080A6F0E:
	movs r2, #0xF6
	lsls r2, r2, #0x02
	adds r1, r5, r2
_080A6F14:
	ldr r2, [r1, #0x00]
	ldrh r1, [r2, #0x06]
	lsls r1, r1, #0x05
	ldr r3, _080A6F30 @ =0x05000200
	adds r1, r1, r3
	ldrh r2, [r2, #0x08]
	lsls r2, r2, #0x15
	lsrs r2, r2, #0x10
	bl LoadPalette
	b _080A6F50
	.byte 0x00, 0x00
_080A6F2C: .4byte 0x09614498
_080A6F30: .4byte 0x05000200
_080A6F34:
	ldr r0, _080A6F58 @ =0x096144B8
	movs r2, #0xF6
	lsls r2, r2, #0x02
	adds r1, r5, r2
	ldr r2, [r1, #0x00]
	ldrh r1, [r2, #0x06]
	lsls r1, r1, #0x05
	ldr r3, _080A6F5C @ =0x05000200
	adds r1, r1, r3
	ldrh r2, [r2, #0x08]
	lsls r2, r2, #0x15
	lsrs r2, r2, #0x10
	bl LoadPalette
_080A6F50:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080A6F58: .4byte 0x096144B8
_080A6F5C: .4byte 0x05000200
.syntax divided
