.syntax unified
	.align 2, 0
	.global func_080E5E44
	.thumb
	.thumb_func
	.type func_080E5E44, %function
func_080E5E44: @ 080E5E44
	push {r4, lr}
	ldr r0, _080E5E7C @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldrb r4, [r0, #0x0D]
	lsls r4, r4, #0x03
	ldr r0, _080E5E80 @ =0x0984D134
	adds r4, r4, r0
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #0x04]
	ldrb r4, [r4, #0x03]
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _080E5E84 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080E5E8C
	ldr r1, _080E5E88 @ =0x09EF6A34
	b _080E5E8E
_080E5E7C: .4byte 0x0203C7AC
_080E5E80: .4byte 0x0984D134
_080E5E84: .4byte 0x02039BB0
_080E5E88: .4byte 0x09EF6A34
_080E5E8C:
	ldr r1, _080E5EA4 @ =0x09EF6A42
_080E5E8E:
	ldr r0, _080E5EA8 @ =0x0203C590
	ldrb r0, [r0, #0x04]
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080E5EA4: .4byte 0x09EF6A42
_080E5EA8: .4byte 0x0203C590
.syntax divided
