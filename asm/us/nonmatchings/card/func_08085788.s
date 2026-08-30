.syntax unified
	.align 2, 0
	.global func_08085788
	.thumb
	.thumb_func
	.type func_08085788, %function
func_08085788: @ 08085788
	adds r3, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldrh r0, [r3, #0x00]
	cmp r0, #0x00
	beq _080857B4
	ldr r1, _080857B8 @ =0x02039DE0
	lsls r0, r2, #0x03
	subs r0, r0, r2
	adds r2, r3, #0x0
	lsls r0, r0, #0x05
	adds r1, #0xC6
	adds r1, r0, r1
_080857A2:
	ldrb r0, [r2, #0x00]
	strb r0, [r1, #0x00]
	ldrb r0, [r2, #0x01]
	strb r0, [r1, #0x01]
	adds r1, #0x02
	adds r2, #0x02
	ldrh r0, [r2, #0x00]
	cmp r0, #0x00
	bne _080857A2
_080857B4:
	bx lr
	.byte 0x00, 0x00
_080857B8: .4byte 0x02039DE0
.syntax divided
