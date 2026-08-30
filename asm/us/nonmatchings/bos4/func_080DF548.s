.syntax unified
	.align 2, 0
	.global func_080DF548
	.thumb
	.thumb_func
	.type func_080DF548, %function
func_080DF548: @ 080DF548
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r0, _080DF564 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	blt _080DF56C
	ldr r0, _080DF568 @ =0x0203C590
	lsls r1, r1, #0x04
	adds r1, r1, r0
	adds r1, #0x26
	ldrb r0, [r1, #0x00]
	b _080DF56E
	.byte 0x00, 0x00
_080DF564: .4byte 0x0203C7AC
_080DF568: .4byte 0x0203C590
_080DF56C:
	movs r0, #0x00
_080DF56E:
	bx lr
.syntax divided
