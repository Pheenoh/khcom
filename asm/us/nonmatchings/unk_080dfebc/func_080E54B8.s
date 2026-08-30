.syntax unified
	.align 2, 0
	.global func_080E54B8
	.thumb
	.thumb_func
	.type func_080E54B8, %function
func_080E54B8: @ 080E54B8
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _080E54DC @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080E54E8
	ldr r1, _080E54E0 @ =0x09EF70D0
	ldr r0, _080E54E4 @ =0x0203C590
	ldrb r0, [r0, #0x04]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	lsls r1, r2, #0x02
	ldr r0, [r0, #0x30]
	b _080E54F8
	.byte 0x00, 0x00
_080E54DC: .4byte 0x02039BB0
_080E54E0: .4byte 0x09EF70D0
_080E54E4: .4byte 0x0203C590
_080E54E8:
	ldr r1, _080E54FC @ =0x09EF70D0
	ldr r0, _080E5500 @ =0x0203C590
	ldrb r0, [r0, #0x04]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	lsls r1, r2, #0x02
	ldr r0, [r0, #0x34]
_080E54F8:
	adds r0, r0, r1
	bx lr
_080E54FC: .4byte 0x09EF70D0
_080E5500: .4byte 0x0203C590
	.byte 0x01, 0x48, 0x00, 0x68, 0x70, 0x47, 0x00, 0x00, 0x30, 0x4F, 0x03, 0x02
.syntax divided
